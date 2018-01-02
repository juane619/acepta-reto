#include <cstdio>

int main() {
    int veces;
    int cont_grupos, cont_min_grupo, cont_max_grupo, cont_aux;
    unsigned long min;

    while (scanf("%d", &veces) > 0 && veces != 0) {
        cont_grupos = cont_max_grupo = cont_aux = 1;
        cont_min_grupo = 10000;

        unsigned long velocidades[veces];

        for (int i = 0; i < veces; i++) {
            scanf("%lu", &velocidades[i]);
        }

        min = velocidades[0];

        for (int j = 1; j < veces; j++) {
            if (velocidades[j] < min) {
                min = velocidades[j];
                cont_grupos++;
                if (cont_aux > cont_max_grupo)
                    cont_max_grupo = cont_aux;
                if (cont_aux < cont_min_grupo)
                    cont_min_grupo = cont_aux;
                cont_aux = 1;
            } else
                cont_aux++;

        }
        if (cont_aux > cont_max_grupo)
            cont_max_grupo = cont_aux;
        if (cont_aux < cont_min_grupo)
            cont_min_grupo = cont_aux;

        printf("%d %d %d\n", cont_grupos, cont_min_grupo, cont_max_grupo);
    }

    return 0;
}