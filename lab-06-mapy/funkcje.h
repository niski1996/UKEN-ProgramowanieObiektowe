#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct PunktySlowa
{
    std::string slowo;
    int punkty;
};
string zamien(const string& s, const string& co, const string& naco);
string kanoniczna_postac(const string& nazwisko);
vector<string> wczytaj_nazwiska(const string& nazwa_pliku) ;
