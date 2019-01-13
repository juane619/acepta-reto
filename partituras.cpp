#include <bits/stdc++.h>
#include <iostream>
#include <queue>
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

class Relacion {
   public:
    int inicial;
    int cociente;
    int divisor;

    Relacion(int musicos) {
        inicial = cociente = musicos;
        divisor = 2;
    }

    bool operator<(const Relacion& other) const {
        return cociente < other.cociente;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int npartituras, ninstruments;
    int npart_real;
    int nmusicos;

    while (cin >> npartituras >> ninstruments) {
        priority_queue<Relacion, vector<Relacion>, less<Relacion> > musicos;

        for (int i = 0; i < ninstruments; i++) {
            cin >> nmusicos;
            musicos.push(nmusicos);
        }
        npart_real = npartituras - ninstruments;

        while (npart_real--) {
            Relacion max = musicos.top();
            musicos.pop();

            if (max.inicial % max.divisor == 0) {
                max.cociente = max.inicial / max.divisor;
                max.divisor++;
            } else {
                max.cociente = max.inicial / max.divisor + 1;
                max.divisor++;
            }

            musicos.push(max);
        }

        cout << musicos.top().cociente << "\n";
    }

    return 0;
}
