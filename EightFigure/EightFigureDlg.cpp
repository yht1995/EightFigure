
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
    , i_editCur(0)
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
    DDX_Control(pDX, IDC_EDIT_TMIE, editTime);
    DDX_Text(pDX, IDC_EDIT_CUR, i_editCur);
    DDX_Control(pDX, IDC_SLIDER1, sliderSpeed);
    DDX_Control(pDX, IDC_BUTTON_PLAY, btnPlay);
    DDX_Control(pDX, IDC_SLIDER_POS, sliderPos);
    DDX_Control(pDX, IDC_EDIT_STATE, editState);
    DDX_Control(pDX, IDC_STATIC_DEPTH, textDepth);
    DDX_Control(pDX, IDC_STATIC_FUNC, textFunc);
    DDX_Control(pDX, IDC_EDIT_DEPTH, editDepth);
    DDX_Control(pDX, IDC_COMBO_FUNC, comboFunc);
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
    ON_BN_CLICKED(IDC_BUTTON_RAND, &CEightFigureDlg::OnBnClickedButtonRand)
    ON_BN_CLICKED(IDC_BUTTON_PLAY, &CEightFigureDlg::OnBnClickedButtonPlay)
    ON_WM_TIMER()
    ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_POS, &CEightFigureDlg::OnNMCustomdrawSliderPos)
    ON_CBN_SELCHANGE(IDC_COMBO_TYPE, &CEightFigureDlg::OnCbnSelchangeComboType)
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
    comboType.AddString(_T("BFS"));
    comboType.AddString(_T("A*"));
    comboType.SetCurSel(0);
    comboFunc.AddString(_T("不在位数"));
    comboFunc.AddString(_T("曼哈顿距离"));
    comboFunc.SetCurSel(0);
    btnNext.EnableWindow(FALSE);
    btnForward.EnableWindow(FALSE);
    sliderSpeed.SetRange(0,100);
    sliderSpeed.SetPos(70);
    textDepth.EnableWindow(FALSE);
    editDepth.EnableWindow(FALSE);
    textFunc.EnableWindow(TRUE);
    comboFunc.EnableWindow(TRUE);
    editDepth.SetWindowTextW(_T("0"));
    srand((unsigned int)time(NULL));
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
        static bool init = true;
        if(init)
        {
            char data1[9] = {6,5,3,8,2,0,4,1,7};
            char data2[9] = {5,1,0,6,4,8,2,7,3};
            EightFigureState s(data1);
            start.SetDataArray(data1);
            target.SetDataArray(data2);

            SetPicA(s);
            SetPicB(start);
            SetPicC(target);
            init = false;
        }
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
    static char last[9] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
    CStatic *pic[9] = {&picA1,&picA2,&picA3,&picA4,&picA5,&picA6,&picA7,&picA8,&picA9};
    char array[9];
    state.GetDataArray(array);
    for (int i = 0;i<9;i++)
    {
        if (array[i] != last[i])
        {
            CBitmap bitmap;
            HBITMAP hBmp;
            bitmap.LoadBitmap(IDB_BITMAP1+array[i]);
            hBmp = (HBITMAP)bitmap.GetSafeHandle();
            pic[i]->SetBitmap(hBmp);
            last[i] = array[i];
        }
    }
}

void CEightFigureDlg::SetPicB(EightFigureState state)
{

    CStatic *pic[9] = {&picB1,&picB2,&picB3,&picB4,&picB5,&picB6,&picB7,&picB8,&picB9};
    char array[9];
    state.GetDataArray(array);
    for (int i = 0;i<9;i++)
    {
        CBitmap bitmap;
        HBITMAP hBmp;
        bitmap.LoadBitmap(IDB_BITMAP10+array[i]);
        hBmp = (HBITMAP)bitmap.GetSafeHandle();
        pic[i]->SetBitmap(hBmp);
    }
}

void CEightFigureDlg::SetPicC(EightFigureState state)
{
    CStatic *pic[9] = {&picC1,&picC2,&picC3,&picC4,&picC5,&picC6,&picC7,&picC8,&picC9};
    char array[9];
    state.GetDataArray(array);
    for (int i = 0;i<9;i++)
    {
        CBitmap bitmap;
        HBITMAP hBmp;
        bitmap.LoadBitmap(IDB_BITMAP10+array[i]);
        hBmp = (HBITMAP)bitmap.GetSafeHandle();
        pic[i]->SetBitmap(hBmp);
    }
}


void CEightFigureDlg::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码
    isPlay = false;
    KillTimer(1);
    btnPlay.EnableWindow(FALSE);
    btnSearch.EnableWindow(FALSE);
    SearchCore *search;
    CString dep,str;
    switch (comboType.GetCurSel())
    {
    case(2):
        editDepth.GetWindowTextW(dep);
        search = new DFS(start,target,_ttoi(dep));
        break;
    case(1):
        search = new BFS(start,target);
        break;
    case(0):
        search = new AStar(start,target,comboFunc.GetCurSel());
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
        str.Format(_T("%d"),path.size());
        editTot.SetWindowTextW(str);
        str.Format(_T("%d"),cur+1);
        editCur.SetWindowTextW(str);
        str.Format(_T("%d(ms)"),search->GetTime());
        editTime.SetWindowTextW(str);
        str.Format(_T("%d"),search->GetStateCount());
        editState.SetWindowTextW(str);
        sliderPos.EnableWindow(TRUE);
        sliderPos.SetRange(0,path.size()-1);
        btnSearch.EnableWindow(TRUE);
        btnForward.EnableWindow(FALSE);
        btnNext.EnableWindow(TRUE);
        btnPlay.EnableWindow(TRUE);
        btnPlay.SetWindowTextW(_T("播放"));
    }
    else
    {
        path.clear();
        MessageBox(_T("不行啊，求不出解"), _T("出错啦"), MB_OK | MB_ICONINFORMATION);
        btnSearch.EnableWindow(TRUE);
        btnNext.EnableWindow(FALSE);
        btnForward.EnableWindow(FALSE);
        btnNext.EnableWindow(FALSE);
        btnPlay.EnableWindow(FALSE);
        sliderPos.EnableWindow(FALSE);
        str.Format(_T("%d"),0);
        editTot.SetWindowTextW(str);
        str.Format(_T("%d"),0);
        editCur.SetWindowTextW(str);
        str.Format(_T("%d(ms)"),search->GetTime());
        editTime.SetWindowTextW(str);
        str.Format(_T("%d"),search->GetStateCount());
    }
}

void CEightFigureDlg::OnBnClickedButtonForward()
{
    // TODO: 在此添加控件通知处理程序代码
    CString str;
    SetPicA(path[--cur]);
    str.Format(_T("%d"),cur+1);
    editCur.SetWindowTextW(str);
    sliderPos.SetPos(cur);
}

void CEightFigureDlg::OnBnClickedButtonNext()
{
    // TODO: 在此添加控件通知处理程序代码
    CString str;
    SetPicA(path[++cur]);
    str.Format(_T("%d"),cur+1);
    editCur.SetWindowTextW(str);
    sliderPos.SetPos(cur);
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
    UpdateData(TRUE);
    if (i_editCur>0 && i_editCur <= (int)path.size())
    {
        cur = i_editCur - 1;
        SetPicA(path[cur]);
        sliderPos.SetPos(cur);
    }
    UpdateData(FALSE);
}


void CEightFigureDlg::OnBnClickedButtonRand()
{
    // TODO: 在此添加控件通知处理程序代码
    std::vector<char> vstart,vtarget;
    char startArray[9],targetArray[9];
    for (char i = 0;i<9;i++)
    {
        vstart.push_back(i);
        vtarget.push_back(i);
    }
    do 
    {
        random_shuffle(vstart.begin(),vstart.end());
        random_shuffle(vtarget.begin(),vtarget.end());
        for (int i = 0;i<9;i++)
        {
            startArray[i] = vstart[i];
            targetArray[i] = vtarget[i];
        }
        start.SetDataArray(startArray);
        target.SetDataArray(targetArray);
    }while(!start.CanSolve(target));
    SetPicB(start);
    SetPicC(target);
}


void CEightFigureDlg::OnBnClickedButtonPlay()
{
    // TODO: 在此添加控件通知处理程序代码
    if (path.empty())
    {
        return;
    }
    if (cur == path.size()-1)
    {
        isPlay = false;
        KillTimer(1);
        btnPlay.SetWindowTextW(_T("播放"));
        cur = 0;
        SetPicA(path[cur]);
        CString str;
        str.Format(_T("%d"),cur+1);
        sliderPos.SetPos(cur);
        return;
    }
    if (isPlay)
    {
        isPlay = false;
        KillTimer(1);
        btnPlay.SetWindowTextW(_T("播放"));
    }
    else
    {
        isPlay = true;
        sliderSpeed.SetRange(0,100);
        sliderSpeed.GetPos();

        timeDelta = (100-sliderSpeed.GetPos())*10;
        SetTimer(1, timeDelta, NULL);
        btnPlay.SetWindowTextW(_T("停止"));
    }
}


void CEightFigureDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 在此添加消息处理程序代码和/或调用默认值
    switch (nIDEvent)
    {
    case (1):
        if (cur>=0&&cur<(int)path.size()-1)
        {
            cur++;
            SetPicA(path[cur]);
            CString str;
            str.Format(_T("%d"),cur+1);
            editCur.SetWindowTextW(str);
            sliderPos.SetPos(cur);
            KillTimer(1);
            timeDelta = (100-sliderSpeed.GetPos())*10;
            SetTimer(1, timeDelta, NULL);
        }
        if (cur == path.size() - 1)
        {
            isPlay = false;
            btnPlay.SetWindowTextW(_T("回到开始"));
            KillTimer(1);
        }
        break;
    default:
        break;
    }
    CDialogEx::OnTimer(nIDEvent);
}


void CEightFigureDlg::OnNMCustomdrawSliderPos(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
    // TODO: 在此添加控件通知处理程序代码
    if (!path.empty())
    {
        cur  = sliderPos.GetPos();
        SetPicA(path[cur]);
        CString str;
        str.Format(_T("%d"),cur+1);
        editCur.SetWindowTextW(str);
        if (cur > 0)
            btnForward.EnableWindow(TRUE);
        else
            btnForward.EnableWindow(FALSE);
        if (cur < (int)path.size()-1)
            btnNext.EnableWindow(TRUE);
        else
            btnNext.EnableWindow(FALSE);
        if (cur == path.size()-1)
        {
            btnPlay.SetWindowTextW(_T("回到开始"));
        }
        else
        {
            if (isPlay)
            {
                btnPlay.SetWindowTextW(_T("停止"));
            }
            else
            {
                btnPlay.SetWindowTextW(_T("播放"));
            }
        }
    }
    *pResult = 0;
}


void CEightFigureDlg::OnCbnSelchangeComboType()
{
    // TODO: 在此添加控件通知处理程序代码
    switch (comboType.GetCurSel())
    {
    case(0):
        textDepth.EnableWindow(FALSE);
        editDepth.EnableWindow(FALSE);
        textFunc.EnableWindow(TRUE);
        comboFunc.EnableWindow(TRUE);
        break;
    case(1):
        textDepth.EnableWindow(FALSE);
        editDepth.EnableWindow(FALSE);
        textFunc.EnableWindow(FALSE);
        comboFunc.EnableWindow(FALSE);
        break;
    case(2):
        textDepth.EnableWindow(TRUE);
        editDepth.EnableWindow(TRUE);
        textFunc.EnableWindow(FALSE);
        comboFunc.EnableWindow(FALSE);
        break;
    default:
        break;
    }
}
