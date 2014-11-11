
// EightFigureDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "EightFigureState.h"
#include "DFS.h"
#include "WFS.h"
#include "AStar.h"
#include "DlgSet.h"

// CEightFigureDlg 对话框
class CEightFigureDlg : public CDialogEx
{
// 构造
public:
	CEightFigureDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_EIGHTFIGURE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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

    int cur;

    std::vector<EightFigureState> path;

    void SetPicA(EightFigureState state);
    void SetPicB(EightFigureState state);
    void SetPicC(EightFigureState state);
public:
    afx_msg void OnBnClickedButtonForward();
    afx_msg void OnBnClickedOk();


private:
    CButton btnForward;
    CButton btnNext;
public:
    afx_msg void OnBnClickedButtonNext();
    afx_msg void OnBnClickedButtonSetStart();
    afx_msg void OnEnChangeEditCur();
private:
    CEdit editTime;
public:
    afx_msg void OnBnClickedButtonRand();
};
