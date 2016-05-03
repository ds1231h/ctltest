/*******************************************************************
����EasyWin
�ļ���EasyWin.c
���ܣ�Windows Ӧ�ó���������
********************************************************************/
#include <windows.h>
#include <windowsx.h>
#include "resource.h"

//��������
BOOL InitWindow(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
/*******************************************************************
������WinMain ()
���ܣ�Win32 Ӧ�ó�����ں��������������ڣ�������Ϣѭ��
********************************************************************/
int WINAPI WinMain(HINSTANCE hInstance,         //��ǰʵ�����
	HINSTANCE hPrevInstance,     //ǰһ��ʵ�����
	PSTR szCmdLine,              //�������ַ�
	int iCmdShow)                //������ʾ��ʽ
{
	MSG msg;

	//����������
	if (!InitWindow(hInstance, iCmdShow))
		return FALSE;

	//������Ϣѭ�����Ӹ�Ӧ�ó������Ϣ�����м�ȡ��Ϣ��
	//�͵���Ϣ������̣�����ȡ��WM_QUIT��Ϣʱ���˳���Ϣѭ����
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

/******************************************************************
������InitWindow ()
���ܣ��������ڡ�
*******************************************************************/
static BOOL InitWindow (HINSTANCE hInstance, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT ("EasyEdit");
	HWND hwnd;
	WNDCLASS wc;
	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = MainWndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon (hInstance, IDI_APPLICATION);
	wc.hCursor = LoadCursor (NULL, (LPCWSTR)IDC_CURSOR2);
	wc.hbrBackground = (HBRUSH)GetStockObject (WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = szAppName;
	if (!RegisterClass (&wc))
	{
		MessageBox (NULL, TEXT ("ע�ᴰ����ʧ�ܣ� "), szAppName,
			MB_ICONERROR);
		return 0;
	}
	hwnd = CreateWindow (szAppName,
		TEXT ("��׼�ؼ���ʾ�����ı��༭��"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		400,380,
		NULL, NULL,
		hInstance, NULL);

	if (!hwnd) return FALSE;

	//��ʾ�����´���
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
	return TRUE;
}

/******************************************************************
������WinProc ()
���ܣ�������������Ϣ
*******************************************************************/
LRESULT CALLBACK MainWndProc (HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HWND hCtrl;
	int wmId;
	switch (message)
	{
	case WM_CREATE:
		CreateWindow(TEXT("STATIC"), TEXT("Test String"), WS_CHILD|WS_VISIBLE, 
			10, 110, 80, 20, hWnd, (HMENU)IDC_STATIC1, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("Click Me"), WS_CHILD|WS_VISIBLE, 
			10, 140, 80, 20, hWnd, (HMENU)IDC_BUTTON1, NULL, NULL);

		//CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), NULL, WS_CHILD|
			//WS_VISIBLE|WS_BORDER,  10, 70, 80, 20, hWnd, (HMENU)IDC_EDIT1, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("�Ա�"), WS_CHILD|WS_VISIBLE|BS_GROUPBOX, 
			120, 110, 130, 50, hWnd, (HMENU)IDC_FRAME1, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("��"), WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON, 
			134, 130, 40, 20, hWnd, (HMENU)IDC_MALE, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("Ů"), WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON, 
			194, 130, 40, 20, hWnd, (HMENU)IDC_FEMALE, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("��ɫ"), WS_CHILD|WS_VISIBLE|BS_CHECKBOX|BS_AUTOCHECKBOX,
			120, 170, 54, 20, hWnd, (HMENU)IDC_CKBRED, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("��ɫ"), WS_CHILD|WS_VISIBLE|BS_CHECKBOX|BS_AUTOCHECKBOX, 
			180, 170, 54, 20, hWnd, (HMENU)IDC_CKBGRN, NULL, NULL);

		CreateWindow(TEXT("BUTTON"), TEXT("��ɫ"), WS_CHILD|WS_VISIBLE|BS_CHECKBOX|BS_AUTOCHECKBOX, 
			240, 170, 54, 20, hWnd, (HMENU)IDC_CKBBLU, NULL, NULL);

		hCtrl = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("LISTBOX"), NULL, WS_CHILD|WS_VISIBLE|LBS_STANDARD,
			10, 200, 80, 90, hWnd, (HMENU)IDC_LISTBOX1, NULL, NULL);

		SendMessage(hCtrl, LB_ADDSTRING, 0, (LPARAM)TEXT("list str1"));

		SendMessage(hCtrl, LB_ADDSTRING, 0, (LPARAM)TEXT("list str2"));

		SendMessage(hCtrl, LB_ADDSTRING, 0, (LPARAM)TEXT("list str3"));

		SendMessage(hCtrl, LB_ADDSTRING, 0, (LPARAM)TEXT("list str4"));

		hCtrl = CreateWindow(TEXT("COMBOBOX"), NULL, WS_CHILD|WS_VISIBLE|WS_VSCROLL|
			CBS_AUTOHSCROLL|CBS_DROPDOWNLIST, 120, 200, 100, 90, hWnd, (HMENU)IDC_CB1, NULL, NULL);

		SendMessage(hCtrl, CB_ADDSTRING, 0, (LPARAM)TEXT("comb str1"));

		SendMessage(hCtrl, CB_ADDSTRING, 0, (LPARAM)TEXT("comb str2"));

		SendMessage(hCtrl, CB_ADDSTRING, 0, (LPARAM)TEXT("comb str3"));

		SendMessage(hCtrl, CB_ADDSTRING, 0, (LPARAM)TEXT("comb str4"));

		SendMessage(hCtrl, CB_SETCURSEL, 1, 0);

		CreateWindow(TEXT("SCROLLBAR"), NULL, WS_CHILD|WS_VISIBLE|SBS_HORZ, 
			10, 300, 200, 20, hWnd, (HMENU)IDC_SCB1, NULL, NULL);

		CreateWindow(TEXT("SCROLLBAR"), NULL, WS_CHILD|WS_VISIBLE|SBS_VERT,
			240, 200, 20, 120, hWnd, (HMENU)IDC_SCB2, NULL, NULL);

		CreateWindow (TEXT ("edit"),			        //��������
			NULL,			                    //�ޱ���
			WS_CHILD|WS_VISIBLE|WS_HSCROLL|	//�༭�ؼ����
			WS_VSCROLL|WS_BORDER|ES_LEFT|
			ES_MULTILINE|ES_AUTOHSCROLL|
			ES_AUTOVSCROLL,
			0, 0, 300, 70,	
			hWnd,		                        //�����ھ��
			(HMENU)1,		                        //�༭�ؼ��Ӵ��ڱ�ʶ
			(HINSTANCE) GetWindowLong (hWnd, GWL_HINSTANCE),
			NULL);

		return 0;

	
	case WM_COMMAND: // ��Ӧ�༭�ؼ�֪ͨ��Ϣ
		if (lParam)
			//�༭�ؼ�֪ͨ��Ϣ
			if ((LOWORD (wParam) == 1) &&(HIWORD(wParam) == EN_ERRSPACE
				|| HIWORD (wParam) == EN_MAXTEXT))
				MessageBox (hWnd,TEXT ("�༭�ؼ��ڴ����"),
				TEXT ("�˵�ʾ������"), MB_OK|MB_ICONSTOP);

		HWND hwndTmp;
		if(lParam != 1) // ���ǲ˵�
		{
		wmId = LOWORD(wParam);
		switch (wmId)
		{
		case IDC_BUTTON1:
			hwndTmp = GetDlgItem(hWnd, IDC_STATIC1);
			SetWindowText(hwndTmp, TEXT("New Text"));
			MessageBox(hWnd, TEXT("Text Changed!"), TEXT("info"), MB_OK);
			break;
		}
		return 0;
		}

	case WM_DESTROY:
		PostQuitMessage (0);
		return 0;
	}
	return DefWindowProc (hWnd, message, wParam, lParam);
} //���� MainWndProc ����