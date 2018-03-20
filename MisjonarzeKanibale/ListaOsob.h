/**
 * @file	ListaOsob.h.
 *
 * @brief	Deklaracja klasy lista osob
 */

#pragma once
#include "Osoba.h"
#include "Kobieta.h"
#include "Mezczyzna.h"
#include <iostream>
#include <vector>

/**
 * @class	ListaOsob
 *
 * @brief	Reprezentuje wszystkie osoby na planszy.
 *
 * @date	23.01.2018
 */

class ListaOsob {
public:

	/**
	 * @fn	ListaOsob::~ListaOsob();
	 *
	 * @brief	Destructor
	 *
	 * @date	23.01.2018
	 */

	~ListaOsob();
public:

	/**
	 * @fn	void ListaOsob::UsunWszystkie();
	 *
	 * @brief	Usuwa wszystkie osoby z planszy
	 *
	 * @date	23.01.2018
	 */

	void UsunWszystkie(); 

	/**
	 * @fn	void ListaOsob::WstawOsobe(Osoba* osoba);
	 *
	 * @brief	Wstawia now¹ osobe na plansze
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	osoba	WskaŸnik na osobê.
	 */

	void WstawOsobe(Osoba* osoba);

	/**
	 * @fn	void ListaOsob::NowaRunda();
	 *
	 * @brief	Wszystkie osoby przechodza na kolejna runde
	 *
	 * @date	23.01.2018
	 */

	void NowaRunda(); 

	/**
	 * @fn	void ListaOsob::ZjedzMisjonarza(int x, int y);
	 *
	 * @brief	Zjada misjonarza na pozycji X Y (usuwa z planszy)
	 *
	 * @date	23.01.2018
	 *
	 * @param	x	The x coordinate.
	 * @param	y	The y coordinate.
	 */

	void ZjedzMisjonarza(int x, int y);

	/**
	 * @fn	void ListaOsob::NawrocKanibala(int x, int y);
	 *
	 * @brief	Nawraca kanibala na pozycji X Y (zamienia kanibala na misjonarza)
	 *
	 * @date	23.01.2018
	 *
	 * @param	x	The x coordinate.
	 * @param	y	The y coordinate.
	 */

	void NawrocKanibala(int x, int y); // 

	/**
	 * @fn	bool ListaOsob::CzyJestParaPlodnychKanibali(int x, int y, Kobieta*& matka, Mezczyzna*& ojciec);
	 *
	 * @brief	Sprawdza, czy na pozycji X Y jest para plodnych kanibali, jesli jest, to zwraca
	 * 			pierwsza napotkana pare (matka, ojciec)
	 *
	 * @date	23.01.2018
	 *
	 * @param 		  	x	  	The x coordinate.
	 * @param 		  	y	  	The y coordinate.
	 * @param [in,out]	matka 	[in,out] If non-null, the matka.
	 * @param [in,out]	ojciec	[in,out] If non-null, the ojciec.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool CzyJestParaPlodnychKanibali(int x, int y, Kobieta*& matka, Mezczyzna*& ojciec);

	/**
	 * @fn	void ListaOsob::Dziecko(Kobieta* matka, Mezczyzna* ojciec);
	 *
	 * @brief	Tworzy dziecko za pomoca rodzicow
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	matka 	If non-null, the matka.
	 * @param [in,out]	ojciec	If non-null, the ojciec.
	 */

	void Dziecko(Kobieta* matka, Mezczyzna* ojciec);

	/**
	 * @fn	void ListaOsob::Wymieranie(int dlugoscZycia);
	 *
	 * @brief	Wymieraj¹ wszystkie osoby, ktore przekrocza maksymalna dlugosc zycia
	 *
	 * @date	23.01.2018
	 *
	 * @param	dlugoscZycia	The dlugosc zycia.
	 */

	void Wymieranie(int dlugoscZycia);

	/**
	 * @fn	void ListaOsob::Wymieranie(int x, int y, int coKtory);
	 *
	 * @brief	Wymiera "coKtory" osobe na podanym polu X Y
	 *
	 * @date	23.01.2018
	 *
	 * @param	x	   	The x coordinate.
	 * @param	y	   	The y coordinate.
	 * @param	coKtory	The co ktory.
	 */

	void Wymieranie(int x, int y, int coKtory); 

	/**
	 * @fn	int ListaOsob::LiczbaOsob();
	 *
	 * @brief	Zwraca calkowita liczbe osob na planszy
	 *
	 * @date	23.01.2018
	 *
	 * @return	An int.
	 */

	int LiczbaOsob(); 

	/**
	 * @fn	void ListaOsob::LiczbaOsob(int& misjonarze, int& kanibale);
	 *
	 * @brief	Zwraca calkowita liczbe osob z podzialem na kanibali i misjonarzy
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	misjonarze	The misjonarze.
	 * @param [in,out]	kanibale  	The kanibale.
	 */

	void LiczbaOsob(int& misjonarze, int& kanibale);

	/**
	 * @fn	void ListaOsob::LiczbaOsob(int x, int y, int& misjonarze, int& kanibale, int& zjadajacyKanibale);
	 *
	 * @brief	Zwraca liczbe osob na pozycji X Y
	 *
	 * @date	23.01.2018
	 *
	 * @param 		  	x				 	The x coordinate.
	 * @param 		  	y				 	The y coordinate.
	 * @param [in,out]	misjonarze		 	The misjonarze.
	 * @param [in,out]	kanibale		 	The kanibale.
	 * @param [in,out]	zjadajacyKanibale	The zjadajacy kanibale.
	 */

	void LiczbaOsob(int x, int y, int& misjonarze, int& kanibale, int& zjadajacyKanibale);

	/**
	 * @fn	void ListaOsob::LiczbaOsob(int x, int y, int& liczbaOsob);
	 *
	 * @brief	Zwraca liczbe osob na pozycji X Y
	 *
	 * @date	23.01.2018
	 *
	 * @param 		  	x		  	The x coordinate.
	 * @param 		  	y		  	The y coordinate.
	 * @param [in,out]	liczbaOsob	The liczba osob.
	 */

	void LiczbaOsob(int x, int y, int& liczbaOsob); // 

private:
	/** @brief	przechowuje wszystkie listaOsob na planszy */
	/** @brief	The lista osob */
	std::vector<Osoba*> listaOsob;
};
