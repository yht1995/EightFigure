#pragma once


// DlgSet �Ի���

class DlgSet : public CDialogEx
{
	DECLARE_DYNAMIC(DlgSet)

public:
	DlgSet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgSet();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
