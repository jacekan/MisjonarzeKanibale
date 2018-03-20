#include "Osoba.h"
#include <cstdlib>

Osoba::Osoba(Parametry* parametry, int x, int y) {
	this->parametry = parametry;
	this->runda = 0;
	this->x = x;
	this->y = y;
}

Osoba::Osoba(Osoba* osoba, bool dziecko) {
	this->parametry = osoba->parametry;
	this->runda = dziecko ? 0 : osoba->runda;
	this->x = osoba->x;
	this->y = osoba->y;
}

Osoba::~Osoba()
{
}

void Osoba::NowaRunda() {
	runda++;
	Wedruj();
}

bool Osoba::JestNaXY(int x, int y) {
	return this->x == x && this->y == y;
}

char Osoba::Typ()
{
	return 0;
}

bool Osoba::CzyPozycjaPrawidlowa(int x, int y) {
	int rozmiarPlanszy = parametry->rozmiarPlanszy;
	return (x >= 0 && y >= 0 && x < rozmiarPlanszy && y < rozmiarPlanszy);
}

void Osoba::Wedruj() {
	int nowyX = x;
	int nowyY = y;
	int kierunek = rand() % 4;
	if (kierunek == 0) {
		nowyX--; // w lewo
	}
	else if (kierunek == 1) {
		nowyX++; // w prawo
	}
	else if (kierunek == 2) {
		nowyY--; // w gore
	}
	else if (kierunek == 3) {
		nowyY++; // w dol
	}
	else {
		//  nigdzie sie nie ruszaj (nie powinno wystapic)
	}
	// jesli nowa pozycja jest prawidlowa, to przejdz na nia
	if (CzyPozycjaPrawidlowa(nowyX, nowyY)) {
		x = nowyX;
		y = nowyY;
	}
}

int Osoba::Wiek() {
	return runda;
}