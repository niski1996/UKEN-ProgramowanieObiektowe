#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "funkcje.h"

using namespace std;

static void zgłoś_błąd(const string& nazwa_pliku) {
    cerr << "Nie udało się otworzyć pliku " << nazwa_pliku << endl;
    cerr << "Przyczyna: " << strerror(errno) << endl;
    exit(1);
}

static ifstream otwórz_plik_do_odczytu(const string& nazwa_pliku) {
    auto plik = ifstream(nazwa_pliku);
    if (!plik) {
        zgłoś_błąd(nazwa_pliku);
    }
    return plik;
}

static ofstream otwórz_plik_do_zapisu(const string& nazwa_pliku) {
    auto plik = ofstream(nazwa_pliku);
    if (!plik) {
        zgłoś_błąd(nazwa_pliku);
    }
    return plik;
}

int main() {
    const string NAZWA_PLIKU_STUDENCI{"studenci.txt"};
    const string NAZWA_PLIKU_OCENY{"oceny.txt"};
    const int LICZBA_STUDENTOW{1000};
    vector<int> pesele;
    map<int, Student> studenci;
    {
        ofstream strumień = otwórz_plik_do_zapisu(NAZWA_PLIKU_STUDENCI);
        pesele = tworz_studentow(strumień, LICZBA_STUDENTOW);
        strumień.close();
    }
    {
        ofstream strumień = otwórz_plik_do_zapisu(NAZWA_PLIKU_OCENY);
        tworz_oceny(pesele, strumień);
        strumień.close();
    }
    {
        ifstream strumień = otwórz_plik_do_odczytu(NAZWA_PLIKU_STUDENCI);
        studenci = wczytaj_studentow(strumień);
        strumień.close();
    }
    string najpopularniejsze_imie = wyznacz_najpopularniejsze_imie(studenci);
    cout << "najpopularniejsze imie: " << najpopularniejsze_imie << endl;

    auto [najpopularniejsze_nazwisko, liczba_osob] = wyznacz_najpopularniejsze_nazwisko(studenci);
    cout << "najpopularniejsze nazwisko: " << najpopularniejsze_nazwisko << '\t' << liczba_osob
         << endl;
    {
        ifstream strumień = otwórz_plik_do_odczytu(NAZWA_PLIKU_OCENY);
        wczytaj_oceny(strumień, &studenci);
        strumień.close();
    }
    wypisz_studentow_z_ocenami(studenci, cout);
    cout << "liczba studentow bez ocen: " << policz_studentow_bez_ocen(studenci) << endl;
}
