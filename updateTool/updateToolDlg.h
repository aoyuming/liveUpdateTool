
// updateToolDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include <vector>
#include "UpdateData.h"


using namespace std;

class CupdateToolDlgAutoProxy;


// CupdateToolDlg 对话框
class CupdateToolDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CupdateToolDlg);
	friend class CupdateToolDlgAutoProxy;

	struct Node
	{
		CString md5;
		CString fileUrl;
		unsigned long int size;//文件大小 字节
	};

// 构造
public:
	CupdateToolDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CupdateToolDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UPDATETOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	CupdateToolDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:

	//本地所有文件路径
	std::vector<CString> m_LocalAllFilePathVect;

	UpdateDataDlg* m_UpdateDataDlg;

	//输出信息
	vector<Node> m_Vect;

	void PushFilePath(std::vector<CString>& vFilePathList, CString strDir);

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg void OnBnClickedButton5();
};
