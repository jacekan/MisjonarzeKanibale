/**
 * @file	Kanibal.h.
 *
 * @brief	Deklaracja klasy kanibal
 */

#pragma once
#include "Osoba.h"

/**
 * @class	Kanibal
 *
 * @brief	Klasa reprezentuj¹ca kanibala.
 * 			Klasa bazowa dla kobiety i mê¿czyzny.
 *
 * @date	23.01.2018
 */

class Kanibal : public Osoba {
public:

	/**
	 * @fn	Kanibal::Kanibal(char plec, Parametry* parametry, int x, int y);
	 *
	 * @brief	Konstruktor tworzacy kanibala o podanej plci na pozycji X Y.
	 *
	 * @date	23.01.2018
	 *
	 * @param 		  	plec	 	P³eæ kanibala;
	 * @param [in,out]	parametry	WskaŸnik na obiekt zawieraj¹c parametry programu.
	 * @param 		  	x		 	Wspó³rzêdna x.
	 * @param 		  	y		 	Wspó³rzêdna y.
	 */

	Kanibal(char plec, Parametry* parametry, int x, int y);

	/**
	 * @fn	Kanibal::Kanibal(Kanibal* kanibal, char plec);
	 *
	 * @brief	Konstruktor tworzacy kanibala o podanej plci.
	 *
	 * @date	23.01.2018
	 *
	 * @param [in,out]	kanibal	If non-null, the kanibal.
	 * @param 		  	plec   	The plec.
	 */

	Kanibal(Kanibal* kanibal, char plec);

public:

	/**
	 * @fn	virtual bool Kanibal::JestPlodny();
	 *
	 * @brief	Sprawdza czy kanibal jest plodny.
	 *
	 * @date	23.01.2018
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	virtual bool JestPlodny(); 

	/**
	 * @fn	Kanibal* Kanibal::Dziecko(char plec);
	 *
	 * @brief	Tworzy dziecko o podanej plci.
	 *
	 * @date	23.01.2018
	 *
	 * @param	plec	P³eæ kanibala.
	 *
	 * @return	Wska¿nik na utworzon¹ osobê.
	 */

	Kanibal* Dziecko(char plec);

	/**
	 * @fn	void Kanibal::Dziecko();
	 *
	 * @brief	Zaznacza, ze kanibal bral udzial w rodzeniu dziecka w tej rundzie.
	 *
	 * @date	23.01.2018
	 */

	void Dziecko(); 

	/**
	 * @fn	void Kanibal::NowaRunda() override;
	 *
	 * @brief	Nowa runda kanibala.
	 *
	 * @date	23.01.2018
	 */

	void NowaRunda() override; 

	/**
	 * @fn	bool Kanibal::MaDzieckoWTejRundzie();
	 *
	 * @brief	Sprawdza, czy kanibal bral udzial w rodzeniu dziecka w tej rundzie
	 *
	 * @date	23.01.2018
	 *
	 * @return	True if it succeeds, false if it fails.
	 */

	bool MaDzieckoWTejRundzie(); 

	/**
	 * @fn	char Kanibal::Plec();
	 *
	 * @brief	Zwraca p³eæ kanibala.
	 *
	 * @date	23.01.2018
	 *
	 * @return	A char.
	 */

	char Plec();

	/**
	 * @fn	char Kanibal::Typ() override;
	 *
	 * @brief	Zwraca typ osoby. 'M' misjonarz 'K' kanibal
	 *
	 * @date	23.01.2018
	 *
	 * @return	A char.
	 */

	char Typ() override;

protected:

	/**
	 * @fn	int Kanibal::DzieckoWRundzie();
	 *
	 * @brief	Zwraca , w ktorej ostatnio bral udzial przy rodzeniu dziecka.
	 *
	 * @date	23.01.2018
	 *
	 * @return	numer rundy.
	 */

	int DzieckoWRundzie();

private:

	/** @brief	numer rundy, w ktorej ostatnio bral udzial przy rodzeniu dziecka */
	int dzieckoWRundzie;

	/** @brief	K - kobieta, M - mezczyzna */
	char plec;
};
