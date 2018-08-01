#include "stdafx.h"
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct parametri {
	int height;
	int width;
	wstring name;
}p;

/*bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}*/

int StringToWString(std::wstring &ws, const std::string &s)
{
	std::wstring wsTmp(s.begin(), s.end());

	ws = wsTmp;

	return 0;
}

//deklaracija funkcije
LRESULT CALLBACK WindowProcedura(HWND,UINT,WPARAM,LPARAM);

//navedene instance su svojevrsni ID-evi za našu aplikaciju koju prenosi naš OS
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, INT ncmdshow)
{
	fstream myFileHandler; //stvaranje Handlera za našu txt datoteku
	myFileHandler.open("parametri.txt"); //otvaramo txt datoteku
										 //while petlja za čitanje svih redaka unutar txt datoteke
	//čitanje parametara iz .txt datoteke i njihovo pohrana u listu
	int brojac = 0;
	while (!myFileHandler.eof()) { //dok se ne dođe do posljednje retka "end-of-line"
		string redak;
		getline(myFileHandler, redak);
		if (brojac == 0) {
			int parametar = stoi(redak);
			p.height = parametar;
		}
		if (brojac == 1) {
			int parametar = stoi(redak);
			p.width = parametar;
		}
		if (brojac == 2) {
			//string -> wstring -> const wchar_t * (kod instance Window klase)
			wstring redak2;
			StringToWString(redak2, redak);
			p.name = redak2;
		};
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

	//ovo je struktura
	WNDCLASSW wc = { 0 };
	//atributi window class strukture:
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass"; //naša klasa će biti identificirana pod tim imenom
	wc.lpfnWndProc = WindowProcedura;//za procesiranje akcije u prozoru i njihovo povezivanje sa prikazom prozora

	//prima tip pointer tako da moramo proslijediti kao referencu
	//registracija naše window klase
	if(!RegisterClassW(&wc))
		return -1;

	//stvaranje instance window klase
	CreateWindowW(L"myWindowClass", p.name.c_str(), WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100,
		p.width, p.height,
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


//definicija funkcije
LRESULT CALLBACK WindowProcedura(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) 
{
	switch (msg) 
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProcW(hWnd, msg, wp, lp);
	}
}
