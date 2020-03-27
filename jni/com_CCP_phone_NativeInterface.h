/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_CCP_phone_NativeInterface */

#ifndef _Included_com_CCP_phone_NativeInterface
#define _Included_com_CCP_phone_NativeInterface
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    initialize
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_initialize
  (JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    connectToCCP
 * Signature: (Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_connectToCCP
  (JNIEnv *, jclass, jstring, jint, jstring, jstring,jstring);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    connectToCCP
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_connectToCCPWithXML
(JNIEnv *, jclass, jstring, jstring, jstring,jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    disConnectToCCP
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_disConnectToCCP
(JNIEnv *, jclass);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setAudioContext
 * Signature: (Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setAudioContext
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setUserName
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setUserName
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    makeCall
 * Signature: (ILjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_CCP_phone_NativeInterface_makeCall
  (JNIEnv *, jclass, jint, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    releaseCall
 * Signature: (Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_releaseCall
  (JNIEnv *, jclass, jstring, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    acceptCall
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_acceptCall
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    rejectCall
 * Signature: (Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_rejectCall
  (JNIEnv *, jclass, jstring, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    pauseCall
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_pauseCall
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    resumeCall
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_resumeCall
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    transferCall
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_transferCall
  (JNIEnv *, jclass, jstring, jstring, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    cancelCall
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_cancelCall
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    sendDTMF
 * Signature: (Ljava/lang/String;C)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_sendDTMF
  (JNIEnv *, jclass, jstring, jchar);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    sendTextMessage
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jstring JNICALL Java_com_CCP_phone_NativeInterface_sendTextMessage
  (JNIEnv *, jclass, jstring, jstring, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getCallState
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_getCallState
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    unInitialize
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_unInitialize
  (JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setCallBackParams
 * Signature: (Ljava/lang/Object;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_CCP_phone_NativeInterface_setCallBackParams
  (JNIEnv *, jclass, jobject, jstring, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setBytesCallBackParams
 * Signature: (Ljava/lang/Object;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_CCP_phone_NativeInterface_setBytesCallBackParams
(JNIEnv *, jclass, jobject, jstring, jstring);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setLogLevel
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_CCP_phone_NativeInterface_setLogLevel
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    enableLoudsSpeaker
 * Signature: (Z)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_enableLoudsSpeaker
  (JNIEnv *, jclass, jboolean);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getLoudsSpeakerStatus
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_CCP_phone_NativeInterface_getLoudsSpeakerStatus
  (JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setMute
 * Signature: (Z)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setMute
  (JNIEnv *, jclass, jboolean);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getMuteStatus
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_CCP_phone_NativeInterface_getMuteStatus
  (JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setRing
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setRing
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setRingback
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setRingback
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getCurrentCall
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_CCP_phone_NativeInterface_getCurrentCall
  (JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setUserData
 * Signature: (ILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setUserData
  (JNIEnv *, jclass, jint, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getUserData
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_CCP_phone_NativeInterface_getUserData
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setCapabilityToken
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setCapabilityToken
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setVideoView
 * Signature: (Ljava/lang/Object;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setVideoView
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setNetworkType
 * Signature: (IZZ)V
 */
JNIEXPORT void JNICALL Java_com_CCP_phone_NativeInterface_setNetworkType
  (JNIEnv *, jclass, jint, jboolean, jboolean);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    selectCamera
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_selectCamera
  (JNIEnv *, jclass, jint, jint, jint, jint, jboolean);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getCameraInfo
 * Signature: ()[Lcom/CCP/phone/CameraInfo;
 */
JNIEXPORT jobjectArray JNICALL Java_com_CCP_phone_NativeInterface_getCameraInfo
  (JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getCallStatistics
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_CCP_phone_NativeInterface_getCallStatistics
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getVersion
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_CCP_phone_NativeInterface_getVersion
  (JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setKeepAliveTimeout
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_com_CCP_phone_NativeInterface_setKeepAliveTimeout
  (JNIEnv *, jclass, jint, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    updateCallMedia
 * Signature: (Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_updateCallMedia
  (JNIEnv *, jclass, jstring, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    answerCallMediaUpdate
 * Signature: (Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_answerCallMediaUpdate
  (JNIEnv *, jclass, jstring, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getCallMeidaType
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_getCallMeidaType
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getCodecEnabled
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_CCP_phone_NativeInterface_getCodecEnabled
(JNIEnv *, jclass, jint);

    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setCodecEnabled
 * Signature: (IZ)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setCodecEnabled
  (JNIEnv *, jclass, jint, jboolean);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setAgcEnabled
 * Signature: (IZ)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setAgcEnabled
(JNIEnv *, jclass, jint, jboolean);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setDtxEnabled
 * Signature: (IZ)I
 */
JNIEXPORT void JNICALL Java_com_CCP_phone_NativeInterface_setDtxEnabled
(JNIEnv *, jclass, jboolean);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setSrtpEnabled
 * Signature: (ZZZILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setSrtpEnabled
(JNIEnv *, jclass, jboolean, jboolean, jboolean, jint, jstring);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setAudioConfig
 * Signature: (IZI)V
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setAudioConfig
(JNIEnv *, jclass, jint, jboolean, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getAudioConfig
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_CCP_phone_NativeInterface_getAudioConfig
(JNIEnv *, jclass, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getAudioConfigMode
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_getAudioConfigMode
(JNIEnv *, jclass, jint);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setVideoBitRates
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_CCP_phone_NativeInterface_setVideoBitRates
(JNIEnv *, jclass, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    startRtpDump
 * Signature: (Ljava/lang/String;ILjava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_startRtpDump
(JNIEnv *, jclass, jstring, jint, jstring, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    stopRtpDump
 * Signature: (Ljava/lang/String;II)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_stopRtpDump
(JNIEnv *, jclass, jstring, jint, jint);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    AmrNBCreateEnc
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_AmrNBCreateEnc
(JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    AmrNBCreateDec
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_AmrNBCreateDec
(JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    AmrNBFreeEnc
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_AmrNBFreeEnc
(JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    AmrNBFreeDec
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_AmrNBFreeDec
(JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    AmrNBEncode
 * Signature: ([SS[SI)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_AmrNBEncode
(JNIEnv *, jclass, jbyteArray, jint, jbyteArray, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    AmrNBEncoderInit
 * Signature: (S)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_AmrNBEncoderInit
(JNIEnv *, jclass, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    AmrNBDecode
 * Signature: ([SS[S)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_AmrNBDecode
(JNIEnv *, jclass, jbyteArray, jint, jbyteArray);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    AmrNBVersion
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_CCP_phone_NativeInterface_AmrNBVersion
(JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    GetUniqueID
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_CCP_phone_NativeInterface_GetUniqueID
(JNIEnv *, jclass);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    SetStunServer
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_SetStunServer__Ljava_lang_String_2
(JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    SetStunServer
 * Signature: (Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_SetStunServer__Ljava_lang_String_2I
(JNIEnv *, jclass, jstring, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    SetFirewallPolicy
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_SetFirewallPolicy
(JNIEnv *, jclass, jint);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    SetShieldMosaic
 * Signature: (Z)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_SetShieldMosaic
(JNIEnv *, jclass, jboolean);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    SetStartBitRateAfterP2PSucceed
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_SetStartBitRateAfterP2PSucceed
(JNIEnv *, jclass, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    startDeliverVideoFrame
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_startDeliverVideoFrame
(JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    stopDeliverVideoFrame
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_stopDeliverVideoFrame
(JNIEnv *, jclass, jstring);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getLocalVideoSnapshot
 * Signature: (Ljava/lang/String;)Lcom/CCP/phone/VideoSnapshot;
 */
JNIEXPORT jobject JNICALL Java_com_CCP_phone_NativeInterface_getLocalVideoSnapshot
(JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getRemoteVideoSnapshot
 * Signature: (Ljava/lang/String;)Lcom/CCP/phone/VideoSnapshot;
 */
JNIEXPORT jobject JNICALL Java_com_CCP_phone_NativeInterface_getRemoteVideoSnapshot
(JNIEnv *, jclass, jstring);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    startRecordVoice
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_startRecordVoice
(JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    stopRecordVoice
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_stopRecordVoice
(JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    startRecordVoice
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_startRecordVoiceEx
(JNIEnv *, jclass, jstring, jstring, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    startRecordVoip
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_startRecordVoip
(JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    stopRecordVoip
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_stopRecordVoip
(JNIEnv *, jclass, jstring);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setTraceFlag
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_CCP_phone_NativeInterface_setTraceFlag
(JNIEnv *, jclass, jboolean);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    checkUserOnline
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_checkUserOnline
(JNIEnv *, jclass, jstring);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    getNetworkStatistic
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_CCP_phone_NativeInterface_getNetworkStatistic
(JNIEnv *, jclass, jstring);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setProcessDataEnabled
 * Signature: (Ljava/lang/String;Z)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setProcessDataEnabled
(JNIEnv *, jclass, jstring, jboolean);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    InitAudioDevice
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_InitAudioDevice
(JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    UNInitAudioDevice
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_UNInitAudioDevice
(JNIEnv *, jclass);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setPrivateCloud
 * Signature: (Ljava/lang/String;Ljava/lang/String;Z)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setPrivateCloud
(JNIEnv *, jclass, jstring, jstring, jboolean);

    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    registerAudioDevice
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_registerAudioDevice
(JNIEnv *, jclass);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    deregisterAudioDevice
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_deregisterAudioDevice
(JNIEnv *, jclass);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    SetNetworkGroupId
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_SetNetworkGroupId
(JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setProcessOriginalDataEnabled
 * Signature: (Ljava/lang/String;Z)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setProcessOriginalDataEnabled
(JNIEnv *, jclass, jstring, jboolean);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    StartVideoCapture
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_StartVideoCapture
  (JNIEnv *, jclass, jstring);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    SetVideoConferenceAddr
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_SetVideoConferenceAddr
(JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    requestMemberVideo
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;I)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_requestMemberVideo
(JNIEnv *, jclass, jstring, jstring, jstring, jobject, jint);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    stopMemberVideo
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_stopMemberVideo
(JNIEnv *, jclass, jstring, jstring, jstring);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setSilkRate
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setSilkRate
(JNIEnv *, jclass, jint);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    resetVideoConfWindow
 * Signature: (Ljava/lang/String;Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_resetVideoConfWindow
(JNIEnv *, jclass, jstring, jobject);

    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    haiyuntongFileEncrypt
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setHaiyuntongEnabled
(JNIEnv *, jclass, jboolean);
    
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    haiyuntongFileEncrypt
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_haiyuntongSetDeviceID
(JNIEnv *, jclass, jstring, jstring, jboolean);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    haiyuntongFileEncrypt
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_haiyuntongFileEncrypt
    (JNIEnv *env, jclass, jbyteArray, jstring, jbyteArray);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    haiyuntongFileDecrypt
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_haiyuntongFileDecrypt
    (JNIEnv *env, jclass, jbyteArray, jstring, jbyteArray);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    haiyuntongGroupFileEncrypt
 * Signature: (Ljava/lang/String;[Ljava/lang/String;I)Ljava/lang/String;
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_haiyuntongGroupFileEncrypt
(JNIEnv *, jclass, jbyteArray, jobjectArray, jint,jbyteArray);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    haiyuntongGroupFileDecrypt
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_haiyuntongGroupFileDecrypt
(JNIEnv *, jclass, jbyteArray, jstring,jbyteArray);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    haiyuntongAddContact
 * Signature: (Ljava/lang/String;)I
 */
/*JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_haiyuntongAddContact
(JNIEnv *, jclass, jstring);*/
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_haiyuntongAddContact
(JNIEnv *, jclass, jobjectArray, jint);
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    haiyuntongDelContact
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_haiyuntongDelContact
(JNIEnv *, jclass, jstring);

/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setNackEnablded
 * Signature: (ZZ)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setNackEnabled
  (JNIEnv *, jclass, jboolean, jboolean);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    isExistOfCert
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_isExistOfCert
(JNIEnv *, jclass, jstring);

    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    openTraceFile
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_openTraceFile
(JNIEnv *, jclass, jstring);
    /*
     * Class:     com_CCP_phone_NativeInterface
     * Method:    openTraceFile
     * Signature: (Ljava/lang/String;)I
     */
    JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_openTraceFile2
    (JNIEnv *, jclass, jstring);
    
/*
 * Class:     com_CCP_phone_NativeInterface
 * Method:    setReconnectFlag
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setReconnectFlag
(JNIEnv *, jclass, jboolean);


JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_startRecord
(JNIEnv *, jclass, jstring);


JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_stopRecord
(JNIEnv *, jclass, jstring);

/*
 * record local video as mp4 file
 */
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_startRecordLocalMedia
(JNIEnv *, jclass, jstring, jobject );

    
JNIEXPORT void JNICALL Java_com_CCP_phone_NativeInterface_stopRecordLocalMedia();

JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_setScreenShareActivity
(JNIEnv *, jclass, jstring, jobject);
/**********  ec live video api begin ***************/
JNIEXPORT void JNICALL Java_com_CCP_phone_NativeInterface_createLiveStream();
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_configLiveVideoStream(JNIEnv *, jclass, jint, jint, jint, jboolean);
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_selectCameraLiveStream(JNIEnv *, jclass, jint);
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_playLiveStream(JNIEnv *, jclass, jstring, jobject);
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_pushLiveStream(JNIEnv *, jclass, jstring, jobject);
JNIEXPORT jint JNICALL Java_com_CCP_phone_NativeInterface_stopLiveStream();
JNIEXPORT void JNICALL Java_com_CCP_phone_NativeInterface_releaseLiveStream();
/**********  ec live video api end ***************/
#ifdef __cplusplus
}
#endif
#endif