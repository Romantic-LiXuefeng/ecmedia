#ifndef ___VOIP_CRPT__H___
#define ___VOIP_CRPT__H___
///Author: CCIT WANGTIANYU
///date: 2014-7-11

//#define FILE_VOIP_PATH "/data/data/com.voice.demo/files"
#define FILE_VOIP_PATH "/data/data/com.hisun.cas/files"
//#define FILE_VOIP_PATH "/data/data/com.ccit.test/files"
//#define FILE_VOIP_PATH "/data/data/com.hisun.chuangyuan/files"

#define VOIPCRPT_API

/************************************************************************/
/*voip�ͻ�������ģ���ʼ��   
[in]appid	Ӧ��id
[in]appidLen	����
[in]testFlag                                          */
/************************************************************************/
VOIPCRPT_API int init(char *appid, long appidLen,  char *UsrId, long UsrIdLen, char *devId);
/************************************************************************/
/*����PIN
[char*]	PIN
[in]	PIN����
[bool]testFlag                                        */
/************************************************************************/

VOIPCRPT_API int setPIN(char *pin , int pinLen, bool testFlag);


/************************************************************************/
/*Э����Կ����
[in]desid		Ŀ���û�id
[in]desidLen	����
[out]inviteKey		Э����Կ���ĸ�ʽ������|ǩ����������ǩ��ֵʹ�á�|������
[out]linviteKeyLen	  Э����Կ                                            */
/************************************************************************/
VOIPCRPT_API int inviteKeyRequest(char *desid, long desidLen, char *inviteKey,long* linviteKeyLen);

/************************************************************************/
/*���лỰ��Կ����
inviteKey		Э����Կ���ģ���ʽ������|ǩ��ֵ��
inviteKeyLen		����
desid	char*	Ŀ���û�ID
ldesidLen	long	����                                           */
/************************************************************************/
VOIPCRPT_API int transmitKeyRequest(char * inviteKey, long inviteKeyLen,char *desid, long ldesidLen);

/************************************************************************/
/*���лỰ��Կ����   
tansmitKey	char*	�Ự��Կ���ģ���ʽ������|ǩ��ֵ��
linviteKeyLen	long	����
desid	char*	Ŀ���û�ID
ldesidLen	long	����
transmitKey	char*	Э����Կ���ĸ�ʽ������|ǩ����������ǩ��ֵʹ�á�|������
ltransmitKeyLen	long	����                                          */
/************************************************************************/
VOIPCRPT_API int transmitKeyRequest(char *inviteKey, long linviteKeyLen,char *desid, long ldesidLen, char *transmitKey,long* ltransmitKeyLen);

/************************************************************************/
/*ɾ���Ự��Կ   
Id	char*	Ŀ���û�ID
idLen	long	����                                         */
/************************************************************************/
VOIPCRPT_API int deleteTransmitKey(char *id,long idLen);

/************************************************************************/
/*��ص绰��ԿЭ������
[in]serviceID		��ʵ�ַ�����id
[in]serviceIDLen	��ʵ�ַ�����id����
[out]inviteKey		Э����Կ���ĸ�ʽ������|ǩ����������ǩ��ֵʹ�á�|������
[out]linviteKeyLen	  Э����Կ                                            */
/************************************************************************/
VOIPCRPT_API int inviteVOIPKeyRequest(char *serviceID, long serviceIDLen, char *inviteKey,long* linviteKeyLen);

/************************************************************************/
/*��ص绰���лỰ��Կ����
inviteKey		Э����Կ���ģ���ʽ������|ǩ��ֵ��
inviteKeyLen		����
serviceID	char*	��ʵ�ַ�����id
serviceIDLen	long	��ʵ�ַ�����id����                                           */
/************************************************************************/
VOIPCRPT_API int VOIPtransmitKeyRequest(char * inviteKey, long inviteKeyLen,char *serviceID, long serviceIDLen);

/************************************************************************/
/*��ص绰���лỰ��Կ����   
tansmitKey	char*	�Ự��Կ���ģ���ʽ������|ǩ��ֵ��
linviteKeyLen	long	����
serviceID	char*	��ʵ�ַ�����id
serviceIDLen	long	��ʵ�ַ�����id����
transmitKey	char*	Э����Կ���ĸ�ʽ������|ǩ����������ǩ��ֵʹ�á�|������
ltransmitKeyLen	long	����                                          */
/************************************************************************/
VOIPCRPT_API int VOIPtransmitKeyRequest(char *inviteKey, long linviteKeyLen,char *serviceID, long serviceIDLen, char *transmitKey,long* ltransmitKeyLen);

/************************************************************************/
/*��ص绰ɾ���Ự��Կ   
serviceID	char*	��ʵ�ַ�����id
serviceIDLen	long	��ʵ�ַ�����id����                              */
/************************************************************************/
VOIPCRPT_API int deleteVOIPTransmitKey(char *serviceID,long serviceIDLen);

/************************************************************************/
/*Ⱥ�������Ự��Կ����   
transmitKey	char*	�������·��ĻỰ��Կ����
transmitKeyLen	long	����             
groupID	char*	Ⱥ��ID��ʶ
groupIDLen	long	Ⱥ���ʶ����                            */
/************************************************************************/
VOIPCRPT_API bool groupTransmitKeyDecrp (char *transmitKey,long transmitKeyLen);

/************************************************************************/
/*ɾ��Ⱥ�������Ự��Կ
serviceID	char*	��ʵ�ַ�����id
serviceIDLen	long	��ʵ�ַ�����id����                              */
/************************************************************************/
VOIPCRPT_API int deleteGroupTransmitKey(char *serviceID,long serviceIDLen);

/************************************************************************/
/*����Ϣ���ܣ���Կֱ�Ӽ��ܷ�����  
sms	char*	�����ܵĶ���Ϣ
smsLen	long	����
desid	char*	���շ��û�ID
ldesidLen	long	����
smsCrpt	char*	���ܺ�Ķ���Ϣ���ģ����ĸ�ʽ������|ǩ��ֵ��
smsCrptLen	long	����                                                  */
/************************************************************************/
VOIPCRPT_API int smsCrpRequest(char *sms, long smsLen, char *desid, long desidLen, char *smsCrpt, long* smsCrptLen );

/************************************************************************/
/*����Ϣ���ܣ���Կֱ�Ӽ��ܷ�����
sms	char*	�����ܵĶ���Ϣ
smsLen	long	����
desid	char*	���ͷ��û�ID
ldesidLen	long	����
smsDeCrpt	char*	���ܺ�Ķ���Ϣ����
smsDeCrptLen	long	����                                                */
/************************************************************************/
VOIPCRPT_API int smsDecrpRequest(char *sms, long smsLen, char *desid, long desidLen, char *smsDeCrpt, long* smsDeCrptLen );

/************************************************************************/
/*�˵��˶���Ϣ���ܣ������ŷⷽʽ��    
sms	char*	�����ܵĶ���Ϣ
smsLen	long	����
desid	char*	Ŀ���û�ID
ldesidLen	long	����
smsCrpt	char*	���ܺ�Ķ���Ϣ����ǩ����P7�����ŷ⣩
smsCrptLen	long	����                                                  */
/************************************************************************/
VOIPCRPT_API int smsCrpEnvelop(char *sms, long smsLen, char *desid, long desidLen, char *smsCrpt, long* smsCrptLen );

/************************************************************************/
/*�˵��˶���Ϣ���ܣ������ŷⷽʽ��
sms	char*	�����ܵĶ���Ϣ
smsLen	long	����
smsDeCrpt	char*	���ܺ�Ķ���Ϣ
smsDeCrptLen	long	����                                                */
/************************************************************************/
VOIPCRPT_API int smsDecrpEnvelop(char *sms, long smsLen, char *desid, long desidLen, char *smsDeCrpt, long* smsDeCrptLen );

/************************************************************************/
/*Ⱥ�����Ϣ���ܣ������ŷⷽʽ��
sms	char*	�����ܵĶ���Ϣ
smsLen	long	����
serverid	char*	������id
serveridLen	long	����
smsCrpt	char*	���ܺ�Ķ���Ϣ����ǩ����P7�����ŷ⣩
smsCrptLen	long	����                                                  */
/************************************************************************/
VOIPCRPT_API int groupSmsCrpEnvelop(char *sms, long smsLen, char *serverid, long serveridLen, char *smsCrpt, long* smsCrptLen ); 

/************************************************************************/
/*Ⱥ�����Ϣ����
sms	char*	�����ܵĶ���Ϣ
smsLen	long	����
serverid	char*	���ͷ�����������ID
serveridLen	long	����
smsDeCrpt	char*	���ܺ�Ķ���Ϣ
smsDeCrptLen	long	����                                                */
/************************************************************************/
VOIPCRPT_API int groupSmsDecrpEnvelop(char *sms, long smsLen, char *serverid, long serveridLen, char *smsDeCrpt, long* smsDeCrptLen ); 

/************************************************************************/
/*�˵����ļ����ܣ������ŷⷽʽ��  
file	char*	�����ܵ��ļ�
fileLen	long	����
desid	char*	���ͷ��û�ID
desidLen	long	����
fileCrpEnvelop	char*	���ܺ���ļ�
fileCrpEnvelopLen	long	����                                           */
/************************************************************************/
VOIPCRPT_API int fileCrpEnvelop(unsigned char *file_short, long fileLen, char *desid, long desidLen, unsigned char *fileCrpEnvelop, long* fileCrpEnvelopLen ); 

/************************************************************************/
/*�˵����ļ����ܣ������ŷⷽʽ��
file	char*	�����ܵ��ļ�
fileLen	long	����
desid	char*	���ͷ��û�ID
desidLen	long	����
fileDeCrpt	char*	���ܺ���ļ�
fileDeCrptLen	long	����                                                */
/************************************************************************/
VOIPCRPT_API int fileDecrpEnvelop(unsigned char *file_short, long fileLen, char *desid, long desidLen, unsigned char *fileDeCrpt, long* fileDeCrptLen ); 

/************************************************************************/
/*Ⱥ���ļ����ܣ������ŷⷽʽ��           
file	char*	�����ܵ��ļ�
fileLen	long	����
desid	char*[]	���շ��û�ID
desidLen	long[]	����
userNum int ���շ��û�����
groupFileCrpEnvelop	char*	���ܺ���ļ�
groupFileCrpEnvelopLen	long	����                                     */
/************************************************************************/
VOIPCRPT_API int groupFileCrpEnvelop(unsigned char *file, long fileLen, char *desid[], long desidLen[], int userNum, unsigned char *groupFileCrpEnvelop, long* groupFileCrpEnvelopLen ); 

/************************************************************************/
/*Ⱥ���ļ����ܣ������ŷⷽʽ��   
file	char*	�����ܵ��ļ�
fileLen	long	����
desid	char*	���ͷ��û�ID
desidLen	long	����
groupFileDecrpt	char*	���ܺ���ļ�
groupFileDecrptLen	long	����                                          */
/************************************************************************/
VOIPCRPT_API int groupFileDecrpEnvelop(unsigned char *file, long fileLen, char *desid, long desidLen, unsigned char *groupFileDecrpt, long*groupFileDecrptLen ); 

/************************************************************************/
/*ý��������
mediaStream	char*	�����ܵ�ý����
mediaStreamLen	long	����
id	char*	���ͷ��û�ID����Ⱥ��id
idLen	long	����
mediaStreamCrp	char*	���ܺ����ý��
mediaStreamCrpLen	long	����                                            */
/************************************************************************/
VOIPCRPT_API int mediaStreamCrp(char *mediaStream, long mediaStreamLen, char *id, long idLen, char *mediaStreamCrp , long* mediaStreamCrpLen ); 

/************************************************************************/
/*ý��������
mediaStream	char*	�����ܵ�ý����
mediaStreamLen	long	����
id	char*	���ͷ��û�ID����Ⱥ��id
idLen	long	����
mediaStreamDecrp	char*	���ܺ��ý����
mediaStreamDecrpLen	long	����                                          */
/************************************************************************/
VOIPCRPT_API int mediaStreamDecrp (char *mediaStream, long mediaStreamLen, char *id, long idLen, char *mediaStreamDecrp , long* mediaStreamDecrpLen );  

/************************************************************************/
/*�����ϵ��
desid	char**	��ϵ��ID
desidLen	long[]	����
num     int     ��ϵ������
*/
/************************************************************************/
VOIPCRPT_API int contactListAdd (char *desid[], long desidLen[], int num); 

/************************************************************************/
/*ɾ����ϵ��
desid	char*	��ϵ��ID
desidLen	long	����                                                    
*/
/************************************************************************/
VOIPCRPT_API int contactListDel (char *desid, long desidLen); 

/************************************************************************/
/*���֤���Ƿ����
desid	char*	��ϵ��ID
desidLen	long	����  
return int 0 ֤�鲻���ڣ�1 ֤�����
*/
/************************************************************************/
VOIPCRPT_API int isExistOfCert (char *desid, long desidLen); 


/*********�Զ��庯��****************/

int tool_readFile(char *filePath, char *fileContent, long *fileLength);
/***********************************/

#endif //___VOIP_CRPT__H___

