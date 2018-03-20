#include "Kobieta.h"

Kobieta::Kobieta(Parametry* parametry, int x, int y) : Kanibal('K', parametry, x, y) {
}

Kobieta::Kobieta(Kanibal* rodzic) : Kanibal(rodzic, 'K') {
}

bool Kobieta::JestPlodny() {
	// kobieta jest plodna, gdy kanibal jest plodny i minela przerwa po urodzeniu dziecka
	return Kanibal::JestPlodny() && DzieckoWRundzie() + parametry->przerwaWPlodnosci < Wiek();
}
