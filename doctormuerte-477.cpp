#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

const int INF = 0x3f3f3f3f;

class Arma {
   public:
    int id, damagei, damagev;

    Arma() { id = damagei = damagev = -1; }

    bool operator<(const Arma& other) const {
        return this->damagei < other.damagei ||
               (this->damagei == other.damagei && damagev > other.damagev) ||
               (this->damagei == other.damagei && damagev == other.damagev &&
                id < other.id);
    }
    bool operator==(const Arma& other) const {
        return (damagei == other.damagei && damagev == other.damagev);
    }
};

void fastscan(int& number) {
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

    int vitality, narmas;
    int damagei, damagev;
    int total_damage;

    while (cin >> vitality) {
        if (vitality == CASO_ESPECIAL) return 0;
        cin >> narmas;
        vi armas_elegidas;

        vector<Arma> armas(narmas);

        for (int i = 0; i < narmas; i++) {
            cin >> damagei >> damagev;
            armas[i].id = i + 1;
            armas[i].damagei = damagei;
            armas[i].damagev = damagev;
        }
        sort(armas.begin(), armas.end());

        total_damage = 0;
        for (int i = 0; i < narmas && total_damage < vitality; i++) {
            total_damage += armas[i].damagev;
            armas_elegidas.push_back(armas[i].id);
        }
        /* while (ptr < armas.size() && total_damage < vitality) {
            if (armas[ptr] == armas[ptr + 1]) {
                if (armas[ptr].id <= armas[ptr + 1].id) {
                    total_damage += armas[ptr].damagev;
                    armas_elegidas.push_back(armas[ptr].id);
                } else {
                    total_damage += armas[ptr + 1].damagev;
                    armas_elegidas.push_back(armas[ptr + 1].id);
                }
            } else if (armas[ptr].damagei == armas[ptr + 1].damagei) {
                if (armas[ptr].damagev >= armas[ptr + 1].damagev) {
                    total_damage += armas[ptr].damagev;
                    armas_elegidas.push_back(armas[ptr].id);
                } else {
                    total_damage += armas[ptr + 1].damagev;
                    armas_elegidas.push_back(armas[ptr + 1].id);
                }
            } else {
                total_damage += armas[ptr].damagev;
                armas_elegidas.push_back(armas[ptr].id);
            }
            ptr++;
        } */

        if (total_damage < vitality) {
            cout << "MUERTE ESCAPA\n";
        } else {
            cout << armas_elegidas[0];
            for (unsigned i = 1; i < armas_elegidas.size(); i++) {
                cout << " " << armas_elegidas[i];
            }
            cout << "\n";
        }
    }

    return 0;
}
