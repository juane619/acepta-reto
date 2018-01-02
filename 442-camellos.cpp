/*Numero de casos indeterminados, hasta leer EOF (CTRL+D, linux o CTRL+Z, windows)*/
//#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    string nombre, notacion;
    char aux;
    nombre.reserve(20);
    notacion.reserve(12);

    while (cin >> nombre && cin >> notacion) {

        if (notacion == "snake_case") {
            for (int i = 0; i < nombre.size(); i++) {
                aux = nombre[i];
                if (i > 0 && isupper(aux)) {
                    nombre.insert(nombre.begin() + i, '_');
                    nombre[i + 1] = tolower(nombre[i + 1]);
                } else if (i > 0 && aux == '-') {
                    nombre[i] = '_';
                } else {
                    aux = tolower(aux);
                    nombre[i] = aux;
                }
            }
        } else if (notacion == "kebab-case") {
            for (int i = 0; i < nombre.size(); i++) {
                aux = nombre[i];
                if (i > 0 && isupper(aux)) {
                    nombre.insert(nombre.begin() + i, '-');
                    nombre[i + 1] = tolower(nombre[i + 1]);
                } else if (i > 0 && aux == '_') {
                    nombre[i] = '-';
                } else {
                    aux = tolower(aux);
                    nombre[i] = aux;
                }
            }
        } else if (notacion == "CamelCase") {
            nombre[0] = toupper(nombre[0]);
            int pos = nombre.find_first_of("-");
            while (pos != string::npos) {
                nombre.erase(pos, 1);
                nombre[pos] = toupper(nombre[pos]);
                pos = nombre.find_first_of("-", pos + 1);
            }
            pos = nombre.find_first_of("_");
            while (pos != string::npos) {
                nombre.erase(pos, 1);
                nombre[pos] = toupper(nombre[pos]);
                pos = nombre.find_first_of("_", pos + 1);
            }
        }

        cout << nombre << endl;
        nombre.clear();
        notacion.clear();
    }

    return 0;
}