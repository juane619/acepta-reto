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
    int compradas, a, b;
    int malas;
    int cont;
    bool contando;
    cin >> veces;

    for (; veces > 0; veces--) {
        cin >> compradas >> a >> b;
        malas = 0;
        cont = 0;
        contando = false;

        for (int i = 0; i < compradas; i++) {
            if (i % b == 0) {
                contando = true;
            }
            if (cont < a && contando) {
                cont++;
                malas++;
            } else {
                contando = false;
                cont = 0;
            }
        }

        cout << malas << "\n";
    }

    return 0;
}
