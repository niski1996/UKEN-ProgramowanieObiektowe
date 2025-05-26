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