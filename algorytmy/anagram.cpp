/*
Program pobiera dwa słowa od użytkownika.
Funkcja czyAnagram sprawdza:
Równość długości słów.
Czy posortowane znaki w obu słowach są identyczne.
Wynik jest wyświetlany na ekranie.
*/

#include <bits/stdc++.h>

using namespace std;

// Funkcja sprawdzająca, czy dwa słowa są anagramami
bool czyAnagram(const std::string& s1, const std::string& s2) {
    // Jeśli długości słów są różne, nie mogą być anagramami
    if (s1.length() != s2.length()) {
        return false;
    }

    // Kopiujemy słowa do lokalnych zmiennych
    string sorteds1 = s1;
    string sorteds2 = s2;

    // Sortujemy oba słowa
    sort(sorteds1.begin(), sorteds1.end());
    sort(sorteds2.begin(), sorteds2.end());

    // Porównujemy posortowane słowa
    return sorteds1 == sorteds2;
}

int main() {
    string s1, s2;

    // Pobieranie słów od użytkownika
    cout << "Podaj pierwsze slowo: ";
    cin >> s1;
    cout << "Podaj drugie slowo: ";
    cin >> s2;

    // Sprawdzanie, czy są anagramami
    if (czyAnagram(s1, s2)) {
        cout << "Slowa \"" << s1 << "\" i \"" << s2 << "\" sa anagramami.\n";
    } else {
        cout << "Slowa \"" << s1 << "\" i \"" << s2 << "\" nie sa anagramami.\n";
    }

    return 0;
}
