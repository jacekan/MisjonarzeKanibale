/**
 * @file	Osoba.h.
 *
 * @brief	Deklaracja klasy Osoba
 */

#pragma once
#include "Parametry.h"

/**
 * @class	Osoba
 *
 * @brief	Klasa bazowa dla misjonarz i kanibala
 *
 * @date	23.01.2018
 */

class Osoba {
public:

	/**
	 * @fn	Osoba::Osoba(Parametry* parametry, int x, int y);
	 *
	 * @brief	Tworzy osobe o podanym typie: K - kanibal, M -misjonarz, na pozycji X Y
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	parametry	If non-null, the parametry.
	 * @param 		  	x		 	The x coordinate.
	 * @param 		  	y		 	The y coordinate.
	 */

	Osoba(Parametry* parametry, int x, int y);

	/**
	 * @fn	Osoba::Osoba(Osoba* osoba, bool dziecko);
	 *
	 * @brief	Tworzy osobe na podstawie innej osoby, ale o nowym typie, jesli dziecko = true, to
	 * 			ustawia wiek na 0
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	osoba  	If non-null, the osoba.
	 * @param 		  	dziecko	True to dziecko.
	 */

	Osoba(Osoba* osoba, bool dziecko);

	/**
	 * @fn	Osoba::~Osoba();
	 *
	 * @brief	Destructor
	 *
	 * @date	23.01.2018
	 */

	virtual ~Osoba();

public:

	/**
	 * @fn	virtual void Osoba::NowaRunda();
	 *
	 * @brief	Nowa runda dla osoby
	 *
	 * @date	23.01.2018
	 */

	virtual void NowaRunda();  

	/**
	 * @fn	bool Osoba::JestNaXY(int x, int y);
	 *
	 * @brief	Sprawdza, czy osoba znajduje sie na pozycji X Y
	 *
	 * @date	23.01.2018
	 *
	 * @param	x	The x coordinate.
	 * @param	y	The y coordinate.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool JestNaXY(int x, int y); 

	/**
	 * @fn	virtual char Osoba::Typ() = 0;
	 *
	 * @brief	Zwraca typ osoby: K - kanibal, M - misjonarz
	 *
	 * @date	23.01.2018
	 *
	 * @return	A char.
	 */

	virtual char Typ() = 0;

	/**
	 * @fn	int Osoba::Wiek();
	 *
	 * @brief	Zwraca wiek osoby (liczbe rund)
	 *
	 * @date	23.01.2018
	 *
	 * @return	An int.
	 */

	int Wiek(); 
protected:

	/** @brief	parametry osoby */
	Parametry* parametry;
private:

	/** @brief	wpolrzedna X osoby */
	int x;
	/** @brief	wspolrzedna Y osoby */
	int y;
	/** @brief	numer rundy (wiek) */
	int runda;

private:

	/**
	 * @fn	bool Osoba::CzyPozycjaPrawidlowa(int x, int y);
	 *
	 * @brief	Sprawdza, czy podana pozycja jest prawidlowa (miesci sie na planszy)
	 *
	 * @date	23.01.2018
	 *
	 * @param	x	The x coordinate.
	 * @param	y	The y coordinate.
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool CzyPozycjaPrawidlowa(int x, int y); // 

	/**
	 * @fn	void Osoba::Wedruj();
	 *
	 * @brief	Przesuwa osobe na nowe pole, zgodnie z zasadami gry
	 *
	 * @date	23.01.2018
	 */

	void Wedruj();
};
