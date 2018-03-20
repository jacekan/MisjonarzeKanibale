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
 * @brief	Reprezentuje kobietê.
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
	 * @param [in,out]	parametry	WskaŸnik na parametry.
	 * @param 		  	x		 	Wspó³rzêdna x.
	 * @param 		  	y		 	Wspó³rzêdna y.
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
	 * @brief	Sprawdza czy kanibal jest p³odny.
	 *
	 * @date	23.01.2018
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool JestPlodny() override; // sprawdza, czy kobieta jest plodna
};
