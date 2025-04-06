#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void zapisz(bool dopisz) {
    ofstream plik;
    if (dopisz)
        plik.open("dane.txt", ios::app);  // dopisywanie
    else
        plik.open("dane.txt");            // nadpisywanie

    if (!plik) {
        cerr << "Błąd otwierania pliku!" << endl;
        return;
    }

    string tekst;
    cout << "Podaj tekst do zapisania (\"exit\" kończy):\n";
    while (true) {
        getline(cin, tekst);
        if (tekst == "exit") break;
        plik << tekst << endl;
    }

    plik.close();
}

void odczytLiniowy() {
    ifstream plik("dane.txt");
    if (!plik) {
        cerr << "Błąd otwierania pliku!" << endl;
        return;
    }

    string linia;
    cout << "\nZawartość pliku:\n";
    while (getline(plik, linia)) {
        cout << linia << endl;
    }

    plik.close();
}

void wyczyscPlik() {
    ofstream czysc("dane.txt", ios::trunc);
    czysc.close();
    cout << "Plik został wyczyszczony." << endl;
}

int main() {
    int wybor;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Zapisz (nadpisz)\n";
        cout << "2. Dopisz\n";
        cout << "3. Odczytaj\n";
        cout << "4. Wyczyść plik\n";
        cout << "0. Wyjście\n";
        cout << "Wybierz: ";
        cin >> wybor;
        cin.ignore(); // czyszczenie bufora

        switch (wybor) {
            case 1: zapisz(false); break;
            case 2: zapisz(true); break;
            case 3: odczytLiniowy(); break;
            case 4: wyczyscPlik(); break;
        }
    } while (wybor != 0);

    return 0;
}
