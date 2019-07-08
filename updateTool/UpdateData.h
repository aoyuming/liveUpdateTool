#pragma once
// UpdateData 对话框

class UpdateDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UpdateDataDlg)

public:
	UpdateDataDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~UpdateDataDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VERSION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
