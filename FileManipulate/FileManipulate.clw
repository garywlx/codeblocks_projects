; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFileManipulateDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FileManipulate.h"

ClassCount=3
Class1=CFileManipulateApp
Class2=CFileManipulateDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FILEMANIPULATE_DIALOG

[CLS:CFileManipulateApp]
Type=0
HeaderFile=FileManipulate.h
ImplementationFile=FileManipulate.cpp
Filter=N

[CLS:CFileManipulateDlg]
Type=0
HeaderFile=FileManipulateDlg.h
ImplementationFile=FileManipulateDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CFileManipulateDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=FileManipulateDlg.h
ImplementationFile=FileManipulateDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FILEMANIPULATE_DIALOG]
Type=1
Class=CFileManipulateDlg
ControlCount=10
Control1=IDC_OPENSRC,button,1342242817
Control2=IDC_SRCFILE,edit,1350631552
Control3=IDC_DSTFILE,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_OPENDST,button,1342242817
Control7=IDC_CANCLE,button,1342242816
Control8=IDC_DELETE,button,1342242816
Control9=IDC_MOVE,button,1342242816
Control10=IDC_COPY,button,1342242816

