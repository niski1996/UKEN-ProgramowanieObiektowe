// Definicje funkcji, czyli implementacje funkcji

#include "funkcje.h"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

using namespace std;

vector<int> tworz_studentow(ostream& strumien, const int N) {
    static vector<string> imiona{
        "Zuzanna",   "Julia",      "Maja",        "Zofia",      "Hanna",    "Alicja",
        "Maria",     "Amelia",     "Oliwia",      "Aleksandra", "Wiktoria", "Emilia",
        "Laura",     "Natalia",    "Pola",        "Liliana",    "Iga",      "Marcelina",
        "Anna",      "Helena",     "Kornelia",    "Klara",      "Jagoda",   "Lucja",
        "Barbara",   "Malgorzata", "Joanna",      "Aniela",     "Izabela",  "Kalina",
        "Marta",     "Roza",       "Katarzyna",   "Ewa",        "Eliza",    "Klaudia",
        "Rozalia",   "Dominika",   "Adrianna",    "Patrycja",   "Urszula",  "Melania",
        "Malwina",   "Marianna",   "Lidia",       "Liwia",      "Aurelia",  "Olga",
        "Daria",     "Kamila",     "Bianka",      "Dorota",     "Gaja",     "Ada",
        "Apolonia",  "Wanda",      "Diana",       "Dagmara",    "Jowita",   "Inga",
        "Jagna",     "Agnieszka",  "Ida",         "Luiza",      "Monika",   "Emma",
        "Jadwiga",   "Roma",       "Aleksander",  "Antoni",     "Jakub",    "Jan",
        "Szymon",    "Filip",      "Mikolaj",     "Wojciech",   "Adam",     "Stanislaw",
        "Michal",    "Wiktor",     "Piotr",       "Nikodem",    "Igor",     "Ignacy",
        "Tymon",     "Milosz",     "Maksymilian", "Tymoteusz",  "Mateusz",  "Bartlomiej",
        "Krzysztof", "Julian",     "Tomasz",      "Gabriel",    "Hubert",   "Fabian",
        "Natan",     "Pawel",      "Kamil",       "Ksawery",    "Bruno",    "Borys",
        "Kajetan",   "Artur",      "Adrian",      "Olaf",       "Krystian", "Sebastian",
        "Cezary",    "Grzegorz",   "Daniel",      "Eryk",       "Tadeusz",  "Blazej",
        "Lukasz",    "Witold",     "Rafal",       "Henryk",     "Tobiasz",  "Damian",
        "Gromoslaw", "Idzi",       "Jarogniew",   "Kosma"};
    static vector<string> nazwiska{
        "Nowak",     "Wojcik",  "Kowalczyk", "Wozniak",   "Mazur",    "Krawczyk",   "Kaczmarek",
        "Zajac",     "Krol",    "Wrobel",    "Wieczorek", "Dudek",    "Adamczyk",   "Stepien",
        "Pawlak",    "Sikora",  "Walczak",   "Szewczyk",  "Pietrzak", "Wlodarczyk", "Kubiak",
        "Kolodziej", "Sobczak", "Mroz",      "Szulc",     "Bator",    "Wolicz",     "Czada",
        "Pazdzioch", "Sokol",   "Kulig",     "Zieba",     "Kot",      "Polak",      "Klimek",
        "Kowal",     "Banach"};
    static uniform_int_distribution<int> rozklad_imion(0, imiona.size() - 1);
    static uniform_int_distribution<int> rozklad_nazwisk(0, nazwiska.size() - 1);
    static uniform_int_distribution<int> rozklad_peseli(123456789, 987654321);
    static default_random_engine silnik(chrono::system_clock::now().time_since_epoch().count());
    vector<int> pesele;

    if (strumien) {
        for (int i = 0; i < N; ++i) {
            int pesel = rozklad_peseli(silnik);
            pesele.push_back(pesel);
            strumien << imiona[rozklad_imion(silnik)] << '\t' << nazwiska[rozklad_nazwisk(silnik)]
                     << '\t' << pesel << endl;
        }
    }
    return pesele;
}

void tworz_oceny(const vector<int>& pesele, ostream& strumien) {
    static vector<string> przedmioty{"matematyka",     "programowanie",        "fizyka",
                                     "grafika",        "bazy_danych",          "algorytmika",
                                     "filozofia",      "mikroinformatyka",     "egiptologia",
                                     "logika_rozmyta", "obliczenia_ziarniste", "sieci_komputerowe"};
    static default_random_engine silnik(chrono::system_clock::now().time_since_epoch().count());
    static uniform_int_distribution<int> rozklad_przedmiotow(0, przedmioty.size() - 1);
    static discrete_distribution<int> rozklad_ocen{0, 0, 0, 0, 1, 2, 3, 4, 3, 2, 1};
    static uniform_int_distribution<int> rozklad_peseli(0, pesele.size() - 1);
    static uniform_int_distribution<int> rozklad_liczby_ocen(1, 3);

    if (strumien) {
        const double MNOZNIK{5.0};
        for (size_t i = 0; i < MNOZNIK * pesele.size(); ++i) {
            strumien << pesele[rozklad_peseli(silnik)] << '\t'
                     << przedmioty[rozklad_przedmiotow(silnik)] << '\t';
            int liczba_ocen = rozklad_liczby_ocen(silnik);
            for (int j = 0; j < liczba_ocen; ++j) {
                strumien << (double)rozklad_ocen(silnik) / 2 << '\t';
            }
            strumien << endl;
        }
    }
}

map<int, Student> wczytaj_studentow(istream& strumien) {
    map<int, Student> studenci;
    int pesel;
    Student student;
    string imie, nazwisko;
    while (strumien >> imie >> nazwisko >> pesel) {
    Student student;
    student.imie = imie;
    student.nazwisko = nazwisko;
    studenci[pesel] = student;
    }

    return studenci;
}

void wczytaj_oceny(istream& strumien, map<int, Student>* studenci) {
    string line;
    while (getline(strumien, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        int pesel;
        string przedmiot;
        
        ss >> pesel >> przedmiot;
        
        vector<double> oceny;
        double ocena;
        while (ss >> ocena) {
            oceny.push_back(ocena);
        }
        
        if (studenci->count(pesel)) {
            (*studenci)[pesel].oceny_z_przedmiotow[przedmiot] = oceny;
        }
    }
}

string wyznacz_najpopularniejsze_imie(const map<int, Student>& studenci) {
    map<string, int> czestosc_imion;
    string najpopularniejsze_imie;
     int max_licznik = 0;

    for (const auto& [pesel, student] : studenci) {
        czestosc_imion[student.imie]++;
    }

    for (const auto& [imie, licznik] : czestosc_imion) {
        if (licznik > max_licznik || 
            (licznik == max_licznik && imie < najpopularniejsze_imie)) {
            max_licznik = licznik;
            najpopularniejsze_imie = imie;
        }
    }

    return najpopularniejsze_imie;
}

pair<string, int> wyznacz_najpopularniejsze_nazwisko(const map<int, Student>& studenci) {
    map<string, int> czestosc_nazwisk;

    string najpopularniejsze_nazwisko;
    int max_czestosc{0};

    for (const auto& [pesel, student] : studenci) {
        czestosc_nazwisk[student.nazwisko]++;
    }

    for (const auto& [nazwisko, licznik] : czestosc_nazwisk) {
        if (licznik > max_czestosc) {
            max_czestosc = licznik;
            najpopularniejsze_nazwisko = nazwisko;
        }
        else if (licznik == max_czestosc && nazwisko < najpopularniejsze_nazwisko) {
            najpopularniejsze_nazwisko = nazwisko;
        }
    }

    return {najpopularniejsze_nazwisko, max_czestosc};
}

void wypisz_studentow_z_ocenami(const map<int, Student>& studenci, ostream& strumien) {
    for (const auto& [pesel, student] : studenci) {
        strumien << student.imie << " " << student.nazwisko << " (" << pesel << ")\n";
        
        for (const auto& [przedmiot, oceny] : student.oceny_z_przedmiotow) {
            strumien << "\t" << przedmiot << "\t";
            
            for (const auto& ocena : oceny) {
                strumien << ocena << " ";
            }
            
            strumien << "\n";
        }
    }
}

int policz_studentow_bez_ocen(const map<int, Student>& studenci) {
    int ilu_bez_ocen{0};
        for (const auto& [pesel, student] : studenci) {
        if (student.oceny_z_przedmiotow.empty()) {
            ilu_bez_ocen++;
        }
    }

    return ilu_bez_ocen;
}
