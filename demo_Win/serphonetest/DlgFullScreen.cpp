// DlgFullScreen.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "serphonetest.h"
#include "DlgFullScreen.h"
#include "afxdialogex.h"


// CDlgFullScreen �Ի���

IMPLEMENT_DYNAMIC(CDlgFullScreen, CDialogEx)

CDlgFullScreen::CDlgFullScreen(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgFullScreen::IDD, pParent)
{

}

CDlgFullScreen::~CDlgFullScreen()
{
}

void CDlgFullScreen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgFullScreen, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEHOVER()
END_MESSAGE_MAP()


// CDlgFullScreen ��Ϣ�������


void CDlgFullScreen::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM(point.x,point.y));
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CDlgFullScreen::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CDlgFullScreen::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnMouseHover(nFlags, point);
}
