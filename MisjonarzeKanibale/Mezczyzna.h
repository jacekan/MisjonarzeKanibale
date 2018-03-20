/**
 * @file	Mezczyzna.h.
 *
 * @brief	Deklaracja klasy mezczyzna 
 */

#pragma once
#include "Kanibal.h"

/**
 * @class	Mezczyzna
 *
 * @brief	Reprezentuje mê¿czyznê
 *
 * @date	23.01.2018
 */

class Mezczyzna : public Kanibal {
public:

	/**
	 * @fn	Mezczyzna::Mezczyzna(Parametry* parametry, int x, int y);
	 *
	 * @brief	Konstructor tworzy mezczyzne na pozycji X Y
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	parametry	If non-null, the parametry.
	 * @param 		  	x		 	The x coordinate.
	 * @param 		  	y		 	The y coordinate.
	 */

	Mezczyzna(Parametry* parametry, int x, int y);

	/**
	 * @fn	Mezczyzna::Mezczyzna(Kanibal* rodzic);
	 *
	 * @brief	Konstructor tworzy mezczyzna na podstawie rodzica
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	rodzic	If non-null, the rodzic.
	 */

	Mezczyzna(Kanibal* rodzic);

public:

	/**
	 * @fn	bool Mezczyzna::JestPlodny() override;
	 *
	 * @brief	Sprawdza, czy mezczyzna jest plodny
	 *
	 * @date	23.01.2018
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool JestPlodny() override; 
};
