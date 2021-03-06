#include "stdafx.h"
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//struct za parametre iz .txt datoteke
struct parametri {
	int wnd_height;
	int wnd_width;
	wstring wnd_name;
	int txtbx_y;
	int txtbx_x;
	int txtbx_width;
	int txtbx_height;
	int bttn_y;
	int bttn_x;
	int bttn_width;
	int bttn_height;
	string bttn_txt;
	string msgbx_name;
	string empty_msgbx;
}p;

//funkcija za konverziju iz stringa u int tip podataka
int KonverzijaStringInt(string par1) {
	int parametar = stoi(par1);
	return parametar;
}

//funkcija za pronalazak parametra u retku datoteke
string PronalazakParametra(string par2) {
	int pozicija = par2.find(":"); //pronalazak pozicije dvotočke u retku
	pozicija += 2; //moramo dodati 2 da bi uvećali pronađenu poziciju 
	string parametar = par2.substr(pozicija); //uzimanje samo onog dijela iza dvotočke u retku
	return parametar;
}

//funkcija za pretvaranje string u wstring
int StringToWString(std::wstring &ws, const std::string &s) {
	std::wstring wsTmp(s.begin(), s.end());
	ws = wsTmp;
	return 0;
}

//deklaracija funkcije za proceduru prozora
LRESULT CALLBACK WindowProcedura(HWND, UINT, WPARAM, LPARAM);

//deklaracije handler-a za TextBox
HWND PoljeZaUnos;
char uneseni_tekst[100];

/******** MAIN PROGRAM *********/
//navedene instance su svojevrsni ID-evi za našu aplikaciju koju prenosi naš OS
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, INT ncmdshow)
{
	/****************************/
	/***** ZA FILE-DOKUMENT *****/
	/****************************/
	fstream myFileHandler; //stvaranje Handlera za našu .txt datoteku
	myFileHandler.open("parametri.txt");
	int brojac = 0;


	//while petlja za čitanje svih redaka unutar .txt datoteke
	while (!myFileHandler.eof()) { //dok se ne dođe do posljednje retka "end-of-line"
		string redak;
		getline(myFileHandler, redak); //spremanje sadržaja retka u string varijablu
		string redak2 = PronalazakParametra(redak);

		if (brojac == 1) { p.wnd_height = KonverzijaStringInt(redak2); }
		if (brojac == 2) { p.wnd_width = KonverzijaStringInt(redak2); }
		if (brojac == 3) { //string -> wstring -> const wchar_t * (kod instance Window klase)
			wstring redak3;
			StringToWString(redak3, redak2);
			p.wnd_name = redak3;
		};
		if (brojac == 4) { p.txtbx_y = KonverzijaStringInt(redak2); }
		if (brojac == 5) { p.txtbx_x = KonverzijaStringInt(redak2); }
		if (brojac == 6) { p.txtbx_width = KonverzijaStringInt(redak2); }
		if (brojac == 7) { p.txtbx_height = KonverzijaStringInt(redak2); }
		if (brojac == 8) { p.bttn_y = KonverzijaStringInt(redak2); }
		if (brojac == 9) { p.bttn_x = KonverzijaStringInt(redak2); }
		if (brojac == 10) { p.bttn_width = KonverzijaStringInt(redak2); }
		if (brojac == 11) { p.bttn_height = KonverzijaStringInt(redak2); }
		if (brojac == 12) { p.bttn_txt = redak2;}
		if (brojac == 13) { p.msgbx_name = redak2; }
		if (brojac == 14) { p.empty_msgbx = redak2; }
		brojac++;
	}

	//obavezno zatvaranje datoteke
	myFileHandler.close();

	//MessageBox(NULL, "Pozdrav!", "Message Box", MB_OK);
	//hWnd = Handler Owner Window, ako je NULL onda ne postoji vlasnik
	//lpText = Poruka koja će biti prikazana
	//lpCaption = Naslov Message Box-a
	//UINT = vrsta message box-a
	//VAŽNO: Obavezno postaviti Character set: Use Multi-Byte Character Set

	/****************************/
	/***** ZA WINDOW-PROZOR *****/
	/****************************/
	WNDCLASSW wc = { 0 };
	//atributi window class strukture:
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass"; //naša klasa će biti identificirana pod tim imenom
	wc.lpfnWndProc = WindowProcedura;//za procesiranje akcije u prozoru i njihovo povezivanje sa prikazom prozora

	//prima tip pointer tako da moramo proslijediti kao referencu
	//registracija naše window klase
	if (!RegisterClassW(&wc))
		return -1;

	//stvaranje instance window klase (handler je hWnd)
	CreateWindowW(L"myWindowClass", p.wnd_name.c_str(), WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100,
		p.wnd_width, p.wnd_height,
		NULL, NULL, NULL, NULL);


	//struktura poruke
	MSG msg = { 0 };

	//moramo imati petlju kako bi se naš prozor prikazivao cijelo vrijeme
	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}


//definicija funkcije za proceduru window-a
LRESULT CALLBACK WindowProcedura(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	/***** TEXTBOX ****/
	case WM_CREATE:
		PoljeZaUnos = CreateWindow("EDIT", "", WS_BORDER | WS_CHILD | WS_VISIBLE,
			p.txtbx_y, p.txtbx_x, p.txtbx_width, p.txtbx_height,
			hWnd, NULL, NULL, NULL);
		CreateWindow("BUTTON", p.bttn_txt.c_str(), WS_VISIBLE | WS_CHILD | WS_BORDER,
			p.bttn_y, p.bttn_x, p.bttn_width, p.bttn_height,
			hWnd, (HMENU)1, NULL, NULL); //case 1
		break;
	case WM_COMMAND:
		switch (LOWORD(wp)){
			case 1:
				int gwtstat = 0; //get-window-text-status
				gwtstat = GetWindowText(PoljeZaUnos, &uneseni_tekst[0], 100);

				char display_text[120] = "Unesli ste tekst: ";
				strcat_s(display_text, uneseni_tekst);

				if (*uneseni_tekst == 0) MessageBox(hWnd, p.empty_msgbx.c_str(), p.msgbx_name.c_str(), MB_OK);
				else MessageBox(hWnd, display_text, p.msgbx_name.c_str(), MB_OK); 
				break;
		}
	break;
	/**** X - IZLAZ IZ PROZORA ***/
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
