# Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
#
# Use of this source code is governed by a BSD-style license
# that can be found in the LICENSE file in the root of the source
# tree. An additional intellectual property rights grant can be found
# in the file PATENTS.  All contributing project authors may
# be found in the AUTHORS file in the root of the source tree.

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

include $(LOCAL_PATH)/../../../android-webrtc.mk

LOCAL_ARM_MODE := arm
LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE := libwebrtc_remote_bitrate_estimator
LOCAL_MODULE_TAGS := optional
LOCAL_CPP_EXTENSION := .cc
LOCAL_SRC_FILES := \
    aimd_rate_control.cc \
    inter_arrival.cc \
    mimd_rate_control.cc \
    overuse_detector.cc \
    overuse_estimator.cc \
    rate_statistics.cc \
    remote_bitrate_estimator_abs_send_time.cc \
    remote_bitrate_estimator_single_stream.cc \
    remote_rate_control.cc \
    test/bwe_test_logging.cc
    
# Flags passed to both C and C++ files.
LOCAL_CFLAGS := \
    $(MY_WEBRTC_COMMON_DEFS) 
   #'-DWEBRTC_ANDROID_OPENSLES'

LOCAL_C_INCLUDES := \
		$(LOCAL_PATH)/. \
		$(LOCAL_PATH)/test \
    $(LOCAL_PATH)/../include \
    $(LOCAL_PATH)/../.. \
    $(LOCAL_PATH)/../../interface \
    $(LOCAL_PATH)/../../rtp_rtcp/source \
    $(LOCAL_PATH)/../../rtp_rtcp/include \
    $(LOCAL_PATH)/../../../system_wrappers/interface
    

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libdl \
    libstlport 

ifndef NDK_ROOT
include external/stlport/libstlport.mk
endif
include $(BUILD_STATIC_LIBRARY)
