// Ejercicio 1 - Capicua (Lab A, "Mas ejercicios")
// Un numero es capicua si se lee igual de izquierda a derecha que de
// derecha a izquierda. Pista del enunciado: crear una funcion que
// invierta el numero, y comparar el resultado con el original.
#include <iostream>
using namespace std;

// Reconstruye "n" al reves, digito por digito.
// Ejemplo: n=12345 -> devuelve 54321
int invertir(int n){
    int invertido = 0;
    while (n != 0){
        int digito = n % 10;      // extrae el ultimo digito
        invertido = invertido * 10 + digito;  // lo va agregando al final del invertido
        n = n / 10;                // descarta el digito ya usado
    }
    return invertido;
}

int main(){
    int n;
    cout << "Ingrese un entero: ";
    cin >> n;

    int inv = invertir(n);

    if (n == inv){
        cout << "Es CAPICUA." << endl;
    } else {
        cout << "No es capicua." << endl;
    }

    return 0;
}
