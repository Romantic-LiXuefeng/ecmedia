#ifndef _CAMSTUDIO_H_
#define _CAMSTUDIO__H_

//�����붨��
enum {
	ERR_CAMSTUDIO_NULL =-200,//��
	ERR_CAMSTUDIO_MONITORCOUNT_LESS,//ϵͳ��Ļ����Ŀ����Ļ��
	ERR_CAMSTUDIO_SCREEN_FRAME_NULL//��֡
};

class screen{
public:
	int index;
	int left;
	int right;
	int top;
	int bottom;
	int width;
	int height;
	char outFile[50];
	char dispName[50];
	int fps;
	HMONITOR hMonitor;
	HDC hdcMonitor;
public:
	screen();
	bool SetDimensions(int left, int right, int top, int bottom);
};

class CaptureScreen {

public:
	CaptureScreen();
	~CaptureScreen();

	int getScreenInfo(screen **screeninfo);

	//Mouse Capture functions
	HCURSOR FetchCursorHandle();

	HANDLE Bitmap2Dib(HBITMAP, UINT);

	//Use these 2 functions to create frames and free frames
	LPBITMAPINFOHEADER captureScreenFrame(HWND hWnd,int left,int top,int width, int height);
	void FreeFrame(LPBITMAPINFOHEADER) ;
	int RGB24Snapshot( BYTE * pData, int size, int width, int height, const char * filename );//����USB��Ƶ����ͷ��ý���ʽΪRGB24����ΰ���Щ���ݱ��BMPλͼ

	/*! @function
	********************************************************************************
	������   : getLocalVideoSnapshot
	����     : ��Ƶͨ���У�ץȡ������Ƶ��ͼ
	����     :  [IN] callid :  0��,1��,2˫
			[OUT] buf: ��ͼ����
			[OUT] size: ���ݳ���
			[OUT] width: ��ͼ���
			[OUT] height: ��ͼ�߶�
	����ֵ   :  �ɹ� 0 ʧ�� -1
	*********************************************************************************/
	int getScreenFrame(int id, unsigned char **buf, int *size, int *width, int *height);
	int getScreenFrameEx(unsigned char **buf, int *size, int *pwidth, int *pheight, int left, int top, int width, int height);

private:
	////////////////////////////////////
	//���ⲿ����ʱ��ȫ�ֱ���
	int count_mon;
	LPBITMAPINFOHEADER _alpbi;
	HCURSOR hSavedCursor;
	int bits;
	int recordcursor;
	int captureTrans;
	int versionOp;
	int timestampAnnotation;
public:
	screen* pscreen;
	int mon_current;

};

#endif 
