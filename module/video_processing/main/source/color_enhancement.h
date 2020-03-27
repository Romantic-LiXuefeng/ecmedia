/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

/*
 * color_enhancement.h
 */
#ifndef WEBRTC_MODULES_VIDEO_PROCESSING_COLOR_ENHANCEMENT_H
#define WEBRTC_MODULES_VIDEO_PROCESSING_COLOR_ENHANCEMENT_H

#include "video_processing.h"
#include "typedefs.h"

namespace yuntongxunwebrtc {
namespace VideoProcessing {

int32_t ColorEnhancement(I420VideoFrame* frame);

}  // namespace VideoProcessing
}  // namespace webrtc

#endif // WEBRTC_MODULES_VIDEO_PROCESSING_COLOR_ENHANCEMENT_H