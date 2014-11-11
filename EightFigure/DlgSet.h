#pragma once


// DlgSet 对话框

class DlgSet : public CDialogEx
{
	DECLARE_DYNAMIC(DlgSet)

public:
	DlgSet(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DlgSet();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
