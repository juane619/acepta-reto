#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nlitros;
    int nrecips;
    bool posible = false;

    while (cin >> nlitros) {
        if (nlitros == CASO_ESPECIAL) return 0;

        cin >> nrecips;
        vi recips(nrecips, 0);

        for (int i = 0; i < nrecips; i++) {
            cin >> recips[i];
            if (recips[i] == nlitros) {
                posible = true;
            }
        }

        if (!posible) {
        } else {
        }

        if (posible)
            cout << "SI\n";
        else
            cout << "NO\n";
    }

    return 0;
}
