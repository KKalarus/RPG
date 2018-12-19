
#include "pch.h"
#include "Postac.h"
Postac::Postac()
{
}

Postac::~Postac()
{
}

CLASS Postac::chooseClass()
{
	YELLOW;
	gotoxy(1, 35);
	cout << "Wybierz swoj¹ klasê postaci. PAMIÊTAJ, KA¯DA KLASA MA W£ASNE UMIEJÊTNOŒCI, ORAZ MO¯E U¯YWAÆ INNYCH PRZEDMIOTÓW! WYBÓR JEST JEDNORAZOWY!";
	gotoxy(1, 4);
	WHITE;
	Sleep(1300);
	YELLOW; cout << "->"; WHITE; cout << " Mieszka³em tam! By³em: ";
	char k;
	int wybor = 0;
	switch (wybor) {
	case 0:
		gotoxy(25, 4);
		cout << "                  ";
		gotoxy(25, 4);
		cout << " [WOJOWNIKIEM]"; YELLOW; cout<<"> ";
		break;
	case 1:
		YELLOW; cout << "<"; WHITE; cout << "[£UCZNIKIEM]"; YELLOW; cout << " > ";
		break;
	case 2:
		YELLOW; cout << "<"; WHITE; cout << "[MAGIEM]"; YELLOW; cout << " > ";
		break;
	case 3:
		YELLOW; cout << "<"; WHITE; cout<<"[Z£ODZIEJEM]"; YELLOW; cout << " > ";
		break;
	case 4:
		YELLOW; cout << "<"; WHITE; cout << "[SZAMANEM] ";
		break;
	}
	do {
		k = _getch();
		if (k == DIR_LEFT) {
			wybor--;
			if (wybor < 0) {
				wybor = 0;
			}
		}
		else if (k == DIR_RIGHT) {
			wybor++;
			if (wybor > 4) {
				wybor = 4;
			}
		}
		switch (wybor) {
		case 0:
			gotoxy(25, 4);
			cout << "                  ";
			gotoxy(25, 4);
			WHITE; cout << " [WOJOWNIKIEM]"; YELLOW; cout << "> ";
			break;
		case 1:
			gotoxy(25, 4);
			cout << "                  ";
			gotoxy(25, 4);
			YELLOW; cout << "<"; WHITE; cout << "[£UCZNIKIEM]"; YELLOW; cout << "> ";
			break;
		case 2:
			gotoxy(25, 4);
			cout << "                  ";
			gotoxy(25, 4);
			YELLOW; cout << "<"; WHITE; cout << "[MAGIEM]"; YELLOW; cout << "> ";
			break;
		case 3:
			gotoxy(25, 4);
			cout << "                  ";
			gotoxy(25, 4);
			YELLOW; cout << "<"; WHITE; cout << "[Z£ODZIEJEM]"; YELLOW; cout << "> ";
			break;
		case 4:
			gotoxy(25, 4);
			cout << "                  ";
			gotoxy(25, 4);
			YELLOW; cout << "<"; WHITE; cout << "[SZAMANEM] ";
			break;
		}
	} while (k != ENTER);
	return static_cast<CLASS>(wybor);
}
void Postac::setClass(CLASS klasa) {
	this->klasa = klasa;
}
CLASS Postac::getClass() 
{
	return this->klasa;
}
void Postac::chooseRace() //Chooses race and gives basic points.
{
	int wybor = 0;
	char k;
	cout << endl << "*Z ogromnym wysi³kiem próbujesz sobie przypomnieæ kim w ogóle jesteœ. Patrzysz na swoje rêce, lecz nie przypominaj¹ Ci nic znajomego. " << endl;
	cout << " Po chwili namys³u uœwiadamiasz sobie kim jesteœ.*" << endl;
	gotoxy(1, 9);
	YELLOW; cout << "->"; WHITE;cout<<" Eeeem, no... cz³owiekiem ? ";
	gotoxy(1, 10);
	YELLOW; cout << "Wybieraj¹c t¹ klasê, dostaniesz dodatkowe: 1 si³y, 1 wytrzyma³oœci, 2 inteligencji. 1 szczêœcia.";
	YELLOW;
	gotoxy(1, 35);
	cout << "Wybierz swoj¹ rasê postaci. W zale¿noœci od rasy, dostaniesz dodatkowe punkty umiejêtnoœci na start. Wybierz m¹drze.                        ";

	//podstawowe umiejetnosci.
	this->str = 1;
	this->dex = 1;
	this->in = 1;
	this->st = 1;
	this->lu = 1;

	do {
		k = _getch();
		if (k == DIR_LEFT) {
			wybor--;
			if (wybor < 0) {
				wybor = 0;
			}
		}
		else if (k == DIR_RIGHT) {
			wybor++;
			if (wybor > 4) {
				wybor = 4;
			}
		}
		switch (wybor) {
		case 0:
			gotoxy(1, 9);
			cout << "                                                                                                                                            ";
			gotoxy(1, 9);
			YELLOW; cout << "->"; WHITE; cout << " Eeeem, no... cz³owiekiem?";
			gotoxy(1, 10);
			cout << "                                                                                                                                            ";
			gotoxy(1, 10);
			YELLOW; cout << "Wybieraj¹c t¹ klasê, dostaniesz dodatkowe: 1 si³y, 1 wytrzyma³oœci, 0 zwinnoœci, 2 inteligencji. 1 szczêœcia.";
			break;
		case 1:
			gotoxy(1, 9);
			cout << "                                                                                                                                            ";
			gotoxy(1, 9);
			YELLOW; cout << "->"; WHITE; cout << " JAK ŒMIESZ! Najwspanialszym ELFEM!";
			gotoxy(1, 10);
			cout << "                                                                                                                                            ";
			gotoxy(1, 10);
			YELLOW; cout << "Wybieraj¹c t¹ klasê, dostaniesz dodatkowe: 0 si³y, 1 wytrzyma³oœci, 1 zwinnoœci, 3 inteligencji. 0 szczêœcia.";
			break;
		case 2:
			gotoxy(1, 9);
			cout << "                                                                                                                                            ";
			gotoxy(1, 9);
			YELLOW; cout << "->"; WHITE; cout << " Œlepy jesteœ, czy co? krasnoludaœ nie widzia³?";
			gotoxy(1, 10);
			cout << "                                                                                                                                            ";
			gotoxy(1, 10);
			YELLOW; cout << "Wybieraj¹c t¹ klasê, dostaniesz dodatkowe: 2 si³y, 2 wytrzyma³oœci, 0 zwinnoœci, 0 inteligencji. 1 szczêœcia.";

			break;
		case 3:
			gotoxy(1, 9);
			cout << "                                                                                                                                            ";
			gotoxy(1, 9);
			YELLOW; cout << "->"; WHITE; cout << " Szanowny Pan wybaczy, ale nawet nie wiem jak tu trafi³em... Hobbitem, informuje tylko ze wzglêdu na moje maniery.";
			gotoxy(1, 10);
			cout << "                                                                                                                                            ";
			gotoxy(1, 10);
			YELLOW; cout << "Wybieraj¹c t¹ klasê, dostaniesz dodatkowe: 0 si³y, 0 wytrzyma³oœci, 3 zwinnoœci, 1 inteligencji. 1 szczêœcia.";
			break;
		case 4:
			gotoxy(1, 9);
			cout << "                                                                                                                                            ";
			gotoxy(1, 9);
			YELLOW; cout << "->"; WHITE; cout << " Cz³owiek g³upi! *Bekniêcie* Ork ja byæ! Ha, Ha!";
			gotoxy(1, 10);
			cout << "                                                                                                                                            ";
			gotoxy(1, 10);
			YELLOW; cout << "Wybieraj¹c t¹ klasê, dostaniesz dodatkowe: 2 si³y, 1 wytrzyma³oœci, 0 zwinnoœci, 0 inteligencji. 2 szczêœcia.";
			break;
		}
	} while (k != ENTER);
	gotoxy(1, 10);
	cout << "                                                                                                                                            ";
	gotoxy(1, 10);
	this->rasa = static_cast<RACE>(wybor);
	switch (wybor) {
	case 0: //Czlowiek
		this->str = this->str + 1;
		this->st = this->st + 1;
		this->in = this->in+ 2;
		this->lu = this->lu + 1;
		break;
	case 1: //Elf
		this->st = this->st + 1;
		this->dex = this->dex + 1;
		this->in = this->in + 3;
		break;
	case 2: //Krasnolud
		this->str = this->str + 2;
		this->st = this->st + 2;
		this->lu = this->lu + 1;
		break;
	case 3: //Hobbit
		this->dex = this->dex + 3;
		this->in = this->in + 1;
		this->lu = this->lu + 1;
		break;
	case 4: //Ork
		this->str = this->str + 2;
		this->st = this->st + 1;
		this->lu = this->lu + 2;
		break;
	}
}
RACE Postac::getRace() {
	return this->rasa;
}
void Postac::chooseName()
{
	string name;
	system("CLS");
	gotoxy(70, 17);
	WHITE;
	cout << "WPISZ IMIE" << endl;
	do {
		gotoxy(70, 18);
		cout << "                                    ";
		gotoxy(70, 18);
		YELLOW;
		getline(cin, name);
	} while (name.length() > 15 && name.length() < 1);
	this->name = name;
}
string Postac::getName() {
	return this->name;
}
void Postac::buildCharacter()
{
	this->freeAbilityPoints = 10;
	int b_str = this->str;; //SILA
	int b_dex = this->dex; //ZWINNOSC
	int b_st = this->st; //STAMINA (WYTRZYMALOSC)
	int b_in = this->in; //INTELIGENCJA
	int b_lu = this->lu; //SZCZESCIE

	int str = b_str; //SILA
	int dex = b_dex; //ZWINNOSC
	int st = b_st; //STAMINA (WYTRZYMALOSC)
	int in = b_in; //INTELIGENCJA
	int lu = b_lu; //SZCZESCIE

	CLS;
	gotoxy(60, 1);
	cout << "WITAJ W OKNIE BUDOWY POSTACI!";
	gotoxy(55, 2);
	cout << "ROZDZIEL POZOSTALE PUNKTY UMIEJETNOSCI.";
	for (int j = 1; j <= 35; j++) {
		gotoxy(1, j);
		cout << "|";
		gotoxy(14, j);
		cout << "|";
	}
	gotoxy(1, 4);
	for (int i = 0; i <= 19; i++) {
		cout << "=";
	}
	gotoxy(19, 5);
	cout << " | ";
	gotoxy(2, 5);
	YELLOW; cout << "SILA"; WHITE;
	gotoxy(1, 6);
	for (int i = 0; i <= 19; i++) {
		cout << "=";
	}
	gotoxy(19, 7);
	cout << " | ";
	gotoxy(2, 7);
	cout << "ZRÊCZNOŒÆ";
	gotoxy(1, 8);
	for (int i = 0; i <= 19; i++) {
		cout << "=";
	}
	gotoxy(19, 9);
	cout << " | ";
	gotoxy(2, 9);
	cout << "WYTRZYMA£OŒÆ";
	gotoxy(1, 10);
	for (int i = 0; i <= 19; i++) {
		cout << "=";
	}
	gotoxy(19, 11);
	cout << " | ";
	gotoxy(2, 11);
	cout << "INTELIGENCJA";
	gotoxy(1, 12);
	for (int i = 0; i <= 19; i++) {
		cout << "=";
	}
	gotoxy(19, 13);
	cout << " | ";
	gotoxy(2, 13);
	cout << "SZCZÊŒCIE";
	gotoxy(1, 14);
	for (int i = 0; i <= 19; i++) {
		cout << "=";
	}
	gotoxy(1, 1);
	for (int i = 0; i <= 19; i++) {
		cout << "=";
	}
	gotoxy(2, 2);
	cout << "WOLNE PUNKTY";
	gotoxy(1, 3);
	for (int i = 0; i <= 19; i++) {
		cout << "=";
	}
	gotoxy(19, 2);
	cout << " | ";
	gotoxy(16, 2);
	cout << "  ";
	gotoxy(16, 2);
	cout << this->freeAbilityPoints;
	gotoxy(17, 13);
	cout << "  ";
	gotoxy(16, 13);
	cout << lu;
	gotoxy(17, 11);
	cout << "  ";
	gotoxy(16, 11);
	cout << in;
	gotoxy(17, 9);
	cout << "  ";
	gotoxy(16, 9);
	cout << st;
	gotoxy(17, 7);
	cout << "  ";
	gotoxy(16, 7);
	cout << dex;
	gotoxy(17, 5);
	cout << "  ";
	gotoxy(16, 5);
	cout << str;
	gotoxy(1, 35);
	cout << "                                                                                                                                                     ";
	gotoxy(1, 35);
	YELLOW;
	cout << "U¯YJ \\/ ORAZ /\\ ABY WYBRAÆ UMIEJÊETNOŒÆ, A NASTÊPNIE -> I <- BY ZMIENIÆ JEJ WARTOŒÆ. PAMIÊTAJ, ¯E MO¯ESZ ZROBIÆ TO TYLKO RAZ, NA POCZ¥TKU GRY!";
	WHITE;
	//showing points etc.
	char k;
	int wybor = 0;
	do {
		k = _getch();
		if (k == DIR_UP) {
			wybor--;
			if (wybor < 0) {
				wybor = 0;
			}
		}
		else if (k == DIR_DOWN) {
			wybor++;
			if (wybor > 4) {
				wybor = 4;
			}
		}
		switch(wybor) {
		case 0:
			gotoxy(2, 5);
			YELLOW; cout << "SILA"; WHITE;
			gotoxy(2, 7);
			cout << "ZRÊCZNOŒÆ";
			gotoxy(2, 9);
			cout << "WYTRZYMA£OŒÆ";
			gotoxy(2, 11);
			cout << "INTELIGENCJA";
			gotoxy(2, 13);
			cout << "SZCZÊŒCIE";
			break;
		case 1:
			gotoxy(2, 5);
			WHITE; cout << "SILA";
			gotoxy(2, 7);
			YELLOW; cout << "ZRÊCZNOŒÆ"; WHITE;
			gotoxy(2, 9);
			cout << "WYTRZYMA£OŒÆ";
			gotoxy(2, 11);
			cout << "INTELIGENCJA";
			gotoxy(2, 13);
			cout << "SZCZÊŒCIE";
			break;
		case 2:
			gotoxy(2, 5);
			WHITE; cout << "SILA";
			gotoxy(2, 7);
			cout << "ZRÊCZNOŒÆ";
			gotoxy(2, 9);
			YELLOW; cout << "WYTRZYMA£OŒÆ"; WHITE;
			gotoxy(2, 11);
			cout << "INTELIGENCJA";
			gotoxy(2, 13);
			cout << "SZCZÊŒCIE";
			break;
		case 3:
			gotoxy(2, 5);
			WHITE; cout << "SILA";
			gotoxy(2, 7);
			cout << "ZRÊCZNOŒÆ";
			gotoxy(2, 9);
			cout << "WYTRZYMA£OŒÆ";
			gotoxy(2, 11);
			YELLOW; cout << "INTELIGENCJA"; WHITE;
			gotoxy(2, 13);
			cout << "SZCZÊŒCIE";
			break;
		case 4:
			gotoxy(2, 5);
			WHITE; cout << "SILA";
			gotoxy(2, 7);
			cout << "ZRÊCZNOŒÆ";
			gotoxy(2, 9);
			cout << "WYTRZYMA£OŒÆ";
			gotoxy(2, 11);
			cout << "INTELIGENCJA";
			gotoxy(2, 13);
			YELLOW; cout << "SZCZÊŒCIE"; WHITE;
			break;
		}
		if (k == DIR_RIGHT) {
			if (this->freeAbilityPoints > 0) {
				switch (wybor) {
				case 0:
					str++;
					this->freeAbilityPoints--;
					break;
				case 1:
					dex++;
					this->freeAbilityPoints--;
					break;
				case 2:
					st++;
					this->freeAbilityPoints--;
					break;
				case 3:
					in++;
					this->freeAbilityPoints--;
					break;
				case 4:
					lu++;
					this->freeAbilityPoints--;
					break;
				}
			}
			else {
				gotoxy(21, 2);
				YELLOW;
				cout << "BRAK WOLNYCH PUNKTÓW!";
				Sleep(2000);
				gotoxy(21, 2);
				cout << "                     ";
				WHITE;
			}
		}
		else if (k == DIR_LEFT) {
			switch (wybor) {
			case 0:
				if (str > b_str) {
					str--;
					this->freeAbilityPoints++;
				}
				else {
					gotoxy(21, 5);
					YELLOW; cout << "NIE MO¯ESZ MIEÆ MNIEJ SI£Y!"; WHITE;
					Sleep(2000);
					gotoxy(21, 5);
					cout << "                           ";
				}
				break;
			case 1:
				if (dex > b_dex) {
					dex--;
					this->freeAbilityPoints++;
				}
				else {
					gotoxy(21, 7);
					YELLOW; cout << "NIE MO¯ESZ MIEÆ MNIEJ ZRÊCZNOŒCI!"; WHITE;
					Sleep(2000);
					gotoxy(21, 7);
					cout << "                                 ";
				}
				break;
			case 2:
				if (st > b_st) {
					st--;
					this->freeAbilityPoints++;
				}
				else {
					gotoxy(21, 9);
					YELLOW; cout << "NIE MO¯ESZ MIEÆ MNIEJ WYTRZYMA£OŒCI!"; WHITE;
					Sleep(2000);
					gotoxy(21, 9);
					cout << "                                    ";
				}
				break;
			case 3:
				if (in > b_in) {
					in--;
					this->freeAbilityPoints++;
				}
				else {
					gotoxy(21, 11);
					YELLOW; cout << "NIE MO¯ESZ MIEÆ MNIEJ INTELIGENCJI!"; WHITE;
					Sleep(2000);
					gotoxy(21, 11);
					cout << "                                   ";
				}
				break;
			case 4:
				if (lu > b_lu) {
					lu--;
					this->freeAbilityPoints++;
				}
				else {
					gotoxy(21, 13);
					YELLOW; cout << "NIE MO¯ESZ MIEÆ MNIEJ SZCZÊŒCIA!"; WHITE;
					Sleep(2000);
					gotoxy(21, 13);
					cout << "                                ";
				}
				break;
			}
		}
		gotoxy(16, 2);
		cout << "  ";
		gotoxy(16, 2);
		cout << this->freeAbilityPoints;
		gotoxy(17, 13);
		cout << "  ";
		gotoxy(16, 13);
		cout << lu;
		gotoxy(17, 11);
		cout << "  ";
		gotoxy(16, 11);
		cout << in;
		gotoxy(17, 9);
		cout << "  ";
		gotoxy(16, 9);
		cout << st;
		gotoxy(17, 7);
		cout << "  ";
		gotoxy(16, 7);
		cout << dex;
		gotoxy(17, 5);
		cout << "  ";
		gotoxy(16, 5);
		cout << str;
		if (k == ENTER) {
			if (this->freeAbilityPoints == 0) {
				break;
			}
			else {
				gotoxy(21, 2);
				YELLOW;
				cout << "ROZDZIEL PUNKTY!";
				Sleep(2000);
				gotoxy(21, 2);
				cout << "                ";
				WHITE;
			}
		}
	} while (true);
	this->str = str;
	this->dex = dex;
	this->st = st;
	this->in = in;
	this->lu = lu;
}
void Postac::initializeEq() 
{
	for (int i = 0; i < 15; i++) {
		eq[i] = (T_FREESPACE);
	}
}
void Postac::showEq() 
{
	for (int i = 0; i < 15; i++) {
		eq[i].showItem();
		cout << endl;
		cout << endl;
	}
}
int Postac::getXp()
{
	return this->xp;
}
int Postac::getLvl()
{
	return this->lvl;
}