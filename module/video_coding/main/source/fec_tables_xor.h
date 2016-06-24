/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_MODULES_VIDEO_CODING_SOURCE_FEC_TABLES_XOR_H_
#define WEBRTC_MODULES_VIDEO_CODING_SOURCE_FEC_TABLES_XOR_H_

// This is a private header for media_opt_util.cc.
// It should not be included by other files.

namespace cloopenwebrtc {

// Table for Protection factor (code rate) of delta frames, for the XOR FEC.
// Input is the packet loss and an effective rate (bits/frame).
// Output is array kCodeRateXORTable[k], where k = rate_i*129 + loss_j;
// loss_j = 0,1,..128, and rate_i varies over some range.
static const int kSizeCodeRateXORTable = 6450;
static const unsigned char kCodeRateXORTable[kSizeCodeRateXORTable] = {
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
11,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
39,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
51,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
8,
8,
8,
8,
8,
8,
8,
8,
8,
8,
8,
8,
8,
8,
8,
30,
30,
30,
30,
30,
30,
30,
30,
30,
30,
30,
30,
30,
30,
30,
56,
56,
56,
56,
56,
56,
56,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
65,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
87,
78,
78,
78,
78,
78,
78,
78,
78,
78,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
6,
6,
6,
23,
23,
23,
23,
23,
23,
23,
23,
23,
23,
23,
23,
23,
23,
23,
44,
44,
44,
44,
44,
44,
50,
50,
50,
50,
50,
50,
50,
50,
50,
68,
68,
68,
68,
68,
68,
68,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
85,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
105,
88,
88,
88,
88,
88,
88,
88,
88,
88,
0,
0,
0,
0,
0,
0,
0,
0,
0,
5,
5,
5,
5,
5,
5,
19,
19,
19,
36,
41,
41,
41,
41,
41,
41,
41,
41,
41,
41,
41,
41,
41,
41,
55,
55,
55,
55,
55,
55,
69,
69,
69,
69,
69,
69,
69,
69,
69,
75,
75,
80,
80,
80,
80,
80,
97,
97,
97,
97,
97,
97,
97,
97,
97,
97,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
102,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
116,
100,
100,
100,
100,
100,
100,
100,
100,
100,
0,
0,
0,
0,
0,
0,
0,
0,
4,
16,
16,
16,
16,
16,
16,
30,
35,
35,
47,
58,
58,
58,
58,
58,
58,
58,
58,
58,
58,
58,
58,
58,
58,
63,
63,
63,
63,
63,
63,
77,
77,
77,
77,
77,
77,
77,
82,
82,
82,
82,
94,
94,
94,
94,
94,
105,
105,
105,
105,
110,
110,
110,
110,
110,
110,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
115,
115,
115,
115,
115,
115,
115,
115,
115,
0,
0,
0,
0,
0,
0,
0,
4,
14,
27,
27,
27,
27,
27,
31,
41,
52,
52,
56,
69,
69,
69,
69,
69,
69,
69,
69,
69,
69,
69,
69,
69,
69,
69,
69,
69,
69,
69,
69,
79,
79,
79,
79,
83,
83,
83,
94,
94,
94,
94,
106,
106,
106,
106,
106,
115,
115,
115,
115,
125,
125,
125,
125,
125,
125,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
0,
0,
0,
3,
3,
3,
17,
28,
38,
38,
38,
38,
38,
47,
51,
63,
63,
63,
72,
72,
72,
72,
72,
72,
72,
76,
76,
76,
76,
80,
80,
80,
80,
80,
80,
80,
80,
80,
84,
84,
84,
84,
93,
93,
93,
105,
105,
105,
105,
114,
114,
114,
114,
114,
124,
124,
124,
124,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
0,
0,
0,
12,
12,
12,
35,
43,
47,
47,
47,
47,
47,
58,
58,
66,
66,
66,
70,
70,
70,
70,
70,
73,
73,
82,
82,
82,
86,
94,
94,
94,
94,
94,
94,
94,
94,
94,
94,
94,
94,
94,
105,
105,
105,
114,
114,
114,
114,
117,
117,
117,
117,
117,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
0,
0,
0,
24,
24,
24,
49,
53,
53,
53,
53,
53,
53,
61,
61,
64,
64,
64,
64,
70,
70,
70,
70,
78,
78,
88,
88,
88,
96,
106,
106,
106,
106,
106,
106,
106,
106,
106,
106,
112,
112,
112,
120,
120,
120,
124,
124,
124,
124,
124,
124,
124,
124,
124,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
0,
0,
5,
36,
36,
36,
55,
55,
55,
55,
55,
55,
55,
58,
58,
58,
58,
58,
64,
78,
78,
78,
78,
87,
87,
94,
94,
94,
103,
110,
110,
110,
110,
110,
110,
110,
110,
116,
116,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
0,
0,
18,
43,
43,
43,
53,
53,
53,
53,
53,
53,
53,
53,
58,
58,
58,
58,
71,
87,
87,
87,
87,
94,
94,
97,
97,
97,
109,
111,
111,
111,
111,
111,
111,
111,
111,
125,
125,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
0,
0,
31,
46,
46,
46,
48,
48,
48,
48,
48,
48,
48,
48,
66,
66,
66,
66,
80,
93,
93,
93,
93,
95,
95,
95,
95,
100,
115,
115,
115,
115,
115,
115,
115,
115,
115,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
0,
4,
40,
45,
45,
45,
45,
45,
45,
45,
45,
49,
49,
49,
74,
74,
74,
74,
86,
90,
90,
90,
90,
95,
95,
95,
95,
106,
120,
120,
120,
120,
120,
120,
120,
120,
120,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
0,
14,
42,
42,
42,
42,
42,
42,
42,
42,
46,
56,
56,
56,
80,
80,
80,
80,
84,
84,
84,
84,
88,
99,
99,
99,
99,
111,
122,
122,
122,
122,
122,
122,
122,
122,
122,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
0,
26,
40,
40,
40,
40,
40,
40,
40,
40,
54,
66,
66,
66,
80,
80,
80,
80,
80,
80,
80,
84,
94,
106,
106,
106,
106,
116,
120,
120,
120,
120,
120,
120,
120,
120,
124,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
3,
34,
38,
38,
38,
38,
38,
42,
42,
42,
63,
72,
72,
76,
80,
80,
80,
80,
80,
80,
80,
89,
101,
114,
114,
114,
114,
118,
118,
118,
118,
118,
118,
118,
118,
118,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
12,
36,
36,
36,
36,
36,
36,
49,
49,
49,
69,
73,
76,
86,
86,
86,
86,
86,
86,
86,
86,
97,
109,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
122,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
22,
34,
34,
34,
34,
38,
38,
57,
57,
57,
69,
73,
82,
92,
92,
92,
92,
92,
92,
96,
96,
104,
117,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
29,
33,
33,
33,
33,
44,
44,
62,
62,
62,
69,
77,
87,
95,
95,
95,
95,
95,
95,
107,
107,
110,
120,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
31,
31,
31,
31,
31,
51,
51,
62,
65,
65,
73,
83,
91,
94,
94,
94,
94,
97,
97,
114,
114,
114,
122,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
29,
29,
29,
29,
29,
56,
56,
59,
70,
70,
79,
86,
89,
89,
89,
89,
89,
100,
100,
116,
116,
116,
122,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
28,
28,
28,
28,
28,
57,
57,
57,
76,
76,
83,
86,
86,
86,
86,
86,
89,
104,
104,
114,
114,
114,
124,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
27,
27,
27,
27,
30,
55,
55,
55,
80,
80,
83,
86,
86,
86,
86,
86,
93,
108,
108,
111,
111,
111,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
26,
26,
26,
26,
36,
53,
53,
53,
80,
80,
80,
90,
90,
90,
90,
90,
98,
107,
107,
107,
107,
107,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
26,
26,
26,
28,
42,
52,
54,
54,
78,
78,
78,
95,
95,
95,
97,
97,
104,
106,
106,
106,
106,
106,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
24,
24,
24,
33,
47,
49,
58,
58,
74,
74,
74,
97,
97,
97,
106,
106,
108,
108,
108,
108,
108,
108,
124,
124,
124,
124,
124,
124,
124,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
24,
24,
24,
39,
48,
50,
63,
63,
72,
74,
74,
96,
96,
96,
109,
111,
111,
111,
111,
111,
111,
111,
119,
119,
122,
122,
122,
122,
122,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
23,
23,
23,
43,
46,
54,
66,
66,
69,
77,
77,
92,
92,
92,
105,
113,
113,
113,
113,
113,
113,
113,
115,
117,
123,
123,
123,
123,
123,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
22,
22,
22,
44,
44,
59,
67,
67,
67,
81,
81,
89,
89,
89,
97,
112,
112,
112,
112,
112,
112,
112,
112,
119,
126,
126,
126,
126,
126,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
21,
21,
24,
43,
45,
63,
65,
65,
67,
85,
85,
87,
87,
87,
91,
109,
109,
109,
111,
111,
111,
111,
111,
123,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
21,
21,
28,
42,
50,
63,
63,
66,
71,
85,
85,
85,
85,
87,
92,
106,
106,
108,
114,
114,
114,
114,
114,
125,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
20,
20,
34,
41,
54,
62,
62,
69,
75,
82,
82,
82,
82,
92,
98,
105,
105,
110,
117,
117,
117,
117,
117,
124,
124,
126,
126,
126,
126,
126,
126,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
20,
20,
38,
40,
58,
60,
60,
73,
78,
80,
80,
80,
80,
100,
105,
107,
107,
113,
118,
118,
118,
118,
118,
120,
120,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
19,
21,
38,
40,
58,
58,
60,
75,
77,
77,
77,
81,
81,
107,
109,
109,
109,
114,
116,
116,
116,
116,
116,
116,
116,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
18,
25,
37,
44,
56,
56,
63,
75,
75,
75,
75,
88,
88,
111,
111,
111,
111,
112,
112,
112,
112,
112,
112,
112,
114,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
18,
30,
36,
48,
55,
55,
67,
73,
73,
73,
73,
97,
97,
110,
110,
110,
110,
110,
110,
110,
110,
110,
110,
110,
116,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
18,
34,
36,
52,
55,
55,
70,
72,
73,
73,
73,
102,
104,
108,
108,
108,
108,
109,
109,
109,
109,
109,
109,
109,
119,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
17,
35,
35,
52,
59,
59,
70,
70,
76,
76,
76,
99,
105,
105,
105,
105,
105,
111,
111,
111,
111,
111,
111,
111,
121,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
17,
34,
36,
51,
61,
62,
70,
70,
80,
80,
80,
93,
103,
103,
103,
103,
103,
112,
112,
112,
112,
112,
116,
118,
124,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
16,
33,
39,
50,
59,
65,
72,
72,
82,
82,
82,
91,
100,
100,
100,
100,
100,
109,
109,
109,
109,
109,
121,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
16,
32,
43,
48,
54,
66,
75,
75,
81,
83,
83,
92,
97,
97,
97,
99,
99,
105,
105,
105,
105,
105,
123,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
15,
31,
46,
47,
49,
69,
77,
77,
81,
85,
85,
93,
95,
95,
95,
100,
100,
102,
102,
102,
102,
102,
120,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
15,
30,
46,
48,
48,
70,
75,
79,
82,
87,
87,
92,
94,
94,
94,
103,
103,
103,
103,
103,
104,
104,
115,
120,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
15,
30,
45,
50,
50,
68,
70,
80,
85,
89,
89,
90,
95,
95,
95,
104,
104,
104,
104,
104,
109,
109,
112,
114,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
14,
29,
44,
54,
54,
64,
64,
83,
87,
88,
88,
88,
98,
98,
98,
103,
103,
103,
103,
103,
113,
113,
113,
113,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
14,
29,
43,
56,
56,
61,
61,
84,
85,
88,
88,
88,
100,
100,
100,
102,
102,
102,
102,
102,
113,
116,
116,
116,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
14,
28,
42,
57,
57,
62,
62,
80,
80,
91,
91,
91,
100,
100,
100,
100,
100,
100,
100,
100,
109,
119,
119,
119,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
14,
28,
42,
56,
56,
65,
66,
76,
76,
92,
92,
92,
97,
97,
97,
101,
101,
101,
101,
101,
106,
121,
121,
121,
126,
126,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
13,
27,
41,
55,
55,
67,
72,
74,
74,
90,
90,
90,
91,
91,
91,
105,
105,
105,
105,
105,
107,
122,
122,
122,
123,
123,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
0,
13,
27,
40,
54,
54,
67,
76,
76,
76,
85,
85,
85,
85,
85,
85,
112,
112,
112,
112,
112,
112,
121,
121,
121,
121,
121,
126,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,
127,


};

}  // namespace webrtc

#endif // WEBRTC_MODULES_VIDEO_CODING_SOURCE_FEC_TABLES_XOR_H_
