#pragma once


// CDlgStatistics �Ի���

class CDlgStatistics : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgStatistics)

public:
	CDlgStatistics(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgStatistics();

// �Ի�������
	enum { IDD = IDD_DIALOG_STATISTICS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
