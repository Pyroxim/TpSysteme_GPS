//---------------------------------------------------------------------------
#pragma hdrstop
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <tchar.h>
#include <stdio.h>
#include <string>

#include "GPS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

GPS::GPS()
{

}
//---------------------------------------------------------------------------
GPS::~GPS()
{

}
//---------------------------------------------------------------------------
void GPS::fermerPort()
{
	CloseHandle(hCom);
}
//---------------------------------------------------------------------------
bool GPS::ouvrirPort()
{
	DCB dcb;
	BOOL fSuccess;

	hCom = CreateFile( "COM1",
					  GENERIC_READ | GENERIC_WRITE,
					  0,
					  NULL,
					  OPEN_EXISTING,
					  0,
					  NULL );

	if (hCom == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	SecureZeroMemory(&dcb, sizeof(DCB));
	dcb.DCBlength = sizeof(DCB);

	fSuccess = GetCommState(hCom, &dcb);

	if (!fSuccess)
	{
		return false;
	}

	dcb.BaudRate = CBR_4800;
	dcb.ByteSize = 8;
	dcb.Parity   = NOPARITY;
	dcb.StopBits = ONESTOPBIT;

	fSuccess = SetCommState(hCom, &dcb);

	if (!fSuccess)
	{
		return false;
	}

	fSuccess = GetCommState(hCom, &dcb);

	if (!fSuccess)
	{
		return false;
	}
	else
	{
		return true;
	}
}
//---------------------------------------------------------------------------
void GPS::lirePort()
{
	Vcontinue = false;
	isRead = false;

	do
	{
		isRead = ReadFile(hCom, &recvChar, 1, &read, NULL);

		if(ignoreData)
		{
			if(recvChar == '$')
			{
				ignoreData = false;
			}
		}

		if(!ignoreData)
		{
			recvBuf.push_back(recvChar);
			if (!isRead)
			{
				Vcontinue = false;
				break;
			}
		}
	} while (Vcontinue);
}
//---------------------------------------------------------------------------
std::deque<char> & GPS::getRecvBuf()
{
	return recvBuf;
}
