/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
#include "modules/rtp_rtcp/include/rtp_header_parser.h"

#include <string.h>

#include "modules/rtp_rtcp/include/rtp_header_extension_map.h"
#include "modules/rtp_rtcp/source/rtp_utility.h"
#include "rtc_base/critical_section.h"
#include "rtc_base/thread_annotations.h"
#include "logging/rtc_event_log/rtc_event_log.h"

namespace webrtc {

class RtpHeaderParserImpl : public RtpHeaderParser {
 public:
  RtpHeaderParserImpl();
  ~RtpHeaderParserImpl() override = default;

 bool Parse(const uint8_t* packet,
              size_t length,
              RTPHeader* header) const override;

  bool RegisterRtpHeaderExtension(RTPExtensionType type, uint8_t id) override;
  bool RegisterRtpHeaderExtension(RtpExtension extension) override;

  bool DeregisterRtpHeaderExtension(RTPExtensionType type) override;
  bool DeregisterRtpHeaderExtension(RtpExtension extension) override;

   //ytx_begin by wx ���������ص�����
   int setECMediaCSRCsCallback(ECMedia_CSRCsCallback* cb) override;

 private:
   void GetCSRCsLists(RTPHeader* header) const; 
   //ytx_end
 private:
  rtc::CriticalSection critical_section_;
  RtpHeaderExtensionMap rtp_header_extension_map_
      RTC_GUARDED_BY(critical_section_);
  //ytx_begin added by wx.
  ECMedia_CSRCsCallback* _csrcsCallback;  
  mutable int64_t base_time;
  //ytx_end
};

RtpHeaderParser* RtpHeaderParser::Create() {
  return new RtpHeaderParserImpl;
}
//ytx_begin by wx
RtpHeaderParserImpl::RtpHeaderParserImpl():_csrcsCallback(nullptr),base_time(0){
}
//ytx_end

bool RtpHeaderParser::IsRtcp(const uint8_t* packet, size_t length) {
  RtpUtility::RtpHeaderParser rtp_parser(packet, length);
  return rtp_parser.RTCP();
}

absl::optional<uint32_t> RtpHeaderParser::GetSsrc(const uint8_t* packet,
                                                  size_t length) {
  RtpUtility::RtpHeaderParser rtp_parser(packet, length);
  RTPHeader header;
  if (rtp_parser.Parse(&header, nullptr)) {
    return header.ssrc;
  }
  return absl::nullopt;
}
//ytx_wx begin...
void RtpHeaderParserImpl::GetCSRCsLists(RTPHeader* header) const {
  bool should_send = false;
  {
    int64_t current_time = Clock::GetRealTimeClock()->TimeInMilliseconds();
    should_send = (current_time - base_time) >= 1000;
    if (should_send) {
      base_time = Clock::GetRealTimeClock()->TimeInMilliseconds();
    }
  }
  if (_csrcsCallback && should_send) {
    _csrcsCallback(header->arrOfCSRCs, header->numCSRCs);
  }
}
// ytx_wx end...
bool RtpHeaderParserImpl::Parse(const uint8_t* packet,
                                size_t length,
                                RTPHeader* header) const{
  RtpUtility::RtpHeaderParser rtp_parser(packet, length);
  *header = RTPHeader();

  RtpHeaderExtensionMap map;
  {
    rtc::CritScope cs(&critical_section_);
    map = rtp_header_extension_map_;
  }

  const bool valid_rtpheader = rtp_parser.Parse(header, &map);
  if (!valid_rtpheader) {
    return false;
  }
  GetCSRCsLists(header);  //callback conference csrc array when csrc
                          // array changed, added by wx 
 
  return true;
}
bool RtpHeaderParserImpl::RegisterRtpHeaderExtension(RtpExtension extension) {
  rtc::CritScope cs(&critical_section_);
  return rtp_header_extension_map_.RegisterByUri(extension.id, extension.uri);
}

bool RtpHeaderParserImpl::RegisterRtpHeaderExtension(RTPExtensionType type,
                                                     uint8_t id) {
  rtc::CritScope cs(&critical_section_);
  return rtp_header_extension_map_.RegisterByType(id, type);
}

bool RtpHeaderParserImpl::DeregisterRtpHeaderExtension(RtpExtension extension) {
  rtc::CritScope cs(&critical_section_);
  return rtp_header_extension_map_.Deregister(
      rtp_header_extension_map_.GetType(extension.id));
}

bool RtpHeaderParserImpl::DeregisterRtpHeaderExtension(RTPExtensionType type) {
  rtc::CritScope cs(&critical_section_);
  return rtp_header_extension_map_.Deregister(type) == 0;
}
//ytx_begin by wx
int RtpHeaderParserImpl::setECMediaCSRCsCallback(ECMedia_CSRCsCallback* cb) {
  if (cb == nullptr) {
    RTC_LOG(LS_ERROR) << "setECMediaCSRCsCallback is null.";
    return -1;
  }

  if (_csrcsCallback == cb) {
    RTC_LOG(LS_WARNING)<< "setECMediaCSRCsCallback already have been set.";
    return 0;
  }

  _csrcsCallback =cb;
  return 0;
}
//ytx_end
}  // namespace webrtc
