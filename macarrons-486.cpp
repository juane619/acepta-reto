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

int gcd(int a, int b) {
    for (;;) {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b) {
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

const int CASO_ESPECIAL = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ncomensales;
    int a, b;
    char aux;
    int comidos;
    int mcm = 1;

    while (cin >> ncomensales) {
        if (ncomensales == CASO_ESPECIAL) return 0;
        mcm = 1;
        comidos = 0;
        vi nums(ncomensales);
        vi denms(ncomensales);

        for (int i = 0; i < ncomensales; i++) {
            cin >> a >> aux >> b;
            mcm = lcm(mcm, b);
            nums[i] = a;
            denms[i] = b;
        }

        for (int i = 0; i < ncomensales; i++) {
            comidos += (mcm / denms[i]) * nums[i];
        }

        cout << mcm - comidos << "\n";
    }

    return 0;
}
