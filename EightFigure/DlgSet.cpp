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
{

}

DlgSet::~DlgSet()
{
}

void DlgSet::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgSet, CDialogEx)
END_MESSAGE_MAP()


// DlgSet 消息处理程序
