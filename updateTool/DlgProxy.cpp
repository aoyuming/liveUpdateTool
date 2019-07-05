
// DlgProxy.cpp : 实现文件
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
	
	// 为使应用程序在自动化对象处于活动状态时一直保持 
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。  设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
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
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	//	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CupdateToolDlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CupdateToolDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CupdateToolDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_IupdateTool 的支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {00FCB98D-79D4-4009-A0F6-4FAA6EA0230F}
static const IID IID_IupdateTool =
{ 0xFCB98D, 0x79D4, 0x4009, { 0xA0, 0xF6, 0x4F, 0xAA, 0x6E, 0xA0, 0x23, 0xF } };

BEGIN_INTERFACE_MAP(CupdateToolDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CupdateToolDlgAutoProxy, IID_IupdateTool, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏在此项目的 StdAfx.h 中定义
// {3BF5B980-4E41-4A7A-8C49-8C0ED4C16034}
IMPLEMENT_OLECREATE2(CupdateToolDlgAutoProxy, "updateTool.Application", 0x3bf5b980, 0x4e41, 0x4a7a, 0x8c, 0x49, 0x8c, 0xe, 0xd4, 0xc1, 0x60, 0x34)


// CupdateToolDlgAutoProxy 消息处理程序
