#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

const int INF = 0x3f3f3f3f;

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

class Superheroe {
   public:
    int hab;
    string pref;

    Superheroe() {
        hab = 0;
        pref = "";
    }

    Superheroe(int hab) { this->hab = hab; }

    bool isEmparejed(const Superheroe& other) const {
        char sign = pref[0];
        int value = pref[1] - '0';
        char signother = other.pref[0];
        int valueother = other.pref[1] - '0';

        if (sign == '>') {
            if (other.hab > value) {
                if (signother == '<') {
                    if (hab < valueother) return true;
                } else if (signother == '>') {
                    if (hab > valueother) return true;
                } else if (hab == valueother) {
                    return true;
                }
            }

        } else if (sign == '<') {
            if (other.hab < value) {
                if (signother == '<') {
                    if (hab < valueother) return true;
                } else if (signother == '>') {
                    if (hab > valueother) return true;
                } else if (hab == valueother) {
                    return true;
                }
            }
        } else {
            if (other.hab == value) {
                if (signother == '<') {
                    if (hab < valueother) return true;
                } else if (signother == '>') {
                    if (hab > valueother) return true;
                } else if (hab == valueother) {
                    return true;
                }
            }
        }

        return false;
    }
};

int isEmparejed(const vector<Superheroe>& supers, int pos,
                vector<bool>& asignado) {
    if (!asignado[pos]) {
        for (int i = pos + 1; i < supers.size(); i++) {
            if (!asignado[i] && supers[pos].isEmparejed(supers[i])) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nsuper;
    int habi;
    string prefe;

    while (cin >> nsuper) {
        if (nsuper == CASO_ESPECIAL) return 0;
        habi = 0;
        prefe = "0";
        vector<Superheroe> supers(nsuper);
        vb asignado(nsuper, false);
        vector<pair<int, int> > emparejamientos;

        for (int i = 0; i < nsuper; i++) {
            cin >> habi;
            supers[i].hab = habi;
        }

        for (int i = 0; i < nsuper; i++) {
            cin >> prefe;
            supers[i].pref = prefe;
        }

        int emparejado;
        for (int i = 0; i < supers.size(); i++) {
            if ((emparejado = isEmparejed(supers, i, asignado)) != -1) {
                asignado[i] = true;
                asignado[emparejado] = true;
                emparejamientos.push_back(
                    pair<int, int>(i + 1, emparejado + 1));
            }
        }

        if (!emparejamientos.empty()) {
            for (int i = 0; i < emparejamientos.size(); i++) {
                cout << emparejamientos[i].first << " "
                     << emparejamientos[i].second << "\n";
            }
            cout << "---\n";
        } else
            cout << "NO HAY\n---\n";
    }

    return 0;
}