/*Numero de casos determinados previamente por teclado*/

#include <cstdio>

using namespace std;

int main() {
    unsigned veces, ejem, cajas;

    scanf("%d", &veces);

    for (; veces > 0; veces--) {
        scanf("%d%d", &ejem, &cajas);
        if(ejem>cajas)
            printf("PRINCIPIO\n");
        else
            printf("ROMANCE\n");
    }

    return 0;
}