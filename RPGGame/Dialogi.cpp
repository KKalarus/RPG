#include "pch.h"
#include "Dialogi.h"
#include "Functions.h"

void Dialog1()
{
	int k;
	WHITE;
	gotoxy(71, 17);
	cout << "ROK 1361" << endl;
	Sleep(1000);
	CLS;
	WHITE;
	gotoxy(1, 1);
	cout << "*KRZYKI W TLE*" << endl;
	Sleep(1700);
	cout << "*Przebiega przed Tob� kobieta z dzieckiem na r�ku.*" << endl;
	gotoxy(1, 35);
	cout << "WCISNIJ "; YELLOW; cout << "<-"; WHITE; cout << " BY POPATRZY� W KIERUNKU Z KT�REGO PRZYBIEG�A KOBIETA";
	gotoxy(124, 35);
	cout << "WCISNIJ"; YELLOW; cout << " -> "; WHITE; cout << "BY ZA NI� POBIEC";
	do {
		k = _getch();
		if (k == DIR_LEFT) {
			gotoxy(1, 3);
			cout << "*Patrzysz w kierunku z kt�rego bieg�a kobieta.*" << endl;
			Sleep(1500);
			cout << "*Widzisz lec�cy kamie�, kt�ry uderza ci� w g�ow�. Tracisz przytomosc.*";
		}
		else if (k == DIR_RIGHT) {
			gotoxy(1, 3);
			cout << "*Biegniesz za kobiet�.*" << endl;
			Sleep(1500);
			cout << "*Po chwili biegu natrafiasz na grup� ludzi, wyra�nie szukaj�cych zaczepki. Dostajesz srogie lanie. Tracisz przytomno��.*" << endl;
		}
	} while (k != DIR_LEFT && k != DIR_RIGHT);
	Sleep(3000);
	CLS;
	gotoxy(1, 1);
	cout << "*Budzisz si� w nieznanym Ci miejscu. Czujesz ciep�o ognia. Otwieraj�c oczy mo�esz zobaczy� cz�owieka siedz�cego obok Ciebie.*" << endl; Sleep(2000);
	cout << "-Oh! Wreszcie si� obudzi�e�"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";  Sleep(500); cout << " A ju� ba�em si�, �e nigdy tego nie zrobisz, hahaha!" << endl;
	Sleep(1500);
	cout << " Dobra. S�uchaj m�ody, koniec tego dobrego. Powiedz mi, co robi�e� w mie�cie podczas ataku? Wygl�dasz zadziwiaj�co znajomo..." << endl;
}

void Dialog2()
{
	WHITE;
	cout << "-G�upi jeste�, czy co?!"; Sleep(1200);
	cout << endl << "*Od wrzasku zadr�a�y �ciany*" << endl; Sleep(1200);
	cout << "-To wida�, na pierwszy rzut oka!"; Sleep(1200);
	cout << endl << " Jak masz na imi� si� pytam!" << endl; Sleep(3000);
}
void Dialog3() {
	cout << endl << " Pewnie jeste� ciekaw co si� wydarzy�o, hmm?"; Sleep(1200);
	cout << endl << " W wielkim skr�cie: Znalaz�em Ci� nieprzytomnego, le��cego niedaleko tawerny."; Sleep(2000);
	cout << endl << " Sytuacja w mie�cie zaczyna�a by� niezbyt ciekawa, a �e alkoholu nie by�o od Ciebie czu�,to Ci� przygarn��em."; Sleep(2500);
	cout << endl << " No c�, pora na mnie. Czuj si� jak u siebie."; Sleep(2000);
	cout << endl << "*Nieznajomy wychodzi z pokoju. Szum na zewn�trz przypomina szeleszcz�ce na wietrze drzewa.*"; Sleep(2000);
	cout << endl << "*Pr�bujesz si� podnie��, jednak nasilaj�cy si� b�l ca�ego cia�a nie daje ci wsta�. Tracisz przytomno��.*"; Sleep(2000);
	cout << endl << "*Budzi ci� deszcz kapi�cy przez dach na g�ow�. Nie wiesz co si� dzieje, a w mieszkaniu nikogo nie s�ycha�.*"; Sleep(2000);
	cout << endl << "*Czujesz si� znacznie lepiej. Ubierasz si� w ciuchy le��ce obok ��ka i wychodzisz z domku. Po kr�tkiej w�dr�wce trafiasz do miasta...*"; Sleep(2500);
	YELLOW;
	gotoxy(59,35);
	cout << "WCISNIJ PRZYCISK BY KONTYNUOWAC";
	_getch();
}

