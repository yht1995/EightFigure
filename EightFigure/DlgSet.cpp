// DlgSet.cpp : 实现文件
//

#include "stdafx.h"
#include "EightFigure.h"
#include "DlgSet.h"
#include "afxdialogex.h"


// DlgSet 对话框

IMPLEMENT_DYNAMIC(DlgSet, CDialogEx)

DlgSet::DlgSet(CWnd* pParent /*=NULL*/)
	: CDialogEx(DlgSet::IDD, pParent)
    ,editS1(1)
    ,editS2(2)
    ,editS3(3)
    ,editS4(4)
    ,editS5(5)
    ,editS6(6)
    ,editS7(7)
    ,editS8(8)
    ,editS9(0)
    ,editT1(0)
    ,editT2(1)
    ,editT3(2)
    ,editT4(3)
    ,editT5(4)
    ,editT6(5)
    ,editT7(6)
    ,editT8(7)
    ,editT9(8)
{

}

DlgSet::~DlgSet()
{
}

void DlgSet::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_S1, editS1);
    DDX_Text(pDX, IDC_EDIT_S2, editS2);
    DDX_Text(pDX, IDC_EDIT_S3, editS3);
    DDX_Text(pDX, IDC_EDIT_S4, editS4);
    DDX_Text(pDX, IDC_EDIT_S5, editS5);
    DDX_Text(pDX, IDC_EDIT_S6, editS6);
    DDX_Text(pDX, IDC_EDIT_S7, editS7);
    DDX_Text(pDX, IDC_EDIT_S8, editS8);
    DDX_Text(pDX, IDC_EDIT_S9, editS9);
    DDX_Text(pDX, IDC_EDIT_T1, editT1);
    DDX_Text(pDX, IDC_EDIT_T2, editT2);
    DDX_Text(pDX, IDC_EDIT_T3, editT3);
    DDX_Text(pDX, IDC_EDIT_T4, editT4);
    DDX_Text(pDX, IDC_EDIT_T5, editT5);
    DDX_Text(pDX, IDC_EDIT_T6, editT6);
    DDX_Text(pDX, IDC_EDIT_T7, editT7);
    DDX_Text(pDX, IDC_EDIT_T8, editT8);
    DDX_Text(pDX, IDC_EDIT_T9, editT9);
}


BEGIN_MESSAGE_MAP(DlgSet, CDialogEx)
    ON_BN_CLICKED(IDOK, &DlgSet::OnBnClickedOk)
END_MESSAGE_MAP()


// DlgSet 消息处理程序


void DlgSet::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码
    UpdateData(TRUE);
    char startArray[9] = { 
        editS1,
        editS2,
        editS3,
        editS4,
        editS5,
        editS6,
        editS7,
        editS8,
        editS9};
    char targetArray[9] = {
        editT1,
        editT2,
        editT3,
        editT4,
        editT5,
        editT6,
        editT7,
        editT8,
        editT9};
    if (start.SetDataArray(startArray) && target.SetDataArray(targetArray))
    {
        if (start.CanSolve(target))
        {
            CDialogEx::OnOK();
        }
        else
        {
            MessageBox(_T("无解"), _T("出错啦"), MB_OK | MB_ICONINFORMATION);
        }
    }
    else
    {
        MessageBox(_T("输入出错了"), _T("出错啦"), MB_OK | MB_ICONWARNING);
    }
}
