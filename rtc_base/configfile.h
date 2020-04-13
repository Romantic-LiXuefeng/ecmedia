#pragma once
//----------------------------------------------------------------------------
// �������ƣ�   ConfigFile.h
// ����˵����   �� ConfigFile �Ķ���
//----------------------------------------------------------------------------

#ifndef __CONFIGFILE_H__
#define __CONFIGFILE_H__

#include <fstream>
#include <iostream>

using namespace std;

#define MAX_LINE_LENGTH 300

//----------------------------------------------------------------------------
// ��˵�������ڶ������ļ����в��������ڸ����Ľ����ͱ���������ñ�����ֵ��
//----------------------------------------------------------------------------
class CConfigFile
{
	//���캯������������
private:    //˽��

protected:  //����

public:     //����
	CConfigFile();
	CConfigFile(const char *pConfigFileName);
	~CConfigFile();


	//����
private:    //˽��
	fstream m_CfgFile;
	short     m_IsOpen;  //�ļ���״̬
	enum
	{
		IS_COMMENT,    //��ע��
		IS_SESSION,    //�ǽ���
		IS_VALUE,       //�Ǳ�����ֵ
		NOT_FOUND       //û���ҵ�ָ���ı�����
	};

protected:  //����

public:     //����


//����
private:    //˽��
	//����һ��ָ���Ľ���
	short  GetSession(const char *pStr, const char *SessionName);
	//��ñ�����ֵ
	short GetContent(const char *pStr, const char *ValueName, char *RetStr);

protected:  //����

public:     //����
	//��һ��ָ���������ļ�
	short  Open(const char *ConfigFileName);
	//�ر������ļ�
	void   Close();
	//���ݸ����Ľ����ͱ����������ļ��ж���������ֵ
	short  GetValue(const char *Session, const char *ValueName, char *RetStr);
	//�����ļ���״̬
	short  IsOpen() { return m_IsOpen; }

};

#endif //__CONFIGFILE_H__