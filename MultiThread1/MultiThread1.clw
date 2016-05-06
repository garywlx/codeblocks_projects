; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCalculateThread
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MultiThread1.h"

ClassCount=4
Class1=CMultiThread1App
Class2=CMultiThread1Dlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CCalculateThread
Resource3=IDD_MULTITHREAD1_DIALOG

[CLS:CMultiThread1App]
Type=0
HeaderFile=MultiThread1.h
ImplementationFile=MultiThread1.cpp
Filter=N

[CLS:CMultiThread1Dlg]
Type=0
HeaderFile=MultiThread1Dlg.h
ImplementationFile=MultiThread1Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CMultiThread1Dlg

[CLS:CAboutDlg]
Type=0
HeaderFile=MultiThread1Dlg.h
ImplementationFile=MultiThread1Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MULTITHREAD1_DIALOG]
Type=1
Class=CMultiThread1Dlg
ControlCount=6
Control1=IDC_SUM,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO1,button,1342177289
Control4=IDC_RADIO2,button,1342177289
Control5=IDC_RADIO3,button,1342177289
Control6=IDC_STATUS,edit,1350631552

[CLS:CCalculateThread]
Type=0
HeaderFile=CalculateThread.h
ImplementationFile=CalculateThread.cpp
BaseClass=CWinThread
Filter=N
LastObject=CCalculateThread

