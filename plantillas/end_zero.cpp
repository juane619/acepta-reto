//#include <iostream>

//Múltiples casos de prueba los cuales estan descritos por una 
//secuencia indeterminada hasta leer 0, y se parara de leer casos al leer cero tambien.

using namespace std;

int main() {
    int mediciones, medicion,i;
    
    scanf("%d", &mediciones);

    while (mediciones > 0) {
        i=0;
        int almacen_mediciones[mediciones];
        do {
            scanf("%d", &medicion);
            mediciones[i]=medicion;
            i++;
        } while (medicion > 0);

        
        scanf("%d", &mediciones);
        //cin >> diam;
    }
    
    return 0;
}