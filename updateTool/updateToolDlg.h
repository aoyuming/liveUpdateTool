
// updateToolDlg.h : ͷ�ļ�
//

#pragma once

class CupdateToolDlgAutoProxy;


// CupdateToolDlg �Ի���
class CupdateToolDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CupdateToolDlg);
	friend class CupdateToolDlgAutoProxy;

// ����
public:
	CupdateToolDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual ~CupdateToolDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UPDATETOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	CupdateToolDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
