#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
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
const char VILLANO = 'X';
const char LIBRE = '.';

int checkVillano(const vector<vc>& sala, int row, int col, string direction) {
    size_t posx = col, posy = row;
    size_t nrows = sala.size(), ncols = sala[0].size();

    if (direction == "ARRIBA") {
        while (posy > 0) {
            posy--;
            if (sala[posy][posx] == VILLANO) {
                return row - posy;
            }
        }
    } else if (direction == "ABAJO") {
        while (posy < nrows - 1) {
            posy++;
            if (sala[posy][posx] == VILLANO) {
                return posy - row;
            }
        }
    } else if (direction == "DERECHA") {
        while (posx < ncols - 1) {
            posx++;
            if (sala[posy][posx] == VILLANO) {
                return posx - col;
            }
        }
    } else {
        while (posx > 0) {
            posx--;
            if (sala[posy][posx] == VILLANO) {
                return col - posx;
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, cols, queries;
    int row, col;
    string direction;
    int distance;

    while (cin >> rows >> cols) {
        if (rows == CASO_ESPECIAL && cols == CASO_ESPECIAL) return 0;

        vector<vc> sala(rows);

        for (int i = 0; i < rows; i++) {
            sala[i] = vc(cols);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> sala[i][j];
            }
        }

        cin >> queries;

        for (int i = 0; i < queries; i++) {
            cin >> row >> col;
            cin >> direction;

            if ((distance = checkVillano(sala, row - 1, col - 1, direction)) ==
                -1) {
                cout << "NINGUNO\n";
            } else {
                cout << distance << "\n";
            }
        }
        cout << "---\n";
    }

    return 0;
}
