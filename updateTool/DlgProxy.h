
// DlgProxy.h: ͷ�ļ�
//

#pragma once

class CupdateToolDlg;


// CupdateToolDlgAutoProxy ����Ŀ��

class CupdateToolDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CupdateToolDlgAutoProxy)

	CupdateToolDlgAutoProxy();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��

// ����
public:
	CupdateToolDlg* m_pDialog;

// ����
public:

// ��д
	public:
	virtual void OnFinalRelease();

// ʵ��
protected:
	virtual ~CupdateToolDlgAutoProxy();

	// ���ɵ���Ϣӳ�亯��

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CupdateToolDlgAutoProxy)

	// ���ɵ� OLE ����ӳ�亯��

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

