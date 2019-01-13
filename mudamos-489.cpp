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

    int nact, nnuevo;
    bool can;

    cin >> nact >> nnuevo;
    while (cin) {
        can = true;
        vi act(nact);
        vi nue(nnuevo);
        for (int i = 0; i < nact; i++) {
            cin >> act[i];
        }
        for (int i = 0; i < nnuevo; i++) {
            cin >> nue[i];
        }

        if (nact > nnuevo) {
            can = false;
        }

        if (can) {
            sort(act.begin(), act.end());
            sort(nue.begin(), nue.end());

            int ptr1 = 0, ptr2 = 0;

            while (ptr1 < nact && ptr2 < nnuevo) {
                if (act[ptr1] <= nue[ptr2]) {
                    ptr1++;
                    ptr2++;
                } else {
                    ptr2++;
                }
            }

            if (ptr1 < nact) {
                can = false;
            }
        }

        if (can) {
            cout << "SI\n";
        } else
            cout << "NO\n";

        cin >> nact >> nnuevo;
    }

    return 0;
}
