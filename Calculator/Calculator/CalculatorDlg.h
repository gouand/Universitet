
// CalculatorDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CCalculatorDlg
class CCalculatorDlg : public CDialogEx
{
// Создание
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	float InputString;
	float InputValue2;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
private:
	CString result;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
private:
	CString Sqrtd;
};
