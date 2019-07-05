
// updateToolDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include <vector>

using namespace std;

class CupdateToolDlgAutoProxy;


// CupdateToolDlg 对话框
class CupdateToolDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CupdateToolDlg);
	friend class CupdateToolDlgAutoProxy;

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
	// 主程序根目录
	CEdit m_MainExeRootPath;

	// 清单文件输出目录
	CEdit m_OutPathEdit;

	// 生成按钮
	CButton m_CrateBtn;

	// 当前清单中的文件
	CListCtrl m_ListCtrl;

	std::vector<CString> m_PathVect;

	//输出文件路径
	CString m_OutPathStr;

	void PushFilePath(std::vector<CString>& vFilePathList, CString strDir);

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	// 远程project.manifest地址
	CEdit m_ProjectUrl;
	// 远程vectsion.manifest地址
	CEdit m_VersionUrl;
	// 远程安装包地址
	CEdit m_PackUrl;
};
