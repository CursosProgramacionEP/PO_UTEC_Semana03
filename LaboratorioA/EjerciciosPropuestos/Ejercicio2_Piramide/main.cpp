// Ejercicio 2 - La piramide (Lab A, "Mas ejercicios")
// El nivel k de la piramide usa k*(k+1)/2 cubos (numero triangular):
// nivel 1 = 1, nivel 2 = 1+2 = 3, nivel 3 = 1+2+3 = 6, nivel 4 = 10, ...
// Dado N cubos disponibles, se quiere saber cual es la altura maxima de
// piramide que se puede armar y cuantos cubos sobran.
#include <iostream>
using namespace std;

// Cuantos cubos necesita un nivel especifico (numero triangular).
int cubosDelNivel(int nivel){
    return (nivel * (nivel + 1)) / 2;
}

// Va agregando niveles completos mientras alcancen los cubos disponibles.
// altura y sobran son parametros de salida (por referencia) porque la
// funcion necesita "devolver" dos resultados a la vez.
void calcularPiramide(int N, int &altura, int &sobran){
    altura = 0;
    int usados = 0;
    int nivel = 1;

    while (usados + cubosDelNivel(nivel) <= N){
        usados = usados + cubosDelNivel(nivel);
        altura = altura + 1;
        nivel = nivel + 1;
    }

    sobran = N - usados;
}

int main(){
    int N, altura, sobran;

    cout << "Ingrese la cantidad de cubos: ";
    cin >> N;

    calcularPiramide(N, altura, sobran);

    cout << "Altura maxima: " << altura << endl;
    cout << "Cubos sobrantes: " << sobran << endl;

    return 0;
}
