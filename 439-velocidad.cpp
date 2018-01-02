/*Numero de casos determinados previamente por teclado*/

#include <iostream>

using namespace std;

int main() {
    unsigned veces;
    char dato1, dato2, igual;
    int val1, val2;

    scanf("%d", &veces);

    for (; veces > 0; veces--) {
        cin >> dato1 >> igual >> val1 >> dato2 >> igual >> val2;

        if (dato1 == 'D' && dato2 == 'T')
            printf("V=%d\n", val1 / val2);
        else if (dato1 == 'T' && dato2 == 'D')
            printf("V=%d\n", val2 / val1);
        else if (dato1 == 'T' && dato2 == 'V')
            printf("D=%d\n", val1 * val2);
        else if (dato1 == 'V' && dato2 == 'T')
            printf("D=%d\n", val2 * val1);
        else if (dato1 == 'V' && dato2 == 'D')
            printf("T=%d\n", val2 / val1);
        else if (dato1 == 'D' && dato2 == 'V')
            printf("T=%d\n", val1 / val2);
    }

    return 0;
}