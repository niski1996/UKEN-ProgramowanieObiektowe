#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "funkcje.h"

using namespace std;

int main()
{
    ifstream strumien_slow("slowa.txt");
    if (!strumien_slow)
    {
        cerr << "Blad otwierania pliku slowa.txt - czy ten plik jest we wlasciwym folderze?\n";
    }
    set<string> zbior_slow = wczytaj_slowa(strumien_slow);
    map<string, int> licznik_slow;
    for (const string &slowo : zbior_slow)
    {
        for (const auto &[poczatek, koniec] : podziel_slowo(slowo))
        {
            dodaj_1_jesli_poczatek_i_koniec_to_slowa(poczatek, koniec, zbior_slow, &licznik_slow);
        }
    }
    vector<PunktySlowa> punkty_slow = stworz_wektor(licznik_slow);
    posortuj_wg_punktow_malejaco(&punkty_slow);
    wypisz_slowa_i_punkty(punkty_slow, cout);
    return 0;
}