/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_MODULES_RTP_RTCP_SOURCE_RTP_SENDER_AUDIO_H_
#define WEBRTC_MODULES_RTP_RTCP_SOURCE_RTP_SENDER_AUDIO_H_

#include "common_types.h"
#include "dtmf_queue.h"
#include "rtp_rtcp_config.h"
#include "rtp_sender.h"
#include "rtp_utility.h"
#include "typedefs.h"
#include "forward_error_correction.h"
#include "producer_fec.h"

namespace cloopenwebrtc {
class RTPSenderAudio: public DTMFqueue
{
public:
    RTPSenderAudio(const int32_t id, Clock* clock,
                   RTPSender* rtpSender);
    virtual ~RTPSenderAudio();

    int32_t RegisterAudioPayload(const char payloadName[RTP_PAYLOAD_NAME_SIZE],
                                 const int8_t payloadType,
                                 const uint32_t frequency,
                                 const uint8_t channels,
                                 const uint32_t rate,
                                 RtpUtility::Payload*& payload);

    int32_t SendAudio(const FrameType frameType,
                      const int8_t payloadType,
                      const uint32_t captureTimeStamp,
                      const uint8_t* payloadData,
                      const size_t payloadSize,
                      const RTPFragmentationHeader* fragmentation);

    // set audio packet size, used to determine when it's time to send a DTMF packet in silence (CNG)
    int32_t SetAudioPacketSize(const uint16_t packetSizeSamples);

    // Store the audio level in dBov for header-extension-for-audio-level-indication.
    // Valid range is [0,100]. Actual value is negative.
    int32_t SetAudioLevel(const uint8_t level_dBov);

    // Send a DTMF tone using RFC 2833 (4733)
      int32_t SendTelephoneEvent(const uint8_t key,
                                 const uint16_t time_ms,
                                 const uint8_t level);

    bool SendTelephoneEventActive(int8_t& telephoneEvent) const;

    void SetAudioFrequency(const uint32_t f);

    int AudioFrequency() const;

    // Set payload type for Redundant Audio Data RFC 2198
    int32_t SetRED(const int8_t payloadType);

    // Get payload type for Redundant Audio Data RFC 2198
    int32_t RED(int8_t& payloadType) const;

    int32_t RegisterAudioCallback(RtpAudioFeedback* messagesCallback);

	int SelectiveRetransmissions() const;
	int SetSelectiveRetransmissions(uint8_t settings);

	// FEC
	size_t FECPacketOverhead() const;

	int32_t SetGenericFECStatus(const bool enable,
		const uint8_t payloadTypeRED,
		const uint8_t payloadTypeFEC);

	int32_t GenericFECStatus(bool& enable,
		uint8_t& payloadTypeRED,
		uint8_t& payloadTypeFEC) const;

	//int32_t SetFecParameters(const FecProtectionParams* delta_params,
	//	const FecProtectionParams* key_params);

protected:
    int32_t SendTelephoneEventPacket(const bool ended,
                                     const uint32_t dtmfTimeStamp,
                                     const uint16_t duration,
                                     const bool markerBit); // set on first packet in talk burst

    bool MarkerBit(const FrameType frameType,
                   const int8_t payloadType);

private:
    int32_t             _id;
    Clock*                    _clock;
    RTPSender*       _rtpSender;
    CriticalSectionWrapper*   _audioFeedbackCritsect;
    RtpAudioFeedback*         _audioFeedback;

    CriticalSectionWrapper*   _sendAudioCritsect;

    uint32_t            _frequency;
    uint16_t            _packetSizeSamples;

    // DTMF
    bool              _dtmfEventIsOn;
    bool              _dtmfEventFirstPacketSent;
    int8_t      _dtmfPayloadType;
    uint32_t    _dtmfTimestamp;
    uint8_t     _dtmfKey;
    uint32_t    _dtmfLengthSamples;
    uint8_t     _dtmfLevel;
    int64_t     _dtmfTimeLastSent;
    uint32_t    _dtmfTimestampLastSent;

    int8_t      _REDPayloadType;

	int32_t _retransmissionSettings;

	// FEC
	ForwardErrorCorrection _fec;
	bool _fecEnabled;
	int8_t _payloadTypeRED;
	int8_t _payloadTypeFEC;
	unsigned int _numberFirstPartition;
	FecProtectionParams fec_params_;
	ProducerFec producer_fec_;


    // VAD detection, used for markerbit
    bool              _inbandVADactive;
    int8_t      _cngNBPayloadType;
    int8_t      _cngWBPayloadType;
    int8_t      _cngSWBPayloadType;
    int8_t      _cngFBPayloadType;
    int8_t      _lastPayloadType;

    // Audio level indication (https://datatracker.ietf.org/doc/draft-lennox-avt-rtp-audio-level-exthdr/)
    uint8_t     _audioLevel_dBov;
};
}  // namespace webrtc

#endif // WEBRTC_MODULES_RTP_RTCP_SOURCE_RTP_SENDER_AUDIO_H_
