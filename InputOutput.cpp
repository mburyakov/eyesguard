
/*********************************************************************
*                                                                    *
* EyesGuard - ��������� ��� ���, ��� ����� ��������� ���� ������,    *
*             ������� �� ����������.                                 *
* ���� ��������� www.eyesguard.org                                   *
*    � �������� ������� (eyesguard@yandex.ru), 2007.                 *
*    ������ ��������� �������� ��������� ����������� ������������.   *
* �� ������ �������������� �� �/��� �������������� � ������������    *
* � ��������� ����������� ������������ �������� GNU � ��� ����,      *
* ��� ��� ���� ������������ ������ ���������� ��                     *
* (Free Software Foundation); ���� ������                            *
* 2 �������� ���� (�� ������ �������) ����� ����� ������� ������.    *
*                                                                    *
* ��������� ���������������� � �������, ��� ��� ����� ��������,      *
* �� ��� ����� �� �� �� ���� ����������� ������������; ���� ���      *
* ��������� ����������� ������������, ��������� � ����������������   *
* ���������� � ������������ ��� ������������ �����. ��� ���������    *
* ����� ��������� ���������� ������������ � �����������              *
* ������������ ��������� GNU (http://www.gnu.org/licenses/gpl.html). *
*                                                                    *
*********************************************************************/

//---------------------------------------------------------------------------
#pragma hdrstop
#include "InputOutput.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

void ReadSettings()
{
   int fileHandle;
   unsigned char Value;

// �������� �����
   if ((fileHandle = open("set.dat",
             O_RDONLY | O_BINARY , S_IREAD)) == -1)
    {
//      MessageBox(MainWnd->Handle, "������ ��� ��������  �� ������ ����� set.dat", "��������!", MB_OK);
      return;
    }


// ������ ��������� ������� ����� ����������
   if ( (read(fileHandle, &Value, 1)) == -1 )
    {
      MessageBox(MainWnd->Handle, "������ ��� ������ ����� set.dat!", "��������!", MB_OK);
      return;
    }


// ��������
   if ( (Value >= 5) && (Value <= 120))
                     {
                      MainWnd->TimeWork = Value;
                     }
     else
      {
       MessageBox(MainWnd->Handle, "������������ ����� ����� ����������!", "��������!", MB_OK);
       MainWnd->TimeWork = 30;
      }


//  ������ ������������ ��������
   lseek(fileHandle, 2,SEEK_SET);
   if ( (read(fileHandle, &Value, 1)) == -1 )
    {
      MessageBox(MainWnd->Handle, "������ ��� ������ ����� set.dat!", "��������!", MB_OK);
      return;
    }


// ��������
   if ( (Value >= 1) && (Value <= 30) )
                     {
                      MainWnd->TimeBreak = Value;
                     }
     else
      {
       MessageBox(MainWnd->Handle, "������������ ����� ��������!", "��������!", MB_OK);
       MainWnd->TimeBreak = 10;
      }


//������ �������� ���������� ��������
   lseek(fileHandle, 4,SEEK_SET);
   if ( (read(fileHandle, &Value, 1)) == -1 )
    {
      MessageBox(MainWnd->Handle, "������ ��� ������ ����� set.dat!", "��������!", MB_OK);
      return;
    }
   MainWnd->EnMonOff = Value;


//������ �������� ��������� ����������
   lseek(fileHandle, 6,SEEK_SET);
   if ( (read(fileHandle, &Value, 1)) == -1 )
    {
      MessageBox(MainWnd->Handle, "������ ��� ������ ����� set.dat!", "��������!", MB_OK);
      return;
    }
   MainWnd->Sound = Value;

//������ ��������� "���������"
   lseek(fileHandle, 8,SEEK_SET);
   if ( (read(fileHandle, &Value, 1)) == -1 )
    {
      MessageBox(MainWnd->Handle, "������ ��� ������ ����� set.dat!", "��������!", MB_OK);
      return;
    }
   MainWnd->Off = Value;

   
   close(fileHandle);
   UpdateWndSet();
}


void WriteSettings()
{
   int fileHandle;

// �������� �����
   if ((fileHandle = open("set.dat",
             O_WRONLY | O_CREAT  | O_BINARY, S_IWRITE)) == -1) //| O_TRUNC
    {


      MessageBox(MainWnd->Handle, "������ ��� �������� �� ������ ����� set.dat", "��������!", MB_OK);


      return;
    }

 if ( !(UpdateProgramSet()) ) return;


// ������ ��������� ������� ����� ����������
   if ( write(fileHandle, &(MainWnd->TimeWork), 1 ) != 1)
    {
      MessageBox(MainWnd->Handle, "������ ��� ������ � ���� set.dat", "��������!", MB_OK);
      return;
    }

// ������ ������������ ��������
   lseek(fileHandle, 2,SEEK_SET);
   if ( write(fileHandle, &(MainWnd->TimeBreak), 1 ) != 1)
    {
      MessageBox(MainWnd->Handle, "������ ��� ������ � ���� set.dat", "��������!", MB_OK);
      return;
    }

// ������ �������� ���������� ��������
   lseek(fileHandle, 4,SEEK_SET);
   if ( write(fileHandle, &(MainWnd->EnMonOff), 1 ) != 1)
    {
      MessageBox(MainWnd->Handle, "������ ��� ������ � ���� set.dat", "��������!", MB_OK);
      return;
    }

// ������ �������� ��������� ����������
   lseek(fileHandle, 6,SEEK_SET);
   if ( write(fileHandle, &(MainWnd->Sound), 1 ) != 1)
    {
      MessageBox(MainWnd->Handle, "������ ��� ������ � ���� set.dat", "��������!", MB_OK);
      return;
    }

// ������ ��������� "���������"
   lseek(fileHandle, 8,SEEK_SET);
   if ( write(fileHandle, &(MainWnd->Off), 1 ) != 1)
    {
      MessageBox(MainWnd->Handle, "������ ��� ������ � ���� set.dat", "��������!", MB_OK);
      return;
    }

   close(fileHandle);

}



void UpdateWndSet()
{

  MainWnd->TimeWorkEdit->Text = IntToStr(MainWnd->TimeWork);
  MainWnd->TimeBreakEdit->Text = IntToStr(MainWnd->TimeBreak);
  MainWnd->CheckSound->Checked = MainWnd->Sound;
  MainWnd->CheckOff->Checked = MainWnd->Off;

  if (MainWnd->Off) MainWnd->PopupOff->Caption = "��������";
               else MainWnd->PopupOff->Caption = "���������";

  MainWnd->CheckEnMonOff->Checked = MainWnd->EnMonOff;
  if (MainWnd->Off)
         {
          MainWnd->TrayIcon->IconIndex = 1;
          MainWnd->PopupMakeBr->Enabled = false;
         }
    else
         {
          MainWnd->TrayIcon->IconIndex = 0;
          MainWnd->PopupMakeBr->Enabled = true;
         } 

}



bool UpdateProgramSet()
{
  MainWnd->Counter = 0;


  MainWnd->TimeBreak = StrToInt(MainWnd->TimeBreakEdit->Text);



  if ( (StrToInt(MainWnd->TimeWorkEdit->Text) < 5) ||
       (StrToInt(MainWnd->TimeWorkEdit->Text) > 120) )
     {
       MessageBox(MainWnd->Handle, "����� ����� ���������� ������ ���� �� 5 �� 120 �����!", "��������!", MB_OK);
       return false;
     }
  MainWnd->TimeWork = StrToInt(MainWnd->TimeWorkEdit->Text);


  if ( (StrToInt(MainWnd->TimeBreakEdit->Text) < 1) ||
       (StrToInt(MainWnd->TimeBreakEdit->Text) > 30) )
     {
       MessageBox(MainWnd->Handle, "����� �������� ������ ���� �� 1 �� 30 �����!", "��������!", MB_OK);
       return false;
     }
  MainWnd->TimeBreak = StrToInt(MainWnd->TimeBreakEdit->Text);


  MainWnd->Sound = MainWnd->CheckSound->Checked;
  MainWnd->Off = MainWnd->CheckOff->Checked;
  if (MainWnd->Off) MainWnd->PopupOff->Caption = "��������";
               else MainWnd->PopupOff->Caption = "���������";

  MainWnd->EnMonOff = MainWnd->CheckEnMonOff->Checked;
  if (MainWnd->Off)
         {
           MainWnd->TrayIcon->IconIndex = 1;
           MainWnd->Timer->Interval = 0;
           MainWnd->PopupMakeBr->Enabled = false;
         }
    else
         {
           MainWnd->TrayIcon->IconIndex = 0;
           MainWnd->Timer->Interval = MainWnd->TimeWork*TIMERMULT;
           MainWnd->PopupMakeBr->Enabled = true;
         }

return true;
}

void CloseWarningMsg()
{
  HWND MesWndHandle = FindWindow(NULL, "EyesGuard !��������! ");
  if (MesWndHandle != NULL)  SendMessage(MesWndHandle, WM_CLOSE, 0,0);

}

