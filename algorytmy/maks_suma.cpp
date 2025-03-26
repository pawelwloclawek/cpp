#include <bits/stdc++.h>
using namespace std;

int main() {
    int T[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(T) / sizeof(T[0]);
    int max_sum = T[0], current_sum = T[0];
    int start = 0, end = 0, pom = 0;

    for (int i = 1; i < n; i++) {
        if (T[i] > current_sum + T[i]) {
            current_sum = T[i];
            pom = i;
        } else {
            current_sum += T[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = pom;
            end = i;
        }
    }
    cout << "Najwieksza suma podciagu: " << max_sum << endl;
    cout << "Podci¹g: ";
    for (int i = start; i <= end; i++) {
        cout << T[i] << " ";
    }
    cout << endl;
    return 0;
}
