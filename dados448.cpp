#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;

bool fastscan(int &number) {
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

    return true;
}

const int CASO_ESPECIAL = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int faces;

    while (cin >> faces) {
        if (faces == CASO_ESPECIAL) return 0;

        int ptr1 = 0, ptr2 = 0;
        int wins1 = 0, wins2 = 0;
        int ptr1aux = 0, ptr2aux = 0;

        vi faces1(faces, 1), faces2(faces, 1);

        for (int i = 0; i < faces; i++) {
            cin >> faces1[i];
        }
        for (int i = 0; i < faces; i++) {
            cin >> faces2[i];
        }

        sort(faces1.begin(), faces1.end());
        sort(faces2.begin(), faces2.end());

        while (ptr1 < faces || ptr2 < faces) {
            if (ptr2 == faces ||
                (ptr1 < faces && faces1[ptr1] < faces2[ptr2])) {
                ptr1++;
                wins1 += ptr2;
                ptr1aux = ptr1;
            } else if (ptr1 == faces ||
                       (ptr2 < faces && faces1[ptr1] > faces2[ptr2])) {
                ptr2++;
                wins2 += ptr1;
                ptr2aux = ptr2;
            } else {
                int repeated = (ptr1 < faces) ? faces1[ptr1] : faces2[ptr2];
                while (ptr1 < faces && faces1[ptr1] == repeated) {
                    ptr1++;
                    wins1 += ptr2aux;
                }
                while (ptr2 < faces && faces2[ptr2] == repeated) {
                    ptr2++;
                    wins2 += ptr1aux;
                }

                ptr1aux = ptr1;
                ptr2aux = ptr2;
            }
        }

        // cout << loses << endl;

        if (wins1 > wins2)
            cout << "PRIMERO\n";
        else if (wins1 < wins2)
            cout << "SEGUNDO\n";
        else
            cout << "NO HAY DIFERENCIA\n";
    }

    return 0;
}
