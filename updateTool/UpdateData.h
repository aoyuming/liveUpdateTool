#pragma once
// UpdateData �Ի���

class UpdateDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UpdateDataDlg)

public:
	UpdateDataDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~UpdateDataDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VERSION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
