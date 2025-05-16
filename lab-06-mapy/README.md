1. Google: nazwiska polskie site:gov.pl
2. Ściągnąć plik CSV (comma-separated values)
3. Mozna w nim poszukac nazwisk swoich i znajomych :-)
4. Otworzyć plik CSV w edytorze i pozamieniać na male litery:
	A, -> a, C' -> c, E, -> e,
	L/ -> l, N' -> n, O' -> o,
	S' -> s, Z' -> x, Z. -> z
Chodzi o to, zeby odrozniac o kreskowane (male o) od duzego O itp.
Zapisac plik :-)
5. Sa nazwiska, ktore mozna pisac na dwa sposoby, np.
	Jasko'lski, Jaskulski
	Drohomski, Drochomski
	Jerzyk, Jez.yk
o'/u, h/ch, rz/z.
6. Cel: znalezc wszystkie nazwiska, ktore mozna zapisywac
na wiecej niz 1 sposob, posortowac je wg liczby sposobow
zapisu malejaco i wypisac
7. Sposob rozwiazania:
- napisac test funkcji
string zamien(const string& s, const string& co, const string& naco)
	ASSERT_EQ(zamien("margaryna", "a", "aa"), "maargaarynaa");
	ASSERT_EQ(zamien("margaryna", "a", ""), "mrgryn");
	ASSERT_EQ(zamien("margaryna", "ar", x"), "mxgxyna");
- napisac funkcje zamien, ktora przechodzi ten test
- napisac reszte programu :-)
kluczowa struktura danych:
	map<string, vector<string>> odwzorowuje "kanoniczna" postac nazwiska
na jego rozne zapisy. "Kanoniczna" postac nazwiska, czyli klucz mapy:
	knazwisko = zamien(nazwisko, "o", "U")
	knazwisko = zamien(knazwisko, "RZ", "z")
	knazwisko = zamien(knazwisko, "CH", "H)
- do tej mapy wczytac wszystkie nazwiska (bez przecinkow i bez licznosci)
- wyciagnac z tej mapy wartosci, czyli wektory jako vector<vector<string>>
- posortowac te wektory wedlug malejacej kolejnosci ich dlugosci
- wypisac te wektory, ktore maja dlugosc > 1
KONIEC
