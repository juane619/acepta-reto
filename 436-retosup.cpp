/*Numero de casos indeterminados, hasta leer EOF (CTRL+D, linux o CTRL+Z, windows)*/
#include <cstdio>

using namespace std;

int main() {
    int micras, altura;
    float conv;
    int i;

    while (scanf("%d%d", &micras, &altura) > 0) {
        conv=micras/1000000.0;
        i=0;
        while(conv<altura){
            conv*=2.0;
            i++;
        }
        printf("%d\n", i);
    }

    return 0;
}
