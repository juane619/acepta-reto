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
    string x, y, aux;
    bool ist = true;
    cin >> veces;

    for (; veces > 0; veces--) {
        ist = true;
        cin >> x >> aux >> y;

        if (x.size() != y.size()) ist = false;

        if (ist) {
            for (size_t i = 0; i < x.size() && ist; i++) {
                if (toupper(x[i]) != toupper(y[i])) ist = false;
            }
        }

        /* transform(x.begin(), x.end(), x.begin(), ::toupper);
        transform(y.begin(), y.end(), y.begin(), ::toupper); */

        if (!ist) {
            cout << "NO TAUTOLOGIA\n";
        } else
            cout << "TAUTOLOGIA\n";
    }

    return 0;
}
