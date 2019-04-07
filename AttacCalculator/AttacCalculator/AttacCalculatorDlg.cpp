
// AttacCalculatorDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "AttacCalculator.h"
#include "AttacCalculatorDlg.h"
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


// Диалоговое окно CAttacCalculatorDlg



CAttacCalculatorDlg::CAttacCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ATTACCALCULATOR_DIALOG, pParent)
	, atacProb(0)
	, realizeAttacSumm(0)
	, saveProtectLevel(0)
	, antivir(FALSE)
	, sum(_T(""))
	, safeControl()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAttacCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, atacProb);
	DDV_MinMaxFloat(pDX, atacProb, 0, 100);
	DDX_Text(pDX, IDC_EDIT4, realizeAttacSumm);
	DDV_MinMaxFloat(pDX, realizeAttacSumm, 0, 100000000);
	DDX_Text(pDX, IDC_EDIT2, saveProtectLevel);
	DDV_MinMaxFloat(pDX, saveProtectLevel, 0, 100);
	DDX_Check(pDX, IDC_CHECK1, antivir);
	DDX_Text(pDX, IDC_STATIC_SUMMA, sum);
	DDX_Control(pDX, IDC_EDIT2, safeControl);
}

BEGIN_MESSAGE_MAP(CAttacCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CAttacCalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(ID_BUTTON_CALCULATE, &CAttacCalculatorDlg::OnBnClickedButtonCalculate)
	ON_BN_CLICKED(IDC_CHECK1, &CAttacCalculatorDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// Обработчики сообщений CAttacCalculatorDlg

BOOL CAttacCalculatorDlg::OnInitDialog()
{
	antivir = true;
	atacProb = 0;
	realizeAttacSumm = 0;
	saveProtectLevel = 0;
	sum = "0.00";
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

void CAttacCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAttacCalculatorDlg::OnPaint()
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
HCURSOR CAttacCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAttacCalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CAttacCalculatorDlg::OnBnClickedButtonCalculate()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(true);
	float summ;
	CString EDIT1S;
	CString EDIT2S;
	CString EDIT4S;
	CEdit *m_pEdit1;
	m_pEdit1 = (CEdit*)GetDlgItemTextW(IDC_EDIT1, EDIT1S);
	CEdit *m_pEdit2;
	m_pEdit1 = (CEdit*)GetDlgItemTextW(IDC_EDIT2, EDIT2S);
	CEdit *m_pEdit4;
	m_pEdit1 = (CEdit*)GetDlgItemTextW(IDC_EDIT4, EDIT4S);
	summ = _ttof(EDIT1S) * (1 - _ttof(EDIT2S)) * _ttof(EDIT4S) * pow(365,-1) * 365;
	atacProb = _ttof(EDIT1S);
	realizeAttacSumm = _ttof(EDIT4S);
	saveProtectLevel = _ttof(EDIT2S);
	//summ = atacProb;
	if (summ < 0) {
		summ *= -1;
	}
	sum.Format(L"%.2f",summ);
	//if (EDIT4S.Replace(EDIT4S, EDIT4S) > 100 || EDIT1S.Replace(EDIT1S,EDIT1S) > 100) sum = "00.00";
	if(atacProb > 100 || saveProtectLevel > 100) sum = "0.00";
	UpdateData(false);
}



void CAttacCalculatorDlg::OnBnClickedCheck1()
{
	UpdateData(true);
	CEdit *m_pEdit1;
	m_pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT2);
	int val;
	val = GetDlgItemInt(IDC_EDIT2);
	if (antivir) m_pEdit1->EnableWindow(true);
	else { m_pEdit1->EnableWindow(false); saveProtectLevel = 0; }
	UpdateData(false);
	// TODO: добавьте свой код обработчика уведомлений
}

