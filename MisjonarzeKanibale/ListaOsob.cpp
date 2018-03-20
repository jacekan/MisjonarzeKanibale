#include "ListaOsob.h"
#include "Misjonarz.h"
#include "Kanibal.h"
#include "Kobieta.h"
#include "Mezczyzna.h"
#include <ctime>

ListaOsob::~ListaOsob()
{
	for (int i = 0; i < listaOsob.size(); i++) {
		delete listaOsob[i];
	}
}

void ListaOsob::UsunWszystkie() {
	for (int i = 0; i < listaOsob.size(); i++) {
		delete listaOsob[i];
	}
	listaOsob.clear();
}

void ListaOsob::WstawOsobe(Osoba* osoba) {
	listaOsob.push_back(osoba);
}

void ListaOsob::NowaRunda() {
	// wszystkie osoby do nowej rundy
	for (int i = 0; i < listaOsob.size(); i++) {
		listaOsob[i]->NowaRunda();
	}
}

void ListaOsob::ZjedzMisjonarza(int x, int y) {
	// zjedz pierwszego napotkanego misjonarza na podanej pozycji X Y
	bool zjedzony = false;
	int i = 0;
	while (i < listaOsob.size() && !zjedzony) {
		Osoba* osoba = listaOsob[i];
		if (osoba->JestNaXY(x, y) && osoba->Typ() == 'M') {
			delete listaOsob[i];
			listaOsob.erase(listaOsob.begin() + i);
			zjedzony = true;
		}
		i++;
	}
}

void ListaOsob::NawrocKanibala(int x, int y) {
	// nawroc pierwszego napotkanego kanibala na pozycji X Y
	bool nawrocony = false;
	int i = 0;
	while (i < listaOsob.size() && !nawrocony) {
		Osoba* osoba = listaOsob[i];
		if (osoba->JestNaXY(x, y) && osoba->Typ() == 'K') {
			Misjonarz* misjonarz = new Misjonarz(osoba);
			delete listaOsob[i];
			listaOsob.erase(listaOsob.begin() + i);
			listaOsob.push_back(misjonarz);
			nawrocony = true;
		}
		i++;
	}
}

bool ListaOsob::CzyJestParaPlodnychKanibali(int x, int y, Kobieta*& matka, Mezczyzna*& ojciec) {
	// znajdz pierwsza plodna pare kanibali na pozycji X Y
	bool jestPlodnyMezczyzna = false;
	bool jestPlodnaKobieta = false;
	int i = 0;
	while (i < listaOsob.size() && !(jestPlodnyMezczyzna && jestPlodnaKobieta)) {
		Osoba* osoba = listaOsob[i];
		if (osoba->JestNaXY(x, y) && osoba->Typ() == 'K') {
			Kanibal* kanibal = (Kanibal*)osoba;
			if (kanibal->JestPlodny()) {
				if (kanibal->Plec() == 'K') {
					jestPlodnaKobieta = true;
					matka = (Kobieta*)kanibal;
				}
				else if (kanibal->Plec() == 'M') {
					jestPlodnyMezczyzna = true;
					ojciec = (Mezczyzna*)kanibal;
				}
			}
		}
		i++;
	}
	return jestPlodnaKobieta && jestPlodnyMezczyzna;
}

void ListaOsob::Dziecko(Kobieta* matka, Mezczyzna* ojciec) {
	// utworz dziecko o losowej plci
	srand(time(NULL));
	char plec = ((rand() % 2) == 0) ? 'K' : 'M';
	Kanibal* dziecko = matka->Dziecko(plec);
	ojciec->Dziecko();
	listaOsob.push_back(dziecko);
}

int ListaOsob::LiczbaOsob() {
	return listaOsob.size();
}

void ListaOsob::LiczbaOsob(int& misjonarze, int& kanibale) {
	misjonarze = 0;
	kanibale = 0;
	for (int i = 0; i < listaOsob.size(); i++) {
		Osoba* osoba = listaOsob[i];
		if (osoba->Typ() == 'K') {
			kanibale++;
		}
		else if (osoba->Typ() == 'M') {
			misjonarze++;
		}
	}
}

void ListaOsob::LiczbaOsob(int x, int y, int& misjonarze, int& kanibale, int& zjadajacyKanibale) {
	misjonarze = 0;
	kanibale = 0;
	zjadajacyKanibale = 0;
	for (int i = 0; i < listaOsob.size(); i++) {
		Osoba* osoba = listaOsob[i];
		if (osoba->JestNaXY(x, y)) {
			if (osoba->Typ() == 'M') {
				misjonarze++;
			}
			else if (osoba->Typ() == 'K') {
				kanibale++;
				if (!((Kanibal*)osoba)->MaDzieckoWTejRundzie()) {
					zjadajacyKanibale++;
				}
			}
		}
	}
}

void ListaOsob::LiczbaOsob(int x, int y, int & liczbaOsob)
{
	liczbaOsob = 0;
	for (int i = 0; i < listaOsob.size(); i++) {
		Osoba* osoba = listaOsob[i];
		if (osoba->JestNaXY(x, y)) {
			++liczbaOsob;
		}
	}
}

void ListaOsob::Wymieranie(int dlugoscZycia) {
	int i = 0;
	while (i < listaOsob.size()) {
		if (listaOsob[i]->Wiek() > dlugoscZycia) {
			delete listaOsob[i];
			listaOsob.erase(listaOsob.begin() + i);
		}
		else {
			i++;
		}
	}
}

void ListaOsob::Wymieranie(int x, int y, int coKtory) {
	if (coKtory < 1) {
		coKtory = 1;
	}
	int licznik = 0;
	int i = 0;
	while (i < listaOsob.size()) {
		if (listaOsob[i]->JestNaXY(x, y)) {
			if ((licznik % coKtory) == 0) {
				delete listaOsob[i];
				listaOsob.erase(listaOsob.begin() + i);
			}
			else {
				i++;
			}
			licznik++;
		}
		else {
			i++;
		}
	}
}
