/**
 * @file	Gra.h.
 *
 * @brief	Deklaracja klasy gra.
 */

#pragma once

#include "Kobieta.h"
#include "Mezczyzna.h"
#include "Misjonarz.h"
#include "ListaOsob.h"
#include "Parametry.h"
#include <iostream>
#include <ctime>

/**
 * @class	Gra
 *
 * @brief	G³ówna klasa programu obs³uguj¹ca przebieg symulacji.
 *
 * @date	23.01.2018
 */

class Gra {
public:

	/**
	 * @fn	Gra::Gra(int argumentCount, char* arguments[]);
	 *
	 * @brief	Konstruktor. Wywo³uje konstruktor klasy Parametry.
	 *
	 * @date	23.01.2018
	 *
	 * @param 		  	argumentCount	Number of arguments.
	 * @param [in,out]	arguments	 	If non-null, the arguments.
	 */

	Gra(int argumentCount, char* arguments[]);

	/**
	 * @fn	Gra::~Gra();
	 *
	 * @brief	Destructor
	 *
	 * @date	23.01.2018
	 */

	~Gra();

public:

	/**
	 * @fn	void Gra::NowaGra();
	 *
	 * @brief	Inicjalizuje grê. Zawiera g³ówn¹ pêtlê programu
	 *
	 * @date	23.01.2018
	 */

	void NowaGra();

	/**
	 * @fn	bool Gra::NowaRunda();
	 *
	 * @brief	Odœwie¿a stan gry w danej rundzie. 
	 * 			
	 * 			Inkrementuje licznik rund. Wywo³uje metody implementuj¹ce rodzenie 
	 * 			dzieci, zjadanie misjonarzy, nawracanie kanibali, wymieranie 
	 * 			z przeludnienia, wymieranie ze staroœci. Zwraca warunek koñca gry.
	 *
	 * @date	23.01.2018
	 *
	 * @return	True jeœli gra trwa, false jeœli siê skoñczy³a.
	 */

private:

	/**
	 * @fn	bool Gra::NowaRunda();
	 *
	 * @brief	Determines if we can nowa runda
	 *
	 * @date	23.01.2018
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool NowaRunda(); // przechodzi do kolejnej rundy

	/**
	 * @fn	void Gra::WstawOsobe(Osoba* osoba);
	 *
	 * @brief	Wstawia osobê na plansze.
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	osoba	If non-null, the osoba.
	 */

	void WstawOsobe(Osoba* osoba);

	/**
	 * @fn	void Gra::LiczbaOsob(int& kanibale, int& misjonarze);
	 *
	 * @brief	Zlicza liczbe osob na planszy: osobno kanibale i misjonarze.
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	kanibale  	Liczba kanibali.
	 * @param [in,out]	misjonarze	Liczba misjonarzy.
	 */

	void LiczbaOsob(int& kanibale, int& misjonarze);

	/**
	 * @fn	int Gra::Runda();
	 *
	 * @brief	Zwraca numer aktualnej rundy.
	 *
	 * @date	23.01.2018
	 *
	 * @return	An int.
	 */

	int Runda(); 

	/**
	 * @fn	void Gra::RozmiescOsoby();
	 *
	 * @brief	Rozmiesc osoby
	 *
	 * @date	23.01.2018
	 */

	void RozmiescOsoby();

	/**
	 * @fn	void Gra::Info();
	 *
	 * @brief	Infoes this object
	 *
	 * @date	23.01.2018
	 */

	void Info();


	/** @brief	parametry gry */
	Parametry* parametry;

	/** @brief	numer rundy */
	int runda;

	/** @brief	kontener na wszystkie osoby biorace udzial w grze (misjonarze i kanibale) */
	ListaOsob listaOsob;

	/**
	 * @fn	void Gra::RozmiescLosowo();
	 *
	 * @brief	Rozmieszcza osoby na planszy w sposób pseudolosowy.
	 *
	 * @date	23.01.2018
	 */

	void RozmiescLosowo();

	/**
	 * @fn	void Gra::RozmiescWNaroznikach();
	 *
	 * @brief	Rozmieszcza osoby na planszy w naro¿nikach.
	 *
	 * @date	23.01.2018
	 */

	void RozmiescWNaroznikach();

	/**
	 * @fn	void Gra::RozmiescKanibaleNaLewoMisjonarzeNaPrawo();
	 *
	 * @brief	Rozmieszcza osoby na planszy kanibale na lewo misjonarze na prawo.
	 *
	 * @date	23.01.2018
	 */

	void RozmiescKanibaleNaLewoMisjonarzeNaPrawo();

	/**
	 * @fn	void Gra::Wymieszaj(int *array, int n);
	 *
	 * @brief	Miesza zawartoœæ tablicy. Dzia³a tylko jeœli n jest du¿o mniejsze od RAND_MAX.
	 * 			Pomocnicza dla void RozmiescLosowo();
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	array	WskaŸnik na tablicê.
	 * @param 		  	n	 	Liczba elementów tablicy.
	 */

	void Wymieszaj(int *array, int n);
};
