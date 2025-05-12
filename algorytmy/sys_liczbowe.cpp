#include <bits/stdc++.h>

using namespace std;

int z_systemu_do_dziesietnego(string liczba, int podstawa)
{
    int wynik = 0;
    int potega = 1;

    for (int i = liczba.size() - 1; i >= 0; i--) {
        char znak = std::toupper(liczba[i]);
        int cyfra;

        if (znak >= '0' && znak <= '9')
            cyfra = znak - '0';
        else if (znak >= 'A' && znak <= 'Z')
            cyfra = znak - 'A' + 10;
        else {
            cerr << "Nieprawidłowy znak: " << znak << "\n";
            return -1;
        }

        if (cyfra >= podstawa) {
           cerr << "Cyfra " << znak << " nie pasuje do systemu o podstawie " << podstawa << "\n";
            return -1;
        }

        wynik += cyfra * potega;
        potega *= podstawa;
    }

    return wynik;
}


// funkcja zamiany z dziesiętnego na dowolny

#include <iostream>
#include <string>

string z_dziesietnego_na_system(int liczba, int podstawa)
{
    if (podstawa < 2 || podstawa > 36) {
        return "Nieprawidłowa podstawa";
    }

    if (liczba == 0) return "0";

    string wynik;
    bool ujemna = false;

    if (liczba < 0) {
        ujemna = true;
        liczba = -liczba;
    }

    while (liczba > 0) {
        int reszta = liczba % podstawa;
        char znak = reszta < 10 ? '0' + reszta : 'A' + (reszta - 10);
        wynik = znak + wynik;
        liczba /= podstawa;
    }

    if (ujemna) wynik = "-" + wynik;
    return wynik;
}



int main() {
    string liczba = "1A";
    int podstawa = 16;

    int dziesietna = z_systemu_do_dziesietnego(liczba, podstawa);
    std::cout << "W systemie dziesiętnym: " << dziesietna << "\n";


    // dla funkcji zamieniającej na sys dowolny
    int liczba1 = 123;
    int podstawa1 = 16;

    std::string wynik = z_dziesietnego_na_system(liczba1, podstawa1);
    std::cout << "W systemie o podstawie " << podstawa1 << ": " << wynik << "\n";
    return 0;
}
