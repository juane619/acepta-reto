#include <iostream>

using namespace std;

int main() {
    int uvas, acum = 0;
    unsigned i = 1;

    while (scanf("%d", &uvas) > 0 && uvas != 0) {
        acum = uvas;
        i = 1;
        while (acum > 0) {
            acum = acum - i;
            i++;
        }
        cout << i-1 << endl;
    }


    return 0;
}
