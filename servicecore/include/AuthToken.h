#ifndef __AUTHTOKEN__H__
#define  __AUTHTOKEN__H__

#include <stdio.h>

#define MAX_AUTHTOKEN_LEN   10240
#define KEY_COUNT  5

//{"calling":"1","called":"1","msgflag":"1","createconf":"1","joinconf":"1"}
const char KEY_TOKEN[KEY_COUNT][32] = {"calling", "called", "msgflag", "createconf", "joinconf"};

/************************************************************************
* ��  ��  ����DecodeAuthToken
* ��     �ܣ�������ȡ��������Ϣ
* ��     �Σ����ܵ��������ַ���
* ��     �Σ����ܵ����룬��ʱû��ʹ��
* ��     �Σ���������Ϣ������ʽΪ010101  0����û�и�������1�����У�2 �����쳣
* ��  ��  ֵ��-1 ʧ��  0 �ɹ�
* ��     �ߣ�
************************************************************************/
int  DecodeAuthToken(const char * token, const char* key, char * output);


/************************************************************************
* ��  ��  ����EncodeAuthToken
* ��     �ܣ���ȡ�û�����������Ϣ
* ��     �Σ���������Ϣ��
* ��     �Σ���������������Ϣ
* ��  ��  ֵ��-1 ʧ��  0 �ɹ�
* ��     �ߣ�
************************************************************************/

int  EncodeAuthToken(const char * token, char *output);

#endif
