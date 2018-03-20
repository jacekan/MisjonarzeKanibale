#include "Mezczyzna.h"

Mezczyzna::Mezczyzna(Parametry* parametry, int x, int y) : Kanibal('M', parametry, x, y) {
}

Mezczyzna::Mezczyzna(Kanibal* rodzic) : Kanibal(rodzic, 'M') {
}

bool Mezczyzna::JestPlodny() {
	// mezczyzna jest plodny, gdy kanibal jest plodny i nie mial dziecka w tej rundzie
	return Kanibal::JestPlodny() && DzieckoWRundzie() < Wiek();
}
