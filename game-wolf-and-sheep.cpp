#include<iostream>
#include<stdlib.h>  
#include<string.h>
using namespace std;
const int SZEROKOSC = 8;
const int WYSOKOSC = 8;
const char CZARNE = ' ';
const char BIALE = '.';
const char ETYKIETA_X[] = "ABCDEFGH";
const char SCIANA = '|';
const char wilkChar = 'w';
const char kozyChar = 'k';
int wilk = 61;

int koza1 = 0;
int koza2 = 2;
int koza3 = 4;
int koza4 = 6;
int koza5 = 9;
int koza6 = 11;
int koza7 = 13;
int koza8 = 15;
int koza9 = 16;
int koza10 = 18;
int koza11 = 20;
int koza12 = 22;


void drukujEtykieteX() {
	cout << ' ';
	for (int j = 0; j < SZEROKOSC; j++) {                             //rysowanie osi znaków ABCD
		cout << ETYKIETA_X[j] << ' ';
	}
	cout << endl;
}
int przypisz_indeks_liter(char litera) {
	for (int i = 0; i < SZEROKOSC; i++) {                          //funkcja przyporzadkowuje cyfrom litery z tablicy X
		if (litera == ETYKIETA_X[i]) {
			return i;
		}
	}
	return -1;
}
void rysujTablice(int wilkPoz, int koza1Poz, int koza2Poz, int koza3Poz, int koza4Poz, int koza5Poz, int koza6Poz, int koza7Poz, int koza8Poz, int koza9Poz, int koza10Poz, int koza11Poz, int koza12Poz) {
	bool black = false;                                    //rysowanie szachownicy

	for (int i = WYSOKOSC; i > 0; i--) {                    //  rysuje kolumny
		cout << SCIANA;                                                        
		for (int j = 0; j < SZEROKOSC; j++) {               // rysuje wiersze
			int obecnaPozycja = (i - 1)*WYSOKOSC + j;       // zaczyna od lewego gornego rogu, czyli pozycji nr 56
			if (obecnaPozycja == wilkPoz) {                 //ustalanie pozycji pionów
				cout << wilkChar;
			}
			else if (obecnaPozycja == koza1Poz || obecnaPozycja == koza2Poz || obecnaPozycja == koza3Poz || obecnaPozycja == koza4Poz || obecnaPozycja == koza5Poz || obecnaPozycja == koza6Poz || obecnaPozycja == koza7Poz|| obecnaPozycja == koza8Poz  || obecnaPozycja == koza9Poz || obecnaPozycja == koza10Poz || obecnaPozycja == koza11Poz || obecnaPozycja == koza12Poz) {
				cout << kozyChar;
			}
			else if (black == true) {
				cout << CZARNE;
			}
			else {
				cout << BIALE;
			}
			cout << SCIANA;
			bool jestToOstatnia = (j == (SZEROKOSC - 1));                                 /*rysowanie scian szachownicy*/
			if (!jestToOstatnia) black = !black;
		}
		int labelY = i;
		cout << labelY << endl;
	}
	drukujEtykieteX(); // rysowanie znakow abcd
}
int obliczaniePozycji(char pos[]) {            // tutaj wpada z klawiatury np G1
	int i = pos[1] - 48;                    // odejmuje 48 bo chcemy miec 1 z tablicy ascii
	                                        // pos zawiera sie w przedziale pos[1] = <49,56> 
	int j = przypisz_indeks_liter(pos[0]);  // zamienia litere na liczbe
	if (j == -1) {
		return -1;
	}                                                                   /*obliczanie pozycji kolejnego ruchu*/
	if (i > WYSOKOSC || i < 1) { 
		return -1;
	}
	int position = (i - 1) * 8 + j; // wzor na nr indeksu w zaleznosci od parametrow , jego zbior zwiera sie <0, 64>
	return position;
}
bool PozycjaJestDostepna(int nastepnaPozycja) {
	if (nastepnaPozycja == koza1 || nastepnaPozycja == koza2 || nastepnaPozycja == koza3 || nastepnaPozycja == koza4 || nastepnaPozycja == koza5 || nastepnaPozycja == koza6 || nastepnaPozycja == koza7 || nastepnaPozycja == koza8 || nastepnaPozycja == koza9 || nastepnaPozycja == koza10 || nastepnaPozycja == koza11 || nastepnaPozycja == koza12 || nastepnaPozycja == wilk) {
		return false;
	}                                                                 //funkcja sprawdza czy pole kolejnego ruchu jest wolne
	return true;
}
bool czyPozycjaWilkaDostepna(int nextPosition) {
	int absoluteDiff = abs(nextPosition - wilk); // sprawdza czy nie stoi wilk
	if (absoluteDiff != 7 && absoluteDiff != 9) { // dwa pola przed wilkiem
		return false;
	}
	return PozycjaJestDostepna(nextPosition);
}                                                                       //funkcje sprawdzaja poprawnosc kolejnego ruchu
																		//kozy i wilka (7,9)
bool czyPozycjaKozyDostepna(int currentPosition, int nextPosition) {
	int diff = nextPosition - currentPosition;
	if (diff != 7 && diff != 9) {
		return false;
	}
	return PozycjaJestDostepna(nextPosition);
}
bool czyPozycjaKozy(int pos) {
	if (pos == koza1 || pos == koza2 || pos == koza3 || pos == koza4 || pos == koza5 || pos == koza6 || pos == koza7 || pos == koza8 || pos == koza9 || pos == koza10 || pos == koza11 || pos == koza12) {
		return true;
	}
	return false;
}
void usuwanieKozy(int & bityPionek) {
	if (bityPionek == koza1) {
		koza1 = -2;
	}
	else if (bityPionek == koza2) {
		koza2 = -2;
	}
	else if (bityPionek == koza3) {
		koza3 = -2;
	}
	else if (bityPionek == koza4) {
		koza4 = -2;
	}
	else if (bityPionek == koza5) {
		koza5 = -2;
	}
	else if (bityPionek == koza6) {
		koza6 = -2;
	}
	else if (bityPionek == koza7) {
		koza7 = -2;
	}
	else if (bityPionek == koza8) {
		koza8 = -2;
	}
	else if (bityPionek == koza9) {
		koza9 = -2;
	}
	else if (bityPionek == koza10) {
		koza10 = -2;
	}
	else if (bityPionek == koza11) {
		koza11 = -2;
	}
	else {
		koza12 = -2;
	}
}
int lapanieKozy(int pos ,int& bityPionek) {                               // f. zwraca nr pola o ile bylo zbicie 

	if ((czyPozycjaKozy(wilk - 9) && PozycjaJestDostepna(pos)) && (pos == wilk-18)){               
		bityPionek = wilk - 9;                                            // spr czy na polu na ktore chce wejsc nie stoi jakas postac
			return wilk -18;
	}
	else if ((czyPozycjaKozy(wilk + 9) && PozycjaJestDostepna(pos)) && (pos == wilk+18)) {
		bityPionek = wilk + 9;
		return wilk +18;
	}
	else if ((czyPozycjaKozy(wilk - 7) && PozycjaJestDostepna(pos)) && (pos == wilk-14)) {
		bityPionek = wilk - 7;
		return wilk -14;
	}
	else if ((czyPozycjaKozy(wilk + 7) && PozycjaJestDostepna(pos)) && (pos == wilk +14)) {
		bityPionek = wilk + 7;
		return wilk + 14;
	}
	else return -1;
   }
bool czyKozyWygraly() { // sprawdza czy wylk jest otoczony przez kozy
	if ((wilk == 43 || wilk == 45 || wilk == 29 || wilk==27 || wilk == 36 || wilk==34 || wilk == 20 || wilk == 18) && (czyPozycjaKozy(wilk - 7) && czyPozycjaKozy(wilk + 7) && czyPozycjaKozy(wilk - 9) && czyPozycjaKozy(wilk + 9) && czyPozycjaKozy(wilk - 14) && czyPozycjaKozy(wilk + 14) && czyPozycjaKozy(wilk - 18) && czyPozycjaKozy(wilk + 18))) {
		return true; 
	}
	else if ((wilk == 47 || wilk == 31) && (czyPozycjaKozy(wilk + 7) && czyPozycjaKozy(wilk - 9) && czyPozycjaKozy(wilk + 14) && czyPozycjaKozy(wilk - 18)))
		return true;
	else if ((wilk == 32 || wilk == 16) && (czyPozycjaKozy(wilk - 7) && czyPozycjaKozy(wilk + 9) && czyPozycjaKozy(wilk - 14) && czyPozycjaKozy(wilk + 18)))
		return true;
	else if ((wilk == 48) && (czyPozycjaKozy(wilk - 7) && czyPozycjaKozy(wilk + 9) && czyPozycjaKozy(wilk - 14) ))
		return true;
	else if ((wilk == 57) && (czyPozycjaKozy(wilk - 9) && czyPozycjaKozy(wilk -7) && czyPozycjaKozy(wilk - 14)))
		return true;
	else if ((wilk == 59 || wilk == 61) && (czyPozycjaKozy(wilk - 9) && czyPozycjaKozy(wilk - 18) && czyPozycjaKozy(wilk - 7) && czyPozycjaKozy(wilk - 14)))
		return true;
	else if ((wilk == 63) && (czyPozycjaKozy(wilk - 9) && czyPozycjaKozy(wilk - 18) ))
		return true;
	else if ((wilk == 9) && (czyPozycjaKozy(wilk - 9) && czyPozycjaKozy(wilk +9) && czyPozycjaKozy(wilk + 18) && czyPozycjaKozy(wilk + 7) && czyPozycjaKozy(wilk - 7)))
		return true;
	else if ((wilk == 11|| wilk == 13) && (czyPozycjaKozy(wilk - 9) && czyPozycjaKozy(wilk + 9) && czyPozycjaKozy(wilk + 18) && czyPozycjaKozy(wilk + 7) && czyPozycjaKozy(wilk - 7)&& czyPozycjaKozy(wilk + 14) ))
		return true;
	else if ((wilk == 41 || wilk ==25) && (czyPozycjaKozy(wilk - 9) && czyPozycjaKozy(wilk + 9) && czyPozycjaKozy(wilk + 18) && czyPozycjaKozy(wilk + 7) && czyPozycjaKozy(wilk - 7) && czyPozycjaKozy(wilk - 14)))
		return true;
	else if ((wilk == 38 || wilk == 22) && (czyPozycjaKozy(wilk - 9) && czyPozycjaKozy(wilk + 9) && czyPozycjaKozy(wilk - 18) && czyPozycjaKozy(wilk + 7) && czyPozycjaKozy(wilk - 7) && czyPozycjaKozy(wilk + 14)))
		return true;
	else if ((wilk == 50 || wilk == 52) && (czyPozycjaKozy(wilk - 9) && czyPozycjaKozy(wilk + 9) && czyPozycjaKozy(wilk - 18) && czyPozycjaKozy(wilk + 7) && czyPozycjaKozy(wilk - 7) && czyPozycjaKozy(wilk - 14)))
		return true;
	else if ((wilk == 54) && (czyPozycjaKozy(wilk - 9) && czyPozycjaKozy(wilk + 9) && czyPozycjaKozy(wilk - 18) && czyPozycjaKozy(wilk + 7) && czyPozycjaKozy(wilk - 7)))
		return true;
	else if ((wilk == 15) && (czyPozycjaKozy(wilk + 7) && czyPozycjaKozy(wilk - 9) && czyPozycjaKozy(wilk + 14)))
		return true;

	return false;
}
int main() {
	char wybranieKozy[] = "  ";
	char nastepnaPozycjaPostaci[] = "  ";
	int poprzedniaPozycjaKozy;
	bool ruchGraczaWilka = true;
	bool wygranaKoz = true;
	bool isGameOver = false;
	
	while (isGameOver == false) {
		system("cls");
		rysujTablice(wilk, koza1, koza2, koza3, koza4, koza5, koza6, koza7, koza8, koza9, koza10, koza11, koza12);
		

		/****************Ruch Wilka *******************/
		if (ruchGraczaWilka) {
			bool nastepnaPozycjaNiewazna = true;
			while (nastepnaPozycjaNiewazna) {
				cout << "Podaj nastepna pozycje wilka: " << endl;
				cin >> nastepnaPozycjaPostaci;
				int pos = obliczaniePozycji(nastepnaPozycjaPostaci);    
				int bityPionek;
				if (lapanieKozy(pos,bityPionek) != -1) {
					wilk = lapanieKozy(pos,bityPionek);
					usuwanieKozy(bityPionek);
					nastepnaPozycjaNiewazna = false;
					ruchGraczaWilka = false;
				}
				else if (pos != -1 && czyPozycjaWilkaDostepna(pos)) {
					if (pos < 8) {       // jesli wilk przejdzie na druga strone - koniec rozgrywki
						wilk = pos;
						isGameOver = true;
						break;
					}
				
					wilk = pos;
					nastepnaPozycjaNiewazna = false;
					ruchGraczaWilka = false;
				}
				else {
					cout << "Nieprawidlowy ruch. ";
				}
			}
		}


		/****************Ruch Koz ******************/
		else {
			bool obecnaPozycjaNiewazna = true;
			while (obecnaPozycjaNiewazna) {
				cout << "Podaj pozycje kozy, ktora chcesz ruszyc: " << endl;
				cin >> wybranieKozy;
				int nastPozycjaKozy = obliczaniePozycji(wybranieKozy);                       //sprawdzanie czy na podanej
				if (nastPozycjaKozy != -1 && czyPozycjaKozy(nastPozycjaKozy)) {                     //pozycji znajduje sie koza
					poprzedniaPozycjaKozy = nastPozycjaKozy;
					obecnaPozycjaNiewazna = false;
				}
				else {
					cout << "Na tej pozycji nie ma Kozy! ";
				}
			}
			bool nastepnaPozycjaNiewazna = true;
			while (nastepnaPozycjaNiewazna) {
				cout << "Podaj nastepna pozycje kozy:" << endl;
				cin >> nastepnaPozycjaPostaci;
				int nastPozycjaKozy1 = obliczaniePozycji(nastepnaPozycjaPostaci);                //sprawdzenie dostepnosci ruchu
				if (nastPozycjaKozy1 != -1 && czyPozycjaKozyDostepna(poprzedniaPozycjaKozy, nastPozycjaKozy1)) {
					if (poprzedniaPozycjaKozy == koza1) {
						koza1 = nastPozycjaKozy1;
					}
					else if (poprzedniaPozycjaKozy == koza2) {
						koza2 = nastPozycjaKozy1;
					}
					else if (poprzedniaPozycjaKozy == koza3) {
						koza3 = nastPozycjaKozy1;
					}
					else if (poprzedniaPozycjaKozy == koza4) {
						koza4 = nastPozycjaKozy1;
					}
					else if (poprzedniaPozycjaKozy == koza5) {
						koza5 = nastPozycjaKozy1;
					}
					else if (poprzedniaPozycjaKozy == koza6) {
						koza6 = nastPozycjaKozy1;
					}
					else if (poprzedniaPozycjaKozy == koza7) {
						koza7 = nastPozycjaKozy1;
					}
					else if (poprzedniaPozycjaKozy == koza8) {
						koza8 = nastPozycjaKozy1;
					}
					else if (poprzedniaPozycjaKozy == koza9) {
						koza9 = nastPozycjaKozy1;
					}
					else if (poprzedniaPozycjaKozy == koza10) {
						koza10 = nastPozycjaKozy1;
					}
					else if (poprzedniaPozycjaKozy == koza11) {
						koza11 = nastPozycjaKozy1;
					}
					else {
						koza12 = nastPozycjaKozy1;
					}
					if (czyKozyWygraly()) {
						wygranaKoz = false;
						isGameOver = true;
						break;
					}
					ruchGraczaWilka = true;
					nastepnaPozycjaNiewazna = false;
				}
				else {
					cout << "Nieprawidlowy ruch! ";
				}
			}

		}
	}
	system("cls");
	rysujTablice(wilk, koza1, koza2, koza3, koza4, koza5, koza6, koza7, koza8, koza9, koza10, koza11, koza12); 
	
	if (wygranaKoz) {
		cout << "Wilki wygrala!" << endl;
	}
	else {
		cout << "Kozy wygraly!" << endl;
	}
	system("pause");
	return 0;


}