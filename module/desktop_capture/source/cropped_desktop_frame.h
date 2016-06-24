/*
 *  Copyright (c) 2014 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_MODULES_DESKTOP_CAPTURE_CROPPED_DESKTOP_FRAME_H_
#define WEBRTC_MODULES_DESKTOP_CAPTURE_CROPPED_DESKTOP_FRAME_H_

#include "desktop_frame.h"

namespace cloopenwebrtc {

// Always takes ownership of |frame|. Returns NULL if |rect| is not contained
// by the bounds of |frame|.
DesktopFrame* CreateCroppedDesktopFrame(DesktopFrame* frame,
                                        const DesktopRect& rect);
}  // namespace cloopenwebrtc

#endif  // WEBRTC_MODULES_DESKTOP_CAPTURE_CROPPED_DESKTOP_FRAME_H_

