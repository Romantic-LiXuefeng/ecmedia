/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "../common_video/source/libyuv/include/webrtc_libyuv.h"
#include "video_render_android_surface_view.h"
#include "../system_wrappers/include/critical_section_wrapper.h"
#include "../system_wrappers/include/tick_util.h"

#ifdef ANDROID_LOG
#include <android/log.h>
#include <stdio.h>

#undef WEBRTC_TRACE
#define WEBRTC_TRACE(a,b,c,...)  __android_log_print(ANDROID_LOG_DEBUG, "*WEBRTC*", __VA_ARGS__)
#else
#include "../system_wrappers/include/trace.h"
#endif

namespace yuntongxunwebrtc {

AndroidSurfaceViewRenderer::AndroidSurfaceViewRenderer(
    const int32_t id,
    const VideoRenderType videoRenderType,
    void* window,
    const bool fullscreen) :
    VideoRenderAndroid(id,videoRenderType,window,fullscreen),
    _javaRenderObj(NULL)
{
}

AndroidSurfaceViewRenderer::~AndroidSurfaceViewRenderer() {
  WEBRTC_TRACE(kTraceInfo, kTraceVideoRenderer, _id,
               "AndroidSurfaceViewRenderer dtor");
  if(g_jvm) {
    // get the JNI env for this thread
    bool isAttached = false;
    JNIEnv* env = NULL;
    if (g_jvm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK) {
      // try to attach the thread and get the env
      // Attach this thread to JVM
      jint res = g_jvm->AttachCurrentThread(&env, NULL);

      // Get the JNI env for this thread
      if ((res < 0) || !env) {
        WEBRTC_TRACE(kTraceError,
                     kTraceVideoRenderer,
                     _id,
                     "%s: Could not attach thread to JVM (%d, %p)",
                     __FUNCTION__,
                     res,
                     env);
        env=NULL;
      }
      else {
        isAttached = true;
      }
    }
    env->DeleteGlobalRef(_javaRenderObj);

    if (isAttached) {
      if (g_jvm->DetachCurrentThread() < 0) {
        WEBRTC_TRACE(kTraceWarning,
                     kTraceVideoRenderer,
                     _id,
                     "%s: Could not detach thread from JVM",
                     __FUNCTION__);
      }
    }
  }
}

int32_t AndroidSurfaceViewRenderer::Init() {
  if (!g_jvm) {
    WEBRTC_TRACE(kTraceError,
                 kTraceVideoRenderer,
                 _id,
                 "(%s): Not a valid Java VM pointer.",
                 __FUNCTION__);
    return -1;
  }
  if(!_ptrWindow) {
    WEBRTC_TRACE(kTraceWarning,
                 kTraceVideoRenderer,
                 _id,
                 "(%s): No window have been provided.",
                 __FUNCTION__);
    return -1;
  }

  // get the JNI env for this thread
  bool isAttached = false;
  JNIEnv* env = NULL;


  if (g_jvm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK)
  {
    // try to attach the thread and get the env
    // Attach this thread to JVM
    jint res = g_jvm->AttachCurrentThread(&env, NULL);

    // Get the JNI env for this thread
    if ((res < 0) || !env) {
      WEBRTC_TRACE(kTraceError,
                   kTraceVideoRenderer,
                   _id,
                   "%s: Could not attach thread to JVM (%d, %p)",
                   __FUNCTION__,
                   res,
                   env);
      return -1;
    }
    isAttached = true;
  }

  jstring tempName = env->NewStringUTF("com/yuntongxun/ecsdk/core/voip/ViESurfaceRenderer");

  jclass renderSurfaceClass = reinterpret_cast<jclass>(env->CallObjectMethod(g_classLoader, g_loadClassID, tempName, 1));

  // get the method ID for the constructor
  jmethodID cid = env->GetMethodID(renderSurfaceClass,
                                   "<init>",
                                   "(Ljava/lang/String;)V");
  if (cid == NULL) {
    WEBRTC_TRACE(kTraceError,
                 kTraceVideoRenderer,
                 _id,
                 "%s: could not get constructor ID",
                 __FUNCTION__);
    return -1; /* exception thrown */
  }

  // construct the object
  jobject javaRenderObjLocal = env->NewObject(renderSurfaceClass,
                                              cid,
                                              env->NewStringUTF((const char *)_ptrWindow));
  if (!javaRenderObjLocal) {
    WEBRTC_TRACE(kTraceError,
                 kTraceVideoRenderer,
                 _id,
                 "%s: could not create Java Render",
                 __FUNCTION__);
    return -1;
  }

  // create a reference to the object (to tell JNI that we are referencing it
  // after this function has returned)
  _javaRenderObj = env->NewGlobalRef(javaRenderObjLocal);
  if (!_javaRenderObj) {
    WEBRTC_TRACE(kTraceError,
                 kTraceVideoRenderer,
                 _id,
                 "%s: could not create Java SurfaceRender object reference",
                 __FUNCTION__);
    return -1;
  }

    env->DeleteLocalRef(javaRenderObjLocal);

  // Detach this thread if it was attached
  if (isAttached) {
    if (g_jvm->DetachCurrentThread() < 0) {
      WEBRTC_TRACE(kTraceWarning,
                   kTraceVideoRenderer,
                   _id,
                   "%s: Could not detach thread from JVM", __FUNCTION__);
    }
  }

  WEBRTC_TRACE(kTraceDebug, kTraceVideoRenderer, _id, "%s done", __FUNCTION__);
  return 0;
}

AndroidStream*
AndroidSurfaceViewRenderer::CreateAndroidRenderChannel(
    int32_t streamId,
    int32_t zOrder,
    const float left,
    const float top,
    const float right,
    const float bottom,
    VideoRenderAndroid& renderer) {
  WEBRTC_TRACE(kTraceDebug,
               kTraceVideoRenderer,
               _id,
               "%s: Id %d",
               __FUNCTION__,
               streamId);
  AndroidSurfaceViewChannel* stream =
      new AndroidSurfaceViewChannel(streamId, g_jvm, renderer, _javaRenderObj);
  if(stream && stream->Init(zOrder, left, top, right, bottom) == 0)
    return stream;
  else
    delete stream;
  return NULL;
}

AndroidSurfaceViewChannel::AndroidSurfaceViewChannel(
    uint32_t streamId,
    JavaVM* jvm,
    VideoRenderAndroid& renderer,
    jobject javaRenderObj) :
    _id(streamId),
    _renderCritSect(*CriticalSectionWrapper::CreateCriticalSection()),
    _renderer(renderer),
    _jvm(jvm),
    _javaRenderObj(javaRenderObj),
#ifndef ANDROID_NDK_8_OR_ABOVE
    _javaByteBufferObj(NULL),
    _directBuffer(NULL),
#endif
    _bitmapWidth(0),
    _bitmapHeight(0) {
}

AndroidSurfaceViewChannel::~AndroidSurfaceViewChannel() {
  WEBRTC_TRACE(kTraceInfo,
               kTraceVideoRenderer,
               _id,
               "AndroidSurfaceViewChannel dtor");
  delete &_renderCritSect;
  if(_jvm) {
    // get the JNI env for this thread
    bool isAttached = false;
    JNIEnv* env = NULL;
    if ( _jvm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK) {
      // try to attach the thread and get the env
      // Attach this thread to JVM
      jint res = _jvm->AttachCurrentThread(&env, NULL);

      // Get the JNI env for this thread
      if ((res < 0) || !env) {
        WEBRTC_TRACE(kTraceError,
                     kTraceVideoRenderer,
                     _id,
                     "%s: Could not attach thread to JVM (%d, %p)",
                     __FUNCTION__,
                     res,
                     env);
        env=NULL;
      }
      else {
        isAttached = true;
      }
    }

    env->DeleteGlobalRef(_javaByteBufferObj);
    if (isAttached) {
      if (_jvm->DetachCurrentThread() < 0) {
        WEBRTC_TRACE(kTraceWarning,
                     kTraceVideoRenderer,
                     _id,
                     "%s: Could not detach thread from JVM",
                     __FUNCTION__);
      }
    }
  }
}

int32_t AndroidSurfaceViewChannel::Init(
    int32_t /*zOrder*/,
    const float left,
    const float top,
    const float right,
    const float bottom) {

  WEBRTC_TRACE(kTraceDebug,
               kTraceVideoRenderer,
               _id,
               "%s: AndroidSurfaceViewChannel",
               __FUNCTION__);
  if (!_jvm) {
    WEBRTC_TRACE(kTraceError,
                 kTraceVideoRenderer,
                 _id,
                 "%s: Not a valid Java VM pointer",
                 __FUNCTION__);
    return -1;
  }

  if( (top > 1 || top < 0) ||
      (right > 1 || right < 0) ||
      (bottom > 1 || bottom < 0) ||
      (left > 1 || left < 0)) {
    WEBRTC_TRACE(kTraceError, kTraceVideoRenderer, _id,
                 "%s: Wrong coordinates", __FUNCTION__);
    return -1;
  }

  // get the JNI env for this thread
  bool isAttached = false;
  JNIEnv* env = NULL;
  if (_jvm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK) {
    // try to attach the thread and get the env
    // Attach this thread to JVM
    jint res = _jvm->AttachCurrentThread(&env, NULL);

    // Get the JNI env for this thread
    if ((res < 0) || !env) {
      WEBRTC_TRACE(kTraceError,
                   kTraceVideoRenderer,
                   _id,
                   "%s: Could not attach thread to JVM (%d, %p)",
                   __FUNCTION__,
                   res,
                   env);
      return -1;
    }
    isAttached = true;
  }
    jstring tempName = env->NewStringUTF("com/yuntongxun/ecsdk/core/voip/ViESurfaceRenderer");
    jclass renderSurfaceClass = reinterpret_cast<jclass>(env->CallObjectMethod(VideoRenderAndroid::g_classLoader, VideoRenderAndroid::g_loadClassID, tempName, 1));

  // get the method ID for the CreateIntArray
  _createByteBufferCid =
    env->GetMethodID(renderSurfaceClass,
                       "CreateByteBuffer",
                       "(II)Ljava/nio/ByteBuffer;");
  if (_createByteBufferCid == NULL) {
    WEBRTC_TRACE(kTraceError,
                 kTraceVideoRenderer,
                 _id,
                 "%s: could not get CreateByteBuffer ID",
                 __FUNCTION__);
    return -1; /* exception thrown */
  }

  // get the method ID for the DrawByteBuffer function
    _drawByteBufferCid = env->GetMethodID(renderSurfaceClass,
                                        "DrawByteBuffer",
                                        "()V");
  if (_drawByteBufferCid == NULL) {
    WEBRTC_TRACE(kTraceError,
                 kTraceVideoRenderer,
                 _id,
                 "%s: could not get DrawByteBuffer ID",
                 __FUNCTION__);
    return -1; /* exception thrown */
  }

  // get the method ID for the SetCoordinates function
    _setCoordinatesCid = env->GetMethodID(renderSurfaceClass,
                                        "SetCoordinates",
                                        "(FFFF)V");
  if (_setCoordinatesCid == NULL) {
    WEBRTC_TRACE(kTraceError,
                 kTraceVideoRenderer,
                 _id,
                 "%s: could not get SetCoordinates ID",
                 __FUNCTION__);
    return -1; /* exception thrown */
  }

  env->CallVoidMethod(_javaRenderObj, _setCoordinatesCid,
                      left, top, right, bottom);

  // Detach this thread if it was attached
  if (isAttached) {
    if (_jvm->DetachCurrentThread() < 0) {
      WEBRTC_TRACE(kTraceWarning,
                   kTraceVideoRenderer,
                   _id,
                   "%s: Could not detach thread from JVM",
                   __FUNCTION__);
    }
  }

  WEBRTC_TRACE(kTraceDebug,
               kTraceVideoRenderer,
               _id,
               "%s: AndroidSurfaceViewChannel done",
               __FUNCTION__);
  return 0;
}


int32_t AndroidSurfaceViewChannel::RenderFrame(
    const uint32_t /*streamId*/,
    I420VideoFrame& videoFrame) {
  // WEBRTC_TRACE(kTraceInfo, kTraceVideoRenderer,_id, "%s:" ,__FUNCTION__);
  _renderCritSect.Enter();
  _bufferToRender.SwapFrame(&videoFrame);
  _renderCritSect.Leave();
  _renderer.ReDraw();
  return 0;
}


/*Implements AndroidStream
 * Calls the Java object and render the buffer in _bufferToRender
 */
void AndroidSurfaceViewChannel::DeliverFrame(JNIEnv* jniEnv) {
  _renderCritSect.Enter();

/*    if(_bufferToRender.width() == 0 || _bufferToRender.height() == 0)
    {
            WEBRTC_TRACE(kTraceError, kTraceVideoRenderer, _id,  "%s: no buffer", __FUNCTION__);
        _renderCritSect.Leave();
        return;
    } */

  if (_bitmapWidth != _bufferToRender.width() ||
      _bitmapHeight != _bufferToRender.height()) {
    WEBRTC_TRACE(kTraceInfo, kTraceVideoRenderer, _id, "%s: New render size %d "
                 "%d",__FUNCTION__,
                 _bufferToRender.width(), _bufferToRender.height());
    if (_javaByteBufferObj) {
      jniEnv->DeleteGlobalRef(_javaByteBufferObj);
      _javaByteBufferObj = NULL;
      _directBuffer = NULL;
    }

	if (!_javaByteBufferObj) {
	    jobject javaByteBufferObj =
	        jniEnv->CallObjectMethod(_javaRenderObj, _createByteBufferCid,
	                                 _bufferToRender.width(),
	                                 _bufferToRender.height());
	    _javaByteBufferObj = jniEnv->NewGlobalRef(javaByteBufferObj);
	    if (!_javaByteBufferObj) {
	      WEBRTC_TRACE(kTraceError, kTraceVideoRenderer, _id,  "%s: could not "
	                   "create Java ByteBuffer object reference", __FUNCTION__);
	      _renderCritSect.Leave();
	      return;
	    } else {
	      _directBuffer = static_cast<unsigned char*>
	          (jniEnv->GetDirectBufferAddress(_javaByteBufferObj));
	      _bitmapWidth = _bufferToRender.width();
	      _bitmapHeight = _bufferToRender.height();
	    }
	}
  }

  if(_javaByteBufferObj && _bitmapWidth && _bitmapHeight) {
    const int conversionResult =
        ConvertFromI420(_bufferToRender, kRGB565, 0, _directBuffer);

    if (conversionResult < 0)  {
      WEBRTC_TRACE(kTraceError, kTraceVideoRenderer, _id, "%s: Color conversion"
                   " failed.", __FUNCTION__);
      _renderCritSect.Leave();
      return;
    }
  }
  _renderCritSect.Leave();
  // Draw the Surface
  jniEnv->CallVoidMethod(_javaRenderObj, _drawByteBufferCid);
}

}  // namespace webrtc