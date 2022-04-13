#ifndef STALE_H
#define STALE_H

/** Stala okreslajaca minimalna dlugosc jaka moze miec nazwa pliku */
const int MinimalnaDlugosc = 5;

/** Stala okreslajaca najwieksza dlugosc za mala na dlugosc nazwy pliku */
const int ZaMalaDlugosc = 4;

/** Stala okreslajaca liczbe parametrow potrzebnych do zadzialania programu podczas szyfrowania lub deszyfrowania */
const int LiczbaParametrow = 8;

/** Stala okreslajaca liczbe parametrow potrzebnych do zadzialania programu podczas lamania szyfru */
const int LiczbaParametrowLamanie = 6;

/** Stala okreslajaca liczbe liter w angielskim alfabecie */
const int LiczbaLiter = 26;

/** Stala okreslajaca minimalna wartosc ASCII dla ktorej dziala program podczas szyfrowania lub deszyfrowania */
const int EnDeOd = 32;

/** Stala okreslajaca maksymalna wartosc ASCII dla ktorej dziala program podczas szyfrowania lub deszyfrowania*/
const int EnDeDo = 126;

/**Stala okreslajaca liczbe znakow ktore sa obslugiwane w czasie szyfrowania lub deszyfrowania */
const int WaznaWartoscEnDe = 95;

/**Stala okreslajaca minimalna wartosc ASCII dla ktorej dziala program podczas lamania szyfru */
const int WaznaWartoscBr = 97;

/** Stala okreslajaca maksymalna wartosc ASCII dla ktorej dziala program podczas lamania szyfru */
const int BrDo = 122;

/** Stala okreslajaca przez ile dzielimy dlugosc pliku czyli podczas okreslania dlugosci klucza. Zmieniajac ja sterujemy jak dlugi klucz mozemy znalezc */
const int Dzielenie = 55;
#endif