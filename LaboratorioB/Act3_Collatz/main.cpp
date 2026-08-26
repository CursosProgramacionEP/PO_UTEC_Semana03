// Actividad 3 - Conjetura de Collatz (Sesion 3B)
// Muestra la secuencia de Collatz desde un numero dado hasta llegar a 1,
// implementada tanto de forma recursiva como iterativa.
#include <iostream>
using namespace std;

void collatzRecursivo(int n){
    cout << n;
    if (n == 1){
        return;
    }
    cout << ", ";
    if (n % 2 == 0){
        collatzRecursivo(n / 2);
    } else {
        collatzRecursivo(3 * n + 1);
    }
}

void collatzIterativo(int n){
    cout << n;
    while (n != 1){
        if (n % 2 == 0){
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        cout << ", " << n;
    }
}

int main(){
    int numero;
    cout << "Ingrese un numero positivo: ";
    cin >> numero;

    cout << "Version recursiva: ";
    collatzRecursivo(numero);
    cout << endl;

    cout << "Version iterativa: ";
    collatzIterativo(numero);
    cout << endl;

    return 0;
}
