#pragma once
#include "EightFigureState.h"

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
public:
    afx_msg void OnBnClickedOk();

    EightFigureState start;
    EightFigureState target;

private:
    int editS1;
    int editS2;
    int editS3;
    int editS4;
    int editS5;
    int editS6;
    int editS7;
    int editS8;
    int editS9;
    int editT1;
    int editT2;
    int editT3;
    int editT4;
    int editT5;
    int editT6;
    int editT7;
    int editT8;
    int editT9;
};
