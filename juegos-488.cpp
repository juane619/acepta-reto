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

    int veces;
    int npuntosg, capaz;
    ll minutos;
    long long tiempo_total;

    ll current;
    int nsesiones;

    cin >> veces;

    for (; veces > 0; veces--) {
        nsesiones = 1;
        cin >> npuntosg >> capaz;

        vector<ll> puntos(npuntosg);
        for (int i = 0; i < npuntosg; i++) {
            cin >> minutos;
            puntos[i] = minutos;
        }

        int last = 0;
        for (int i = 0; i < npuntosg; i++) {
            if (puntos[i] - last > capaz) {
                last = puntos[i - 1];
                nsesiones++;
            }
        }

        cout << nsesiones << '\n';
    }

    return 0;
}
