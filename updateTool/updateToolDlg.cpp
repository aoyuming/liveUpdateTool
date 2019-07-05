
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
	DDX_Control(pDX, IDC_EDIT1, m_MainExeRootPath);
	DDX_Control(pDX, IDC_EDIT2, m_OutPathEdit);
	DDX_Control(pDX, IDC_BUTTON3, m_CrateBtn);
	DDX_Control(pDX, IDC_LIST3, m_ListCtrl);
	DDX_Control(pDX, IDC_EDIT3, m_ProjectUrl);
	DDX_Control(pDX, IDC_EDIT4, m_VersionUrl);
	DDX_Control(pDX, IDC_EDIT5, m_PackUrl);
}

BEGIN_MESSAGE_MAP(CupdateToolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CupdateToolDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CupdateToolDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CupdateToolDlg::OnBnClickedButton3)
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

	m_MainExeRootPath.EnableWindow(FALSE);
	m_OutPathEdit.EnableWindow(FALSE);

	CRect rect;
	m_ListCtrl.GetWindowRect(&rect);
	m_ListCtrl.InsertColumn(0, _T("当前清单文件路径                 注：生成后的文件路径是相对于主程序的路径"), LVCFMT_LEFT, rect.Width());

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
		//递归遍历szpath
		m_PathVect.clear();
		PushFilePath(m_PathVect, szPath);

		//设置edit为选中的文件夹
		m_MainExeRootPath.SetWindowText(szPath);
		m_ListCtrl.DeleteAllItems();
		for (int i = 0; i < (int)m_PathVect.size(); ++i)
			m_ListCtrl.InsertItem(i, m_PathVect[i]);
	}
	else
		AfxMessageBox("无效的目录，请重新选择");
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
		m_OutPathStr = szPath;
		m_OutPathStr += _T("\\project.manifest");
		m_OutPathEdit.SetWindowText(m_OutPathStr);
	}
	else
		AfxMessageBox("无效的目录，请重新选择");
}

//生成按钮点击
void CupdateToolDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_PathVect.size() == 0)
	{
		MessageBox(_T("生成失败"));
		return;
	}

	struct Node
	{
		CString md5;
		CString fileUrl;
	};

	//生成相对于主程序的清单路径
	vector<Node> vect;
	CString mianPath, proUrl, verUrl, packUrl;
	m_ProjectUrl.GetWindowText(proUrl);
	m_VersionUrl.GetWindowText(verUrl);
	m_PackUrl.GetWindowText(packUrl);
	m_MainExeRootPath.GetWindowText(mianPath);

	if (proUrl == _T("") || verUrl == _T("") || mianPath == _T("") || packUrl == _T(""))
	{
		MessageBox(_T("生成失败，请填写正确的信息"));
		return;
	}

	for (int i = 0; i < (int)m_PathVect.size(); ++i)
	{
		Node node;
		int count = m_PathVect[i].GetLength() - mianPath.GetLength();
		node.fileUrl = m_PathVect[i].Right(count);
		node.md5 = getFileMD5(m_PathVect[i].GetBuffer()).c_str();
		vect.push_back(node);
	}

	CString allData, temp;
	temp.Format(_T("%d\r\n"), vect.size());
	allData += CString(_T("远程packageUrl地址:")) + packUrl;
	allData += CString(_T("远程project.manifest地址:")) + proUrl + _T("\r\n");
	allData += CString(_T("远程version.manifest地址:")) + verUrl + _T("\r\n");
	allData += CString(_T("清单文件数量:")) + temp;

	//写入文件
	for (int i = 0; i < (int)vect.size(); ++i)
	{
		temp.Format(_T("文件url:%s\r\nmd5:%s\r\n"), vect[i].fileUrl, vect[i].md5);
		allData += temp;
	}

	FILE* pf = NULL;
	fopen_s(&pf, m_OutPathStr, "wb");
	if (!pf)
		return;

	fwrite(allData.GetBuffer(), allData.GetLength(), 1, pf);
	fclose(pf);
	MessageBox(_T("写入成功！"));
}
