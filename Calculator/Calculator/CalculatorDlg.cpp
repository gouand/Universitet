
// CalculatorDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно CCalculatorDlg



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, InputString(0)
	, InputValue2(0)
	, result(_T(""))
	, Sqrtd(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, InputString);
	DDX_Text(pDX, IDC_EDIT2, InputValue2);
	DDX_Text(pDX, IDC_STATIC_RESULT, result);
	DDX_Text(pDX, IDC_SQRT, Sqrtd);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculatorDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// Обработчики сообщений CCalculatorDlg

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(true);
	CString Cfield1;
	CString Cfield2;
	double summ;
	CEdit* field1;
	CEdit* field2;
	field1 = (CEdit*)GetDlgItemTextW(IDC_EDIT1, Cfield1);
	field2 = (CEdit*)GetDlgItemTextW(IDC_EDIT2, Cfield2);
	summ = InputString + InputValue2;
	result.Format(L"%f", summ);
	UpdateData(false);
}


void CCalculatorDlg::OnBnClickedButton4()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(true);
	CString Cfield1;
	CString Cfield2;
	double summ;
	CEdit* field1;
	CEdit* field2;
	field1 = (CEdit*)GetDlgItemTextW(IDC_EDIT1, Cfield1);
	field2 = (CEdit*)GetDlgItemTextW(IDC_EDIT2, Cfield2);
	summ = InputString * InputValue2;
	result.Format(L"%f", summ);
	UpdateData(false);
}


void CCalculatorDlg::OnBnClickedButton2()
{
	UpdateData(true);
	CString Cfield1;
	CString Cfield2;
	double summ;
	CEdit* field1;
	CEdit* field2;
	field1 = (CEdit*)GetDlgItemTextW(IDC_EDIT1, Cfield1);
	field2 = (CEdit*)GetDlgItemTextW(IDC_EDIT2, Cfield2);
	summ = InputString - InputValue2;
	result.Format(L"%f", summ);
	UpdateData(false);
}


void CCalculatorDlg::OnBnClickedButton3()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(true);
	CString Cfield1;
	CString Cfield2;
	double summ;
	CEdit* field1;
	CEdit* field2;
	field1 = (CEdit*)GetDlgItemTextW(IDC_EDIT1, Cfield1);
	field2 = (CEdit*)GetDlgItemTextW(IDC_EDIT2, Cfield2);
	summ = InputString / InputValue2;
	result.Format(L"%f", summ);
	UpdateData(false);
}


void CCalculatorDlg::OnBnClickedButton5()
{
	UpdateData(true);
	CString Cfield1;
	CString Cfield2;
	double sqrt1;
	CEdit* field1;
	CEdit* field2;
	field1 = (CEdit*)GetDlgItemTextW(IDC_SQRT, Cfield1);
	sqrt1 = sqrtf(_ttof(Sqrtd));
	result.Format(L"%f", sqrt1);
	UpdateData(false);
}
