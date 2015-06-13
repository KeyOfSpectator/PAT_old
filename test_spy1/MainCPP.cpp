//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include "resource.h"

BOOL APIENTRY MainDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
 POINT  MousePoint;
 TCHAR str[256];
 HWND hWnd;
 switch(message)
 {
 case WM_INITDIALOG:
  {
   SetWindowPos(hDlg, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
   SetTimer(hDlg, 1, 100, NULL);
   return(TRUE);
  }
 case WM_CLOSE:
  {
   AnimateWindow(hDlg, 1000, AW_HIDE|AW_BLEND);
   EndDialog(hDlg, TRUE);
   return(TRUE);
  }
 case WM_TIMER:
  {
   GetCursorPos(&MousePoint);
   hWnd = WindowFromPoint(MousePoint);
   SendMessage(hWnd, WM_GETTEXT, 255, (long)str);
   SetDlgItemText(hDlg, IDC_CAPTION, str);
   GetClassName(hWnd, str, 255);
   SetDlgItemText(hDlg, IDC_CLASSNAME, str);
   _ltow(GetClassLong(hWnd, GCW_ATOM), str, 10);
   SetDlgItemText(hDlg, IDC_CLASSATOM, str);
   _ltow(GetWindowLong(hWnd, GWL_STYLE), str, 2);
   SetDlgItemText(hDlg, IDC_STYLE, str);
   _ltow(GetWindowLong(hWnd, GWL_EXSTYLE), str, 2);
   SetDlgItemText(hDlg, IDC_EXTSTYLE, str);
   _ltow(GetWindowLong(hWnd, GWL_ID), str, 10);
   SetDlgItemText(hDlg, IDC_ID, str);
   return(TRUE);
  }
 case WM_DESTROY:
  {
   KillTimer(hDlg, 1);
   return(TRUE);
  }
 case WM_COMMAND:
  {
   if(LOWORD(wParam) == IDC_QUIT)
    EndDialog(hDlg, TRUE);
   return(TRUE);
  }
 }
 return(FALSE);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
 DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAINDLG), NULL, (DLGPROC)MainDlgProc);
 return(0);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////