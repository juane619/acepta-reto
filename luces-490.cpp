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

    int nilum;
    int nvisit;
    ll asombro, asombrod;

    cin >> nilum >> nvisit;
    while (cin) {
        vector<ll> grados(nilum);

        for (int i = 0; i < nilum; i++) {
            cin >> grados[i];
        }

        ll maxic = 0, maxid = 0;
        for (int j = 0; j <= nilum - nvisit; j++) {
            asombro = asombrod = 0;
            for (int i = j + 1; i < nvisit + j; i++) {
                if (grados[i] > grados[i - 1]) {
                    asombro += (grados[i] - grados[i - 1]);
                    asombrod += (grados[i - 1] - grados[i]);
                } else if (grados[i] < grados[i - 1]) {
                    asombro -= (grados[i - 1] - grados[i]);
                    asombrod += (grados[i - 1] - grados[i]);
                }
            }
            asombro = max(asombro, asombrod);
            maxic = max(maxic, asombro);
        }

        cout << maxic << '\n';

        cin >> nilum >> nvisit;
    }

    return 0;
}
