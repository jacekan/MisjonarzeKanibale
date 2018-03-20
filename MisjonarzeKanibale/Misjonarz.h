/**
 * @file	Misjonarz.h.
 *
 * @brief	Deklaracja klasy Misjonarz
 */

#pragma once
#include "Osoba.h"

/**
 * @class	Misjonarz
 *
 * @brief	Reprezentuje misjonarza
 *
 * @date	23.01.2018
 */

class Misjonarz : public Osoba {
public:

	/**
	 * @fn	Misjonarz::Misjonarz(Parametry* parametry, int x, int y);
	 *
	 * @brief	Konstructor tworzy misjonarza na pozycji X Y
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	parametry	If non-null, the parametry.
	 * @param 		  	x		 	The x coordinate.
	 * @param 		  	y		 	The y coordinate.
	 */

	Misjonarz(Parametry* parametry, int x, int y);

	/**
	 * @fn	Misjonarz::Misjonarz(Osoba* osoba);
	 *
	 * @brief	Konstructor tworzy misjonarza na podstawie innej osoby
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	osoba	If non-null, the osoba.
	 */

	Misjonarz(Osoba* osoba);
public:

	/**
	 * @fn	char Misjonarz::Typ() override;
	 *
	 * @brief	Gets the typ
	 *
	 * @date	23.01.2018
	 *
	 * @return	A char.
	 */

	char Typ() override;
};