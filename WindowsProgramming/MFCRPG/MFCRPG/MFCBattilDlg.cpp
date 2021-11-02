// MFCBattilDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFCRPG.h"
#include "MFCBattilDlg.h"
#include "afxdialogex.h"


// MFCBattilDlg 대화 상자

IMPLEMENT_DYNAMIC(MFCBattilDlg, CDialogEx)

MFCBattilDlg::MFCBattilDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MFCBattilDlg::~MFCBattilDlg()
{
}

void MFCBattilDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MFCBattilDlg, CDialogEx)
END_MESSAGE_MAP()


// MFCBattilDlg 메시지 처리기


BOOL MFCBattilDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
