// Actividad 3 - Barra de progreso (parte 1)
// Plantilla dada por el enunciado; la implementacion de las funciones
// se hace despues de main(), tal como lo indica la diapositiva.
#include <iostream>
#include <string>
using namespace std;

void ingresar_nota(int&);
void imprimir_barra(int);

int main(){
    int nota;
    ingresar_nota(nota);
    imprimir_barra(nota);
    return 0;
}

void ingresar_nota(int &nota){
    do {
        cout << "Ingrese la nota (0-20): ";
        cin >> nota;
    } while (nota < 0 || nota > 20);
}

void imprimir_barra(int nota){
    int porcentaje = (nota * 100) / 20;
    int cantidadBarras = porcentaje / 2; // 1 barra cada 2%, hasta 50 barras

    cout << "0 % ";
    for (int i = 0; i < cantidadBarras; i++){
        cout << "|";
    }
    if (cantidadBarras > 0){
        cout << " ";
    }
    cout << porcentaje << " %/100 %" << endl;
}
