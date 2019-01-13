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

const int CASO_ESPECIAL = 0;

int main() {
    int a, p;
    while (scanf("%d%d", &a, &p) == 2 && (a != 0 || p != 0)) {
        int cont = a;
        vi V;
        for (int i = 0; i < a; i++) V.push_back(i + 1);
        if (a == 1)
            cout << 1 << '\n';
        else {
            int i = 0;
            while (cont != 1) {
                int res = p - 1;
                while (res != 0) {
                    i++;
                    i %= V.size();
                    res--;
                }
                tiradas[i] = true;
                cont--;
            }
            cout << V[0] << '\n';
        }
    }
    return 0;
}
