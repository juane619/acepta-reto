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

// No acabada
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x) return m;

        // If x greater, ignore left half
        if (arr[m] < x) l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

// Ineficiente, o busqueda binaria o STL.
int firstGreater(int arr[], int sizearr, int x) {
    for (int i = 0; i < sizearr; i++) {
        if (arr[i] >= x) {
            return i;
        }
    }
    return sizearr - 1;
}

// Ineficiente, todos los posibles pares sumados
void sumanX(int arr[], int tope, int x) {
    int suma;
    for (int i = 0; i < tope; i++) {
        for (int j = i + 1; j < tope; j++) {
            suma = arr[i] + arr[j];
            if (suma == x) {
                if (arr[i] <= arr[j])
                    cout << arr[i] << " " << arr[j] << "\n";
                else
                    cout << arr[j] << " " << arr[i] << "\n";
                return;
            }
        }
    }
}

// Eficiente, empieza a la vez desde el principio y final y segun sean las
// sumas, va aumentando por cada uno de los lados
void hasArrayTwoCandidates(int A[], int arr_size, int sum) {
    int l, r;

    /* Now look for the two candidates in
       the sorted array*/
    l = 0;
    r = arr_size - 1;
    while (l < r) {
        if (A[l] + A[r] == sum) {
            // if (A[i] <= A[j])
            cout << A[l] << " " << A[r] << "\n";
            // else
            //  cout << A[j] << " " << A[i] << "\n";
            return;
        } else if (A[l] + A[r] < sum)
            l++;
        else  // A[i] + A[j] > sum
            r--;
    }
    return;
}

const int CASO_ESPECIAL = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nhechizos;
    ll danio_rel, total_danio, dif;
    int tope;

    while (cin >> nhechizos) {
        if (nhechizos == CASO_ESPECIAL) return 0;
        vi danios(nhechizos, -1);

        danio_rel = 0;
        for (int i = 0; i < nhechizos; i++) {
            cin >> danios[i];
            danio_rel += danios[i];
        }
        cin >> total_danio;
        dif = danio_rel - total_danio;

        if (danios[nhechizos - 1] <= dif)
            tope = nhechizos;
        else
            // tope = upper_bound(danios.begin(), danios.end(), dif) -
            // danios.begin(); //mas rapido
            tope = firstGreater(&danios[0], nhechizos, dif);  // mas lento
        // tanto uno como el otro, necesitan estar ordenados

        hasArrayTwoCandidates(&danios[0], tope, dif);
    }

    return 0;
}
