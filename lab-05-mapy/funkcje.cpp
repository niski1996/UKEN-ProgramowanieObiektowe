#include <fstream>
#include <set>
#include <string>
#include <algorithm>

#include "funkcje.h"

using namespace std;

set<string> wczytaj_slowa(istream &strumien)
{
    set<string> wynik;
    string slowo;
    while (strumien >> slowo)
    {
        wynik.insert(slowo);
    }
    return wynik;
}

vector<pair<string, string>> podziel_slowo(const string &slowo)
{
    vector<pair<string, string>> wynik;
    for (size_t i = 1; i < slowo.size(); ++i)
    {
        wynik.emplace_back(slowo.substr(0, i), slowo.substr(i));
    }
    return wynik;
}

void dodaj_1_jesli_poczatek_i_koniec_to_slowa(
    const string &poczatek,
    const string &koniec,
    const set<string> &zbior_slow,
    map<string, int> *licznik_slow)
{
    if (zbior_slow.count(poczatek) && zbior_slow.count(koniec))
    {
        (*licznik_slow)[poczatek]++;
        (*licznik_slow)[koniec]++;
    }
}

vector<PunktySlowa> stworz_wektor(const map<string, int> &licznik_slow)
{
    vector<PunktySlowa> wynik;
    for (const auto &[slowo, punkty] : licznik_slow)
    {
        wynik.push_back(PunktySlowa{slowo, punkty});
    }
    return wynik;
}

void posortuj_wg_punktow_malejaco(vector<PunktySlowa> *punkty_slow)
{
    std::sort(punkty_slow->begin(), punkty_slow->end(),
              [](const PunktySlowa &a, const PunktySlowa &b)
              {
                  if (a.punkty != b.punkty)
                      return a.punkty > b.punkty;
                  return a.slowo < b.slowo;
              });
}

void wypisz_slowa_i_punkty(const vector<PunktySlowa> &punkty_slow, ostream &strumien)
{
    for (const auto &ps : punkty_slow)
    {
        strumien << ps.slowo << '\t' << ps.punkty << '\n';
    }
}