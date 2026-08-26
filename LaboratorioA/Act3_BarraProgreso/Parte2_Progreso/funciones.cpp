#include <iostream>
#include "funciones.h"
using namespace std;

void ingresar_nota(int &nota){
    do {
        cout << "Ingrese la nota (0-20): ";
        cin >> nota;
    } while (nota < 0 || nota > 20);
}

// Aqui "porcentaje" ya viene calculado; imprime UNA barra para ese porcentaje.
void imprimir_barra(int porcentaje){
    int cantidadBarras = porcentaje / 2;

    cout << "0 % ";
    for (int i = 0; i < cantidadBarras; i++){
        cout << "|";
    }
    if (cantidadBarras > 0){
        cout << " ";
    }
    cout << porcentaje << " %/100 %" << endl;
}

// Muestra la secuencia de barras desde 0 % hasta el porcentaje final,
// avanzando de 5 % en 5 %.
void imprimir_progreso(int nota){
    int porcentajeFinal = (nota * 100) / 20;
    for (int p = 0; p <= porcentajeFinal; p += 5){
        imprimir_barra(p);
    }
}
