/*Numero de casos indeterminados, hasta leer EOF (CTRL+D, linux o CTRL+Z, windows)*/
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string secuencia_dig;
    int secuencia[10];
    int aux;
    bool seguir=false;
    
    while (cin >> secuencia_dig) {
        for (int j = 0; j < 10; j++)
            secuencia[j]=0;
        seguir=true;
        
        for (int i = 0; i < secuencia_dig.size(); i++){
            aux=secuencia_dig[i]-'0';
            secuencia[aux]++;
        }
        for (int j = 0; j < 10-1 && seguir; j++)
            if(secuencia[j] != secuencia[j+1])
                seguir=false;
        
        if(!seguir)
            cout << "no subnormal\n";
        else
            cout << "subnormal\n";
    }


    return 0;
}