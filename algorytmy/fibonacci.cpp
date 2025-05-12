#include <bits/stdc++.h>

using namespace std;

// Sprawdza, czy liczba n jest liczbą Fibonacciego
bool czy_fibonacci_iteracyjnie(int n)
{
    if (n < 0) return false;
    int a = 0, b = 1;
    while (a <= n)
    {
        if (a == n) return true;
        int temp = a + b;
        a = b;
        b = temp;
    }
    return false;
}


// Generuje n pierwszych liczb ciągu Fibonacciego zaczynajac od 0!
vector<long long> generuj_fibonacci(int n)
{
    vector<long long> fib;
    if (n >= 1) fib.push_back(0);
    if (n >= 2) fib.push_back(1);
    for (int i = 2; i < n; i++)
    {
        fib.push_back(fib[i-1] + fib[i-2]);
    }
    return fib;
}

int main() {
    int liczba = 21;
    int ile = 10;

    // Sprawdzenie czy liczba jest w ciągu Fibonacciego
    if (czy_fibonacci_iteracyjnie(liczba))
    {
        cout << liczba << " jest liczba Fibonacciego.\n";
    }
    else
    {
        cout << liczba << " nie jest liczba Fibonacciego.\n";
    }

    // Generowanie ciągu
    vector<long long> ciag = generuj_fibonacci(ile);
    cout << "Pierwsze " << ile << " liczb ciagu Fibonacciego:\n";
    for (long long x : ciag) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
