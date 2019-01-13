#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;

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

bool fullTrail(const vector<int>& predecs, int start) {
    int curr_pred = predecs[start];
    bool impossible = false;

    while (curr_pred != 0 && !impossible) {
        if (curr_pred == -1) return false;
        curr_pred = predecs[curr_pred];
    }
    if (!impossible) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nspecies;
    int rels;
    int o, d;
    bool impossible = false;

    while (cin >> nspecies) {
        if (nspecies == CASO_ESPECIAL) return 0;
        vi predecs(nspecies, -1);

        cin >> rels;
        for (int i = 0; i < rels; i++) {
            cin >> o >> d;
            if (d == 1)
                predecs[o - 1] = d - 1;
            else
                predecs[d - 1] = o - 1;
        }

        impossible = false;
        for (int i = 1; i < nspecies && !impossible; i++) {
            impossible = !fullTrail(predecs, i);
        }

        if (impossible || nspecies < 2)
            if (rels == 0)
                cout << "TODAS\n";
            else
                cout << "FALTA ALGUNA\n";
        else
            cout << "TODAS\n";
    }

    return 0;
}
