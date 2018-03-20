#include "Kanibal.h"
#include "Kobieta.h"
#include "Mezczyzna.h"

Kanibal::Kanibal(char plec, Parametry* parametry, int x, int y) : Osoba(parametry, x, y) {
	this->plec = plec;
	this->dzieckoWRundzie = 0;
}

Kanibal::Kanibal(Kanibal* kanibal, char plec) : Osoba(kanibal, true) {
	this->plec = plec;
	this->dzieckoWRundzie = 0;
}

void Kanibal::NowaRunda() {
	Osoba::NowaRunda();
}

bool Kanibal::JestPlodny() {
	// kanibal jest plodny, gdy osogie odpowiedni wiek
	return Wiek() >= parametry->dojrzaloscKanibala;
}

Kanibal* Kanibal::Dziecko(char plec) {
	// oznacz kanibala, ze rodzil dziecko
	Dziecko();
	Kanibal* dziecko;
	// utworz dziecko o podanej plci
	if (plec == 'K') {
		dziecko = new Kobieta(this);
	}
	else {
		dziecko = new Mezczyzna(this);
	}
	return dziecko;
}

void Kanibal::Dziecko() {
	dzieckoWRundzie = Wiek();
}

bool Kanibal::MaDzieckoWTejRundzie() {
	return dzieckoWRundzie == Wiek();
}

char Kanibal::Plec() {
	return plec;
}

char Kanibal::Typ()
{
	return 'K';
}

int Kanibal::DzieckoWRundzie() {
	return dzieckoWRundzie;
}
