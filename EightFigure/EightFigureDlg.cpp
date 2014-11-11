
// EightFigureDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "EightFigure.h"
#include "EightFigureDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEightFigureDlg 对话框



CEightFigureDlg::CEightFigureDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEightFigureDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEightFigureDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_STATIC_PIC_A1, picA1);
    DDX_Control(pDX, IDC_STATIC_PIC_A2, picA2);
    DDX_Control(pDX, IDC_STATIC_PIC_A3, picA3);
    DDX_Control(pDX, IDC_STATIC_PIC_A4, picA4);
    DDX_Control(pDX, IDC_STATIC_PIC_A5, picA5);
    DDX_Control(pDX, IDC_STATIC_PIC_A6, picA6);
    DDX_Control(pDX, IDC_STATIC_PIC_A7, picA7);
    DDX_Control(pDX, IDC_STATIC_PIC_A8, picA8);
    DDX_Control(pDX, IDC_STATIC_PIC_A9, picA9);
    DDX_Control(pDX, IDC_STATIC_PIC_B1, picB1);
    DDX_Control(pDX, IDC_STATIC_PIC_B2, picB2);
    DDX_Control(pDX, IDC_STATIC_PIC_B3, picB3);
    DDX_Control(pDX, IDC_STATIC_PIC_B4, picB4);
    DDX_Control(pDX, IDC_STATIC_PIC_B5, picB5);
    DDX_Control(pDX, IDC_STATIC_PIC_B6, picB6);
    DDX_Control(pDX, IDC_STATIC_PIC_B7, picB7);
    DDX_Control(pDX, IDC_STATIC_PIC_B8, picB8);
    DDX_Control(pDX, IDC_STATIC_PIC_B9, picB9);
    DDX_Control(pDX, IDC_STATIC_PIC_C1, picC1);
    DDX_Control(pDX, IDC_STATIC_PIC_C2, picC2);
    DDX_Control(pDX, IDC_STATIC_PIC_C3, picC3);
    DDX_Control(pDX, IDC_STATIC_PIC_C4, picC4);
    DDX_Control(pDX, IDC_STATIC_PIC_C5, picC5);
    DDX_Control(pDX, IDC_STATIC_PIC_C6, picC6);
    DDX_Control(pDX, IDC_STATIC_PIC_C7, picC7);
    DDX_Control(pDX, IDC_STATIC_PIC_C8, picC8);
    DDX_Control(pDX, IDC_STATIC_PIC_C9, picC9);
    DDX_Control(pDX, IDC_COMBO_TYPE, comboType);
    DDX_Control(pDX, IDOK, btnSearch);
    DDX_Control(pDX, IDC_EDIT_CUR, editCur);
    DDX_Control(pDX, IDC_EDIT_TOT, editTot);
    DDX_Control(pDX, IDC_BUTTON_FORWARD, btnForward);
    DDX_Control(pDX, IDC_BUTTON_NEXT, btnNext);
}

BEGIN_MESSAGE_MAP(CEightFigureDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_FORWARD, &CEightFigureDlg::OnBnClickedButtonForward)
    ON_BN_CLICKED(IDOK, &CEightFigureDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDC_BUTTON_NEXT, &CEightFigureDlg::OnBnClickedButtonNext)
    ON_BN_CLICKED(IDC_BUTTON_SET_START, &CEightFigureDlg::OnBnClickedButtonSetStart)
    ON_EN_CHANGE(IDC_EDIT_CUR, &CEightFigureDlg::OnEnChangeEditCur)
END_MESSAGE_MAP()


// CEightFigureDlg 消息处理程序

BOOL CEightFigureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
    comboType.AddString(_T("DFS"));
    comboType.AddString(_T("WFS"));
    btnNext.EnableWindow(FALSE);
    btnForward.EnableWindow(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CEightFigureDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CEightFigureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
        char data1[9] = {1,2,3,4,5,6,7,8,0};
        char data2[9] = {1,2,3,4,5,6,0,7,8};
        picA.SetDataArray(data1);
        start.SetDataArray(data1);
        target.SetDataArray(data2);

        SetPicA(picA);
        SetPicB(start);
        SetPicC(target);
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CEightFigureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CEightFigureDlg::SetPicA(EightFigureState state)
{
    char array[9];
    state.GetDataArray(array);

    CBitmap bitmap1,bitmap2,bitmap3,bitmap4,bitmap5,bitmap6,bitmap7,bitmap8,bitmap9;
    HBITMAP hBmp1,hBmp2,hBmp3,hBmp4,hBmp5,hBmp6,hBmp7,hBmp8,hBmp9;

    bitmap1.LoadBitmap(IDB_BITMAP1+array[0]);
    hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();
    picA1.SetBitmap(hBmp1);

    bitmap2.LoadBitmap(IDB_BITMAP1+array[1]);
    hBmp2 = (HBITMAP)bitmap2.GetSafeHandle();
    picA2.SetBitmap(hBmp2);

    bitmap3.LoadBitmap(IDB_BITMAP1+array[2]);
    hBmp3 = (HBITMAP)bitmap3.GetSafeHandle();
    picA3.SetBitmap(hBmp3);

    bitmap4.LoadBitmap(IDB_BITMAP1+array[3]);
    hBmp4 = (HBITMAP)bitmap4.GetSafeHandle();
    picA4.SetBitmap(hBmp4);

    bitmap5.LoadBitmap(IDB_BITMAP1+array[4]);
    hBmp5 = (HBITMAP)bitmap5.GetSafeHandle();
    picA5.SetBitmap(hBmp5);

    bitmap6.LoadBitmap(IDB_BITMAP1+array[5]);
    hBmp6 = (HBITMAP)bitmap6.GetSafeHandle();
    picA6.SetBitmap(hBmp6);

    bitmap7.LoadBitmap(IDB_BITMAP1+array[6]);
    hBmp7 = (HBITMAP)bitmap7.GetSafeHandle();
    picA7.SetBitmap(hBmp7);

    bitmap8.LoadBitmap(IDB_BITMAP1+array[7]);
    hBmp8 = (HBITMAP)bitmap8.GetSafeHandle();
    picA8.SetBitmap(hBmp8);

    bitmap9.LoadBitmap(IDB_BITMAP1+array[8]);
    hBmp9 = (HBITMAP)bitmap9.GetSafeHandle();
    picA9.SetBitmap(hBmp9);
}

void CEightFigureDlg::SetPicB(EightFigureState state)
{
    char array[9];
    state.GetDataArray(array);

    CBitmap bitmap1,bitmap2,bitmap3,bitmap4,bitmap5,bitmap6,bitmap7,bitmap8,bitmap9;
    HBITMAP hBmp1,hBmp2,hBmp3,hBmp4,hBmp5,hBmp6,hBmp7,hBmp8,hBmp9;

    bitmap1.LoadBitmap(IDB_BITMAP10+array[0]);
    hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();
    picB1.SetBitmap(hBmp1);

    bitmap2.LoadBitmap(IDB_BITMAP10+array[1]);
    hBmp2 = (HBITMAP)bitmap2.GetSafeHandle();
    picB2.SetBitmap(hBmp2);

    bitmap3.LoadBitmap(IDB_BITMAP10+array[2]);
    hBmp3 = (HBITMAP)bitmap3.GetSafeHandle();
    picB3.SetBitmap(hBmp3);

    bitmap4.LoadBitmap(IDB_BITMAP10+array[3]);
    hBmp4 = (HBITMAP)bitmap4.GetSafeHandle();
    picB4.SetBitmap(hBmp4);

    bitmap5.LoadBitmap(IDB_BITMAP10+array[4]);
    hBmp5 = (HBITMAP)bitmap5.GetSafeHandle();
    picB5.SetBitmap(hBmp5);

    bitmap6.LoadBitmap(IDB_BITMAP10+array[5]);
    hBmp6 = (HBITMAP)bitmap6.GetSafeHandle();
    picB6.SetBitmap(hBmp6);

    bitmap7.LoadBitmap(IDB_BITMAP10+array[6]);
    hBmp7 = (HBITMAP)bitmap7.GetSafeHandle();
    picB7.SetBitmap(hBmp7);

    bitmap8.LoadBitmap(IDB_BITMAP10+array[7]);
    hBmp8 = (HBITMAP)bitmap8.GetSafeHandle();
    picB8.SetBitmap(hBmp8);

    bitmap9.LoadBitmap(IDB_BITMAP10+array[8]);
    hBmp9 = (HBITMAP)bitmap9.GetSafeHandle();
    picB9.SetBitmap(hBmp9);
}

void CEightFigureDlg::SetPicC(EightFigureState state)
{
    char array[9];
    state.GetDataArray(array);

    CBitmap bitmap1,bitmap2,bitmap3,bitmap4,bitmap5,bitmap6,bitmap7,bitmap8,bitmap9;
    HBITMAP hBmp1,hBmp2,hBmp3,hBmp4,hBmp5,hBmp6,hBmp7,hBmp8,hBmp9;

    bitmap1.LoadBitmap(IDB_BITMAP10+array[0]);
    hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();
    picC1.SetBitmap(hBmp1);

    bitmap2.LoadBitmap(IDB_BITMAP10+array[1]);
    hBmp2 = (HBITMAP)bitmap2.GetSafeHandle();
    picC2.SetBitmap(hBmp2);

    bitmap3.LoadBitmap(IDB_BITMAP10+array[2]);
    hBmp3 = (HBITMAP)bitmap3.GetSafeHandle();
    picC3.SetBitmap(hBmp3);

    bitmap4.LoadBitmap(IDB_BITMAP10+array[3]);
    hBmp4 = (HBITMAP)bitmap4.GetSafeHandle();
    picC4.SetBitmap(hBmp4);

    bitmap5.LoadBitmap(IDB_BITMAP10+array[4]);
    hBmp5 = (HBITMAP)bitmap5.GetSafeHandle();
    picC5.SetBitmap(hBmp5);

    bitmap6.LoadBitmap(IDB_BITMAP10+array[5]);
    hBmp6 = (HBITMAP)bitmap6.GetSafeHandle();
    picC6.SetBitmap(hBmp6);

    bitmap7.LoadBitmap(IDB_BITMAP10+array[6]);
    hBmp7 = (HBITMAP)bitmap7.GetSafeHandle();
    picC7.SetBitmap(hBmp7);

    bitmap8.LoadBitmap(IDB_BITMAP10+array[7]);
    hBmp8 = (HBITMAP)bitmap8.GetSafeHandle();
    picC8.SetBitmap(hBmp8);

    bitmap9.LoadBitmap(IDB_BITMAP10+array[8]);
    hBmp9 = (HBITMAP)bitmap9.GetSafeHandle();
    picC9.SetBitmap(hBmp9);
}


void CEightFigureDlg::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码
    btnSearch.EnableWindow(FALSE);
    SearchCore *search;
    switch (comboType.GetCurSel())
    {
    case(0):
        search = new DFS(start,target);
        break;
    case(1):
        search = new WFS(start,target);
        break;
    default:
        btnSearch.EnableWindow(TRUE);
        return;
    }
    if (search->Search())
    {
        search->GetPath(path);
        SetPicA(path[0]);
        cur = 0;
        CString str;
        str.Format(_T("%d"),path.size());
        editTot.SetWindowTextW(str);
        str.Format(_T("%d"),cur+1);
        editCur.SetWindowTextW(str);
        btnSearch.EnableWindow(TRUE);
        btnForward.EnableWindow(FALSE);
        btnNext.EnableWindow(TRUE);
    }
    else
    {
        MessageBox(_T("无解"), _T("出错啦"), MB_OK | MB_ICONINFORMATION);
        btnSearch.EnableWindow(FALSE);
        btnForward.EnableWindow(FALSE);
    }
}

void CEightFigureDlg::OnBnClickedButtonForward()
{
    // TODO: 在此添加控件通知处理程序代码
    CString str;
    SetPicA(path[--cur]);
    str.Format(_T("%d"),cur+1);
    editCur.SetWindowTextW(str);
    if (cur == 0)
    {
        btnForward.EnableWindow(FALSE);
    }
    if (cur < (int)path.size())
    {
        btnNext.EnableWindow(TRUE);
    }
}

void CEightFigureDlg::OnBnClickedButtonNext()
{
    // TODO: 在此添加控件通知处理程序代码
    CString str;
    SetPicA(path[++cur]);
    str.Format(_T("%d"),cur+1);
    editCur.SetWindowTextW(str);
    if (cur >= 1)
    {
        btnForward.EnableWindow(TRUE);
    }
    if (cur == path.size()-1)
    {
        btnNext.EnableWindow(FALSE);
    }
}


void CEightFigureDlg::OnBnClickedButtonSetStart()
{
    // TODO: 在此添加控件通知处理程序代码
    DlgSet dlg;
    if (dlg.DoModal() == IDOK)
    {
        start = dlg.start;
        target = dlg.target;
        SetPicB(start);
        SetPicC(target);
    }
}


void CEightFigureDlg::OnEnChangeEditCur()
{
    // TODO:  如果该控件是 RICHEDIT 控件，它将不
    // 发送此通知，除非重写 CDialogEx::OnInitDialog()
    // 函数并调用 CRichEditCtrl().SetEventMask()，
    // 同时将 ENM_CHANGE 标志“或”运算到掩码中。

    // TODO:  在此添加控件通知处理程序代码

}
