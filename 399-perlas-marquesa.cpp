//#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    unsigned diam = 1;
    unsigned collar[1000];
    short nperlas;
    bool puede;

    scanf("%d", &diam);
    //cin >> diam;

    while (diam > 0) {
        nperlas = 0;
        puede = true;
        do {
            collar[nperlas] = diam;
            nperlas++;
            scanf("%d", &diam);
            //cin >> diam;
        } while (diam > 0);

        if (nperlas % 2 == 0)
            //cout << "NO\n";
            printf("NO\n");
        else {
            bool mayor = false;
            unsigned collaraux[nperlas];
            short i = 0;

            sort(collar, collar + nperlas);

            for (short j = 0; j < nperlas && puede; j++) {
                if (collar[j] == collar[j + 1] && !mayor) {
                    collaraux[i] = collar[j];
                    i++;
                    j++;
                } else {
                    if (mayor) {
                        puede = false;
                    } else {
                        collaraux[i] = collar[j];
                        i++;
                        mayor = true;
                    }
                }
            }
            if (puede) {
                for (short j = nperlas - 2; j > 0; j -= 2) {
                    collaraux[i] = collar[j];
                    i++;
                }

                for (short j = 0; j < nperlas; j++) {
                    //cout << collaraux[j];
                    printf("%d", collaraux[j]);
                    if (j != nperlas - 1)
                        printf(" ");
                }
                printf("\n");
                //cout << "\n";
            } else
                printf("NO\n");
                //cout << "NO\n";
        }
        scanf("%d", &diam);
        //cin >> diam;
    }
}