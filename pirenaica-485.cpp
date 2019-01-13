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

const int CASO_ESPECIAL = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int netapas;
    int distancia;
    int total;

    while (cin >> netapas) {
        if (netapas == CASO_ESPECIAL) return 0;
        total = 0;
        vi distancias(netapas);
        vi restantes(netapas);

        for (int i = 0; i < netapas; i++) {
            cin >> distancia;
            distancias[i] = distancia;
            total += distancia;
        }

        restantes[0] = total;

        for (int i = 1; i < netapas; i++) {
            restantes[i] = total - distancias[i - 1];
            total -= distancias[i - 1];
        }

        cout << restantes[0];
        for (int i = 1; i < netapas; i++) {
            cout << ' ' << restantes[i];
        }
        cout << '\n';
    }

    return 0;
}
