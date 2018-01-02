/*Numero de casos indeterminados, hasta leer EOF (CTRL+D, linux o CTRL+Z, windows)*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int nnaipes, naipe;
    int j, k, cont;

    while (scanf("%d", &nnaipes) && nnaipes != 0) {
        int naipes[nnaipes];
        int aux[nnaipes];

        for (int i = 0; i < nnaipes; i++) {
            scanf("%d", &naipe);
            naipes[i] = naipe;
            aux[i] = naipe;
        }

        sort(aux, aux + nnaipes);

        j = k = cont = 0;

        while (j < nnaipes && k < nnaipes) {
            if (naipes[j] != aux[k])
                j++;
            else if (naipes[j] == aux[k]){
                cont++;
                j++, k++;
            }
        }
        
        printf("%d\n", nnaipes-cont);

    }

    return 0;
}