/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
#include "rtp_header_parser.h"

#include "rtp_header_extension.h"
#include "rtp_utility.h"
#include "critical_section_wrapper.h"
#include "scoped_ptr.h"

namespace cloopenwebrtc {

class RtpHeaderParserImpl : public RtpHeaderParser {
 public:
  RtpHeaderParserImpl();
  virtual ~RtpHeaderParserImpl() {}

  virtual bool Parse(const uint8_t* packet,
                     size_t length,
                     RTPHeader* header) const OVERRIDE;

  virtual bool RegisterRtpHeaderExtension(RTPExtensionType type,
                                          uint8_t id) OVERRIDE;

  virtual bool DeregisterRtpHeaderExtension(RTPExtensionType type) OVERRIDE;
  virtual int setECMediaConferenceParticipantCallback(ECMedia_ConferenceParticipantCallback* cb);
 private:
  scoped_ptr<CriticalSectionWrapper> critical_section_;
  RtpHeaderExtensionMap rtp_header_extension_map_ GUARDED_BY(critical_section_);
  ECMedia_ConferenceParticipantCallback *_participantCallback;
};

RtpHeaderParser* RtpHeaderParser::Create() {
  return new RtpHeaderParserImpl;
}

RtpHeaderParserImpl::RtpHeaderParserImpl()
    : critical_section_(CriticalSectionWrapper::CreateCriticalSection()) {}

bool RtpHeaderParser::IsRtcp(const uint8_t* packet, size_t length) {
  RtpUtility::RtpHeaderParser rtp_parser(packet, length);
  return rtp_parser.RTCP();
}

bool RtpHeaderParserImpl::Parse(const uint8_t* packet,
                                size_t length,
                                RTPHeader* header) const {
  RtpUtility::RtpHeaderParser rtp_parser(packet, length);
  memset(header, 0, sizeof(*header));

  RtpHeaderExtensionMap map;
  {
    CriticalSectionScoped cs(critical_section_.get());
    rtp_header_extension_map_.GetCopy(&map);
  }

  const bool valid_rtpheader = rtp_parser.Parse(*header, &map);
  if (!valid_rtpheader) {
    return false;
  }
    // ECMedia_ConferenceParticipantCallback
  _participantCallback(header->arrOfCSRCs, header->numCSRCs);
  return true;
}

bool RtpHeaderParserImpl::RegisterRtpHeaderExtension(RTPExtensionType type,
                                                     uint8_t id) {
  CriticalSectionScoped cs(critical_section_.get());
  return rtp_header_extension_map_.Register(type, id) == 0;
}

bool RtpHeaderParserImpl::DeregisterRtpHeaderExtension(RTPExtensionType type) {
  CriticalSectionScoped cs(critical_section_.get());
  return rtp_header_extension_map_.Deregister(type) == 0;
}
    
int RtpHeaderParserImpl::setECMediaConferenceParticipantCallback(ECMedia_ConferenceParticipantCallback* cb) {
    if(cb == nullptr) {
        // LOG(LS_ERROR) << "ECMedia_ConferenceParticipantCallback is null.";
        return -1;
    }
    
    if(_participantCallback == cb) {
        // LOG(LS_WARNING) << "ECMedia_ConferenceParticipantCallback already have been set.";
        return 0;
    }
    
    _participantCallback = cb;
    return 0;
}
}  // namespace webrtc
