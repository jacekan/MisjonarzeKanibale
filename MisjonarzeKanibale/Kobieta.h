/**
 * @file	Kobieta.h.
 *
 * @brief	Deklaracja klasy Kobieta
 */

#pragma once
#include "Kanibal.h"

/**
 * @class	Kobieta
 *
 * @brief	Reprezentuje kobiet�.
 *
 * @date	23.01.2018
 */

class Kobieta : public Kanibal {
public:

	/**
	 * @fn	Kobieta::Kobieta(Parametry* parametry, int x, int y);
	 *
	 * @brief	Constructor
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	parametry	Wska�nik na parametry.
	 * @param 		  	x		 	Wsp�rz�dna x.
	 * @param 		  	y		 	Wsp�rz�dna y.
	 */
	 
	Kobieta(Parametry* parametry, int x, int y);

	/**
	 * @fn	Kobieta::Kobieta(Kanibal* rodzic);
	 *
	 * @brief	Constructor
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	rodzic	na rodzica.
	 */

	Kobieta(Kanibal* rodzic);

public:

	/**
	 * @fn	bool Kobieta::JestPlodny() override;
	 *
	 * @brief	Sprawdza czy kanibal jest p�odny.
	 *
	 * @date	23.01.2018
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool JestPlodny() override; // sprawdza, czy kobieta jest plodna
};
