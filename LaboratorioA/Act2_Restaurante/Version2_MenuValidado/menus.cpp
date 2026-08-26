#include <iostream>
#include "menus.h"
using namespace std;

const int NUM_PLATOS = 3;

void menu2(){
    cout << "Bienvenido al restaurante 6004" << endl;
    cout << "Menu de hoy" << endl;
    cout << "1. Lomo saltado" << endl;
    cout << "2. Tallarines verdes" << endl;
    cout << "3. Arroz chaufa" << endl;
}

int cantidadPlatos(){
    return NUM_PLATOS;
}

string nombrePlato(int opcion){
    if (opcion == 1){
        return "Lomo saltado";
    } else if (opcion == 2){
        return "Tallarines verdes";
    } else {
        return "Arroz chaufa";
    }
}

int elegirOpcion(){
    int opcion;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    while (opcion < 1 || opcion > cantidadPlatos()){
        cout << "Opcion incorrecta." << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
    }
    return opcion;
}
