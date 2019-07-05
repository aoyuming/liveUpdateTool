
// DlgProxy.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "updateTool.h"
#include "DlgProxy.h"
#include "updateToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CupdateToolDlgAutoProxy

IMPLEMENT_DYNCREATE(CupdateToolDlgAutoProxy, CCmdTarget)

CupdateToolDlgAutoProxy::CupdateToolDlgAutoProxy()
{
	EnableAutomation();
	
	// ΪʹӦ�ó������Զ��������ڻ״̬ʱһֱ���� 
	//	���У����캯������ AfxOleLockApp��
	AfxOleLockApp();

	// ͨ��Ӧ�ó����������ָ��
	//  �����ʶԻ���  ���ô�����ڲ�ָ��
	//  ָ��Ի��򣬲����öԻ���ĺ���ָ��ָ��
	//  �ô���
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CupdateToolDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CupdateToolDlg)))
		{
			m_pDialog = reinterpret_cast<CupdateToolDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CupdateToolDlgAutoProxy::~CupdateToolDlgAutoProxy()
{
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	//	������������ AfxOleUnlockApp��
	//  ���������������⣬�⻹���������Ի���
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CupdateToolDlgAutoProxy::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease��  ���ཫ�Զ�
	// ɾ���ö���  �ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CupdateToolDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CupdateToolDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// ע��: ��������˶� IID_IupdateTool ��֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡�  �� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {00FCB98D-79D4-4009-A0F6-4FAA6EA0230F}
static const IID IID_IupdateTool =
{ 0xFCB98D, 0x79D4, 0x4009, { 0xA0, 0xF6, 0x4F, 0xAA, 0x6E, 0xA0, 0x23, 0xF } };

BEGIN_INTERFACE_MAP(CupdateToolDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CupdateToolDlgAutoProxy, IID_IupdateTool, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 ���ڴ���Ŀ�� StdAfx.h �ж���
// {3BF5B980-4E41-4A7A-8C49-8C0ED4C16034}
IMPLEMENT_OLECREATE2(CupdateToolDlgAutoProxy, "updateTool.Application", 0x3bf5b980, 0x4e41, 0x4a7a, 0x8c, 0x49, 0x8c, 0xe, 0xd4, 0xc1, 0x60, 0x34)


// CupdateToolDlgAutoProxy ��Ϣ�������
