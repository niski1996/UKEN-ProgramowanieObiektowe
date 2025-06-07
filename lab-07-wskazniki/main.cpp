
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>
#include <chrono>
#include <random>

#include "funkcje.h"



///////////////////////////////////////////
int main ()
{
	unsigned int rozmiar = los_uint();
	double * pTabZwWsk = alokuj_tablice_zwykly_wskaznik(rozmiar); // Funkcja alokuje tablice o zadanym rozmiarze.
	wypelnij (pTabZwWsk, rozmiar);  // Funkcja wypelnia tablice losowymi wartosciami.
	wypisz (pTabZwWsk, rozmiar); // Funkcja wypisuje tablice na standardowe wyjscie.
	delete [] pTabZwWsk; // MUSIMY zwolnic pamiec!

	separator();

	std::shared_ptr<double []> pTab = alokuj_tablice(rozmiar); // Funkcja alokuje tablice o zadanym rozmiarze.
	wypelnij (pTab, rozmiar);  // Funkcja wypelnia tablice losowymi wartosciami.
	wypisz (pTab, rozmiar);    // Funkcja wypisuje tablice na standardowe wyjscie.

	separator();

	for (int i = 0; i < 6; i++)
	{
		double nowa = los_double();
		std::cout << nowa << std::endl;
		push_back(&pTab, &rozmiar, nowa);  // Funkcja dodaje nowa wartosc na koniec tablicy. Zwieksza tym samym rozmiar tablicy.
		wypisz(pTab, rozmiar);
	}

	separator();

	while (rozmiar)
	{
		pop_back(&pTab, &rozmiar); // Funkcja usuwa ostatnia wartosc z tablicy. Zmniejsza tym samym jej rozmiar.
		wypisz(pTab, rozmiar);
	}

	separator();

	pTab = alokuj_tablice(rozmiar);
	wypisz(pTab, rozmiar);

	for (int i = 0; i < 10; i++)
	{
		double nowa = los_double();
		std::cout << nowa << std::endl;
		push_back(&pTab, &rozmiar, nowa);
		wypisz(pTab, rozmiar);
	}

	separator();

	while (rozmiar > 0)
	{
		wypisz(pTab, rozmiar);
		std::cout << "rozmiar: " << rozmiar << std::endl;
		auto [mini, maxi] = usun_min_max(&pTab, &rozmiar); // Funkcja usuwa z tablicy wartosc minimalną i maksymalną. Skraca tym samym tablice. Jezeli maksimum i minimum sa takie same, funkcja usuwa tylko jedna wartosc.
		std::cout << "mini: " << mini << std::endl;
		std::cout << "maxi: " << maxi << std::endl;
	}

	separator();

  rozmiar = los_uint();

	typedef std::shared_ptr<double[]> pTabD;
	typedef std::pair<pTabD, unsigned int> tablica; // typ: tablica z rozmiarem

	std::vector<tablica> tablice_w_wektorze (rozmiar); // std::vector<std::pair<std::shared_ptr<double[]>, unsigned int>> tablice_w_wektorze (rozmiar);
	for (auto it = tablice_w_wektorze.begin(); it != tablice_w_wektorze.end(); it++)
	{
		unsigned int n = los_uint();
		it->first = alokuj_tablice(n);
		it->second = n;
		wypelnij(it->first, it->second);
	}

	std::cout << rozmiar << " tablic w wektorze" << std::endl;
	wypisz(tablice_w_wektorze);

	return 0;
}

// To tyle :-)
