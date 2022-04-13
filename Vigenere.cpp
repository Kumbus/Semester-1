#include <iostream>
#include<fstream>
#include"Funkcje.h"
using namespace std;

int main(int argc, char* argv[])
{
    string flaga = "";
    if (Flagi(argc, argv, flaga) == false)
        return 0;

    if (flaga == "--en" || flaga=="--de")
    {
        string nazwaklucza, nazwawejscia, nazwawyjscia;

        if (SprawdzanieParametrow(argc, argv, nazwaklucza, nazwawejscia, nazwawyjscia) == false)
        {
            Instrukcja();
            return 0;
        }

        vector <char> tekst = WczytajDane(nazwawejscia);
        vector <char> klucz = WczytajDane(nazwaklucza);

        ofstream plz(nazwawyjscia.c_str());
        
        if (flaga == "--en")
        {
            Szyfruj(tekst, klucz, plz);
            cout << "Tekst zostal zaszyfrowany" << endl;
            plz.close();
            return 0;
        }
        else
        {
            Deszyfruj(tekst, klucz, plz);
            cout << "Tekst zostal odszyfrowany" << endl;
            plz.close();
            return 0;
        }
    }
    else
    {
        string nazwawejscia, nazwawyjscia;

        if (SprawdzanieParametrowLamanie(argc, argv, nazwawejscia, nazwawyjscia) == false)
        {
            Instrukcja();
            return 0;
        }

        vector <char> tekst = WczytajDaneLamanie(nazwawejscia);

        ofstream plz(nazwawyjscia.c_str());

        int dlugoscklucza = DlugoscKlucza(tekst);
        string klucz= ZnajdzKlucz(dlugoscklucza, tekst);

        DeszyfrujPoLamaniu(tekst, klucz, plz);
        cout << "Szyfr zostal zlamany :D" << endl;
        plz.close();
    }
}