// UpdateData.cpp : 实现文件
//

#include "stdafx.h"
#include "updateTool.h"
#include "UpdateData.h"
#include "afxdialogex.h"


// UpdateData 对话框

IMPLEMENT_DYNAMIC(UpdateDataDlg, CDialogEx)

UpdateDataDlg::UpdateDataDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_UPDATE_DATA_DLG, pParent)
{

}

UpdateDataDlg::~UpdateDataDlg()
{
}

void UpdateDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UpdateDataDlg, CDialogEx)
END_MESSAGE_MAP()


// UpdateData 消息处理程序


BOOL UpdateDataDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
