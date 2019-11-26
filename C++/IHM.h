//---------------------------------------------------------------------------

#ifndef IHMH
#define IHMH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "GPS.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *Button1;
	TButton *Button2;
	TTimer *Timer1;
	TButton *Button3;
	TMemo *MemoGlobal;
	TMemo *MemoLat;
	TMemo *MemoLong;
	TMemo *MemoProf;
	TMemo *MemoTemp;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// Déclarations utilisateur
	GPS * gps;
	static DWORD WINAPI RecvThread(LPVOID param);
	HANDLE sync;
	std::deque<std::vector<char> > trames;
	double longitude;
	double latitude;
public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
