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

    string numero;
    int punto;
    string entera, fraccionaria;
    string salidaentera = "", salidafrac = "";
    bool cero_izquierda, cero_derecha;

    while (cin >> numero) {
        salidaentera = salidafrac = "0";
        cero_izquierda = cero_derecha = false;
        punto = numero.find('.');

        if (punto != -1) {
            entera = numero.substr(0, punto);
            fraccionaria = numero.substr(punto + 1, numero.size());
        } else {
            entera = numero;
        }

        for (int i = 0; i < entera.size(); i++) {
            char curr = numero.c_str()[i];
            if (!cero_izquierda) {
                if (curr != '0') {
                    salidaentera.clear();
                    salidaentera.push_back(curr);
                    cero_izquierda = true;
                }
            } else {
                salidaentera.push_back(curr);
            }
        }
        for (int i = numero.size() - 1; i > punto; i--) {
            char curr = numero.c_str()[i];
            if (!cero_derecha) {
                if (curr != '0') {
                    salidafrac.clear();
                    salidafrac.push_back(curr);
                    cero_derecha = true;
                }
            } else {
                salidafrac.push_back(curr);
            }
        }

        if (punto == -1) {
            cout << salidaentera;
        } else {
            if (salidafrac.size() > 0) {
                if (cero_derecha) {
                    reverse(salidafrac.begin(), salidafrac.end());
                    cout << salidaentera << "." << salidafrac;
                } else {
                    cout << salidaentera;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}