
// updateToolDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "updateTool.h"
#include "updateToolDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include "md5file.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CupdateToolDlg 对话框


IMPLEMENT_DYNAMIC(CupdateToolDlg, CDialogEx);

CupdateToolDlg::CupdateToolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_UPDATETOOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CupdateToolDlg::~CupdateToolDlg()
{
	// 如果该对话框有自动化代理，则
	//  将此代理指向该对话框的后向指针设置为 NULL，以便
	//  此代理知道该对话框已被删除。
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CupdateToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CupdateToolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CupdateToolDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CupdateToolDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CupdateToolDlg::OnBnClickedButton3)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON5, &CupdateToolDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CupdateToolDlg 消息处理程序

BOOL CupdateToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT8)->EnableWindow(FALSE);

	CRect rect;
	GetDlgItem(IDC_LIST3)->GetWindowRect(&rect);
	((CListCtrl*)GetDlgItem(IDC_LIST3))->InsertColumn(1, _T("相对于主程序的路径"), LVCFMT_LEFT, rect.Width() * 0.55);
	((CListCtrl*)GetDlgItem(IDC_LIST3))->InsertColumn(2, _T("MD5"), LVCFMT_LEFT, rect.Width() * 0.3);
	((CListCtrl*)GetDlgItem(IDC_LIST3))->InsertColumn(3, _T("文件大小(字节)"), LVCFMT_LEFT, rect.Width() * 0.147);

	SetTimer(0, 30, NULL);

	m_UpdateDataDlg = NULL;

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CupdateToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CupdateToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CupdateToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 当用户关闭 UI 时，如果控制器仍保持着它的某个
//  对象，则自动化服务器不应退出。  这些
//  消息处理程序确保如下情形: 如果代理仍在使用，
//  则将隐藏 UI；但是在关闭对话框时，
//  对话框仍然会保留在那里。

void CupdateToolDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CupdateToolDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CupdateToolDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CupdateToolDlg::CanExit()
{
	// 如果代理对象仍保留在那里，则自动化
	//  控制器仍会保持此应用程序。
	//  使对话框保留在那里，但将其 UI 隐藏起来。
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CupdateToolDlg::PushFilePath(std::vector<CString>& vFilePathList, CString strDir)
{
	CFileFind finder;
	BOOL isNotEmpty = finder.FindFile(strDir + _T("*.*"));//总文件夹，开始遍历 
	while (isNotEmpty)
	{
		isNotEmpty = finder.FindNextFile();//查找文件 
		CString filename = finder.GetFilePath();//获取文件的路径，可能是文件夹，可能是文件 
		if (!(finder.IsDirectory()))
		{
			//如果是文件则加入文件列表 
			vFilePathList.push_back(filename);//将一个文件路径加入容器 
		}
		else 
		{
			//递归遍历用户文件夹，跳过非用户文件夹 
			if (!(finder.IsDots() || finder.IsHidden() || finder.IsSystem() || finder.IsTemporary() || finder.IsReadOnly()))
			{
				PushFilePath(vFilePathList,filename + _T("/"));
			}
		}
	}
}

//根目录选择按钮点击
void CupdateToolDlg::OnBnClickedButton1()
{
	CFileDialog fileDlg(true, _T("exe"), _T("*.exe"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("exe Files (*.exe)|*.exe|All File (*.*)|*.*||"), NULL);
	if (fileDlg.DoModal() == IDOK)    //弹出对话框  
	{
		CString path = fileDlg.GetPathName();//得到完整的文件名和目录名拓展名
		CString mainRoutineName = fileDlg.GetFileName();
		int count = path.GetLength() - mainRoutineName.GetLength();
		m_Vect.clear();
		GetDlgItem(IDC_EDIT1)->SetWindowText(path.Left(count));//将主程序目录显示
		GetDlgItem(IDC_EDIT7)->SetWindowText(mainRoutineName);
		GetDlgItem(IDC_EDIT2)->SetWindowText(path.Left(count) + _T("project.manifest"));
		GetDlgItem(IDC_EDIT8)->SetWindowText(path.Left(count) + _T("version.manifest"));

		//递归遍历szpath
		m_LocalAllFilePathVect.clear();
		PushFilePath(m_LocalAllFilePathVect, path.Left(count));

		//设置edit为选中的文件夹
		GetDlgItem(IDC_EDIT1)->SetWindowText(path.Left(count));
		((CListCtrl*)GetDlgItem(IDC_LIST3))->DeleteAllItems();

		CString mianPath = path.Left(count);
		for (int i = 0; i < (int)m_LocalAllFilePathVect.size(); ++i)
		{
			Node node;
			int count = m_LocalAllFilePathVect[i].GetLength() - mianPath.GetLength();
			node.fileUrl = m_LocalAllFilePathVect[i].Right(count + 1);
			node.md5 = getFileMD5(m_LocalAllFilePathVect[i].GetBuffer()).c_str();

			CFile file;
			if (!file.Open(m_LocalAllFilePathVect[i], CFile::modeRead))
			{
				CString hint = m_LocalAllFilePathVect[i] + _T("打开失败");
				MessageBox(hint);
				return;
			}
			node.size = file.GetLength();
			m_Vect.push_back(node);
			file.Close();
		}

		//显示出来
		for (int i = 0; i < (int)m_Vect.size(); ++i)
		{
			CString size;
			size.Format(_T("%d"), m_Vect[i].size);
			int c = m_LocalAllFilePathVect[i].GetLength() - mianPath.GetLength();
			int row = ((CListCtrl*)GetDlgItem(IDC_LIST3))->InsertItem(i, m_Vect[i].fileUrl);
			((CListCtrl*)GetDlgItem(IDC_LIST3))->SetItemText(row, 1, m_Vect[i].md5);
			((CListCtrl*)GetDlgItem(IDC_LIST3))->SetItemText(row, 2, size);
		}
	}
}

//输出目录选择按钮点击
void CupdateToolDlg::OnBnClickedButton2()
{
	char szPath[MAX_PATH];     //存放选择的目录路径 
	ZeroMemory(szPath, sizeof(szPath));
	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	bi.lpszTitle = "请选择需要打包的目录：";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;

	//弹出选择目录对话框
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);
	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		CString temp;
		temp = szPath;
		temp += _T("\\project.manifest");
		GetDlgItem(IDC_EDIT2)->SetWindowText(temp);
	}
	else
		AfxMessageBox("无效的目录，请重新选择");
}

//生成按钮点击
void CupdateToolDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_LocalAllFilePathVect.size() == 0)
	{
		MessageBox(_T("生成失败"));
		return;
	}

	//生成相对于主程序的清单路径
	CString mianPath, proUrl, verUrl, packUrl, name, LaunchParameters, version, proUotput;
	GetDlgItem(IDC_EDIT3)->GetWindowText(proUrl);
	GetDlgItem(IDC_EDIT4)->GetWindowText(verUrl);
	GetDlgItem(IDC_EDIT5)->GetWindowText(packUrl);
	GetDlgItem(IDC_EDIT1)->GetWindowText(mianPath);
	GetDlgItem(IDC_EDIT6)->GetWindowText(LaunchParameters);
	GetDlgItem(IDC_EDIT7)->GetWindowText(name);
	GetDlgItem(IDC_EDIT9)->GetWindowText(version);
	GetDlgItem(IDC_EDIT2)->GetWindowText(proUotput);

	if (LaunchParameters == _T(""))
		LaunchParameters = _T("null");

	CString allData, temp;
	temp.Format(_T("%d\r\n"), m_LocalAllFilePathVect.size());
	allData += CString(_T("远程packageUrl地址:")) + packUrl + _T("\r\n");
	allData += CString(_T("远程project.manifest地址:")) + proUrl + _T("\r\n");
	allData += CString(_T("远程version.manifest地址:")) + verUrl + _T("\r\n");
	allData += CString(_T("主程序名字:")) + name + _T("\r\n");
	allData += CString(_T("启动参数:")) + LaunchParameters + _T("\r\n");
	allData += CString(_T("清单文件数量:")) + temp;

	//写入文件
	for (int i = 0; i < (int)m_Vect.size(); ++i)
	{
		temp.Format(_T("文件url:%s\r\nMd5:%s\r\nSize:%d\r\n"), m_Vect[i].fileUrl, m_Vect[i].md5, m_Vect[i].size);
		allData += temp;
	}

	FILE* pf = NULL;
	fopen_s(&pf, proUotput, "wb");
	if (!pf)
		return;

	fwrite(allData.GetBuffer(), allData.GetLength(), 1, pf);
	fclose(pf);

	//写入version.manifest
	CString verOouputPath;
	GetDlgItem(IDC_EDIT8)->GetWindowText(verOouputPath);

	pf = NULL;
	fopen_s(&pf, verOouputPath, "wb");
	if (!pf)
		return;

	m_UpdateDataDlg->GetDlgItem(IDC_EDIT1)->GetWindowText(temp);
	allData.Format(_T("版本:%s\r\n"), version);
	allData += temp;
	fwrite(allData.GetBuffer(), allData.GetLength(), 1, pf);
	fclose(pf);
	MessageBox(_T("写入成功！"));
}


void CupdateToolDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 0)
	{
		BOOL enable = TRUE;
		CString mianPath, proUrl, verUrl, packUrl, name, LaunchParameters, outPut, version, updateData = "";
		GetDlgItem(IDC_EDIT3)->GetWindowText(proUrl);
		GetDlgItem(IDC_EDIT4)->GetWindowText(verUrl);
		GetDlgItem(IDC_EDIT5)->GetWindowText(packUrl);
		GetDlgItem(IDC_EDIT1)->GetWindowText(mianPath);
		GetDlgItem(IDC_EDIT6)->GetWindowText(LaunchParameters);
		GetDlgItem(IDC_EDIT7)->GetWindowText(name);
		GetDlgItem(IDC_EDIT2)->GetWindowText(outPut);
		GetDlgItem(IDC_EDIT9)->GetWindowText(version);
		if (m_UpdateDataDlg)
			m_UpdateDataDlg->GetDlgItem(IDC_EDIT1)->GetWindowText(updateData);
		if (proUrl == _T("") || verUrl == _T("") || outPut ==  _T("")
			|| mianPath == _T("") || packUrl == _T("") 
			|| version == _T("") || updateData == _T("")
			|| (name == _T("") && LaunchParameters == _T("")))
		{
			enable = FALSE;
		}
		GetDlgItem(IDC_BUTTON3)->EnableWindow(enable);
	}

	CDialogEx::OnTimer(nIDEvent);
}


//配置版本变更信息
void CupdateToolDlg::OnBnClickedButton5()
{
	if (!m_UpdateDataDlg)
	{
		m_UpdateDataDlg = new UpdateDataDlg;
		m_UpdateDataDlg->Create(IDD_UPDATE_DATA_DLG);
	}

	m_UpdateDataDlg->ShowWindow(SW_SHOW);
}
