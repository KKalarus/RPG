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
	cout << "*Przebiega przed Tob¹ kobieta z dzieckiem na rêku.*" << endl;
	gotoxy(1, 35);
	cout << "WCISNIJ "; YELLOW; cout << "<-"; WHITE; cout << " BY POPATRZYÆ W KIERUNKU Z KTÓREGO PRZYBIEG£A KOBIETA";
	gotoxy(124, 35);
	cout << "WCISNIJ"; YELLOW; cout << " -> "; WHITE; cout << "BY ZA NI¥ POBIEC";
	do {
		k = _getch();
		if (k == DIR_LEFT) {
			gotoxy(1, 3);
			cout << "*Patrzysz w kierunku z którego bieg³a kobieta.*" << endl;
			Sleep(1500);
			cout << "*Widzisz lec¹cy kamieñ, który uderza ciê w g³owê. Tracisz przytomosc.*";
		}
		else if (k == DIR_RIGHT) {
			gotoxy(1, 3);
			cout << "*Biegniesz za kobiet¹.*" << endl;
			Sleep(1500);
			cout << "*Po chwili biegu natrafiasz na grupê ludzi, wyraŸnie szukaj¹cych zaczepki. Dostajesz srogie lanie. Tracisz przytomnoœæ.*" << endl;
		}
	} while (k != DIR_LEFT && k != DIR_RIGHT);
	Sleep(3000);
	CLS;
	gotoxy(1, 1);
	cout << "*Budzisz siê w nieznanym Ci miejscu. Czujesz ciep³o ognia. Otwieraj¹c oczy mo¿esz zobaczyæ cz³owieka siedz¹cego obok Ciebie.*" << endl; Sleep(2000);
	cout << "-Oh! Wreszcie siê obudzi³eœ"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";  Sleep(500); cout << " A ju¿ ba³em siê, ¿e nigdy tego nie zrobisz, hahaha!" << endl;
	Sleep(1500);
	cout << " Dobra. S³uchaj m³ody, koniec tego dobrego. Powiedz mi, co robi³eœ w mieœcie podczas ataku? Wygl¹dasz zadziwiaj¹co znajomo..." << endl;
}

void Dialog2()
{
	WHITE;
	cout << "-G³upi jesteœ, czy co?!"; Sleep(1200);
	cout << endl << "*Od wrzasku zadr¿a³y œciany*" << endl; Sleep(1200);
	cout << "-To widaæ, na pierwszy rzut oka!"; Sleep(1200);
	cout << endl << " Jak masz na imiê siê pytam!" << endl; Sleep(3000);
}
void Dialog3() {
	cout << endl << " Pewnie jesteœ ciekaw co siê wydarzy³o, hmm?"; Sleep(1200);
	cout << endl << " W wielkim skrócie: Znalaz³em Ciê nieprzytomnego, le¿¹cego niedaleko tawerny."; Sleep(2000);
	cout << endl << " Sytuacja w mieœcie zaczyna³a byæ niezbyt ciekawa, a ¿e alkoholu nie by³o od Ciebie czuæ,to Ciê przygarn¹³em."; Sleep(2500);
	cout << endl << " No có¿, pora na mnie. Czuj siê jak u siebie."; Sleep(2000);
	cout << endl << "*Nieznajomy wychodzi z pokoju. Szum na zewn¹trz przypomina szeleszcz¹ce na wietrze drzewa.*"; Sleep(2000);
	cout << endl << "*Próbujesz siê podnieœæ, jednak nasilaj¹cy siê ból ca³ego cia³a nie daje ci wstaæ. Tracisz przytomnoœæ.*"; Sleep(2000);
	cout << endl << "*Budzi ciê deszcz kapi¹cy przez dach na g³owê. Nie wiesz co siê dzieje, a w mieszkaniu nikogo nie s³ychaæ.*"; Sleep(2000);
	cout << endl << "*Czujesz siê znacznie lepiej. Ubierasz siê w ciuchy le¿¹ce obok ³ó¿ka i wychodzisz z domku. Po krótkiej wêdrówce trafiasz do miasta...*"; Sleep(2500);
	YELLOW;
	gotoxy(59,35);
	cout << "WCISNIJ PRZYCISK BY KONTYNUOWAC";
	_getch();
}

