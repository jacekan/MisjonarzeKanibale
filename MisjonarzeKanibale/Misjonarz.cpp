#include "Misjonarz.h"

Misjonarz::Misjonarz(Parametry* parametry, int x, int y) : Osoba(parametry, x, y) {
}

Misjonarz::Misjonarz(Osoba* osoba) : Osoba(osoba, false) {
}

char Misjonarz::Typ()
{
	return 'M';
}
