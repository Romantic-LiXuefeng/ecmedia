/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

// This sub-API supports the following functionalities:
//  - External encryption and decryption.

#ifndef WEBRTC_VIDEO_ENGINE_INCLUDE_VIE_ENCRYPTION_H_
#define WEBRTC_VIDEO_ENGINE_INCLUDE_VIE_ENCRYPTION_H_

#include "common_types.h"

namespace yuntongxunwebrtc {
class VideoEngine;

class WEBRTC_DLLEXPORT ViEEncryption {
 public:
  // Factory for the ViEEncryption sub‐API and increases an internal reference
  // counter if successful. Returns NULL if the API is not supported or if
  // construction fails.
  static ViEEncryption* GetInterface(VideoEngine* video_engine);

  // Releases the ViEEncryption sub-API and decreases an internal reference
  // counter.
  // Returns the new reference count. This value should be zero
  // for all sub-API:s before the VideoEngine object can be safely deleted.
  virtual int Release() = 0;

  // This function registers a encryption derived instance and enables
  // external encryption for the specified channel.
  virtual int RegisterExternalEncryption(const int video_channel,
                                         Encryption& encryption) = 0;

  // This function deregisters a registered encryption derived instance
  // and disables external encryption.
  virtual int DeregisterExternalEncryption(const int video_channel) = 0;

public:
	virtual int EnableSRTPSend(int channel, ccp_srtp_crypto_suite_t crypt_type, const char* key) = 0;

	virtual int DisableSRTPSend(int channel) = 0;

	virtual int EnableSRTPReceive(int channel, ccp_srtp_crypto_suite_t crypt_type, const char* key) = 0;

	virtual int DisableSRTPReceive(int channel) = 0;

	virtual int CcpSrtpInit(int channel) = 0;
	virtual int CcpSrtpShutdown(int channel) = 0;

 protected:
  ViEEncryption() {}
  virtual ~ViEEncryption() {}
};

}  // namespace yuntongxunwebrtc

#endif  // WEBRTC_VIDEO_ENGINE_INCLUDE_VIE_ENCRYPTION_H_
