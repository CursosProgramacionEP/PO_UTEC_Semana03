// Actividad 1 - Conversion temporal (Sesion 3A)
// Version DEFECTUOSA: los parametros se pasan por VALOR.
//
// Defecto: "convertir" recibe copias locales de horas, min y seg (de hecho
// ni siquiera las recibe como parametros, las declara sueltas dentro de la
// funcion). Cualquier cambio que se haga dentro de la funcion se pierde al
// terminar la funcion, por lo que las variables horas, min y seg de main()
// nunca se actualizan y siempre se imprimen como 0.
#include <iostream>
#include <string>
using namespace std;

void convertir(int segundos){
    int horas=0, min=0, seg=0;
    horas = segundos/3600;      // cuántas horas completas hay
    segundos %= 3600;       // le "quita" esas horas, dejando el resto en segundos
    min = segundos/60;        // de lo que sobró, cuántos minutos completos hay
    seg = segundos%60;        // lo que sobra después de los minutos son los segundos
    // Estas variables locales desaparecen al salir de la funcion.
}

int main(){
    int segundos, horas=0, min=0, seg=0;
    cout << "Segundos: ";
    cin >> segundos;

    convertir(segundos);

    cout << "Conversion: ";
    cout << horas << "h " << min << "m " << seg << "s" << endl;
    // Siempre se imprime "0h 0m 0s" sin importar el valor ingresado.
    return 0;
}
