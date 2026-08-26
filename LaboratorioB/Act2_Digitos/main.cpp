// Actividad 2 - Digitos (Sesion 3B)
// Imprime, de forma recursiva, los digitos de un numero entero desde el
// mas significativo hasta el menos significativo.
#include <iostream>
using namespace std;

void imprimirDigitos(int n){
    if (n == 0){
        return;
    }
    // Primero se procesa lo que queda al quitar el ultimo digito (llamada
    // recursiva) y RECIEN despues se imprime el digito actual: asi se logra
    // el orden del mas significativo al menos significativo.
    imprimirDigitos(n / 10);
    cout << n % 10;
}

int main(){
    int numero;
    cout << "Ingrese un numero entero: ";
    cin >> numero;

    if (numero == 0){
        cout << 0 << endl;
        return 0;
    }

    if (numero < 0){
        cout << "-";
        numero = -numero;
    }

    imprimirDigitos(numero);
    cout << endl;
    return 0;
}
