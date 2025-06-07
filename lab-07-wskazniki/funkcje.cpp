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

	std::normal_distribution<double> gauss(170, 10);
	return gauss(silnik);
}

unsigned int los_uint()
{
	static std::default_random_engine silnik(std::chrono::system_clock::now().time_since_epoch().count());

	std::uniform_int_distribution<unsigned int> jednorodny(10, 20);
	return jednorodny(silnik);
}

void separator()
{
	std::cout << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << std::endl;
}

//////////////////////////////////////////
std::shared_ptr<double[]> alokuj_tablice(const unsigned int n)
{
	return std::shared_ptr<double[]>(new double[n]);
}

double *alokuj_tablice_zwykly_wskaznik(const unsigned int n)
{
	return new double[n];
}

void wypelnij(std::shared_ptr<double[]> p, const int n)
{
	for (int i = 0; i < n; i++)
		p[i] = los_double();
}

void wypelnij(double *p, const int n)
{
	for (int i = 0; i < n; i++)
		p[i] = los_double();
}

void wypisz(const double *p, const int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << p[i] << std::endl;
	}
	std::cout << std::endl;
}

void wypisz(std::shared_ptr<double[]> p, const int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << p[i] << " ";
	}
}

std::pair<double, double> usun_min_max(std::shared_ptr<double[]> *p, unsigned int *n)
{
	if (*n == 0)
		return {0, 0};

	unsigned int size = *n;
	double *arr = p->get();

	double min_val = arr[0];
	double max_val = arr[0];
	unsigned int min_idx = 0;
	unsigned int max_idx = 0;

	for (unsigned int i = 1; i < size; ++i)
	{
		if (arr[i] < min_val)
		{
			min_val = arr[i];
			min_idx = i;
		}
		if (arr[i] > max_val)
		{
			max_val = arr[i];
			max_idx = i;
		}
	}

	unsigned int new_size = size - (min_idx == max_idx ? 1 : 2);
	if (new_size == 0)
	{
		*p = nullptr;
		*n = 0;
		return {min_val, max_val};
	}

	std::shared_ptr<double[]> new_array(new double[new_size]);
	unsigned int j = 0;
	for (unsigned int i = 0; i < size; ++i)
	{
		if (i != min_idx && i != max_idx)
		{
			new_array[j++] = arr[i];
		}
	}

	*p = new_array;
	*n = new_size;
	return {min_val, max_val};
}

void push_back(std::shared_ptr<double[]> *p, unsigned int *n, const double d)
{
	unsigned int new_size = *n + 1;
	std::shared_ptr<double[]> new_array(new double[new_size]);
	for (unsigned int i = 0; i < *n; ++i)
	{
		new_array[i] = (*p)[i];
	}
	new_array[*n] = d;
	*p = new_array;
	*n = new_size;
}

void pop_back(std::shared_ptr<double[]> *p, unsigned int *n)
{
	if (*n == 0)
		return;
	unsigned int new_size = *n - 1;
	if (new_size == 0)
	{
		*p = nullptr;
		*n = 0;
		return;
	}
	std::shared_ptr<double[]> new_array(new double[new_size]);
	for (unsigned int i = 0; i < new_size; ++i)
	{
		new_array[i] = (*p)[i];
	}
	*p = new_array;
	*n = new_size;
}

void wypisz(const std::vector<std::pair<std::shared_ptr<double[]>, unsigned int>> &t)
{
	for (const auto &[ptr, size] : t)
	{
		for (unsigned int i = 0; i < size; ++i)
		{
			std::cout << ptr[i] << " ";
		}
		std::cout << std::endl;
	}
}
