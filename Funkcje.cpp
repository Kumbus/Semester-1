#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<cstdlib>
#include<cmath>
#include <limits>
#include"Stale.h"
using namespace std;

void Instrukcja()
{
	cout << "Nalezy wybrac opcje 1, 2 lub 3 i podac :" << endl;
	cout << "   1) Flaga --en :" << endl;
	cout << "      a) -i nazwa pliku tekstowego, w ktorym jest tekst do zaszyfrownia" << endl;
	cout << "      b) -k nazwa pliku tekstowego, w ktorym jest klucz" << endl;
	cout << "      c) -i nazwa pliku tekstowego, do ktorego zapisujemy zaszyfrowany tekst" << endl;
	cout << "   2) Flaga --de :" << endl;
	cout << "      a) -i nazwa pliku tekstowego, w ktorym jest tekst do odszyfrownia" << endl;
	cout << "      b) -k nazwa pliku tekstowego, w ktorym jest klucz" << endl;
	cout << "      c) -o nazwa pliku tekstowego, do ktorego zapisujemy odszyfrowany tekst" << endl;
	cout << "   3) Flaga --br :" << endl;
	cout << "      a) -i nazwa pliku tekstowego, w ktorym jest zaszyfrowany tekst do zlamania" << endl;
	cout << "      b) -o nazwa pliku tekstowego, do ktorego zapisujemy odszyfrowany tekst" << endl;
}

bool Flagi(const int& argc, char* argv[], string& flaga)
{
	for (int i = 0; i < argc; i++)
	{
		string parametr = argv[i];
		if (parametr == "--en" || parametr == "--de" || parametr == "--br")
			flaga = parametr;
	}

	if (flaga == "")
	{
		cout << "Zostala podana zla flaga lub flaga nie zostala podana" << endl;
		Instrukcja();
		return false;;
	}
	return true;
}

bool SprawdzPliki(const int& miejsce, const string parametr, const int& argc, char* argv[])
{
	if (miejsce == argc - 1)
	{
		cout << "Po parametrze " << parametr << " nie podano nazwy pliku"<<endl;
		return false;
	}
	else
	{
		string nazwa = argv[miejsce + 1];
		if ((nazwa.length() < MinimalnaDlugosc) || (nazwa.find(".txt", nazwa.length() - ZaMalaDlugosc) == string::npos))
		{
			cout << "Plik podany po parametrze " << parametr << " nie jest plikiem tekstowym"<<endl;
			return false;
		}
		else if(parametr == "-k" || parametr == "-i")
		{
			ifstream plik(nazwa.c_str());
			string s = "";
			plik >> s;

			if(s == "")
			{
				cout << "Plik po parametrze " << parametr << " jest pusty lub nie istnieje" << endl;
				plik.close();
				return false;
			}

			plik.close();

		}
	}
	return true;
}

bool SprawdzanieParametrow(const int& argc, char* argv[], string &nazwaklucza,string &nazwawejscia,string &nazwawyjscia)
{
	bool bylok = false;
	bool byloi = false;
	bool byloo = false;
	for (int i = 0; i < argc; i++)
	{
		string nazwa;
		string parametr = argv[i];
		if (i != argc - 1)
			nazwa = argv[i + 1];

		if (parametr == "-k" && SprawdzPliki(i, parametr, argc, argv) == true)
		{
			bylok = true;
			nazwaklucza = nazwa;
		}
		else if (parametr == "-i" && SprawdzPliki(i, parametr, argc, argv) == true)
		{
			byloi = true;
			nazwawejscia = nazwa;
		}
		else if (parametr == "-o" && SprawdzPliki(i, parametr, argc, argv) == true)
		{
			byloo = true;
			nazwawyjscia = nazwa;
		}

	}

	if ((byloi && bylok && byloo) == false)
	{
		cout << "Podawanie parametrow nie powiodlo sie"<<endl;
		return false;
	}
	 if (argc>LiczbaParametrow)
		cout << "Ostrzezenie! Oprocz wymaganych paramtrow zostaly podane inne, niepotrzebne parametry"<<endl;
	return true;
}

vector<char> WczytajDane(const string& nazwa)
{
	ifstream plo(nazwa.c_str());
	string s;
	vector<char>wyrazy;

	while (getline(plo,s))
	{
		for (size_t i = 0; i < s.length(); i++)
		{
			if(s[i]>=EnDeOd && s[i]<=EnDeDo)
				wyrazy.push_back(s[i]);
			else
			{
				cout << "W pliku z danymi lub w pliku z kluczem znajduja sie znaki spoza tabeli ASCII z przedzialu <32, 126> wiec program sie nie wykonal" << endl;
				plo.close();
				Instrukcja();
				exit(123);
			}
		}
	}
	
	plo.close();
	return wyrazy;
}


void Szyfruj(const vector<char> tekst,const vector<char> klucz, ostream& wyjscie)
{
	int licznik = 0;
	int miejsce = 0;

	for (size_t i = 0; i < tekst.size(); i++)
	{

		if (licznik == klucz.size())
			licznik = 0;

		miejsce = klucz[licznik] + tekst[i];

		while (miejsce > EnDeDo)
			miejsce = miejsce - WaznaWartoscEnDe;

		licznik++;	

		wyjscie << (char)miejsce;
	}
	return;
}

void Deszyfruj(const vector<char> tekst, const vector<char> klucz, ostream& wyjscie)
{
	int licznik = 0;
	int miejsce = 0;

	for (size_t i = 0; i < tekst.size(); i++)
	{
		if (licznik == klucz.size())
			licznik = 0;

		miejsce = tekst[i] - klucz[licznik];

		while (miejsce < EnDeOd)
			miejsce = miejsce + WaznaWartoscEnDe;

		licznik++;

		wyjscie << (char)miejsce;
	}
	return;
}


bool SprawdzanieParametrowLamanie(const int& argc, char* argv[], string& nazwawejscia, string& nazwawyjscia)
{
	bool byloi = false;
	bool byloo = false;
	for (int i = 0; i < argc; i++)
	{
		string nazwa;
		string parametr = argv[i];
		if (i != argc - 1)
			nazwa = argv[i + 1];

		if (parametr == "-i" && SprawdzPliki(i, parametr, argc, argv) == true)
		{
			byloi = true;
			nazwawejscia = nazwa;
		}
		else if (parametr == "-o" && SprawdzPliki(i, parametr, argc, argv) == true)
		{
			byloo = true;
			nazwawyjscia = nazwa;
		}

	}

	if ((byloi && byloo) == false)
	{
		cout << "Podawanie parametrow nie powiodlo sie" << endl;
		return false;
	}
	if (argc > LiczbaParametrowLamanie)
		cout << "Ostrzezenie! Oprocz wymaganych paramtrow zostaly podane inne, niepotrzebne parametry" << endl;
	return true;
}

vector<char> WczytajDaneLamanie(const string& nazwa)
{
	ifstream plo(nazwa.c_str());
	string s;
	vector<char>wyrazy;

	while (plo >> s)
	{
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s[i] <= BrDo && s[i] >= WaznaWartoscBr)
				wyrazy.push_back(s[i]);
			else
			{
				cout << "W tekscie, ktory trzeba zlamac sa znaki niebedace malymi literami alfabetu angielskiego wiec zlamanie go sie powiedzie";
				plo.close();
				Instrukcja();
				exit(123);
			}
		
		}
	}

	plo.close();
	return wyrazy;
}


int DlugoscKlucza(const vector<char>wyrazy)
{
	vector<int>koincydencje;
	vector<char>przesuniecie;

	przesuniecie = wyrazy;
	koincydencje.push_back(0);

	for (size_t i = 1; i < wyrazy.size(); i++)
	{
		char koniecvectora = przesuniecie.back();

		for (int j = wyrazy.size() - 1; j > 0; j--)
			przesuniecie[j] = przesuniecie[j - 1];

		przesuniecie[0] = koniecvectora;
		koincydencje.push_back(0);

		for (size_t j = 0; j < wyrazy.size(); j++)
		{
			if (przesuniecie[j] == wyrazy[j])
				koincydencje[i]++;
		}	
	}

	int miejsce = 0;
	int max = 0;

	for (size_t i = 0; i < koincydencje.size()/Dzielenie; i++)
	{
		if (max < koincydencje[i])
		{
			max = koincydencje[i];
			miejsce = i;
		}
	}
		return miejsce;
}

double ObliczanieCzestosci(const vector<char> kolumna,const int& przesuniecie)
{
	double czestosciPL[LiczbaLiter] = { 0.0891, 0.0147, 0.0396, 0.0325, 0.0766, 0.0030, 0.0142, 0.0108, 0.0821, 0.0228, 0.0351, 0.0210, 0.0280, 0.0552, 0.0775, 0.0313, 0.0014, 0.0469, 0.0432, 0.0398, 0.0250, 0.0004, 0.0465, 0.0002, 0.0376, 0.0564 };
	
	map<char, int> czestosci;
	vector <char> kolumnakopia = kolumna;
		for (size_t j = 0; j < kolumna.size(); j++)
		{
			kolumnakopia[j] = kolumnakopia[j] - przesuniecie;
			if (kolumnakopia[j] < WaznaWartoscBr)
				kolumnakopia[j] = kolumnakopia[j] + LiczbaLiter;

			czestosci[kolumnakopia[j]]++;
		}
	
	double suma = 0;
	double rozmiar = kolumna.size();
	for (auto element : czestosci)	
			suma = suma + abs((double)(element.second /rozmiar)  - czestosciPL[element.first - WaznaWartoscBr]);
			
	return suma;

}

string ZnajdzKlucz(const int& dlugoscklucza, const vector<char>wyrazy)
{
	string klucz = "";
	vector<vector<char>> kolumny;
	vector<char> kolumna;

	int licznikklucza = 0;

	for (int i = 0; i < dlugoscklucza; i++)
	{
		kolumny.push_back(kolumna);
	}

	for (size_t i = 0; i < wyrazy.size(); i++)
	{
		if (licznikklucza == dlugoscklucza)
			licznikklucza = 0;

		kolumny[licznikklucza].push_back(wyrazy[i]);

		licznikklucza++;
	}

	double blisko;
	double najblizej ;
	int litera;

	for (int i = 0; i < dlugoscklucza; i++)
	{
		najblizej = DBL_MAX;
		for (int j = 0; j < LiczbaLiter; j++)
		{
			blisko=ObliczanieCzestosci(kolumny[i],j);
			if (blisko < najblizej)
			{
				najblizej = blisko;
				litera = j;
			}
			
		}
		klucz = klucz + (char)(litera + WaznaWartoscBr);
	}

	return klucz;
}

void DeszyfrujPoLamaniu(const vector<char> tekst,const string& klucz, ostream& wyjscie)
{
	size_t licznik = 0;
	int miejsce = 0;

	for (size_t i = 0; i < tekst.size(); i++)
	{
		if (licznik >= klucz.length())
			licznik = 0;

		miejsce = tekst[i] - klucz[licznik]+WaznaWartoscBr;

		while (miejsce < WaznaWartoscBr)
			miejsce = miejsce + LiczbaLiter;

		licznik++;
		wyjscie << (char)miejsce;
	}
	return;
}