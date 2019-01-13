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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nballs;

    while (cin >> nballs) {
        if (nballs == CASO_ESPECIAL) return 0;

        vb repeated(2000, false);
        vi balls(nballs, 0);
        vi results;

        for (int i = 0; i < nballs; i++) {
            cin >> balls[i];
        }
        // sort(balls.begin(), balls.end());

        // Podriamos utilizar un set en vez de array de booleanos pero es menos
        // eficiente aunque mas funcional
        // si formed;

        // Ahorras ordenacion previa utilizando max, min
        for (int i = 0; i < nballs; i++) {
            for (int j = i + 1; j < nballs; j++) {
                int result =
                    (max(balls[j], balls[i]) - min(balls[j], balls[i]));
                if (!repeated[result]) {
                    results.push_back(result);
                    repeated[result] = true;
                }
            }
        }

        sort(results.begin(), results.end());

        // Para hacer cosas en todos los elementos excepto en el ultimo, como
        // comas o espacios en blanco
        cout << results[0];
        for (int i = 1; i < results.size(); i++) {
            cout << " " << results[i];
        }

        cout << "\n";
    }

    return 0;
}
