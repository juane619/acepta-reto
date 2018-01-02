/*Numero de casos indeterminados, hasta leer EOF (CTRL+D, linux o CTRL+Z, windows)*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string numero;
    short pos, auxpos;
    short tam, ele;
    vector<short> num;
    num.reserve(750);

    while (cin >> numero) {
        num.clear();
        pos = auxpos = 0;

        int pos = numero.find_first_of(".");
        if (pos == string::npos)
            num.push_back(atoi(numero.c_str()));
        else {
            while (pos != string::npos) {
                num.push_back(atoi(numero.substr(auxpos, pos).c_str()));
                auxpos = pos + 1;
                pos = numero.find_first_of(".", pos + 1);
            }
            num.push_back(atoi(numero.substr(auxpos).c_str()));
        }

        for (int i = num.size() - 1; i >= 0; i--) {
            if (i == num.size() - 1)
                num[i]++;
            if (num[i] == 1000) {
                num[i] = 0;
                if (i == 0) {
                    num.insert(num.begin(), 1);
                } else
                    num[i - 1]++;
            }
        }

        tam=num.size();
        
        for (int i = 0; i < tam; i++) {
            ele=num[i];
            if (i == 0) {
                if (i == tam - 1)
                    printf("%d", ele);
                else
                    printf("%d.", ele);
            } else if (i != tam - 1)
                printf("%03d.", ele);
            else
                printf("%03d", ele);
        }

        printf("\n");
    }

    return 0;
}