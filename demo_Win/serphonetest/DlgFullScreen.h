#pragma once


// CDlgFullScreen �Ի���

class CDlgFullScreen : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFullScreen)

public:
	CDlgFullScreen(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgFullScreen();

// �Ի�������
	enum { IDD = IDD_DIALOG_FULL_SCREEN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
};
