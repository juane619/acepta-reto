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

int umbral, formas;
vi pesos(24);

void comb(int comidas, int peso_acum, int in) {
    if (comidas == 0 && peso_acum <= umbral) {
        formas++;
        return;
    }
    if (peso_acum > umbral || in < 0) {
        return;
    }
    comb(comidas - 1, peso_acum + pesos[in], in - 1);  // Cogemos uva
    comb(comidas, peso_acum, in - 1);                  // No cogemos uva
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nuvas;

    while (cin >> umbral) {
        cin >> nuvas;
        if (umbral == CASO_ESPECIAL && nuvas == CASO_ESPECIAL) {
            return 0;
        }

        formas = 0;

        for (int i = 0; i < nuvas; i++) {
            cin >> pesos[i];
        }
        sort(pesos.begin(), pesos.begin() + 12);

        comb(12, 0, nuvas - 1);

        cout << formas << '\n';
    }
    return 0;
}
