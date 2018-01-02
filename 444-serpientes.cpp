#include <iostream>

/*
 * Leer múltiples casos de prueba, cada uno con unas lineas que lo describen, hasta leer cero.
 */
using namespace std;

int main() {
    int mediciones, med_con;
    int cont_gen, cont_ceros, max_cont;
    bool start_cont = false, already;

    while ((scanf("%d%d", &mediciones, &med_con) > 0) && (mediciones != 0 || med_con != 0)) {
        cont_ceros = max_cont = cont_gen = 0;
        start_cont = false;
        int alm_mediciones[mediciones];
        for (int i = 0; i < mediciones; i++) {
            scanf("%d", &alm_mediciones[i]);
        }

        for (int i = 0; i < mediciones; i++) {
            if (alm_mediciones[i] == 1) {
                cont_gen++;
                if (cont_gen > max_cont)
                    max_cont = cont_gen;

                if (start_cont) {
                    start_cont = false;
                    cont_gen += cont_ceros;
                    cont_ceros = 0;

                    if (cont_gen > max_cont)
                        max_cont = cont_gen;

                }
                start_cont = true;
            } else { //es cero
                if (start_cont) {
                    cont_ceros++;

                    if (cont_ceros > med_con) {
                        cont_ceros = 0;
                        cont_gen = 0;
                        start_cont = false;
                    }
                }
            }
        }
        cout << max_cont << endl;
    }

    return 0;

}444-serpientes
