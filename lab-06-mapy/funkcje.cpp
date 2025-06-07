#include <fstream>
#include <set>
#include <string>
#include <algorithm>

#include "funkcje.h"

using namespace std;

string zamien(const string& s, const string& co, const string& naco) {
    string result;
    size_t pos = 0;
    size_t found;
    
    while ((found = s.find(co, pos)) != string::npos) {
        result.append(s, pos, found - pos);
        result.append(naco);
        pos = found + co.length();
    }
    
    result.append(s, pos, s.length() - pos);
    return result;
}

string kanoniczna_postac(const string& nazwisko) {
    string k = zamien(nazwisko, "o", "U");
    k = zamien(k, "RZ", "z");
    k = zamien(k, "CH", "H");
    return k;
}
vector<string> wczytaj_nazwiska(const string& nazwa_pliku) {
    vector<string> nazwiska;
    ifstream plik(nazwa_pliku);
    string linia;

    if (!plik.is_open()) {
        cerr << "Nie można otworzyć pliku: " << nazwa_pliku << endl;
        return nazwiska;
    }

    getline(plik, linia);

    while (getline(plik, linia)) {
        size_t przecinek = linia.find(',');
        if (przecinek != string::npos) {
            string nazwisko = linia.substr(0, przecinek);
            if (!nazwisko.empty() && nazwisko.front() == '"' && nazwisko.back() == '"') {
                nazwisko = nazwisko.substr(1, nazwisko.size() - 2);
            }
            nazwiska.push_back(nazwisko);
        }
    }

    return nazwiska;
}