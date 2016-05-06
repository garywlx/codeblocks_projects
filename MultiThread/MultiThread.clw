; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUIThread
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MultiThread.h"

ClassCount=4
Class1=CMultiThreadApp
Class2=CMultiThreadDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CUIThread
Resource3=IDD_MULTITHREAD_DIALOG

[CLS:CMultiThreadApp]
Type=0
HeaderFile=MultiThread.h
ImplementationFile=MultiThread.cpp
Filter=N

[CLS:CMultiThreadDlg]
Type=0
HeaderFile=MultiThreadDlg.h
ImplementationFile=MultiThreadDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_MILLISECOND

[CLS:CAboutDlg]
Type=0
HeaderFile=MultiThreadDlg.h
ImplementationFile=MultiThreadDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MULTITHREAD_DIALOG]
Type=1
Class=CMultiThreadDlg
ControlCount=5
Control1=IDSTART,button,1342242817
Control2=IDCREATE,button,1342242816
Control3=IDC_PROGRESS1,msctls_progress32,1350565888
Control4=IDC_MILLISECOND,edit,1350631552
Control5=IDC_STATIC,static,1342308352

[CLS:CUIThread]
Type=0
HeaderFile=UIThread.h
ImplementationFile=UIThread.cpp
BaseClass=CWinThread
Filter=N
LastObject=CUIThread

