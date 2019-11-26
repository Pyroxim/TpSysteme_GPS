//---------------------------------------------------------------------------
#ifndef GPSH
#define GPSH

#include <windows.h>
#include <queue>
class GPS
{
	HANDLE hCom;
	DWORD written;
	DWORD read;
	char recvChar;
	bool Vcontinue;
	int isRead;
	bool ignoreData;

	std::deque<char> recvBuf;

	public:
	GPS();
	~GPS();
	bool ouvrirPort();
	void lirePort();
	void fermerPort();

	std::deque<char> & getRecvBuf();
};
//---------------------------------------------------------------------------
#endif
