
// EightFigureDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "EightFigureState.h"
#include "DFS.h"
#include "BFS.h"
#include "AStar.h"
#include "DlgSet.h"
#include "afxcmn.h"

// CEightFigureDlg �Ի���
class CEightFigureDlg : public CDialogEx
{
// ����
public:
	CEightFigureDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_EIGHTFIGURE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
    CStatic picA1;
    CStatic picA2;
    CStatic picA3;
    CStatic picA4;
    CStatic picA5;
    CStatic picA6;
    CStatic picA7;
    CStatic picA8;
    CStatic picA9;
    CStatic picB1;
    CStatic picB2;
    CStatic picB3;
    CStatic picB4;
    CStatic picB5;
    CStatic picB6;
    CStatic picB7;
    CStatic picB8;
    CStatic picB9;
    CStatic picC1;
    CStatic picC2;
    CStatic picC3;
    CStatic picC4;
    CStatic picC5;
    CStatic picC6;
    CStatic picC7;
    CStatic picC8;
    CStatic picC9;

    CButton btnSearch;
    CEdit editCur;
    CEdit editTot;
    CComboBox comboType;

    EightFigureState picA;
    EightFigureState start;
    EightFigureState target;

    CButton btnForward;
    CButton btnNext;
    CEdit editTime;
    CSliderCtrl sliderSpeed;
    CButton btnPlay;

    int cur;
    int timeDelta;
    int i_editCur;

    bool isPlay;

    std::vector<EightFigureState> path;
    void SetPicA(EightFigureState state);
    void SetPicB(EightFigureState state);
    void SetPicC(EightFigureState state);
public:
    afx_msg void OnBnClickedButtonForward();
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedButtonPlay();
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnBnClickedButtonRand();
    afx_msg void OnBnClickedButtonNext();
    afx_msg void OnBnClickedButtonSetStart();
    afx_msg void OnEnChangeEditCur();
private:
    CSliderCtrl sliderPos;
public:
    afx_msg void OnNMCustomdrawSliderPos(NMHDR *pNMHDR, LRESULT *pResult);
};
