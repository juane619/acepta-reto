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

const char CASO_ESPECIAL = '.';

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char calc;

    while (cin >> calc) {
        if (calc == CASO_ESPECIAL) return 0;

        int colores[2];

        for (int i = 0; i < 2; i++) {
            colores[i] = 0;
        }

        while (calc != '.') {
            if (calc == 'N') {
                colores[0]++;
            } else {
                colores[1]++;
            }

            cin >> calc;
        }

        int n, g;

        n = colores[0] % 2;
        g = colores[1] % 2;

        if (!n && !g) {
            cout << "EMPAREJADOS";
        } else if (n && g) {
            cout << "PAREJA MIXTA";
        } else if (n) {
            cout << "NEGRO SOLITARIO";
        } else if (g) {
            cout << "GRIS SOLITARIO";
        }

        cout << "\n";
    }
    return 0;
}
