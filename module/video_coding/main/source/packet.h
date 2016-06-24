/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_MODULES_VIDEO_CODING_PACKET_H_
#define WEBRTC_MODULES_VIDEO_CODING_PACKET_H_

#include "module_common_types.h"
#include "jitter_buffer_common.h"
#include "typedefs.h"

namespace cloopenwebrtc {

class VCMPacket {
public:
    VCMPacket();
    VCMPacket(const uint8_t* ptr,
              const size_t size,
              const WebRtcRTPHeader& rtpHeader);
    VCMPacket(const uint8_t* ptr,
              size_t size,
              uint16_t seqNum,
              uint32_t timestamp,
              bool markerBit);

    void Reset();

    uint8_t           payloadType;
    uint32_t          timestamp;
    // NTP time of the capture time in local timebase in milliseconds.
    int64_t ntp_time_ms_;
    uint16_t          seqNum;
    const uint8_t*    dataPtr;
    size_t          sizeBytes;
    bool                    markerBit;

    FrameType               frameType;
    cloopenwebrtc::VideoCodecType  codec;

    bool isFirstPacket;                 // Is this first packet in a frame.
    VCMNaluCompleteness completeNALU;   // Default is kNaluIncomplete.
    bool insertStartCode;               // True if a start code should be inserted before this
                                        // packet.
    int width;
    int height;
    RTPVideoHeader codecSpecificHeader;

protected:
    void CopyCodecSpecifics(const RTPVideoHeader& videoHeader);
};

}  // namespace webrtc
#endif // WEBRTC_MODULES_VIDEO_CODING_PACKET_H_
