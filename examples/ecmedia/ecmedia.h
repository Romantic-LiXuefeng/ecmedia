#ifndef ECMEDIA_H
#define ECMEDIA_H

#ifdef WEBRTC_ANDROID
#include "jni.h"
#define ECMEDIA_API JNIEXPORT
#elif defined(WIN32)
#define ECMEDIA_API _declspec(dllexport)
#else
#define ECMEDIA_API
#endif

#include "ec_common_types.h"
#include "sdk_common.h"

// TODO�� for test, remove later
#include <windows.h>
#include <wingdi.h>
#include <sstream>
#include <string>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************/
/*** ������: ��ʼ��                                                      ***/
/*** ����:   ��ȡý���ʵ��                                              ***/
/*** ����ֵ: ����  int                                                   ***/
/*** ��������: ��                                                        ***/
/***************************************************************************/
ECMEDIA_API int ECMedia_init();

/****************************************************************************/
/*** ������: ����ʼ��                                                     ***/
/*** ����:   �ͷ�ý���ʵ��                                               ***/
/*** ����ֵ: ����  int                                                   ***/
/*** ��������: ��                                                         ***/
/****************************************************************************/
ECMEDIA_API int ECMedia_uninit();

/****************************************************************************/
/*** ������: ����ý��ͨ��id                                               ***/
/*** ����:   ý����ʼ��������ͨ��ID                                     ***/
/*** ����ֵ: ����    bool   true  �ɹ�      false  ʧ��                   ***/
/*** ��������: ����  channel_id    ����   int                             ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_generate_channel_id(int& channel_id);

/****************************************************************************/
/*** ������: �ͷ�ý��ͨ��id                                               ***/
/*** ����:   �ͷ�ͨ��ID                                     ***/
/*** ����ֵ: ����    bool   true  �ɹ�      false  ʧ��                   ***/
/*** ��������: ����  channel_id    ����   int                             ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_release_channel_id(int channel_id);

/****************************************************************************/
/*** ������: ��������                                                     ***/
/*** ����:   ����ý��������                                               ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����    l_addr���ص�ַ       ����   const char*           ***/
/*** ��������2: ����    l_port���ض˿�       ����   int                   ***/
/*** ��������3: ����    r_addrԶ�˵�ַ       ����   const char*           ***/
/*** ��������4: ����    r_portԶ�˶˿�       ����   int                   ***/
/*** ��������5: ����    id ����ID            ����   const char*           ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_create_transport(const char* l_addr,
                                          int l_port,
                                          const char* r_addr,
                                          int r_port,
                                          const char* id);

/****************************************************************************/
/*** ������: ����ͨ��                                                     ***/
/*** ����:   ý��ⴴ���߼�ͨ��                                           ***/
/*** ����ֵ: ����  bool   true  �ɹ�      false  ʧ��                     ***/
/*** ��������1: ����    tid                  ����   int                   ***/
/*** ��������2: ����    channel_id           ����   int                   ***/
/*** ��������3: ����    is_video             ����   bool                  ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_create_channel(const char* tid, int& channel_id, bool is_video= true);

/****************************************************************************/
/*** ������: �ͷ�ͨ��                                                     ***/
/*** ����:   ý����ͷ��߼�ͨ��                                           ***/
/*** ����ֵ: ����  void                                                   ***/
/*** ��������1: ����    channel_id           ����   int                   ***/
/*** ��������2: ����    is_video             ����   bool                  ***/
/****************************************************************************/
ECMEDIA_API void ECMedia_destroy_channel( int& channel_id,bool is_video = true);

/****************************************************************************/
/*** ������: ��ʼͨ��                                                     ***/
/*** ����:   ��ʼchannel_id�߼�                                           ***/
/*** ����ֵ: ����  bool     true  �ɹ�         false  ʧ��                ***/
/*** ��������1: ����    channel_id           ����   int                   ***/
/*** ��������2: ����    is_video             ����   bool                  ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_start_channel(int channel_id);

/****************************************************************************/
/*** ������: ֹͣͨ��                                                     ***/
/*** ����:   ֹͣchannel_id�߼�                                           ***/
/*** ����ֵ: ����  bool   true  �ɹ�      false  ʧ��                     ***/
/*** ��������1: ����    channel_id           ����   int                   ***/
/*** ��������2: ����    is_video             ����   bool                  ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_stop_channel(int channel_id, bool is_video = true);

/****************************************************************************/
/*** ������: ���ӱ�����Ⱦ����                                             ***/
/*** ����:   ���ӱ�����Ƶ��Ⱦ����                                         ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����    channel_id           ����   int                   ***/
/*** ��������2: ����    video_window         ����   void*                 ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_add_local_render(int chanel_id, void* video_window);

/****************************************************************************/
/*** ������: ����Զ����Ⱦ����                                             ***/
/*** ����:   ����Զ�˽�����Ƶ��Ⱦ����                                     ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����    channel_id           ����   int                   ***/
/*** ��������2: ����    video_window         ����   void*                 ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_add_remote_render(int peer_id, void* video_window);

/****************************************************************************/
/*** ������: ���ñ�����Ƶ��ssrc                                           ***/
/*** ����:   ����ͨ��channel_id����ý����ssrc                             ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����    channel_id           ����   int                   ***/
/*** ��������2: ����    ssrc                 ����   unsigned int          ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_video_set_local_ssrc(int channel_id, unsigned int ssrc);


/****************************************************************************/
/*** ������: ����Զ����Ƶ��ssrc                                           ***/
/*** ����:   ����ͨ��channel_idԶ��ý����ssrc                             ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����    channel_id           ����   int                   ***/
/*** ��������2: ����    ssrc                 ����   unsigned int          ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_video_set_remote_ssrc(int channel_id, unsigned int ssrc);

/****************************************************************************/
/*** ������: ���ñ�����Ƶ��ssrc                                           ***/
/*** ����:   ����ͨ��channel_idԶ��ý����ssrc                             ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����    channel_id           ����   int                   ***/
/*** ��������2: ����    ssrc                 ����   unsigned int          ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_audio_set_local_ssrc(int channel_id, unsigned int ssrc);

/****************************************************************************/
/*** ������: ����Զ����Ƶ��ssrc                                           ***/
/*** ����:   ����ͨ��channel_idԶ��ý����ssrc                             ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����    channel_id           ����   int                   ***/
/*** ��������2: ����    ssrc                 ����   unsigned int          ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_audio_set_remote_ssrc(int channel_id, unsigned int ssrc);

/****************************************************************************/
/*** ������: ����������Ƶtrack                                            ***/
/*** ����:   ����������ƵԴtrack                                          ***/
/*** ����ֵ: ����  void*    ���ش�����trackָ��                           ***/
/*** ��������1: ����    track_id             ����   const char            ***/
/*** ��������2: ����    voice_index          ����   int                   ***/
/****************************************************************************/
ECMEDIA_API void* ECMedia_create_audio_track(const char* track_id, int voice_index=0);

/****************************************************************************/
/*** ������: �ͷű�����Ƶtrack                                            ***/
/*** ����:   �ͷű�����ƵԴtrack                                          ***/
/*** ����ֵ: ����  void                                                   ***/
/*** ��������1: ����    track               ����   void*                  ***/
/****************************************************************************/
ECMEDIA_API void ECMedia_destroy_audio_track(void* track);

/****************************************************************************/
/*** ������: ����������Ƶtrack                                            ***/
/*** ����:   ����������ƵԴtrack                                          ***/
/*** ����ֵ: ����  void*    ���ش�����trackָ��                           ***/
/*** ��������1: ����    video_mode           ����   int                   ***/
/*** ��������2: ����    track_id             ����   const char            ***/
/*** ��������3: ����    camera_index         ����   int                   ***/
/****************************************************************************/
//ECMEDIA_API void* ECMedia_create_video_track(int video_mode, const char* track_id, int camera_index);
ECMEDIA_API void* ECMedia_create_video_track(const char* track_params);

/****************************************************************************/
/*** ������: �ͷű�����Ƶtrack                                            ***/
/*** ����:   �ͷű�����ƵԴtrack                                          ***/
/*** ����ֵ: ����  void                                                   ***/
/*** ��������1: ����    track               ����   void*                  ***/
/****************************************************************************/
ECMEDIA_API void ECMedia_destroy_video_track(void* track);

/****************************************************************************/
/*** ������: Ԥ��������Ƶtrack                                            ***/
/*** ����:   ����Ԥ��������ƵԴtrack                                      ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����    window_id           ����   int                    ***/
/*** ��������2: ����    track         ����   void*                  ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_preview_video_track(int window_id, void* track);

    /****************************************************************************/
/*** ������: ѡ����ƵԴ                                                   ***/
/*** ����:   ����ƵԴtrack���߼�ͨ��channel_id                          ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/ 
/*** ��������1: ����    tid                  ����   const char*           ***/
/*** ��������2: ����    channel_id           ����   int                   ***/
/*** ��������3: ����    track_id             ����   const char*           ***/
/*** ��������4: ����    video_track          ����   void*                 ***/
/*** ��������5: ����    stream_ids           ���� std::vector<std::string>***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_select_video_source(
    const char* tid,
    int channelid,
    const char* track_id,
    void* video_track,
    const char* stream_ids);


/****************************************************************************/
/*** ������: ѡ����ƵԴ                                                   ***/
/*** ����:   ����ƵԴtrack���߼�ͨ��channel_id                          ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����    tid                  ����   const char*           ***/
/*** ��������2: ����    channel_id           ����   int                   ***/
/*** ��������3: ����    track_id             ����   const char*           ***/
/*** ��������4: ����    audio_track          ����   void*                 ***/
/*** ��������5: ����    stream_ids           ���� std::vector<std::string>***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_select_audio_source(const char* tid, int channelid, const char* track_id, void* audio_track, const std::vector<std::string>& stream_ids);

/****************************************************************************/
/*** ������: ֹͣ��������                                                 ***/
/*** ����:   ֹͣ���估����ͨ��                                           ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������: ��                                                         ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_stop_connect();


/****************************************************************************/
/*** ������: ���ñ��ؾ���                                                 ***/
/*** ����:   ��������ƵԴ����                                             ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����    channel_id            ����    int                 ***/
/*** ��������2: ����    bMute                 ����    bool                 ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_set_local_audio_mute(int channel_id, bool bMute);

/****************************************************************************/
/*** ������: ����Զ�˾���                                                 ***/
/*** ����:   ��Զ����Ƶ����                                               ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����    channel_id            ����    int                 ***/
/*** ��������2: ����    bMute                 ����    bool                ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_set_remote_audio_mute(int channel_id, bool bMute);

ECMEDIA_API bool ECMedia_request_remote_ssrc(int channel_id, int ssrc);

/****************************************************************************/
/*** ������: ��ȡ��Ƶ����                                                 ***/
/*** ����:   ��ȡý���֧�ֵ���Ƶ�����ʽ                                 ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����   jsonVideoCodecInfos    ����    char*               ***/
/*** ��������2: ����   length                 ����    int                 ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_get_video_codecs(char* jsonVideoCodecInfos,int* length);

/****************************************************************************/
/*** ������: ��ȡ��Ƶ����                                                 ***/
/*** ����:   ��ȡý���֧�ֵ���Ƶ�����ʽ                                 ***/
/*** ����ֵ: ����  bool    true  �ɹ�      false  ʧ��                    ***/
/*** ��������1: ����   jsonAudioCodecInfos    ����    char*               ***/
/*** ��������2: ����   length                 ����    int                 ***/
/****************************************************************************/
ECMEDIA_API bool ECMedia_get_audio_codecs(char* jsonAudioCodecInfos,int* length);


ECMEDIA_API bool ECMedia_set_video_nack_status(const int channelId, const bool enable_nack);

ECMEDIA_API bool ECMedia_set_video_ulpfec_status(const int channelId,
                          const bool enable,
                          const uint8_t payloadtype_red,
                          const uint8_t payloadtype_fec);

ECMEDIA_API bool ECMedia_set_video_degradation_mode(const int channelId, int mode);

ECMEDIA_API bool ECMedia_send_key_frame(const int channelId);

ECMEDIA_API bool ECMedia_set_key_frame_request_callback(const int channelId, void* cb);

ECMEDIA_API bool ECMedia_set_aec(bool enable);

ECMEDIA_API bool ECMedia_set_agc(bool enable);

ECMEDIA_API bool ECMedia_set_ns(bool enable);

ECMEDIA_API void* ECMedia_create_audio_device();

ECMEDIA_API bool ECMedia_set_audio_recording_volume(uint32_t vol);

ECMEDIA_API bool ECMedia_get_audio_device_list(const char* json);

ECMEDIA_API bool ECMedia_set_audio_recording_device(int index);

ECMEDIA_API bool ECMedia_get_video_devices(char* devices, int* len);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// ECMEDIA_API int ECMedia_init_audio();
// ECMEDIA_API int ECMedia_uninit_audio();
// ECMEDIA_API int ECMedia_init_video();
// ECMEDIA_API int ECMedia_uninit_video();

//ECMEDIA_API int ECMedia_audio_create_channel(int& peer_id, bool is_video);
//ECMEDIA_API int ECMedia_delete_channel(int& peer_id, bool is_video);

ECMEDIA_API int ECMedia_delete_channel(int peer_id);

ECMEDIA_API int ECMdeia_num_of_capture_devices();
ECMEDIA_API int ECMedia_get_capture_device(int index,
                                           char* name,
                                           int name_len,
                                           char* id,
                                           int id_len);
ECMEDIA_API int ECMedia_num_of_capabilities(const char* id, int id_len);

ECMEDIA_API int ECMedia_get_capture_capability(const char* id,
                                               int id_len,
                                               int index,
                                               CameraCapability& capability);
ECMEDIA_API int ECMedia_allocate_capture_device(const char* id,
                                                int len,
                                                int& deviceid);
ECMEDIA_API int ECMedia_connect_capture_device(int deviceid, int peer_id);

ECMEDIA_API int ECMedia_start_capture(int deviceid, CameraCapability cam);
ECMEDIA_API int ECMedia_stop_capture(int deviceid);

//ECMEDIA_API int ECMedia_set_local_video_window(int deviceid,
//                                               void* video_window);

// NOTE: add_render not only add render, but also start rendering as well.
// maybe we should change the add_xxx into start_xxx

ECMEDIA_API int ECMedia_stop_local_render(int peer_id, int deviceid);
ECMEDIA_API int ECMedia_stop_remote_render(int peer_id, int deviceid);

// ECMEDIA_API int ECMedia_num_of_supported_codecs_video();

// ECMEDIA_API int ECMedia_num_of_supported_codecs_audio();

ECMEDIA_API int ECMedia_start_mic(int peer_id, int deviceid);

ECMEDIA_API int ECMedia_start_sendrecv(int peer_id);

ECMEDIA_API int ECMedia_video_start_receive(int peer_id);
/*
 *
 */
ECMEDIA_API int ECMedia_video_stop_receive(int peer_id);
/*
 *
 */
ECMEDIA_API int ECMedia_video_start_send(int peer_id);
/*
 *
 */
ECMEDIA_API int ECMedia_video_stop_send(int peer_id);

/*
 *1
 */
ECMEDIA_API int ECMedia_audio_start_receive(int peer_id);
/*
 *1
 */
ECMEDIA_API int ECMedia_audio_stop_receive(int peer_id);
/*
 *1
 */
ECMEDIA_API int ECMedia_audio_start_send(int peer_id);
/*
 *1
 */
ECMEDIA_API int ECMedia_audio_stop_send(int peer_id);

ECMEDIA_API bool ECMedia_start_connect(int audio_channel_id, int video_channel_id);





ECMEDIA_API int ECMedia_get_supported_codecs_video(
    std::vector<ecmedia::VideoCodec>* video_codecs);

ECMEDIA_API int ECMedia_get_supported_codecs_audio(
    std::vector<ecmedia::AudioCodec>* audio_codecs);

ECMEDIA_API int ECMedia_set_send_codec_video(int peer_id,
                                             ecmedia::VideoCodec* video_codec);

ECMEDIA_API int ECMedia_set_receive_codec_video(
    int peer_id,
    ecmedia::VideoCodec* video_codec);

ECMEDIA_API int ECMedia_set_send_codec_audio(int peer_id,
                                             ecmedia::AudioCodec* audio_codec);

ECMEDIA_API int ECMedia_set_receive_playloadType_audio(
    int peer_id,
    ecmedia::AudioCodec* audio_codec);

ECMEDIA_API int ECMedia_video_set_send_destination(int peer_id,
                                                   const char* r_addr,
                                                   const char* l_addr,
                                                   int port);




ECMEDIA_API int ECMedia_audio_set_send_destination(int peer_id,
                                                   const char* r_addr,
                                                   const char* l_addr,
                                                   int port);

ECMEDIA_API int ECMedia_set_video_protect_mode(int mode);

//ECMEDIA_API void ECMedia_add_tracks();
#ifdef __cplusplus
}
#endif

#endif
