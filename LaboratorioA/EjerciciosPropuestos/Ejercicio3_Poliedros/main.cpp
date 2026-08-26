// Ejercicio 3 - Poliedros Regulares (Lab A, "Mas ejercicios")
// Menu con los 5 poliedros regulares; el usuario elige uno, ingresa la
// arista, y el programa muestra el nombre del solido y su volumen.
// Las formulas de volumen estan implementadas aparte, en poliedros.h/.cpp.
#include <iostream>
#include <string>
#include "poliedros.h"
using namespace std;

int main(){
    cout << "Poliedros regulares:" << endl;
    cout << "1. Tetraedro" << endl;
    cout << "2. Cubo" << endl;
    cout << "3. Octaedro" << endl;
    cout << "4. Dodecaedro" << endl;
    cout << "5. Icosaedro" << endl;

    int opcion;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    double arista;
    cout << "Ingrese la longitud de la arista: ";
    cin >> arista;

    string nombre;
    double volumen;

    // Decision multiple: una rama por cada poliedro del menu.
    if (opcion == 1){
        nombre = "Tetraedro";
        volumen = volumenTetraedro(arista);
    } else if (opcion == 2){
        nombre = "Cubo";
        volumen = volumenCubo(arista);
    } else if (opcion == 3){
        nombre = "Octaedro";
        volumen = volumenOctaedro(arista);
    } else if (opcion == 4){
        nombre = "Dodecaedro";
        volumen = volumenDodecaedro(arista);
    } else if (opcion == 5){
        nombre = "Icosaedro";
        volumen = volumenIcosaedro(arista);
    } else {
        cout << "Opcion incorrecta." << endl;
        return 0;
    }

    cout << "Solido: " << nombre << endl;
    cout << "Volumen: " << volumen << endl;

    return 0;
}
