/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

// This file contains interfaces used for creating the VideoCaptureModule
// and DeviceInfo.

#ifndef WEBRTC_MODULES_VIDEO_CAPTURE_INCLUDE_VIDEO_CAPTURE_FACTORY_H_
#define WEBRTC_MODULES_VIDEO_CAPTURE_INCLUDE_VIDEO_CAPTURE_FACTORY_H_

#include "video_capture.h"

namespace yuntongxunwebrtc {

class VideoCaptureFactory {
 public:
  // Create a video capture module object
  // id - unique identifier of this video capture module object.
  // deviceUniqueIdUTF8 - name of the device.
  //                      Available names can be found by using GetDeviceName

  static VideoCaptureModule* Create(const int32_t id,
	  const char* deviceUniqueIdUTF8, VideoCaptureCapability *settings=NULL);

  // Create a video capture module object used for external capture.
  // id - unique identifier of this video capture module object
  // externalCapture - [out] interface to call when a new frame is captured.
  static VideoCaptureModule* Create(const int32_t id,
                                    VideoCaptureExternal*& externalCapture);

  static VideoCaptureModule::DeviceInfo* CreateDeviceInfo(
      const int32_t id);

#ifdef WEBRTC_ANDROID
  static WebRtc_Word32 SetAndroidObjects(void* javaVM, void* env, void* javaContext);
#endif

 private:
  ~VideoCaptureFactory();
};

}  // namespace webrtc

#endif  // WEBRTC_MODULES_VIDEO_CAPTURE_INCLUDE_VIDEO_CAPTURE_FACTORY_H_