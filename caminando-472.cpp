#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

const int INF = 0x3f3f3f3f;

void fastscan(int &number) {
    // variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c == '-') {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative) number *= -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int desnivel = 0, ncotas = 0;
    int cota = 0, inicio = 0, anterior = 0;
    int dif = 0;
    bool apta;

    cin >> desnivel >> ncotas;
    while (cin) {
        apta = true;
        dif = 0;
        anterior = 1000001;

        vi cotas(ncotas, -1);

        for (int i = 0; i < ncotas; i++) {
            cin >> cotas[i];
        }

        for (int i = 0; i < ncotas && apta; i++) {
            cota = cotas[i];

            if (cota > anterior) {
                if (i > 0) {
                    dif = cota - inicio;
                    if (dif > desnivel) {
                        apta = false;
                    }
                }
            } else if (cota <= anterior)
                inicio = cota;
            anterior = cota;
        }

        if (apta) {
            cout << "APTA\n";
        } else
            cout << "NO APTA\n";

        cin >> desnivel >> ncotas;
    }

    return 0;
}
