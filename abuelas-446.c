#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

bool fastscan(int &number) {
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

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nabuelas, nnombres;
    string nombre_real = "", current_name = "";
    cin >> nabuelas;

    for (; nabuelas > 0; nabuelas--) {
        bool falsa = false;
        cin >> nombre_real >> nnombres;
        int i = 0;
        for (; i < nnombres; i++) {
            cin >> current_name;
            if (i != nnombres - 1 && current_name == nombre_real && !falsa) {
                cout << "FALSA\n";
                falsa = true;
            }
        }
        if (!falsa) {
            if (i > 1 && current_name == nombre_real) {
                cout << "VERDADERA\n";
            } else
                cout << "FALSA\n";
        }
    }

    return 0;
}