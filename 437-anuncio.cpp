/*Numero de casos determinados previamente por teclado*/

//#include <iostream>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

int main() {
    unsigned veces;
    int horas, minutos, segundos;
    time_t now;
    struct tm newyear;
    
    time(&now);
    newyear=*localtime(&now);
    newyear.tm_hour=0; newyear.tm_min=0; newyear.tm_sec=0;

    diff
    scanf("%d", &veces);
    //cin >> veces;

    for (; veces > 0; veces--) {
        scanf("%02d:%02d:%02d", &horas, &minutos, &segundos);
        horas = 24 - horas;
        minutos = 60 - minutos;
        segundos = 60 - segundos;
        
        if(segundos==60)
            segundos=0;
        if(minutos)
            horas-=1;
        if(segundos)
            minutos-=1;
        if(minutos==60)
            minutos=0;
        
            
        printf("%02d:%02d:%02d\n", horas,minutos,segundos);
    }

    return 0;
}