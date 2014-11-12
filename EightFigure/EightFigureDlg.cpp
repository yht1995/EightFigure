
// EightFigureDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "EightFigure.h"
#include "EightFigureDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CEightFigureDlg �Ի���



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
END_MESSAGE_MAP()


// CEightFigureDlg ��Ϣ�������

BOOL CEightFigureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    comboType.AddString(_T("DFS"));
    comboType.AddString(_T("BFS"));
    comboType.AddString(_T("A*"));
    comboType.SetCurSel(0);
    btnNext.EnableWindow(FALSE);
    btnForward.EnableWindow(FALSE);
    sliderSpeed.SetRange(0,100);
    sliderSpeed.SetPos(70);
    srand((unsigned int)time(NULL));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CEightFigureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CEightFigureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CEightFigureDlg::SetPicA(EightFigureState state)
{
    char array[9],curArray[9];
    state.GetDataArray(array);
    picA.GetDataArray(curArray);

    CBitmap bitmap1,bitmap2,bitmap3,bitmap4,bitmap5,bitmap6,bitmap7,bitmap8,bitmap9;
    HBITMAP hBmp1,hBmp2,hBmp3,hBmp4,hBmp5,hBmp6,hBmp7,hBmp8,hBmp9;
    if (curArray[0] != array[0])
    {
        bitmap1.LoadBitmap(IDB_BITMAP1+array[0]);
        hBmp1 = (HBITMAP)bitmap1.GetSafeHandle();
        picA1.SetBitmap(hBmp1);
    }
    if (curArray[1] != array[1])
    {
        bitmap2.LoadBitmap(IDB_BITMAP1+array[1]);
        hBmp2 = (HBITMAP)bitmap2.GetSafeHandle();
        picA2.SetBitmap(hBmp2);
    }
    if (curArray[2] != array[2])
    {
        bitmap3.LoadBitmap(IDB_BITMAP1+array[2]);
        hBmp3 = (HBITMAP)bitmap3.GetSafeHandle();
        picA3.SetBitmap(hBmp3);
    }
    if (curArray[3] != array[3])
    {
        bitmap4.LoadBitmap(IDB_BITMAP1+array[3]);
        hBmp4 = (HBITMAP)bitmap4.GetSafeHandle();
        picA4.SetBitmap(hBmp4);
    }
    if (curArray[4] != array[4])
    {
        bitmap5.LoadBitmap(IDB_BITMAP1+array[4]);
        hBmp5 = (HBITMAP)bitmap5.GetSafeHandle();
        picA5.SetBitmap(hBmp5);
    }

    if (curArray[5] != array[5])
    {
        bitmap6.LoadBitmap(IDB_BITMAP1+array[5]);
        hBmp6 = (HBITMAP)bitmap6.GetSafeHandle();
        picA6.SetBitmap(hBmp6);
    }

    if (curArray[6] != array[6])
    {
        bitmap7.LoadBitmap(IDB_BITMAP1+array[6]);
        hBmp7 = (HBITMAP)bitmap7.GetSafeHandle();
        picA7.SetBitmap(hBmp7);
    }

    if (curArray[7] != array[7])
    {
        bitmap8.LoadBitmap(IDB_BITMAP1+array[7]);
        hBmp8 = (HBITMAP)bitmap8.GetSafeHandle();
        picA8.SetBitmap(hBmp8);
    }

    if (curArray[8] != array[8])
    {
        bitmap9.LoadBitmap(IDB_BITMAP1+array[8]);
        hBmp9 = (HBITMAP)bitmap9.GetSafeHandle();
        picA9.SetBitmap(hBmp9);
    }
    picA = state;
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
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    isPlay = false;
    btnPlay.EnableWindow(FALSE);
    btnSearch.EnableWindow(FALSE);
    SearchCore *search;
    switch (comboType.GetCurSel())
    {
    case(2):
        search = new DFS(start,target);
        break;
    case(1):
        search = new BFS(start,target);
        break;
    case(0):
        search = new AStar(start,target);
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
        str.Format(_T("%d(ms)"),search->GetTime());
        sliderPos.SetRange(0,path.size()-1);
        editTime.SetWindowTextW(str);
        btnSearch.EnableWindow(TRUE);
        btnForward.EnableWindow(FALSE);
        btnNext.EnableWindow(TRUE);
        btnPlay.EnableWindow(TRUE);
        btnPlay.SetWindowTextW(_T("����"));
    }
    else
    {
        MessageBox(_T("�޽�"), _T("������"), MB_OK | MB_ICONINFORMATION);
        btnSearch.EnableWindow(TRUE);
        btnNext.EnableWindow(FALSE);
        btnForward.EnableWindow(FALSE);
    }
}

void CEightFigureDlg::OnBnClickedButtonForward()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CString str;
    SetPicA(path[--cur]);
    str.Format(_T("%d"),cur+1);
    editCur.SetWindowTextW(str);
    sliderPos.SetPos(cur);
}

void CEightFigureDlg::OnBnClickedButtonNext()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CString str;
    SetPicA(path[++cur]);
    str.Format(_T("%d"),cur+1);
    editCur.SetWindowTextW(str);
    sliderPos.SetPos(cur);
}


void CEightFigureDlg::OnBnClickedButtonSetStart()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
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
    // TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
    // ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
    // ���������� CRichEditCtrl().SetEventMask()��
    // ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

    // TODO:  �ڴ���ӿؼ�֪ͨ����������
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
    // TODO: �ڴ���ӿؼ�֪ͨ����������
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
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    if (path.empty())
    {
        return;
    }
    if (cur == path.size()-1)
    {
        isPlay = false;
        KillTimer(1);
        btnPlay.SetWindowTextW(_T("����"));
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
        btnPlay.SetWindowTextW(_T("����"));
    }
    else
    {
        isPlay = true;
        sliderSpeed.SetRange(0,100);
        sliderSpeed.GetPos();

        timeDelta = (100-sliderSpeed.GetPos())*10;
        SetTimer(1, timeDelta, NULL);
        btnPlay.SetWindowTextW(_T("ֹͣ"));
    }
}


void CEightFigureDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
            btnPlay.SetWindowTextW(_T("�ص���ʼ"));
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
    // TODO: �ڴ���ӿؼ�֪ͨ����������
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
            btnPlay.SetWindowTextW(_T("�ص���ʼ"));
        }
        else
        {
            if (isPlay)
            {
                btnPlay.SetWindowTextW(_T("ֹͣ"));
            }
            else
            {
                btnPlay.SetWindowTextW(_T("����"));
            }
        }
    }
    *pResult = 0;
}
