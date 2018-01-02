/*Numero de casos indeterminados, hasta leer EOF (CTRL+D, linux o CTRL+Z, windows)*/
#include <stdio.h>
#include <queue>

using namespace std;

int main() {
    int p, n; //partituras e instrumentos (minimo una partitura para cada instrumento hay)
    int resta, divisiones;
    int musicos;
    int musicos_totales;
    priority_queue<int> instrumentos;
    int division, divisionaux;

    while (scanf("%d%d", &p, &n) > 0) {

        musicos_totales = divisiones = 0;

        if (p < n)
            p = n;

        for (int i = 0; i < n; i++) {
            scanf("%d", &musicos);
            musicos_totales += musicos;
            instrumentos.push(musicos);
        }

        if (p >= musicos_totales)
            printf("1\n");
        else if (p == n) {
            printf("%d\n", instrumentos.top());
        } else {
            resta = p - n;
            for (; divisiones < resta; divisiones++) {
                division = instrumentos.top();
                divisionaux=division/2;
                instrumentos.pop();
                instrumentos.push(divisionaux);
                instrumentos.push(division - divisionaux);
            }

            printf("%d\n", instrumentos.top());

        }

        while (!instrumentos.empty()) {
            instrumentos.pop();
        }
    }

    return 0;
}