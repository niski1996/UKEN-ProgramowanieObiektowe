#pragma once
// DEKLARACJE (NAGŁÓWKI) FUNKCJI

#include <string>
#include <vector>
#include <memory>


/** @return Funkcja zwraca losowa wartosc zmiennoprzecinkowa. */
double los_double();

/** @return Funkcja zwraca losowa wartosc calkowita bez znaku.*/
unsigned int los_uint();

/** Funkcja wypisuje separator. */
void separator();

/** Funkcja wyszukuje maksimum i minimum w tablicy i usuwa je z niej. Funkcja skraca tablice. Jezeli maksimum jest rowne minimum, funkcja usuwa tylko jedna wartosc z tablicy.
  @return para: minimum i maksimum
  @param[out] p tablica, po wykonaniu funkcji nie zawiera minimum i maksimum
  @param[out] n rozmiar tablicy, po wykonaniu funkcji jest zmniejszony*/
std::pair<double, double> usun_min_max (std::shared_ptr<double[]> * p, unsigned int * n);

/** Funkcja alokuje tablice wartosci zmiennoprzecinkowych o zadanym rozmiarze.
  @param n rozmiar tablicy
  @return wskaznik na zaalokowana tablice */
std::shared_ptr<double []> alokuj_tablice (const unsigned int n);


/** Funkcja alokuje tablice wartosci zmiennoprzecinkowych o zadanym rozmiarze.
  @param n rozmiar tablicy
  @return wskaznik na zaalokowana tablice */
double * alokuj_tablice_zwykly_wskaznik (const unsigned int n);

/** Funkcja wypisuje tablice na ekran.
  @param p tablica do wypisania
  @param n rozmiar tablicy */
void wypisz(const double * p, const int n);

/** Funkcja wypelnia tablice wartosciami losowymi.
  @param p tablica do wypelnienia
  @param n rozmiar tablicy */
void wypelnij(double * p, const int n);

/** Funkcja wypelnia tablice wartosciami losowymi.
  @param p tablica do wypelnienia
  @param n rozmiar tablicy */
void wypelnij(std::shared_ptr<double[]> p, const int n);

/** Funkcja wypisuje tablice na ekran.
  @param p tablica do wypisania
  @param n rozmiar tablicy */
void wypisz(std::shared_ptr<double[]> p, const int n);

/** Funkcja dodaje wartosc na koniec tablicy. Funkcja wydluza tablice.
  @param p tablica
  @param n rozmiar tablicy
  @param d wartosc do dodania*/
void push_back(std::shared_ptr<double[]> * p, unsigned int * n, const double d);

/** Jezeli tablica zawiera jakies wartosci, funkcja usuwa wartosc z koniec tablicy. Funkcja skraca tablice.
  @param p tablica
  @param n rozmiar tablicy */
void pop_back(std::shared_ptr<double[]> * p, unsigned int * n);

void wypisz(const std::vector<std::pair<std::shared_ptr<double[]> , unsigned int>> & t);
