/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

// Unit tests for ComfortNoise class.

#include "comfort_noise.h"

#include "testing/gtest/include/gtest/gtest.h"
#include "mock_decoder_database.h"
#include "sync_buffer.h"

namespace cloopenwebrtc {

TEST(ComfortNoise, CreateAndDestroy) {
  int fs = 8000;
  MockDecoderDatabase db;
  SyncBuffer sync_buffer(1, 1000);
  ComfortNoise cn(fs, &db, &sync_buffer);
  EXPECT_CALL(db, Die());  // Called when |db| goes out of scope.
}

// TODO(hlundin): Write more tests.

}  // namespace cloopenwebrtc
