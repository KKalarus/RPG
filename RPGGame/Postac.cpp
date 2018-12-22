
#include "pch.h"
#include "Postac.h"

Postac::Postac()
{
	mapka[11][11].setCity();
}

Postac::~Postac()
{
}

CLASS Postac::chooseClass()
{
	YELLOW;
	gotoxy(1, 35);
	cout << "Wybierz swoj� klas� postaci. PAMI�TAJ, KA�DA KLASA MA W�ASNE UMIEJ�TNO�CI, ORAZ MO�E U�YWA� INNYCH PRZEDMIOT�W! WYB�R JEST JEDNORAZOWY!";
	gotoxy(1, 4);
	WHITE;
	Sleep(1300);
	YELLOW; cout << "->"; WHITE; cout << " Mieszka�em tam! By�em: ";
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
		YELLOW; cout << "<"; WHITE; cout << "[�UCZNIKIEM]"; YELLOW; cout << " > ";
		break;
	case 2:
		YELLOW; cout << "<"; WHITE; cout << "[MAGIEM]"; YELLOW; cout << " > ";
		break;
	case 3:
		YELLOW; cout << "<"; WHITE; cout<<"[Z�ODZIEJEM]"; YELLOW; cout << " > ";
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
			YELLOW; cout << "<"; WHITE; cout << "[�UCZNIKIEM]"; YELLOW; cout << "> ";
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
			YELLOW; cout << "<"; WHITE; cout << "[Z�ODZIEJEM]"; YELLOW; cout << "> ";
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

void Postac::chooseRace() //Chooses race and gives basic points.
{
	int wybor = 0;
	char k;
	cout << endl << "*Z ogromnym wysi�kiem pr�bujesz sobie przypomnie� kim w og�le jeste�. Patrzysz na swoje r�ce, lecz nie przypominaj� Ci nic znajomego. " << endl;
	cout << " Po chwili namys�u u�wiadamiasz sobie kim jeste�.*" << endl;
	gotoxy(1, 9);
	YELLOW; cout << "->"; WHITE;cout<<" Eeeem, no... cz�owiekiem ? ";
	gotoxy(1, 10);
	YELLOW; cout << "Wybieraj�c t� klas�, dostaniesz dodatkowe: 1 si�y, 1 wytrzyma�o�ci, 2 inteligencji. 1 szcz�cia.";
	YELLOW;
	gotoxy(1, 35);
	cout << "Wybierz swoj� ras� postaci. W zale�no�ci od rasy, dostaniesz dodatkowe punkty umiej�tno�ci na start. Wybierz m�drze.                        ";

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
			YELLOW; cout << "->"; WHITE; cout << " Eeeem, no... cz�owiekiem?";
			gotoxy(1, 10);
			cout << "                                                                                                                                            ";
			gotoxy(1, 10);
			YELLOW; cout << "Wybieraj�c t� klas�, dostaniesz dodatkowe: 1 si�y, 1 wytrzyma�o�ci, 0 zwinno�ci, 2 inteligencji. 1 szcz�cia.";
			break;
		case 1:
			gotoxy(1, 9);
			cout << "                                                                                                                                            ";
			gotoxy(1, 9);
			YELLOW; cout << "->"; WHITE; cout << " JAK �MIESZ! Najwspanialszym ELFEM!";
			gotoxy(1, 10);
			cout << "                                                                                                                                            ";
			gotoxy(1, 10);
			YELLOW; cout << "Wybieraj�c t� klas�, dostaniesz dodatkowe: 0 si�y, 1 wytrzyma�o�ci, 1 zwinno�ci, 3 inteligencji. 0 szcz�cia.";
			break;
		case 2:
			gotoxy(1, 9);
			cout << "                                                                                                                                            ";
			gotoxy(1, 9);
			YELLOW; cout << "->"; WHITE; cout << " �lepy jeste�, czy co? krasnoluda� nie widzia�?";
			gotoxy(1, 10);
			cout << "                                                                                                                                            ";
			gotoxy(1, 10);
			YELLOW; cout << "Wybieraj�c t� klas�, dostaniesz dodatkowe: 2 si�y, 2 wytrzyma�o�ci, 0 zwinno�ci, 0 inteligencji. 1 szcz�cia.";

			break;
		case 3:
			gotoxy(1, 9);
			cout << "                                                                                                                                            ";
			gotoxy(1, 9);
			YELLOW; cout << "->"; WHITE; cout << " Szanowny Pan wybaczy, ale nawet nie wiem jak tu trafi�em... Hobbitem, informuje tylko ze wzgl�du na moje maniery.";
			gotoxy(1, 10);
			cout << "                                                                                                                                            ";
			gotoxy(1, 10);
			YELLOW; cout << "Wybieraj�c t� klas�, dostaniesz dodatkowe: 0 si�y, 0 wytrzyma�o�ci, 3 zwinno�ci, 1 inteligencji. 1 szcz�cia.";
			break;
		case 4:
			gotoxy(1, 9);
			cout << "                                                                                                                                            ";
			gotoxy(1, 9);
			YELLOW; cout << "->"; WHITE; cout << " Cz�owiek g�upi! *Bekni�cie* Ork ja by�! Ha, Ha!";
			gotoxy(1, 10);
			cout << "                                                                                                                                            ";
			gotoxy(1, 10);
			YELLOW; cout << "Wybieraj�c t� klas�, dostaniesz dodatkowe: 2 si�y, 1 wytrzyma�o�ci, 0 zwinno�ci, 0 inteligencji. 2 szcz�cia.";
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
	cout << "ZR�CZNO��";
	gotoxy(1, 8);
	for (int i = 0; i <= 19; i++) {
		cout << "=";
	}
	gotoxy(19, 9);
	cout << " | ";
	gotoxy(2, 9);
	cout << "WYTRZYMA�O��";
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
	cout << "SZCZʌCIE";
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
	cout << "U�YJ \\/ ORAZ /\\ ABY WYBRA� UMIEJ�ETNO��, A NAST�PNIE -> I <- BY ZMIENI� JEJ WARTO��. PAMI�TAJ, �E MO�ESZ ZROBI� TO TYLKO RAZ, NA POCZ�TKU GRY!";
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
			cout << "ZR�CZNO��";
			gotoxy(2, 9);
			cout << "WYTRZYMA�O��";
			gotoxy(2, 11);
			cout << "INTELIGENCJA";
			gotoxy(2, 13);
			cout << "SZCZʌCIE";
			break;
		case 1:
			gotoxy(2, 5);
			WHITE; cout << "SILA";
			gotoxy(2, 7);
			YELLOW; cout << "ZR�CZNO��"; WHITE;
			gotoxy(2, 9);
			cout << "WYTRZYMA�O��";
			gotoxy(2, 11);
			cout << "INTELIGENCJA";
			gotoxy(2, 13);
			cout << "SZCZʌCIE";
			break;
		case 2:
			gotoxy(2, 5);
			WHITE; cout << "SILA";
			gotoxy(2, 7);
			cout << "ZR�CZNO��";
			gotoxy(2, 9);
			YELLOW; cout << "WYTRZYMA�O��"; WHITE;
			gotoxy(2, 11);
			cout << "INTELIGENCJA";
			gotoxy(2, 13);
			cout << "SZCZʌCIE";
			break;
		case 3:
			gotoxy(2, 5);
			WHITE; cout << "SILA";
			gotoxy(2, 7);
			cout << "ZR�CZNO��";
			gotoxy(2, 9);
			cout << "WYTRZYMA�O��";
			gotoxy(2, 11);
			YELLOW; cout << "INTELIGENCJA"; WHITE;
			gotoxy(2, 13);
			cout << "SZCZʌCIE";
			break;
		case 4:
			gotoxy(2, 5);
			WHITE; cout << "SILA";
			gotoxy(2, 7);
			cout << "ZR�CZNO��";
			gotoxy(2, 9);
			cout << "WYTRZYMA�O��";
			gotoxy(2, 11);
			cout << "INTELIGENCJA";
			gotoxy(2, 13);
			YELLOW; cout << "SZCZʌCIE"; WHITE;
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
				cout << "BRAK WOLNYCH PUNKT�W!";
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
					YELLOW; cout << "NIE MO�ESZ MIE� MNIEJ SI�Y!"; WHITE;
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
					YELLOW; cout << "NIE MO�ESZ MIE� MNIEJ ZR�CZNO�CI!"; WHITE;
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
					YELLOW; cout << "NIE MO�ESZ MIE� MNIEJ WYTRZYMA�O�CI!"; WHITE;
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
					YELLOW; cout << "NIE MO�ESZ MIE� MNIEJ INTELIGENCJI!"; WHITE;
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
					YELLOW; cout << "NIE MO�ESZ MIE� MNIEJ SZCZʌCIA!"; WHITE;
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
void Postac::addItem()
{
	int space=-1;
	for (int i = 0; i < 15; i++) {
		if (eq[i].getType() == T_FREESPACE) {
			space = i;
			break;
		}
	}
	if (space != -1) {
		eq[space] = Item(T_ARMOR, 0, "Zbroja paladyna", 1, 1, 1, 1, 1, 0, 99, 0, 99, 0, 10, 24,Q_LEGENDARY);
	}
}
void Postac::showEq(int i) 
{
		eq[i].showItem(static_cast<int>(this->klasa));
}
bool Postac::visit()
{
	char k;
	int wybor = 0;
	cout << "Natrafi�e� na : ";
	switch (static_cast<int>(mapka[playerY][playerX].getPlace())) {
	case 0:
		BLUE; cout << "LAS"; WHITE;
		cout << "Chcesz si� w niego zapu�ci�? " << endl;
	case 1:
		BLUE; cout << "GORY"; WHITE;
		cout << "Chcesz si� po nich przej��? ";
	case 2:
		BLUE; cout << "DOM"; WHITE;
		cout << "Chcesz do niego wej��?";
	case 3:
		BLUE; cout << "JASKINIE"; WHITE;
		cout << "Chcesz j� zbada�?";
	case 4:
		BLUE; cout << "MIASTO"; WHITE;
		cout << "Chcesz je odwiedzi�?";
	}
	YELLOW; cout << "NIE"; WHITE; cout << "/"; cout << "TAK";
	do {
		k = _getch();
		if (k == DIR_RIGHT)wybor++;
		else if (k == DIR_LEFT) wybor--;
		if (wybor > 1) wybor = 1;
		else if (wybor < 0) wybor = 0;
		if (wybor == 0) {
			YELLOW; cout << "NIE"; WHITE; cout << "/"; cout << "TAK";
		}
		else {
			cout << "NIE"; cout << "/"; 	YELLOW; cout << "TAK"; WHITE;
		}
	} while (k != ENTER);
	if (wybor == 0) {
		return false;
	}
	else {
		mapka[playerY][playerX].visitPlace();
		return true;
	}
}
void Postac::equipItem(int item) {
	if (eq[item].isItemEquiped()) {
		eq[item].takeOff();
		this->str -= eq[item].getGStr();
		this->dex -= eq[item].getGDex();
		this->in -= eq[item].getGIn();
		this->st -= eq[item].getGSt();
		this->lu -= eq[item].getGLu();
		this->attackValueMax -= eq[item].getAttStr();
		this->attackValueMin -= eq[item].getAttStr();
		this->armor -= eq[item].getArmor();
	}
	else {
		TYPE currentItemType = eq[item].getType();
		bool sameTypeEquiped = false;
		for (int i = 0; i < 15; i++) {
			if (eq[i].isItemEquiped() == true && eq[i].getType() == currentItemType) {
				sameTypeEquiped = true;
				break;
			}
		}
		if (!sameTypeEquiped&&this->str >= eq[item].getNStr() && this->dex >= eq[item].getNDex() && this->in >= eq[item].getNIn() && this->st >= eq[item].getNSt() && this->lu >= eq[item].getNLu() && static_cast<int>(this->klasa) == eq[item].getClass()) {

			eq[item].equip();

			this->str += eq[item].getGStr();
			this->dex += eq[item].getGDex();
			this->in += eq[item].getGIn();
			this->st += eq[item].getGSt();
			this->lu += eq[item].getGLu();
			this->attackValueMax += eq[item].getAttStr();
			this->attackValueMin += eq[item].getAttStr();
			this->armor += eq[item].getArmor();
		}
	}
}

//GET METHODS
	CLASS Postac::getClass()
	{
		return this->klasa;
	}
	RACE Postac::getRace() {
		return this->rasa;
	}
	string Postac::getName() {
		return this->name;
	}
	int Postac::getXp()
	{
		return this->xp;
	}
	int Postac::getLvl()
	{
		return this->lvl;
	}

	int Postac::getStr()
	{
		return this->str;
	}

	int Postac::getDex()
	{
		return this->dex;
	}

	int Postac::getSt()
	{
		return this->st;
	}

	int Postac::getIn()
	{
		return this->in;
	}

	int Postac::getLu()
	{
		return this->lu;
	}
	int Postac::getHPotions()
	{
		return this->hPotions;
	}
	int Postac::getMPotions()
	{
		return this->mPotions;
	}
	int Postac::getHP()
	{
		return this->hp;
	}
	int Postac::getMinAttack()
	{
		return this->attackValueMin;
	}
	int Postac::getMaxAttack()
	{
		return this->attackValueMax;
	}
	int Postac::getArmor()
	{
		return this->armor;
	}

