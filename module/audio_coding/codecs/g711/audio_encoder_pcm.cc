/*
 *  Copyright (c) 2014 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "audio_encoder_pcm.h"

#include <limits>

#include "g711_interface.h"

namespace cloopenwebrtc {

namespace {
int16_t NumSamplesPerFrame(int num_channels,
                           int frame_size_ms,
                           int sample_rate_hz) {
  int samples_per_frame = num_channels * frame_size_ms * sample_rate_hz / 1000;
  CHECK_LE(samples_per_frame, std::numeric_limits<int16_t>::max())
      << "Frame size too large.";
  return static_cast<int16_t>(samples_per_frame);
}
}  // namespace

AudioEncoderPcm::AudioEncoderPcm(const Config& config, int sample_rate_hz)
    : sample_rate_hz_(sample_rate_hz),
      num_channels_(config.num_channels),
      payload_type_(config.payload_type),
      num_10ms_frames_per_packet_(config.frame_size_ms / 10),
      full_frame_samples_(NumSamplesPerFrame(config.num_channels,
                                             config.frame_size_ms,
                                             sample_rate_hz_)),
      first_timestamp_in_buffer_(0) {
  CHECK_GT(sample_rate_hz, 0) << "Sample rate must be larger than 0 Hz";
  CHECK_EQ(config.frame_size_ms % 10, 0)
      << "Frame size must be an integer multiple of 10 ms.";
  speech_buffer_.reserve(full_frame_samples_);
}

AudioEncoderPcm::~AudioEncoderPcm() {
}

int AudioEncoderPcm::sample_rate_hz() const {
  return sample_rate_hz_;
}
int AudioEncoderPcm::num_channels() const {
  return num_channels_;
}
int AudioEncoderPcm::Num10MsFramesInNextPacket() const {
  return num_10ms_frames_per_packet_;
}

int AudioEncoderPcm::Max10MsFramesInAPacket() const {
  return num_10ms_frames_per_packet_;
}

bool AudioEncoderPcm::EncodeInternal(uint32_t timestamp,
                                     const int16_t* audio,
                                     size_t max_encoded_bytes,
                                     uint8_t* encoded,
                                     EncodedInfo* info) {
  const int num_samples = sample_rate_hz() / 100 * num_channels();
  if (speech_buffer_.empty()) {
    first_timestamp_in_buffer_ = timestamp;
  }
  for (int i = 0; i < num_samples; ++i) {
    speech_buffer_.push_back(audio[i]);
  }
  if (speech_buffer_.size() < static_cast<size_t>(full_frame_samples_)) {
    info->encoded_bytes = 0;
    return true;
  }
  CHECK_EQ(speech_buffer_.size(), static_cast<size_t>(full_frame_samples_));
  int16_t ret = EncodeCall(&speech_buffer_[0], full_frame_samples_, encoded);
  speech_buffer_.clear();
  info->encoded_timestamp = first_timestamp_in_buffer_;
  info->payload_type = payload_type_;
  if (ret < 0)
    return false;
  info->encoded_bytes = static_cast<size_t>(ret);
  return true;
}

int16_t AudioEncoderPcmA::EncodeCall(const int16_t* audio,
                                     size_t input_len,
                                     uint8_t* encoded) {
  return WebRtcG711_EncodeA(const_cast<int16_t*>(audio),
                            static_cast<int16_t>(input_len),
                            reinterpret_cast<int16_t*>(encoded));
}

int16_t AudioEncoderPcmU::EncodeCall(const int16_t* audio,
                                     size_t input_len,
                                     uint8_t* encoded) {
  return WebRtcG711_EncodeU(const_cast<int16_t*>(audio),
                            static_cast<int16_t>(input_len),
                            reinterpret_cast<int16_t*>(encoded));
}

}  // namespace cloopenwebrtc
