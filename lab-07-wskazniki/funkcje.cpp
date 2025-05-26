// DEFINICJE (IMPLEMENTACJE) FUNKCJI

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <string>
#include <memory>

#include "funkcje.h"

///////////////////////////////

double los_double()
{
	static std::default_random_engine silnik(std::chrono::system_clock::now().time_since_epoch().count());

	std::normal_distribution<double> gauss (170, 10);
	return gauss(silnik);
}

unsigned int los_uint()
{
	static std::default_random_engine silnik(std::chrono::system_clock::now().time_since_epoch().count());

	std::uniform_int_distribution<unsigned int> jednorodny (10, 20);
	return jednorodny(silnik);
}

void separator()
{
	std::cout << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << std::endl;
}

//////////////////////////////////////////
std::shared_ptr<double []> alokuj_tablice (const unsigned int n)
{
	return std::shared_ptr<double[]> (new double[n]);
}

double * alokuj_tablice_zwykly_wskaznik (const unsigned int n)
{
	return new double[n];
}

void wypelnij(std::shared_ptr<double[]> p, const int n)
{
	for (int i = 0; i < n; i++)
		p[i] = los_double();
}

void wypelnij(double * p, const int n)
{
	for (int i = 0; i < n; i++)
		p[i] = los_double();
}

void wypisz(const double * p, const int n)
{
}

void wypisz(std::shared_ptr<double[]> p, const int n)
{
}

std::pair<double, double> usun_min_max (std::shared_ptr<double[]> * p, unsigned int * n)
{
	return {0,0};
}

void push_back(std::shared_ptr<double[]> * p, unsigned int * n, const double d)
{
}

void pop_back(std::shared_ptr<double[]> * p, unsigned int * n)
{
}

void wypisz(const std::vector<std::pair<std::shared_ptr<double[]> , unsigned int>> & t)
{
}
