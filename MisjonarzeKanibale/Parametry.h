/**
 * @file	Parametry.h.
 *
 * @brief	Deklaracja klasy Parametry.
 */

#pragma once

/**
 * @struct	Parametry
 *
 * @brief	Przetwarza parametry z wiersza poleceñ.
 *
 * @date	23.01.2018
 */

struct Parametry {
	/** @brief	rozmiar planszy N */
	int rozmiarPlanszy;
	/** @brief	maksymalna liczba rund w grze */
	int maxLiczbaRund;
	/** @brief	wiek, w ktorym kanibal osiaga dojrzalosc */
	int dojrzaloscKanibala;
	/** @brief	czas przerwy w plodnosci (kobiety) po urodzeniu dziecka */
	int przerwaWPlodnosci;
	/** @brief	dlugosc zycia */
	int dlugoscZycia;
	/** @brief	maksymalny dopuszczalny tlok (liczba osob) na jednym polu */
	int maxTlok;
	/** @brief	co ktory osobnik umiera z przeludnienia */
	int umieraCo;
	/** @brief	wstepny sposob rozmieszczenia osobnikow na planszy */
	int sposobRozmieszczenia;
	/** @brief	liczba kobiet uzytych do wstepnego wypelniania planszy */
	int liczbaKobiet;
	/** @brief	liczba mezczyzn uzytych do wstepnego wypelniania planszy */
	int liczbaMezczyzn;
	/** @brief	liczba misjonarzy uzytych do wstepnego wypelniania planszy */
	int liczbaMisjonarzy;

	/**
	 * @fn	Parametry(int argc, char* argv[]);
	 *
	 * @brief	Pobiera parametry z wiersza poleceñ i sprawdza ich poprawnoœæ.
	 *
	 * @date	23.01.2018
	 *
	 * @param 		  	argc	Number of arguments.
	 * @param [in,out]	argv	If non-null, the arguments.
	 */

	Parametry(int argc, char* argv[]);
};
