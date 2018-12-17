#pragma once
#include "pch.h"
#include <iostream>
#include "Postac.h"
#include <Windows.h>
#include <conio.h>
#include "Warrior.h"
#include "Dialogi.h"

/*		#######################
		##TYTU£ DO WYMYŒLENIA##
		##BUILD-NoOneCaresTBH##
		##KRZYSZTOF   KALARUS##
		#######################		*/

using namespace std; 

Postac *postac;
CLASS klasa;
RACE rasa;
Warrior warrior(static_cast<CLASS>(0));

void intro() {
	Dialog1();
	klasa = postac->chooseClass();
	switch (klasa) {
	case 0:
		postac = &warrior;
		break;
	}
	switch (klasa) {
	case 0:
		WHITE;
		cout << endl << "-Ahh"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "Wojownik. "; Sleep(900);
		cout << "Zna³em kilku takich jak Ty."; Sleep(900); cout << " M³ody, narwany."; Sleep(900); cout << " Nie dziwne, ¿e ktoœ spuœci³ Ci srogie lanie.";
		break;
	}
	Sleep(1000); cout << endl << " Wracaj¹c do rzeczy."; Sleep(900); cout << " Kim w ogóle jesteœ?"; Sleep(900); " G³uchy jesteœ czy co?!"; Sleep(1000);
	postac->chooseRace();
	Dialog2();
	postac->chooseName();
	CLS;
	WHITE;
	cout << "-Witaj, " << postac->getName() << "."; Sleep(900);
	Dialog3();
	WHITE;
	postac->buildCharacter();
	postac->initializeEq();
}
void test() {

}
int main()
{
	setlocale(LC_CTYPE, "Polish");
	setwindowsize(148, 35);
	intro();
	_getch();
}
