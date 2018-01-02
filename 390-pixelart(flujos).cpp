#include <cstdio>

int main() {
    unsigned veces;
    int disp_cian, disp_mag, disp_yellow;
    char pixel;
    bool puede;

    scanf("%d", &veces);

    for (; veces > 0; veces--) {
        scanf("%d%d%d", &disp_mag, &disp_yellow, &disp_cian);

        puede = disp_cian >= 0 && disp_mag >= 0 && disp_yellow >= 0;

        pixel = getc(stdin);

        while (puede && pixel != '\n') {
            if (pixel != ' ') {
                switch (pixel) {
                    case 'M':
                        disp_mag--;
                        break;
                    case 'C':
                        disp_cian--;
                        break;
                    case 'A':
                        disp_yellow--;
                        break;
                    case 'R':
                        disp_yellow--;
                        disp_mag--;
                        break;
                    case 'V':
                        disp_cian--;
                        disp_yellow--;
                        break;
                    case 'L':
                        disp_cian--;
                        disp_mag--;
                        break;
                    case 'N':
                        disp_cian--;
                        disp_mag--;
                        disp_yellow--;
                        break;
                    default:
                        ;
                }
                puede = disp_cian >= 0 && disp_mag >= 0 && disp_yellow >= 0;
            }
            pixel = getc(stdin);
        }

        if (pixel != '\n')
            scanf("%*[^\n]%*c"); //LIMPIAMOS BUFFER MANUALMENTE


        if (!puede) {
            printf("NO\n");
        } else
            printf("SI %d %d %d\n", disp_mag, disp_yellow, disp_cian);
    }

}