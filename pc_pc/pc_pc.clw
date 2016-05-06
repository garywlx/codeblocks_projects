; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "pc_pc.h"

ClassCount=5
Class1=CPc_pcApp
Class2=CPc_pcDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=ShowThread
Class5=CalculateThread
Resource3=IDD_PC_PC_DIALOG

[CLS:CPc_pcApp]
Type=0
HeaderFile=pc_pc.h
ImplementationFile=pc_pc.cpp
Filter=N

[CLS:CPc_pcDlg]
Type=0
HeaderFile=pc_pcDlg.h
ImplementationFile=pc_pcDlg.cpp
Filter=D
LastObject=CPc_pcDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=pc_pcDlg.h
ImplementationFile=pc_pcDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PC_PC_DIALOG]
Type=1
Class=CPc_pcDlg
ControlCount=36
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_receive,edit,1352730628
Control5=IDC_STATIC,static,1342308352
Control6=IDC_send,edit,1352732676
Control7=IDC_MSCOMM1,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control8=IDC_MSCOMM2,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control9=IDC_STOP,button,1342242816
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,button,1342177287
Control12=IDC_PORT1,combobox,1344339970
Control13=IDC_STATIC,static,1342308352
Control14=IDC_PORT2,combobox,1344339970
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_BAUD_RATE1,combobox,1344339970
Control18=IDC_STATIC,static,1342308352
Control19=IDC_BAUD_RATE2,combobox,1344339970
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_PARITY_BIT1,combobox,1344339970
Control25=IDC_DATA_BIT1,combobox,1344339970
Control26=IDC_STOP_BIT1,combobox,1344339970
Control27=IDC_BUFFER_SIZE1,combobox,1344339970
Control28=IDC_STATIC,static,1342308352
Control29=IDC_PARITY_BIT2,combobox,1344339970
Control30=IDC_STOP_BIT2,combobox,1344339970
Control31=IDC_DATA_BIT2,combobox,1344339970
Control32=IDC_BUFFER_SIZE2,combobox,1344339970
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352
Control36=ID_SAVE_SETTING,button,1342242816

[CLS:ShowThread]
Type=0
HeaderFile=ShowThread.h
ImplementationFile=ShowThread.cpp
BaseClass=CWinThread
Filter=N

[CLS:CalculateThread]
Type=0
HeaderFile=alculateThread.h
ImplementationFile=alculateThread.cpp
BaseClass=CWinThread
Filter=N
LastObject=CalculateThread

