#include "Parametry.h"
#include <iostream>
#include <sstream>

Parametry::Parametry(int argc, char * argv[])
{

	// parametry domyslne
	rozmiarPlanszy = 5;
	maxLiczbaRund = 20;
	dojrzaloscKanibala = 2;
	przerwaWPlodnosci = 2;
	dlugoscZycia = 10;
	maxTlok = 10;
	umieraCo = 3;
	sposobRozmieszczenia = 3;
	liczbaKobiet = 20;
	liczbaMezczyzn = 20;
	liczbaMisjonarzy = 40;

	int tmp = 0;

	if (argc > 1) {
		std::istringstream ss(argv[1]);
		if (!(ss >> tmp)) {
			std::cerr << "Argument nr 1 \"" << argv[1] << "\" jest nieprawidlowy.\n";
			std::cerr << "Przywrocono wartosc domyslna: " << rozmiarPlanszy << std::endl << std::endl;
		}
		else
			if (tmp < 5 || tmp > 25) {
				std::cerr << "Argument nr 1 \"" << argv[1] << "\" jest nieprawidlowy.\n";
				std::cerr << "rozmiarPlanszy moze przyjac wartosci od 5 do 25";
				std::cerr << "Przywrocono wartosc domyslna: " << rozmiarPlanszy << std::endl << std::endl;
			}
			else
				rozmiarPlanszy = tmp;
	}

	if (argc > 2) {
		std::istringstream ss(argv[2]);
		if (!(ss >> tmp)) {
			std::cerr << "Argument nr 2 \"" << argv[2] << "\" jest nieprawidlowy.\n";
			std::cerr << "Przywrocono wartosc domyslna: " << maxLiczbaRund << std::endl << std::endl;
		}
		else
			if (tmp < 1) {
				std::cerr << "Argument nr 2 \"" << argv[2] << "\" jest nieprawidlowy.\n";
				std::cerr << "maxLiczbaRund musi byc wieksza od 0.";
				std::cerr << "Przywrocono wartosc domyslna: " << maxLiczbaRund << std::endl << std::endl;
			}
			else
				maxLiczbaRund = tmp;
	}

	if (argc > 3) {
		std::istringstream ss(argv[3]);
		if (!(ss >> tmp)) {
			std::cerr << "Argument nr 3 \"" << argv[3] << "\" jest nieprawidlowy.\n";
			std::cerr << "Przywrocono wartosc domyslna: " << dojrzaloscKanibala << std::endl << std::endl;
		}
		else
			if (tmp < 1) {
				std::cerr << "Argument nr 3 \"" << argv[3] << "\" jest nieprawidlowy.\n";
				std::cerr << "dojrzaloscKanibala musi byc wieksza od 0.";
				std::cerr << "Przywrocono wartosc domyslna: " << dojrzaloscKanibala << std::endl << std::endl;
			}
			else
				dojrzaloscKanibala = tmp;
	}

	if (argc > 4) {
		std::istringstream ss(argv[4]);
		if (!(ss >> tmp)) {
			std::cerr << "Argument nr 4 \"" << argv[4] << "\" jest nieprawidlowy.\n";
			std::cerr << "Przywrocono wartosc domyslna: " << przerwaWPlodnosci << std::endl << std::endl;
		}
		else
			if (tmp < 1) {
				std::cerr << "Argument nr 4 \"" << argv[4] << "\" jest nieprawidlowy.\n";
				std::cerr << "przerwaWPlodnosci musi byc wieksza od 0.";
				std::cerr << "Przywrocono wartosc domyslna: " << przerwaWPlodnosci << std::endl << std::endl;
			}
			else
				przerwaWPlodnosci = tmp;
	}

	if (argc > 5) {
		std::istringstream ss(argv[5]);
		if (!(ss >> tmp)) {
			std::cerr << "Argument nr 5 \"" << argv[5] << "\" jest nieprawidlowy.\n";
			std::cerr << "Przywrocono wartosc domyslna: " << dlugoscZycia << std::endl << std::endl;
		}
		else
			if (tmp < 1) {
				std::cerr << "Argument nr 5 \"" << argv[5] << "\" jest nieprawidlowy.\n";
				std::cerr << "dlugoscZycia musi byc wieksza od 0.";
				std::cerr << "Przywrocono wartosc domyslna: " << dlugoscZycia << std::endl << std::endl;
			}
			else
				dlugoscZycia = tmp;
	}

	if (argc > 6) {
		std::istringstream ss(argv[6]);
		if (!(ss >> tmp)) {
			std::cerr << "Argument nr 6 \"" << argv[6] << "\" jest nieprawidlowy.\n";
			std::cerr << "Przywrocono wartosc domyslna: " << maxTlok << std::endl << std::endl;
		}
		else
			if ((tmp < 1) || (tmp > 10)) {
				std::cerr << "Argument nr 6 \"" << argv[6] << "\" jest nieprawidlowy.\n";
				std::cerr << "maxTlok moze przyjac wartosc od 1 do 10.";
				std::cerr << "Przywrocono wartosc domyslna: " << maxTlok << std::endl << std::endl;
			}
			else
				maxTlok = tmp;
	}

	if (argc > 7) {
		std::istringstream ss(argv[7]);
		if (!(ss >> tmp)) {
			std::cerr << "Argument nr 7 \"" << argv[7] << "\" jest nieprawidlowy.\n";
			std::cerr << "Przywrocono wartosc domyslna: " << umieraCo << std::endl << std::endl;
		}
		else
			if (tmp < 1) {
				std::cerr << "Argument nr 7 \"" << argv[7] << "\" jest nieprawidlowy.\n";
				std::cerr << "umieraCo musi byc wieksza od 0.";
				std::cerr << "Przywrocono wartosc domyslna: " << umieraCo << std::endl << std::endl;
			}
			else
				umieraCo = tmp;
	}

	if (argc > 8) {
		std::istringstream ss(argv[8]);
		bool blednyParametr = !(ss >> tmp);
		if (blednyParametr || (tmp > 3) || (tmp < 1)) {
			std::cerr << "Argument nr 8 \"" << argv[8] << "\" jest nieprawidlowy.\n";
			std::cerr << "Prawid³owa wartosc to 1, 2 lub 3.";
			std::cerr << "Przywrocono wartosc domyslna: " << sposobRozmieszczenia << std::endl << std::endl;
		}
		else
			sposobRozmieszczenia = tmp;
	}


	int maxLiczbaOsob = rozmiarPlanszy*rozmiarPlanszy*maxTlok / 3;

	if (argc > 9) {
		std::istringstream ss(argv[9]);
		if (!(ss >> tmp)) {
			std::cerr << "Argument nr 9 \"" << argv[9] << "\" jest nieprawidlowy.\n";
			std::cerr << "Przywrocono wartosc domyslna: " << liczbaKobiet << std::endl << std::endl;
		}
		else
			if ((tmp > maxLiczbaOsob) || (tmp < 0)) {
				std::cerr << "Argument nr 9 \"" << argv[9] << "\" jest nieprawidlowy.\n";
				std::cerr << "liczbaKobiet nie moze byc mniejsza od 0.";
				std::cerr << "Maksymalna liczba osob nie moze byc wieksza niz " << maxLiczbaOsob << '\n';
				std::cerr << "Przywrocono wartosc domyslna: " << liczbaKobiet << std::endl << std::endl;
			}
			else
				liczbaKobiet = tmp;
	}

	int liczbaOsob = 0;

	if (argc > 10) {
		std::istringstream ss(argv[10]);
		if (!(ss >> tmp)) {
			std::cerr << "Argument nr 10 \"" << argv[10] << "\" jest nieprawidlowy.\n";
			std::cerr << "Przywrocono wartosc domyslna: " << liczbaMezczyzn << std::endl << std::endl;
		}
		else {
			liczbaOsob = liczbaKobiet + tmp;
			if (liczbaOsob > maxLiczbaOsob) {
				std::cerr << "Argument nr 10 \"" << argv[10] << "\" jest nieprawidlowy.\n";
				std::cerr << "Zadeklarowana liczba osob jest za duza.\nLiczba osob nie moze byc wieksza niz " << maxLiczbaOsob << '\n';
				std::cerr << "Przywrocono wartosc domyslna: " << liczbaMezczyzn << std::endl << std::endl;
			}
			else
				if (tmp < 0) {
					std::cerr << "Argument nr 10 \"" << argv[10] << "\" jest nieprawidlowy.\n";
					std::cerr << "liczbaMezczyzn nie moze byc mniejsza od 0.";
					std::cerr << "Przywrocono wartosc domyslna: " << liczbaMezczyzn << std::endl << std::endl;
				}
				else
					liczbaMezczyzn = tmp;
		}
	}

	if (argc > 11) {
		std::istringstream ss(argv[11]);
		if (!(ss >> tmp)) {
			std::cerr << "Argument nr 11 \"" << argv[11] << "\" jest nieprawidlowy.\n";
			std::cerr << "Przywrocono wartosc domyslna: " << liczbaMisjonarzy << std::endl << std::endl;

		}
		else {
			liczbaOsob = liczbaKobiet + liczbaMezczyzn + tmp;
			if (liczbaOsob > maxLiczbaOsob) {
				std::cerr << "Argument nr 11 \"" << argv[11] << "\" jest nieprawidlowy.\n";
				std::cerr << "Zadeklarowana liczba osob jest za duza.\nLiczba osob nie moze byc wieksza niz " << maxLiczbaOsob << '\n';
				std::cerr << "Przywrocono wartosc domyslna: " << liczbaMisjonarzy << std::endl << std::endl;
			}
			else
				if (tmp < 0) {
					std::cerr << "Argument nr 11 \"" << argv[11] << "\" jest nieprawidlowy.\n";
					std::cerr << "liczbaMisjonarzy nie moze byc mniejsza od 0.";
					std::cerr << "Przywrocono wartosc domyslna: " << liczbaMisjonarzy << std::endl << std::endl;
				}
				else
				{
					liczbaMisjonarzy = tmp;
				}
		}
	}
	liczbaOsob = liczbaKobiet + liczbaMezczyzn + liczbaMisjonarzy;
	if (liczbaOsob > maxLiczbaOsob)
		exit(99);

}