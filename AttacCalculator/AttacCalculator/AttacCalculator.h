﻿
// AttacCalculator.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CAttacCalculatorApp:
// Сведения о реализации этого класса: AttacCalculator.cpp
//

class CAttacCalculatorApp : public CWinApp
{
public:
	CAttacCalculatorApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CAttacCalculatorApp theApp;
