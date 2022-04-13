#ifndef FUNKCJE_H
#define FUNKCJE_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;





/** Funkcja wypisuje instrukcje jakie podac parametry po ich blednym wpisaniu */
void Instrukcja();

/** Funkcja sprawdza czy zostala podana dobra flaga i przypisuje ta flage do stringa
@param argc liczba parametrow
@param argv[] tablica parametrow
@param flaga string do ktorego jest przekazywana podana flaga
@return true, jesli zostala podana odpowiednia flaga
		false, nie jesli zostala podana odpowiednia flaga*/
bool Flagi(const int& argc, char* argv[], string& flaga);

/** Funkcja sprawdza czy po parametrze jest podana poprawna nazwa pliku.
@param miejsce pozycja parametru w tablicy parametrow
@param parametr parametr dla ktorego jest sprawdzany plik
@param argc liczba parametrow
@param argv[] tablica parametrow
@return true, jesli nie ma zadnych bledow
		false, jesli jakis blad zostal wykryty */
bool SprawdzPliki(const int& miejsce, const string& parametr, const int& argc, char* argv[]);

/** Funkcja sprawdza czy zostaly podane wszystkie potrzebne parametry podczas szyfrowania lub deszyfrowania i przekazuje nazwy plikow do odpowiednich stringow.
@param argc liczba podanych parametrow
@param argv tablica parametrow
@param nazwaklucza string, do ktorego bedzie przypisana nazwa pliku z kluczem
@param nazwawejscia string, do ktorego bedzie przypisana nazwa pliku z danymi
@param nazwawyjscia string, do ktorego bedzie przypisana nazwa pliku wyjsciowego
@return true, jesli wszytkie 3 parametry zostaly podane wraz z plikami im odpowiadajacymi
		false, jesli ktorys z parametrow nie zostal podany lub plik po nim jest bledny */
bool SprawdzanieParametrow(const int& argc, char* argv[], string& nazwaklucza, string& nazwawejscia, string& nazwawyjscia);

/** Funkcja wczytuje dane z pliku, sprawdza czy nie ma w nim niedozwolonych znakow i zapisuje je do vectora.
@param nazwa nazwa pliku, z ktorego beda wczytywane dane
@return vector wyrazow, ktore byly w pliku rozbite na pojedyncze znaki*/
vector<char> WczytajDane(const string& nazwa);

/** Funkcja szyfruje tekst metoda Vigenerea i zapisuje zaszyfrowany tekst do pliku.
@param tekst tekst, ktory bedzie szyfrowany
@param klucz klucz, ktorym bedziemy szyfrowac 
@param wyjscie plik do, ktorego bedzie zapisywany zaszyfrowany tekst */
void Szyfruj(const vector<char> tekst,const vector<char> klucz, ostream& wyjscie);

/** Funkcja deszyfruje tekst metoda Vigenerea i zapisuje odszyfrowany tekst do pliku.
@param tekst tekst, ktory bedzie deszyfrowany
@param klucz klucz, ktorym bedziemy deszyfrowac
@param wyjscie plik do, ktorego bedzie zapisywany odszyfrowany tekst */
void Deszyfruj(const vector<char> tekst,const  vector<char> klucz, ostream& wyjscie);

/** Funkcja sprawdza czy zostaly podane wszystkie potrzebne parametry podczas szyfrowania lub deszyfrowania i przekazuje nazwy plikow do odpowiednich stringow.
@param argc liczba podanych parametrow
@param argv tablica parametrow
@param nazwawejscia string, do ktorego bedzie przypisana nazwa pliku z danymi
@param nazwawyjscia string, do ktorego bedzie przypisana nazwa pliku wyjsciowego
@return true, jesli wszytkie 3 parametry zostaly podane wraz z plikami im odpowiadajacymi
		false, jesli ktorys z parametrow nie zostal podany lub plik po nim jest bledny */
bool SprawdzanieParametrowLamanie(const int& argc, char* argv[], string& nazwawejscia, string& nazwawyjscia);

/** Funkcja wczytuje zaszyfrowany tekst przeznaczony do zlamanie, sprawdza czy nie ma w nim znakow, ktore to lamanie uniemozliwiaja i zapisuje dane do vectora.
@param nazwa nazwa pliku, z ktorego sa wczytywane dane
@return vector wyrazow, ktore byly w pliku rozbite na pojedyncze znaki*/
vector<char> WczytajDaneLamanie(const string& nazwa);

/** Funkcja wyznacza dlugosc klucza, ktorym byl szyfrowany tekst. 
@param wyrazy tekst, ktory zostal zaszyfrowany metoda Vigenerea
@return dlugosc klucza uzytego do szyfrowania*/
int DlugoscKlucza(const vector<char>wyrazy);

/** Funkcja oblicza jak czesto wystepuje kazda litera alfabetu w miejscach zaszyfrowanych ta sama litera klucza
@param kolumna wszystkie litery przesuniete o ta sama litere klucza
@param przesuniecie numer litery, o ktora bedzie przesuwana kolumna, gdzie a=0, b=1, ..., z=25
@return wartosc, dla ktorej suma wartosci bezwzglednych roznicy pomiedzy czestoscia wystepowania litery w kolumnie, a czestoscia wystepowania w jezyku jest najmniejsza */
double ObliczanieCzestosci(const vector<char> kolumna,const int& przesuniecie);

/** Funkcja zwraca klucz lub jego wielokrotnosc, ktorym z najwiekszym prawdopodobienstwem byl szyfrowany tekst
@param dlugoscklucza dlugosc klucza, ktorym byl szyfrowany tekst
@param wyrazy zaszyfrowany tekst w postaci vectora pojedynczych znakow
@return klucz lub jego wielokrotnosc */
string ZnajdzKlucz(const int& dlugoscklucza,const vector<char> wyrazy);

/** Funkcja deszyfruje tekst po tym jak zostal zlamany klucz jakim teskt byl zaszyfrowany
@param tekst tekst do odszyfrowania
@param klucz klucz jakim tekst byl zaszyfrowany
@param wyjscie plik, do ktorego jest zapisywany odszyfrowany tekst */
void DeszyfrujPoLamaniu(const vector<char> tekst,const string& klucz, ostream& wyjscie);
#endif 

