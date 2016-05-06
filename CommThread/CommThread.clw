; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCommThreadDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CommThread.h"

ClassCount=3
Class1=CCommThreadApp
Class2=CCommThreadDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_COMMTHREAD_DIALOG

[CLS:CCommThreadApp]
Type=0
HeaderFile=CommThread.h
ImplementationFile=CommThread.cpp
Filter=N

[CLS:CCommThreadDlg]
Type=0
HeaderFile=CommThreadDlg.h
ImplementationFile=CommThreadDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_EDIT_SEND

[CLS:CAboutDlg]
Type=0
HeaderFile=CommThreadDlg.h
ImplementationFile=CommThreadDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COMMTHREAD_DIALOG]
Type=1
Class=CCommThreadDlg
ControlCount=8
Control1=ID_BT_SEND,button,1342242817
Control2=ID_BUTTON_CANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC1,static,1342308352
Control5=IDC_EDIT_SEND,edit,1352728580
Control6=IDC_EDIT_RECEIVE,edit,1352728580
Control7=IDC_MSCOMM1,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control8=IDC_MSCOMM2,{648A5600-2C6E-101B-82B6-000000000014},1342242816

