// UpdateData.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "updateTool.h"
#include "UpdateData.h"
#include "afxdialogex.h"


// UpdateData �Ի���

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


// UpdateData ��Ϣ�������


BOOL UpdateDataDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
