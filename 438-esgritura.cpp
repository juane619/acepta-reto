/*Numero de casos indeterminados, hasta leer EOF (CTRL+D, linux o CTRL+Z, windows)*/
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string mensaje;
    int count_letras, count_excl;

    while (getline(cin, mensaje)) {
        count_excl=count_letras=0;

        for (int i = 0; i < mensaje.size(); i++){
            char aux=mensaje[i];
            if(aux=='!')
                count_excl++;
            else if((aux>=65 && aux<=90) || (aux>=97 && aux<=122))
                count_letras++;
        }


        if(count_excl>count_letras)
            cout << "ESGRITO\n";
        else
            cout << "escrito\n";
    }


    return 0;
}4
