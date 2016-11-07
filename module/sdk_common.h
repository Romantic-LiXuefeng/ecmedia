#ifndef _SDK_COMMON_H_
#define _SDK_COMMON_H_
#include <time.h>
#ifdef __APPLE__
#include <stdint.h>
#endif

#if defined WEBRTC_ANDROID || defined __APPLE__ 
typedef long long __int64;
#endif

#ifdef WIN32
typedef __int64 __int64_t;
#endif

typedef struct {
	int width;
	int height;
	int maxfps;
} CameraCapability;

typedef struct{
	int index;
	char name[256];
    char id[256];
	int capabilityCount;
	CameraCapability *capability;
}  CameraInfo ;

#define  kTitleLength 32
typedef intptr_t ScreenID;
typedef intptr_t WindowID;
struct WindowShare {
	WindowID id;
	// Title of the window in UTF-8 encoding.
	char title[kTitleLength];
};


typedef struct{
	int index;
	char name[128];  //utf8
    char guid[128];	  //utf8
}  SpeakerInfo ;

typedef struct{
	int index;
	char name[128];   //utf8
	char guid[128];    //utf8
}  MicroPhoneInfo ;

enum {
	ROTATE_AUTO,
	ROTATE_0,
	ROTATE_90,
	ROTATE_180,
	ROTATE_270
};

typedef struct 
{
    unsigned short fractionLost;
    unsigned int cumulativeLost;
    unsigned int extendedMax;
    unsigned int jitterSamples;
    int rttMs;
    unsigned int bytesSent;
    unsigned int packetsSent;
    unsigned int bytesReceived;
    unsigned int packetsReceived;
} MediaStatisticsInfo;

enum ECMediaDesktopShareType
{
    ECMediaShareNone = -1,
    ECMediaShareScreen = 0,
    ECMediaShareWindow = 1
};

enum ECMediaRotateCapturedFrame {
    ECMediaRotateCapturedFrame_0 = 0,
    ECMediaRotateCapturedFrame_90 = 90,
    ECMediaRotateCapturedFrame_180 = 180,
    ECMediaRotateCapturedFrame_270 = 270,
#ifdef __APPLE_CC__
    ECMediaRotateCapturedFrame_auto = 360,
#endif
};

typedef struct{
    long long id;
    // Title of the window in UTF-8 encoding.
    char title[512];
}WindowInfo;

enum
{
    AUDIO_AGC,
    AUDIO_EC,
    AUDIO_NS,
    AUDIO_HC
};

enum NsMode    // type of Noise Suppression
{
    kNsUnchanged = 0,   // previously set mode
    kNsDefault,         // platform default
    kNsConference,      // conferencing default
    kNsLowSuppression,  // lowest suppression
    kNsModerateSuppression,
    kNsHighSuppression,
    kNsVeryHighSuppression,     // highest suppression
};

enum AgcMode                  // type of Automatic Gain Control
{
    kAgcUnchanged = 0,        // previously set mode
    kAgcDefault,              // platform default
    // adaptive mode for use when analog volume control exists (e.g. for
    // PC softphone)
    kAgcAdaptiveAnalog,
    // scaling takes place in the digital domain (e.g. for conference servers
    // and embedded devices)
    kAgcAdaptiveDigital,
    // can be used on embedded devices where the capture signal level
    // is predictable
    kAgcFixedDigital
};

// EC modes
enum EcMode                  // type of Echo Control
{
    kEcUnchanged = 0,          // previously set mode
    kEcDefault,                // platform default
    kEcConference,             // conferencing default (aggressive AEC)
    kEcAec,                    // Acoustic Echo Cancellation
    kEcAecm,                   // AEC mobile
};

//enum  {
//    codec_PCMU = 0,
//    codec_G729,
//    codec_OPUS48,
//    codec_OPUS16,
//    codec_OPUS8,
//    codec_VP8,
//    codec_H264,
//};

typedef enum _CCPClientFirewallPolicy {
    SerphonePolicyNoFirewall = 0,
    SerphonePolicyUseIce
    
} CCPClientFirewallPolicy;

typedef enum {
	account_Status_Online,
	account_Status_Offline,
	account_Status_NotExist,
	account_Status_TimeOut,
	account_Status_None
} Account_Status;

//typedef enum {
//    Video_Conference_status_RequestTimeout = -1,
//    Video_Conference_status_OK = 0,
//    Video_Conference_status_NotExist,
//    Video_Conference_status_UserExclusive,
//    Video_Conference_status_RequestedUserExclusive,
//    Video_Conference_status_RequestedUserNoVideo
//} Video_Conference_status;
//
//typedef enum {
//	Video_Conference_State_Nomal =0,
//	Video_Conference_State_Requesting,
//	Video_Conference_State_RequestFailed,
//	Video_Conference_State_Streaming,
//	Video_Conference_State_Canceling,
//} Video_Conference_State;

//
//typedef struct {
//    char *remoteSip;
//	int local_port;
//    void *video_window;
//    bool is_waiting;
//    time_t request_time;
//    int request_status;
//	int conference_state;
//    int server_port;
//} VideoConferenceDesc;


// Statistics for an RTCP channel
struct _RtcpStatistics{
	_RtcpStatistics()
		: fraction_lost(0),
		cumulative_lost(0),
		extended_max_sequence_number(0),
		jitter(0) {}

	unsigned char fraction_lost;
	unsigned int cumulative_lost;
	unsigned int  extended_max_sequence_number;
	unsigned int  jitter;
};

// Data usage statistics for a (rtp) stream.
struct _StreamDataCounters {
	_StreamDataCounters()
		: first_packet_time_ms(-1),
		bytes(0),
		header_bytes(0),
		padding_bytes(0),
		packets(0),
		retransmitted_bytes(0),
		retransmitted_header_bytes(0),
		retransmitted_padding_bytes(0),
		retransmitted_packets(0),
		fec_packets(0) {}

	void Add(const _StreamDataCounters& other) {
		bytes += other.bytes;
		header_bytes += other.header_bytes;
		padding_bytes += other.padding_bytes;
		packets += other.packets;
		retransmitted_bytes += other.retransmitted_bytes;
		retransmitted_header_bytes += other.retransmitted_header_bytes;
		retransmitted_padding_bytes += other.retransmitted_padding_bytes;
		retransmitted_packets += other.retransmitted_packets;
		fec_packets += other.fec_packets;
		if (other.first_packet_time_ms != -1 &&
			(other.first_packet_time_ms < first_packet_time_ms ||
			first_packet_time_ms == -1)) {
				// Use oldest time.
				first_packet_time_ms = other.first_packet_time_ms;
		}
	}

	__int64_t TimeSinceFirstPacketInMs(__int64_t now_ms) const {
		return (first_packet_time_ms == -1) ? -1 : (now_ms - first_packet_time_ms);
	}

	size_t TotalBytes() const {
		return bytes + header_bytes + padding_bytes;
	}

	size_t RetransmittedBytes() const {
		return retransmitted_bytes + retransmitted_header_bytes +
			retransmitted_padding_bytes;
	}

	size_t MediaPayloadBytes() const {
		return bytes - retransmitted_bytes;
	}

	// TODO(pbos): Rename bytes -> media_bytes.
	__int64_t first_packet_time_ms;  // Time when first packet is sent/received.
	size_t bytes;  // Payload bytes, excluding RTP headers and padding.
	size_t header_bytes;  // Number of bytes used by RTP headers.
	size_t padding_bytes;  // Number of padding bytes.
	unsigned int packets;  // Number of packets.
	size_t retransmitted_bytes;  // Number of retransmitted payload bytes.
	size_t retransmitted_header_bytes;  // Retransmitted bytes used by RTP header.
	size_t retransmitted_padding_bytes;  // Retransmitted padding bytes.
	unsigned int retransmitted_packets;  // Number of retransmitted packets.
	unsigned int fec_packets;  // Number of redundancy packets.
};

struct Stats{
	Stats()
		:encode_frame_rate(0),
		media_bitrate_bps(0),
		suspended(false){}
	int encode_frame_rate; //发送端实际的编码帧率
	int media_bitrate_bps; //发送端实际的发送速率
	bool suspended;       
};

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif
#endif