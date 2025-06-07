#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include "funkcje.h"


using namespace std;


int main() {
    vector<string> nazwiska = wczytaj_nazwiska("nazwiska.csv");
    if (nazwiska.empty()) {
        cerr << "Błąd: Nie wczytano żadnych nazwisk." << endl;
        return 1;
    }
    cout << "Wczytano " << nazwiska.size() << " nazwisk." << endl;
    
    map<string, vector<string>> mapa_nazwisk;
    
    for (const auto& nazwisko : nazwiska) {
        string kanoniczna = kanoniczna_postac(nazwisko);
        if (find(
            mapa_nazwisk[kanoniczna].begin(), mapa_nazwisk[kanoniczna].end(), nazwisko
            ) == mapa_nazwisk[kanoniczna].end()) {
            mapa_nazwisk[kanoniczna].push_back(nazwisko);
        }
    }
    
    vector<vector<string>> wyniki;
    for (const auto& para : mapa_nazwisk) {
        if (para.second.size() > 1) {
            wyniki.push_back(para.second);
        }
    }
    
    sort(wyniki.begin(), wyniki.end(), [](const vector<string>& a, const vector<string>& b) {
        if (a.size() != b.size()) {
            return a.size() > b.size();
        }
        return a[0] < b[0]; 
    });
    
    cout << "\nZnaleziono " << wyniki.size() << " grup nazwisk z wieloma wariantami:" << endl;
    for (const auto& grupa : wyniki) {
        cout << "Warianty (" << grupa.size() << "): ";
        for (size_t i = 0; i < grupa.size(); ++i) {
            cout << grupa[i];
            if (i != grupa.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    
    return 0;
}