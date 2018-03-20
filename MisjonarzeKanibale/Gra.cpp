#include "Gra.h"


Gra::Gra(int argc, char* argv[]) {
	this->parametry = new Parametry(argc, argv);
	this->runda = 0;
}

Gra::~Gra()
{
	delete parametry;
}

void Gra::NowaGra() {
	this->runda = 0;
	listaOsob.UsunWszystkie();

	Info();

	std::cout << "Inicjacja" << std::endl;
	// inicjacja gry i wstepne rozmieszczenie osob

	RozmiescOsoby();
	std::cout << "Poczatek gry" << std::endl;
	// petla gry - kolejne rundy
	do {
		// zlicz misjonarzy i kanibali w danej rundzie
		int kanibale;
		int misjonarze;
		LiczbaOsob(kanibale, misjonarze);
		std::cout << "runda: " << Runda() << " ->  kanibale: " << kanibale << ", misjonarze: " << misjonarze << std::endl;
	} while (NowaRunda());
	std::cout << "Koniec gry" << std::endl;
}

bool Gra::NowaRunda() {
	//listaOsob.wypisz(parametry);
	runda++;
	listaOsob.NowaRunda();
	// przejdz przez kazde pole na planszy i ...
	for (int x = 0; x < parametry->rozmiarPlanszy; x++) {
		for (int y = 0; y < parametry->rozmiarPlanszy; y++) {
			// urodzenie dzieci przez wszystkie pary (M+K), ktore w tej rundzie jeszcze nie rodzily
			Kobieta* matka;
			Mezczyzna* ojciec;
			while (listaOsob.CzyJestParaPlodnychKanibali(x, y, matka, ojciec)) {
				listaOsob.Dziecko(matka, ojciec);
			}
			int misjonarze = 0;
			int kanibale = 0;
			int zjadajacyKanibale = 0;
			listaOsob.LiczbaOsob(x, y, misjonarze, kanibale, zjadajacyKanibale);
			// zjedz misjonarza, jesli trzeba
			if (misjonarze > 0 && misjonarze <= zjadajacyKanibale) {
				listaOsob.ZjedzMisjonarza(x, y);
			}
			// nawroc kanibala, jesli to mozliwe
			if (zjadajacyKanibale > 0 && misjonarze >= zjadajacyKanibale) {
				listaOsob.NawrocKanibala(x, y);
			}
			// gdy za ciasno na polu, to czesc osob wymrze
			if (misjonarze + kanibale > parametry->maxTlok) {
				listaOsob.Wymieranie(x, y, parametry->umieraCo);
			}
		}
	}
	// niech umra wszystike za stare osoby
	listaOsob.Wymieranie(parametry->dlugoscZycia);
	// koniec, gdy przekroczony limit rund lub wszystkie osoby wymarly
	return runda < parametry->maxLiczbaRund && listaOsob.LiczbaOsob() > 0;
}

void Gra::WstawOsobe(Osoba* osoba) {
	listaOsob.WstawOsobe(osoba);
}

void Gra::LiczbaOsob(int& kanibale, int& misjonarze) {
	listaOsob.LiczbaOsob(misjonarze, kanibale);
}

int Gra::Runda() {
	return runda;
}

void Gra::RozmiescOsoby() {
	if (parametry->sposobRozmieszczenia == 1) {
		RozmiescLosowo();
	}
	else if (parametry->sposobRozmieszczenia == 2) {
		RozmiescWNaroznikach();
	}
	else if (parametry->sposobRozmieszczenia == 3) {
		RozmiescKanibaleNaLewoMisjonarzeNaPrawo();
	}
}

void Gra::Info()
{
	std::cout << "Misjonarze i kanibale" << std::endl;
	std::cout << "uzycie:" << std::endl;
	std::cout << "MisjonarzeKanibale.exe rozmiarPlanszy maxLiczbaRund dojrzaloscKanibala przerwaWPlodnosci dlugoscZycia maxTlok umieraCo sposobRozmieszczenia liczbaKobiet liczbaMezczyzn liczbaMisjonarzy" << std::endl;
	std::cout << std::endl;
}

void Gra::Wymieszaj(int *array, int n)
{
	if (n > 1)
	{
		srand(time(NULL));
		int i;
		for (i = 0; i < n; i++)
		{
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}

// rozmieszcza osoby losowo na calej planszy
void Gra::RozmiescLosowo() {
	int liczbaMisjonarzy = parametry->liczbaMisjonarzy;
	int liczbaKobiet = parametry->liczbaKobiet;
	int liczbaMezczyzn = parametry->liczbaMezczyzn;

	int	liczbaPolNaPlanszy = parametry->rozmiarPlanszy*parametry->rozmiarPlanszy;
	int* losowePole = new int[liczbaPolNaPlanszy];
	for (int i = 0; i < liczbaPolNaPlanszy; i++) {
		losowePole[i] = i;
	}
	srand(time(NULL));
	Wymieszaj(losowePole, liczbaPolNaPlanszy);
	for (int i = 0; i < liczbaPolNaPlanszy; i++) {
		int y = losowePole[i] % parametry->rozmiarPlanszy;
		int x = losowePole[i] / parametry->rozmiarPlanszy;
		int losowyTlok = (rand() % parametry->maxTlok + 1);

		if (losowyTlok > 0) {
			if (liczbaMisjonarzy > 0) {
				int losowaLiczbaMisjonarzy = rand() % (losowyTlok + 1);
				if (losowaLiczbaMisjonarzy > liczbaMisjonarzy) {
					losowaLiczbaMisjonarzy = liczbaMisjonarzy;
				}
				for (int i = 0; i < losowaLiczbaMisjonarzy; i++) {
					Misjonarz* misjonarz = new Misjonarz(parametry, x, y);
					WstawOsobe(misjonarz);
				}
				losowyTlok -= losowaLiczbaMisjonarzy;
				liczbaMisjonarzy -= losowaLiczbaMisjonarzy;
			}

			if (losowyTlok > 0 && liczbaKobiet > 0) {
				int losowaLiczbaKobiet = rand() % (losowyTlok + 1);
				if (losowaLiczbaKobiet > liczbaKobiet) {
					losowaLiczbaKobiet = liczbaKobiet;
				}
				for (int i = 0; i < losowaLiczbaKobiet; i++) {
					Kobieta* kobieta = new Kobieta(parametry, x, y);
					WstawOsobe(kobieta);
				}
				losowyTlok -= losowaLiczbaKobiet;
				liczbaKobiet -= losowaLiczbaKobiet;
			}

			if (losowyTlok > 0 && liczbaMezczyzn > 0) {
				int losowaLiczbaMezczyzn = losowyTlok;
				if (losowaLiczbaMezczyzn > liczbaMezczyzn) {
					losowaLiczbaMezczyzn = liczbaMezczyzn;
				}
				for (int i = 0; i < losowaLiczbaMezczyzn; i++) {
					Mezczyzna* mezczyzna = new Mezczyzna(parametry, x, y);
					WstawOsobe(mezczyzna);
				}
				liczbaMezczyzn -= losowaLiczbaMezczyzn;

			}
		}

	}

	if (liczbaKobiet > 0 || liczbaMezczyzn > 0 || liczbaMisjonarzy > 0) {
		int i = 0;
		while (i < liczbaPolNaPlanszy && (liczbaKobiet > 0)) {
			int y = i % parametry->rozmiarPlanszy;
			int x = i / parametry->rozmiarPlanszy;
			int liczbaOsob = 0;
			listaOsob.LiczbaOsob(x, y, liczbaOsob);
			for (int j = 0; j < (parametry->maxTlok - liczbaOsob) && (liczbaKobiet > 0); j++) {
				Kobieta* kobieta = new Kobieta(parametry, x, y);
				WstawOsobe(kobieta);
				--liczbaKobiet;
			}
			++i;
		}
		while (i < liczbaPolNaPlanszy && (liczbaMezczyzn > 0)) {
			int y = i % parametry->rozmiarPlanszy;
			int x = i / parametry->rozmiarPlanszy;
			int liczbaOsob = 0;
			listaOsob.LiczbaOsob(x, y, liczbaOsob);
			for (int j = 0; j < (parametry->maxTlok - liczbaOsob) && (liczbaMezczyzn > 0); j++) {
				Mezczyzna* mezczyzna = new Mezczyzna(parametry, x, y);
				WstawOsobe(mezczyzna);
				--liczbaMezczyzn;
			}
			++i;
		}
		while (i < liczbaPolNaPlanszy && (liczbaMisjonarzy > 0)) {
			int y = i % parametry->rozmiarPlanszy;
			int x = i / parametry->rozmiarPlanszy;
			int liczbaOsob = 0;
			listaOsob.LiczbaOsob(x, y, liczbaOsob);
			for (int j = 0; j < (parametry->maxTlok - liczbaOsob) && (liczbaMisjonarzy > 0); j++) {
				Misjonarz* misjonarz = new Misjonarz(parametry, x, y);
				WstawOsobe(misjonarz);
				--liczbaMisjonarzy;
			}
			++i;
		}
	}
	delete[] losowePole;
}

// rozmieszcza w osobnych naroznikach (cwiartkach): misjonarze, kobiety, mezczyzni
void Gra::RozmiescWNaroznikach() {
	for (int i = 0; i < parametry->liczbaMisjonarzy / 2; i++) {
		int poleWKolejnosci = i / parametry->maxTlok;
		int y1 = poleWKolejnosci % (parametry->rozmiarPlanszy / 2);
		int y2 = parametry->rozmiarPlanszy - 1 - (poleWKolejnosci % (parametry->rozmiarPlanszy / 2));
		int x = parametry->rozmiarPlanszy - 1 - poleWKolejnosci / (parametry->rozmiarPlanszy / 2);

		Misjonarz* misjonarz = new Misjonarz(parametry, x, y1);
		WstawOsobe(misjonarz);

		if (i < parametry->liczbaMisjonarzy - 1) {
			Misjonarz* misjonarz = new Misjonarz(parametry, x, y2);
			WstawOsobe(misjonarz);
		}
	}

	for (int i = 0; i < parametry->liczbaKobiet; i++) {
		int poleWKolejnosci = i / parametry->maxTlok;
		int y = poleWKolejnosci % (parametry->rozmiarPlanszy / 2);
		int x = poleWKolejnosci / (parametry->rozmiarPlanszy / 2);

		Osoba* osoba = new Kobieta(parametry, x, y);
		WstawOsobe(osoba);
	}

	for (int i = 0; i < parametry->liczbaMezczyzn; i++) {
		int poleWKolejnosci = i / parametry->maxTlok;
		int y = parametry->rozmiarPlanszy - 1 - (poleWKolejnosci % (parametry->rozmiarPlanszy / 2));
		int x = poleWKolejnosci / (parametry->rozmiarPlanszy / 2);

		Osoba* osoba = new Mezczyzna(parametry, x, y);
		WstawOsobe(osoba);
	}
}

// rozmieszcza kanibali na lewej polowie planszy (osobno kobiety i mezczyzni), a misjonarzy na prawej polowie
void Gra::RozmiescKanibaleNaLewoMisjonarzeNaPrawo() {
	for (int i = 0; i < parametry->liczbaMisjonarzy; i++) {
		int poleWKolejnosci = i / parametry->maxTlok;
		int y = poleWKolejnosci % parametry->rozmiarPlanszy;
		int x = parametry->rozmiarPlanszy - 1 - poleWKolejnosci / parametry->rozmiarPlanszy;

		Misjonarz* misjonarz = new Misjonarz(parametry, x, y);
		WstawOsobe(misjonarz);
	}

	for (int i = 0; i < parametry->liczbaKobiet + parametry->liczbaMezczyzn; i++) {
		int poleWKolejnosci = i / parametry->maxTlok;
		int y = poleWKolejnosci % parametry->rozmiarPlanszy;
		int x = poleWKolejnosci / parametry->rozmiarPlanszy;

		Osoba* osoba;
		if (i < parametry->liczbaKobiet) {
			osoba = new Kobieta(parametry, x, y);
		}
		else {
			osoba = new Mezczyzna(parametry, x, y);
		}
		WstawOsobe(osoba);
	}
}
