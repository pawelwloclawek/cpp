#include <bits/stdc++.h>
using namespace std;

void szukajLidera (double T[], int N)
{
    double lider = T[0];
    int pom = 1, ilosc = 0;
    for (int i=1; i<N; i++)

        if (pom==0)
        {
            lider = T[i];
            pom=1;
        }
        else if (T[i] == lider) pom++;
        else pom--;
        if (pom==0) cout << "W zbiorze brak lidera \n";
        else
        {
            for (int i=0; i<N; i++)
                if (T[i] == lider) ilosc++;
            if (ilosc>N/2) cout  << "Liczba " << lider << " jest liderem " << endl;
            else cout << "w zbiorze nie ma lidera \n";
        }

}



int main()
{
    double T[] = {1,4,4,3,2,2,2,2,2,2,2,2,4,2,3,2,4,2,3,2,1,2,2,1,2,2,2};
    szukajLidera(T, 27);
    return 0;
}
