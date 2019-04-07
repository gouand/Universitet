
// AttacCalculatorDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CAttacCalculatorDlg
class CAttacCalculatorDlg : public CDialogEx
{
// Создание
public:
	CAttacCalculatorDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ATTACCALCULATOR_DIALOG };
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
public:
	afx_msg void OnEnChangeEdit1();
private:
	float atacProb;
	float realizeAttacSumm;
	float saveProtectLevel;
	BOOL antivir;
	CString sum;
	CEdit safeControl;
public:
	afx_msg void OnBnClickedButtonCalculate();
	afx_msg void OnBnClickedCheck1();
};
