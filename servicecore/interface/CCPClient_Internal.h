#ifndef _CCPCLIENT_INTERNAL_H_
#define _CCPCLIENT_INTERNAL_H_

#include "sdk_common.h"
#include "../ECMedia/source/MediaStatisticsData.pb.h"

// #ifdef WIN32
// #define CCPAPI  _declspec(dllexport)
// #else
 #define CCPAPI
// #endif


#ifndef __cplusplus
typedef enum {false, true} bool;
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/*! @function
	********************************************************************************
	������   : connect
	����     : ������ͨѶƽ̨���п��Ʒ�����
	����     : [IN]  proxy_addr   : ��ͨѶƽ̨���п��Ʒ�������ַ
			   [IN]  proxy_port	  : ��ͨѶƽ̨���п��Ʒ������˿�
			   [IN]  account	  : �û��ʺ�
			   [IN]  password	  : �û�����
              [IN]  capability    : base64������û�Ȩ�޿���
	����ֵ   : �Ƿ��ʼ���ɹ� 0���ɹ��� ��0ʧ��
	*******************************************************************************/
	CCPAPI int connectToCCP(const char *proxy_addr, int proxy_port, const char *account, const char *password, const char *capability);


    /*! @function
     ********************************************************************************
     ������   : connectToCCPWithXML
     ����     : ������ͨѶƽ̨���п��Ʒ�����
     ����     : [IN]  addressXML     : �������������ַ��XML
     [IN]  account       : �û��ʺ�
     [IN]  password      : �û�����
     [IN]  capability    : base64������û�Ȩ�޿���
     ����ֵ   : �Ƿ��ʼ���ɹ� 0���ɹ���
     -1��XML��ʽ����
     -2��STATUS���㣻
     -3��û��IP�б�
     *******************************************************************************/
	CCPAPI int connectToCCPWithXML(const char *addressXML, const char *account, const char *password, const char *capability);

    /*! @function
     ********************************************************************************
     ������   : connect
     ����     : �Ͽ�������ͨѶƽ̨���п��Ʒ�����
     ����ֵ   : �Ƿ��ʼ���ɹ� 0���ɹ��� ��0ʧ��
     *******************************************************************************/
    CCPAPI int disConnectToCCP();

	/*! @function
	********************************************************************************
	������   : sendTextMessage
	����     : �����ı���Ϣ
	����     : [IN]  receiver : ������
			   [IN]	 message  : ��Ϣ����
	����ֵ   : ��Ϣid
	*******************************************************************************/
	CCPAPI const char *sendTextMessage(const char *receiver, const char *message, const char *userdata);

	CCPAPI int getCallState(const char *callid);

	CCPAPI int setLogLevel( int level);

    CCPAPI void setTraceFlag(bool enable);
	
	CCPAPI int	enableGlobalAudioInDevice(bool enable);

	CCPAPI int	enableLoudsSpeaker(bool enable);

	CCPAPI bool getLoudsSpeakerStatus();

	CCPAPI int setMute(bool on);

	CCPAPI bool getMuteStatus();

	CCPAPI int setSpeakerMute(bool on);

	CCPAPI bool getSpeakerMuteStatus();

    CCPAPI bool getMuteStatusSoft(const char* callid);

    CCPAPI int setMuteSoft(const char*callid, bool on);

	CCPAPI int setRing(const char* filename);

	CCPAPI int setRingback(const char*filename);

    CCPAPI int setPreRing(const char* filename);

    CCPAPI int setAfterRing(const char* filename);

	CCPAPI int setUserData(int type ,const char *data);

	CCPAPI int getUserData(int type, char* buffer, int buflen);

	CCPAPI const char *getCurrentCall();

	int setAndroidObjects(void* javaVM, void* env, void* context);
	CCPAPI int setVideoView( void *view, void *localView);

	CCPAPI void setCapabilityToken(const char *token);

	CCPAPI void setNetworkType(int networktype,bool connected,bool reconnect);

	CCPAPI void sendKeepAlive();

	CCPAPI int selectCamera(int cameraIndex, int capabilityIndex,int fps,int rotate,bool force);

	CCPAPI int getCameraInfo(CameraInfo **);

    /*! @function
     ********************************************************************************
     ������   : getCallStatistics
     ����     : ��ȡ���е�ͳ������
     ����    : [IN] type : ý������. enum {VOICE_CALL,VIDEO_CALL};
              [OUT] statistics:  MediaStatisticsInfo�ṹ��ͳ������
     ����ֵ   :  �ɹ� 0
     ʧ�� -1
     *****************************************************************************/
	CCPAPI int getCallStatistics(int type,MediaStatisticsInfo *);

	CCPAPI void  enableKeepAlive(bool enable);

	CCPAPI void  setKeepAliveTimeout(int forWiFi, int for3G);

	//CCPAPI int setUserName(const char*username);

    /*! @function
     ********************************************************************************
     ������   : setCodecEnabled
     ����     : ����֧�ֵı���뷽ʽ��Ĭ��ȫ����֧��
     ����     : [IN]  type : ���������.
                     enum  {
                     codec_iLBC,
                     codec_G729,
                     codec_PCMU,
                     codec_PCMA,
                     codec_VP8,
                     codec_H264,
					 codec_H264SVC,
                     codec_SILK8K,
                     codec_SILK12K,
                     codec_SILK16K,
                     codec_AMR
                     };
                [IN] enabled: 0 ��֧�֣�1 ֧��
     ����ֵ   :  ʼ�շ��� 0
     *******************************************************************************/
    CCPAPI int setCodecEnabled(int type, bool enabled);
    CCPAPI bool getCodecEnabled(int type);

    /*! @function
     ********************************************************************************
     ������   : setAudioConfigEnabled
     ����     : ������Ƶ����Ŀ���
     ����     :   [IN] type : ��Ƶ��������. enum { AUDIO_AGC, AUDIO_EC, AUDIO_NS };
                 [IN] enabled:  AGCĬ�Ϲر�; EC��NSĬ�Ͽ���.
                 [IN] mode: ���Զ�Ӧ��ģʽ: AgcMode��EcMode��NsMode.
     ����ֵ   :  �ɹ� 0
                ʧ�� -1
     *****************************************************************************/
    CCPAPI int setAudioConfigEnabled(int type, bool enabled, int mode);
    CCPAPI int getAudioConfigEnabled(int type, bool *enabled, int *mode);

    /*! @function
     ********************************************************************************
     ������   : resetAudioDevice
     ����     : ����������Ƶ�豸
     ����ֵ   :  �ɹ� 0
     ʧ�� -1
     *****************************************************************************/
    CCPAPI int resetAudioDevice();

    /*! @function
     ********************************************************************************
     ������   : setDtxEnabled
     ����     : ����DTX���ܵĿ�����Ĭ���ǹرա��رպ�û���������������ٴ���     ***************************************************************************/
    CCPAPI void setDtxEnabled(bool enabled);

    /*! @function
     ********************************************************************************
     ������   : setVideoBitRates
     ����     : ������Ƶѹ��������
     ����     :  [IN] bitrates :  ��Ƶ������kb/s
     ***************************************************************************/
    CCPAPI void setVideoBitRates(int bitrates);

    /*! @function
     ********************************************************************************
     ������   : startRtpDump
     ����     : ����Rtp���ݵ��ļ��� ֻ����ͨ�������е��ã����û�е���stopRtpDump��ͨ��������ײ���Զ�����
     ����     :  [IN] callid :  �ػ�ID
                [IN] mediaType: ý�����ͣ� 0����Ƶ 1����Ƶ
                [IN] fileName: �ļ���
                [IN] direction: ��Ҫ����RTP�ķ���0������ 1������
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int startRtpDump(const char *callid, int mediaType, const char *fileName, int direction);

    /*! @function
     ********************************************************************************
     ������   : stopRtpDump
     ����     : ֹͣ����RTP���ݣ�ֻ����ͨ�������е��á�
     ����     :  [IN] callid :  �ػ�ID
                [IN] mediaType: ý�����ͣ� 0����Ƶ 1����Ƶ
                [IN] direction: ��Ҫ����RTP�ķ���0������ 1������
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int stopRtpDump(const char *callid, int mediaType, int direction);

	    /*! @function
     ********************************************************************************
     ������   : getSpeakerInfo
     ����     : ��ȡ��������Ϣ��ֻ��windowsʹ��
     ����     :  [IN] speakerinfo����������Ϣ
     ����ֵ   :  ����������
     ***************************************************************************/
    CCPAPI int getSpeakerInfo(SpeakerInfo **speakerinfo);

	    /*! @function
     ********************************************************************************
     ������   : selectSpeaker
     ����     : ѡ����������������ͨ��������ѡ��ֻ��windowsʹ��;�����ѡ����������ʹ��ϵͳĬ��������
     ����     :  [IN] speakerIndex : SpeakerInfo��indexֵ����getSpeakerInfo��ȡ
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int selectSpeaker(int speakerIndex);

	    /*! @function
     ********************************************************************************
     ������   : getMicroPhoneInfo
     ����     : ��ȡ��˷���Ϣ��ֻ��windowsʹ��
     ����     :  [IN] microphoneinfo :  ��˷���Ϣ
     ����ֵ   :  ��˷����
     *********************************************************************************/
    CCPAPI int getMicroPhoneInfo(MicroPhoneInfo** microphoneinfo);

	    /*! @function
     ********************************************************************************
     ������   : stopRtpDump
	 ����     : ѡ����˷磬������ͨ��������ѡ��ֻ��windowsʹ�ã������ѡ����˷磬ʹ��ϵͳĬ����˷�
	 ����     :  [IN] microphoneIndex : MicroPhoneInfo��indexֵ����getMicroPhoneInfo��ȡ
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int selectMicroPhone(int microphoneIndex);

	CCPAPI int getUniqueID(char *uniqueid, int len);

    /*! @function
     ********************************************************************************
     ������   : setStunServer
	 ����     : ����Stun Server��ͨ�����server��ȡ������ַ��
	 ����     :  [IN] server : ��������ַ
     ����     :  [IN] port   : ����˿ڣ�Ĭ��3478
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int setStunServer(const char *server, int port = 3478);

    /*! @function
     ********************************************************************************
     ������   : setFirewallPolicy
	 ����     : ���÷���ǽ���͡�
	 ����     :  [IN] policy : ����ǽ���͡�
                 typedef enum _CCPClientFirewallPolicy {
                 SerphonePolicyNoFirewall = 0,
                 SerphonePolicyUseIce
                 } CCPClientFirewallPolicy;
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int setFirewallPolicy(CCPClientFirewallPolicy policy);

    /*! @function
     ********************************************************************************
     ������   : setShieldMosaic
	 ����     : �����Ƿ�������Ƶ��������е������ˡ�Ĭ�ϲ����Ρ�
	 ����     :  [IN] flag : TRUE ���Σ�FALSE �����Ρ�
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int setShieldMosaic(bool flag);

    /*! @function
     ********************************************************************************
     ������   : seRateAfterP2PSucceed
	 ����     : ��Ƶͨ����P2P�ɹ���Ϊ��ȡ�ø��õĻ��ʣ����Խ��������õĸ�һЩ��Ĭ��330��
	 ����     :  [IN] rate : ������Ĭ��330��
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int seRateAfterP2PSucceed(int rate);

    /*! @function
     ********************************************************************************
     ������   : startDeliverVideoFrame
	 ����     : ��Ƶͨ���У����ô˺������ܹ���ȡ������Ƶ�����ݡ���Ƶ����ͨ���ص�onDeliverVideoFrame�ϱ���
	 ����     :  [IN] callid :  �ỰID
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int startDeliverVideoFrame(const char *callid);

    /*! @function
     ********************************************************************************
     ������   : stopDeliverVideoFrame
	 ����     : ��Ƶͨ���У�ֹͣ��ȡ������Ƶ��.�������������onDeliverVideoFrame�ص������е��á�
	 ����     :  [IN] callid :  �ỰID
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int stopDeliverVideoFrame(const char *callid);

	    /*! @function
     ********************************************************************************
     ������   : startRecordVoice
	 ����     :  ��ʼͨ��¼����Ҫ��ͨ����ʼ����á�
	 ����     :  [IN] callid :  �ỰID
				    [IN] filename: ¼���ļ�������·��
     ����ֵ   :  �ɹ� 0 ʧ�� -1 �˺Ų�֧��¼�� -3
     *********************************************************************************/
	CCPAPI int startRecordVoice(const char *callid, const char *filename);

	    /*! @function
     ********************************************************************************
     ������   : stopRecordVoice
	 ����     : ����ͨ��¼�������û�е��ã�ͨ����������Զ����á�
	 ����     :  [IN] callid :  �ỰID
     ����ֵ   :  �ɹ� 0 ʧ�� -1  �˺Ų�֧��¼�� -3
     *********************************************************************************/
	CCPAPI int stopRecordVoice(const char *callid);

	    /*! @function
     ********************************************************************************
     ������   : startRecordVoiceEx
	 ����     :  ��ʼͨ��¼����Ҫ��ͨ����ʼ����á�
	 ����     :  [IN] callid :  �ỰID
					[IN] rFileName: Զ��¼���ļ�������·��
				    [IN] lFileName: ����¼���ļ�������·��
     ����ֵ   :  �ɹ� 0 ʧ�� -1 �˺Ų�֧��¼�� -3
     *********************************************************************************/
	CCPAPI int startRecordVoiceEx(const char *callid, const char *rFileName, const char *lFileName);

    /*! @function
     ********************************************************************************
     ������   : getLocalVideoSnapshot
	 ����     : ��Ƶͨ���У�ץȡ������Ƶ��ͼ
	 ����     :  [IN] callid :  �ỰID
                [OUT] buf: ��ͼ����
                [OUT] size: ���ݳ���
                [OUT] width: ��ͼ���
                [OUT] height: ��ͼ�߶�
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int getLocalVideoSnapshot(const char *callid, unsigned char **buf, unsigned int *size, unsigned int *width, unsigned int *height);
    /*! @function
     ********************************************************************************
     ������   : getLocalVideoSnapshot
	 ����     : ��Ƶͨ���У�ץȡԶ����Ƶ��ͼ
	 ����     :  [IN] callid :  �ỰID
     [OUT] buf: ��ͼ����
     [OUT] size: ���ݳ���
     [OUT] width: ��ͼ���
     [OUT] height: ��ͼ�߶�
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int getRemoteVideoSnapshot(const char *callid, unsigned char **buf, unsigned int *size, unsigned int *width, unsigned int *height);


	    /*! @function
     ********************************************************************************
     ������   : getLocalVideoSnapshot
	 ����     : ��Ƶͨ���У�ץȡ������Ƶ��ͼ������ΪJPG��ʽ
	 ����     :  [IN] callid :  �ỰID
                  [IN] fielName: ����ͼƬ·��, UTF8
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int getLocalVideoSnapshotExt(const char *callid, const char *fielName);

    /*! @function
     ********************************************************************************
     ������   : getLocalVideoSnapshot
	 ����     : ��Ƶͨ���У�ץȡԶ����Ƶ��ͼ������ΪJPG��ʽ
	 ����     :  [IN] callid :  �ỰID
				  [IN] fielName: ����ͼƬ·����UTF8
	 ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int getRemoteVideoSnapshotExt(const char *callid, const char *fielName);

	CCPAPI int startRecordRemoteVideo(const char *callid, const char *filename);
	CCPAPI int stopRecordRemoteVideo(const char *callid);

	CCPAPI int startRecordLocalVideo(const char *callid, const char *filename);
	CCPAPI int stopRecordLocalVideo(const char *callid);
	
    //CCPAPI int startRecordVoip(const char *callid, const char *filename);
    //CCPAPI int stopRecordVoip(const char *callid);

    /*! @function
     ********************************************************************************
     ������   : noiseSuppression
	 ����     : ¼�����롣
	 ����     :  [IN] audioSamples :  ¼������
     [OUT] out: ��������Ƶ����
     ����ֵ   :  �ɹ� 0 ʧ�� -1
     *********************************************************************************/
    CCPAPI int noiseSuppression(const void* audioSamples,short *out);

		   /*! @function
     ********************************************************************************
     ������   : checkUserOnline
     ����     : �ж�voip�û��Ƿ����ߣ�ͬ�����ؽ���������3��
     ����     : [IN]  user :  voip�˺�
     ����ֵ   : Account_Status
     *******************************************************************************/
	CCPAPI int checkUserOnline(const char *user);

	   /*! @function
     ********************************************************************************
     ������   : getNetworkStatistic
     ����     : ��ȡͨ��������������Ϣ
     ����     : [IN]  callid : �Ựid��
                [OUT] duration�� ý�彻���ĳ���ʱ�䣬��λ�룬����Ϊ0��
                [OUT] send_total����durationʱ���ڣ����緢�͵�����������λ�ֽڣ�
				[OUT] recv_total����durationʱ���ڣ�������յ�����������λ�ֽڣ�
     ����ֵ   : 0���ɹ�   -1��ʧ��
     *******************************************************************************/
    CCPAPI int getNetworkStatistic(const char *callid, long long *duration, long long *send_total_sim, long long *recv_total_sim, long long *send_total_wifi, long long *recv_total_wifi);

    /*! @function
     ********************************************************************************
     ������   : notifyVideoRotate
     ����     : ������ת����������
     ����     : [IN]  receiver : ������
     [IN]	 degree  : ������ת�Ķ�����0�ȣ�90�ȣ�180�ȣ�270�ȣ�
     ����ֵ   : ��Ϣid
     *******************************************************************************/
	CCPAPI const char *notifyVideoRotate(const char *receiver, const char *degree);

    /*! @function
     ********************************************************************************
     ������   : android_media_init_audio
     ����     : �˺�����Ϊandroid IMʱ��ʼ����Ƶ�豸ʹ��
     ����     : NO
     ����ֵ   :
     *******************************************************************************/
	CCPAPI int android_media_init_audio();

    /*! @function
     ********************************************************************************
     ������   : android_media_uninit_audio
     ����     : �˺�����Ϊandroid IMʱ�ͷ���Ƶ�豸ʹ��
     ����     : NO
     ����ֵ   :
     *******************************************************************************/
    CCPAPI int android_media_uninit_audio();

    /*! @function
     ********************************************************************************
     ������   : SetAudioGain
     ����     : ���Կ�������������ý��������һ�����ķŴ󡣴˽ӿ��ǶԵײ���պͷ��͵����ݽ��зŴ������С���ĺ���������ͨ��������ʵʱ������Ч��
     ����     : [IN]  inaudio_gain : �Խ������ݽ������洦��
                [IN]  outaudio_gain : �Է������ݽ������洦
     ����ֵ   : 0 �ɹ��� -1 ʧ��
     *******************************************************************************/
    CCPAPI int setAudioGain(float inaudio_gain, float outaudio_gain);
		    /*! @function
     ********************************************************************************
     ������   : setSpeakerVolume
     ����     : ��������������Ĭ��ֵ����Χ����0~255��
     ����     : volume
     ����ֵ   : 0���ɹ�  -1��ʧ��
     *******************************************************************************/
	CCPAPI int setSpeakerVolume(unsigned int volume);

		    /*! @function
     ********************************************************************************
     ������   : getSpeakerVolume
     ����     : ��ȡ����������Ĭ��ֵ����Χ����0~255��
     ����     : volume
     ����ֵ   : 0���ɹ�  -1��ʧ��
     *******************************************************************************/
	CCPAPI unsigned int getSpeakerVolume();


	/*! @function
     ********************************************************************************
     ������   : startRecordScreen
     ����     : ͨ�������У���ʼ¼��
     ����     : [IN]  callid : �Ựid��
                [IN] filename��¼��������ļ�����
                [IN] bitrates������¼��ѹ��������Ĭ��640��
				[IN] fps��¼����֡����Ĭ��10֡ÿ�룻
				[IN] type: ¼������Ļѡ�� 0������ 1������
     ����ֵ   : 0���ɹ�   -1��ʧ��
     *******************************************************************************/
	CCPAPI int startRecordScreen(const char *callid, const char *filename, int bitrates, int fps, int type);

	CCPAPI int startRecordScreen(const char *callid, const char *filename, int bitrates, int fps, int type);

	/*! @function
     ********************************************************************************
     ������   : stopRecordScreen
     ����     : ֹͣ¼����ͨ������ʱ�����������ñ�������
     ����     : [IN]  callid : �Ựid��
     ����ֵ   : 0���ɹ�   -1��ʧ��
     *******************************************************************************/
	CCPAPI int stopRecordScreen(const char *callid);

		/*! @function
     ********************************************************************************
     ������   : getUsedCameraInfo
     ����     : ��ȡ�ײ�����ʹ�õ�����ͷ��Ϣ����������ʼ���󣬵ײ����ѡ��Ĭ������ͷ������������SelectCamera�󣬻�ı�ײ�����ʹ�õ�����ͷ��Ϣ��
     ����     :  [OUT] cameraIndex :����ͷ����
				  [OUT] capabilityIndex������ʹ�õ�����
				  [OUT] maxFps   ���õ������Ƶ֡��
				  [OUT] cameraRotate   ���õ�ͼ����ת
     ����ֵ   : 0���ɹ�   -1��ʧ��
     *******************************************************************************/
	CCPAPI int getUsedCameraInfo(int *cameraIndex, int *capabilityIndex, int *maxFps, int *cameraRotate);


		/*! @function
     ********************************************************************************
     ������   : resetVideoViews
     ����     : windows�£������ʼ����̫С�����洰�ڱ��ʱ����Ⱦ��Ȼ��С���ڣ�����ͻ�ģ����ͨ�������У�
				 ���ڴ�С�ı�������������������ڣ���������ӿڣ���������render��
     ����     :  [IN] callid : ����ID
				  [IN] rWnd�� ��ʾԶ����Ƶ���ھ��������Ϊ��
				  [IN] lWnd :  ��ʾ������Ƶ���ھ��������Ϊ��
     ����ֵ   : 0���ɹ�   -1��ʧ��
     *******************************************************************************/
	CCPAPI int resetVideoViews(const char *callid, void *rWnd, void *lWnd);

	CCPAPI void setBindLocalIP(const char* localip);

	CCPAPI int startVideoCapture(const char* callid);

    /*! @function
     ********************************************************************************
     ������   : setSilkRate
     ����     : ����silk������
     ����     :  [IN] rate : ������5000~20000����
     ����ֵ   : 0���ɹ�   -1��ʧ��
     *******************************************************************************/
    CCPAPI int setSilkRate(int rate);

	    /*! @function
     ********************************************************************************
     ������   : PlayAudioFromRtpDump
     ����     :  ��ʼ����rtpplay���ŵ���Ƶ����
     ����     :  [IN] localPort��
					[IN] ptName :
					[IN] ploadType :
     ����ֵ   : 0���ɹ�   -1��ʧ��
     *******************************************************************************/
	CCPAPI int PlayAudioFromRtpDump(int localPort, const char *ptName, int ploadType, int crypt_type, const char* key);
	    /*! @function
     ********************************************************************************
     ������   : StopPlayAudioFromRtpDump
     ����     : ֹͣ����rtpplay���ŵ���Ƶ���ݡ�
     ����ֵ   : 0���ɹ�   -1��ʧ��
     *******************************************************************************/
	CCPAPI int StopPlayAudioFromRtpDump();

	    /*! @function
     ********************************************************************************
     ������   : PlayVideoFromRtpDump
     ����     : ��ʼ����rtpplay���ŵ���Ƶ���ݡ���
	 ����     :  [IN] localPort��
					 [IN] ptName :
					 [IN] ploadType :
					 [IN] videoWindow ��
     ����ֵ   : 0���ɹ�   -1��ʧ��
     *******************************************************************************/
	CCPAPI int PlayVideoFromRtpDump(int localPort, const char *ptName, int ploadType, void *videoWindow, int crypt_type, const char* key);

	    /*! @function
     ********************************************************************************
     ������   : StopPlayVideoFromRtpDump
     ����     :  ֹͣ����rtpplay���ŵ���Ƶ����
     ����ֵ   : 0���ɹ�   -1��ʧ��
     *******************************************************************************/
	CCPAPI int StopPlayVideoFromRtpDump();

		    /*! @function
     ********************************************************************************
     ������   : startVideoWithoutCall
     ����     : ͨ��֮�⣬�򿪱�����Ƶ, Ϊץͼ��׼��
	 ����     :   [IN] cameraIndex��
					 [IN] videoW :
					 [IN] videoH :
					 [IN] rotate ��
					 [IN] videoWnd:
     ����ֵ   : 0���ɹ�   -1��ʧ��
     *******************************************************************************/
	CCPAPI int startVideoWithoutCall(int cameraIndex, int videoW, int videoH, int rotate, void *videoWnd);

		    /*! @function
     ********************************************************************************
     ������   : stopVideoWithoutCall
     ����     : ͨ��֮�⣬ֹͣ������Ƶ
     ����ֵ   : 0���ɹ�   -1��ʧ��
     *******************************************************************************/
	CCPAPI int stopVideoWithoutCall();

		    /*! @function
     ********************************************************************************
     ������   : getSnapshotWithoutCall
	 ����     : ͨ��֮�⣬�򿪱�����Ƶ��ץͼ�����浽����
	 ����     :  [IN] filePath��
	 ����ֵ   : 0���ɹ�   -1��ʧ��
	 *******************************************************************************/
	CCPAPI int getSnapshotWithoutCall(const char *filePath);

	CCPAPI void initHaiyuntongFailed();

		    /*! @function
     ********************************************************************************
     ������   : setNackEnablded
	 ����     : ����Nack�ش����ܵĿ���
	 ����     :  [IN] audioEnabled����Ƶ�ش�
				   [IN] videoEnabled����Ƶ�ش�
	 ����ֵ   : 0���ɹ�   -1��ʧ��
	 *******************************************************************************/
    CCPAPI int setNackEnabled(bool audioEnabled, bool videoEnabled);
	CCPAPI int setVideoProtectionMode(int mode);

	CCPAPI int setP2PEnabled(bool enabled);
	CCPAPI int setRembEnabled(bool enabled);
	CCPAPI int setTmmbrEnabled(bool enabled);

	CCPAPI int setVideoMode(int videoModeIndex); //only for demo test 0: Real-time, 1:screen-share
	CCPAPI int setDesktopShareParam(int desktop_width, int desktop_height, int desktop_frame_rate, int desktop_bit_rate);
	 /*! @function
     ********************************************************************************
     ������   : setVideoPacketTimeOut
	 ����     : ���ý�����Ƶ���ݵĳ�ʱʱ�䣬��λs�� �ο��¼���G_EVENT_VideoPacketTimeOut
	 ����     :  [IN] timeout����ʱ���
	 ����ֵ   : 0���ɹ�   -1��ʧ��
	 *******************************************************************************/
	CCPAPI int setVideoPacketTimeOut(int timeout);

	/*! @function
     ********************************************************************************
     ������   : getLocalIP
	 ����     : ��ȡ��ǰ��IP��ַ
	 ����     :  [IN] dst�����ӵ�Ŀ���ַ
				   [OUT] result�� ��ȡ����IP��ַ
	 ����ֵ   : 0���ɹ�   -1��ʧ��
	 *******************************************************************************/
	CCPAPI int getLocalIP(const char *dst, char *result);

		/*! @function
     ********************************************************************************
     ������   : FixedCameraInfo
	 ����     : ָ��ʹ�õ�����ͷ�������ϵͳ����ͷ��ƥ�䣬��������ͷʧ��
	 ����     :  [IN] cameraName�� ָ������ͷ���֣� ����Ϊ�գ����ܺ�cameraIdͬʱΪ��
				   [IN] cameraId:   ָ������ͷid������Ϊ�գ����ܺ�cameraNameͬʱΪ��
				   [IN]  width:  ָ��������Ϊ0
 				   [IN]  height: ָ���ߣ�����Ϊ0
	 ����ֵ   : 0���ɹ�   -1��ʧ��
	 *******************************************************************************/
	CCPAPI int FixedCameraInfo(const char *cameraName, const char *cameraId, int width, int height);

		/*! @function
     ********************************************************************************
     ������   : ConfigureChromaKey
	 ����     : �������ⱳ��ǽ
	 ����     :  [IN] bgImage ���ⱳ��ͼƬ�� ֧��jpgͼƬ
				   [IN] angle�� ��ͼǿ�ȣ�����Χ0-360���Ƽ���Χ10-90
				   [IN] noise_level:  ����������Ƽ���Χ10-80
				   [IN]  r ��g ��b�� ��ʵ����ǽrgbֵ
	 ����ֵ   : 0���ɹ�   -1��ʧ��
	 *******************************************************************************/
	CCPAPI int ConfigureChromaKey(const char *bgImage, float angle, float noise_level, int r, int g, int b);

		/*! @function
     ********************************************************************************
     ������   : StartVirtualBackGround
	 ����     : �������ⱳ��ǽ����
	 ����ֵ   : 0���ɹ�   -1��ʧ��
	 *******************************************************************************/
	CCPAPI int StartVirtualBackGround();

		/*! @function
     ********************************************************************************
     ������   : StopVirtualBakcGround
	 ����     : �������ⱳ��ǽ����
	 ����ֵ   : 0���ɹ�   -1��ʧ��
	 *******************************************************************************/
	CCPAPI int StopVirtualBakcGround();

	//add by ylr
	/************************************************************************/
	/* ��ȡͳ����Ϣ                                                                     */
	/************************************************************************/

	CCPAPI int GetStatsData(int type, char* callid, void** pbDataArray, int *pArraySize);
	CCPAPI int DeleteStatsData(void* pbDataArray);
	CCPAPI int GetBandwidthUsage(const char* callid,
								unsigned int& total_bitrate_sent,
								unsigned int& video_bitrate_sent,
								unsigned int& fec_bitrate_sent,
								unsigned int& nackBitrateSent);
	CCPAPI int GetEstimatedSendBandwidth(const char* callid,
								unsigned int* estimated_bandwidth);
	CCPAPI int GetEstimatedReceiveBandwidth(const char* callid,
								unsigned int* estimated_bandwidth);

	CCPAPI int GetReceiveChannelRtcpStatistics(const char* callid,
								_RtcpStatistics& basic_stats,
								__int64& rtt_ms);

	CCPAPI int GetSendChannelRtcpStatistics(const char* callid,
								_RtcpStatistics& basic_stats,
								__int64& rtt_ms);

	CCPAPI int GetRtpStatistics(const char* callid,
								_StreamDataCounters& sent,
								_StreamDataCounters& received);

	CCPAPI int GetSendStats(const char* callid, int &encode_frame_rate, int &media_bitrate_bps, int &width, int &height, bool &suspended);

	CCPAPI int StartRecord();
	CCPAPI int StopRecord();

#ifdef __cplusplus
}
#endif

#endif //_CCPCLIENT_H_
