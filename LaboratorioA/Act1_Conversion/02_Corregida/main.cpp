// Actividad 1 - Conversion temporal (Sesion 3A)
// Version CORREGIDA: los parametros h, m y s se pasan por REFERENCIA,
// por lo que los cambios hechos dentro de "convertir" si se reflejan
// en las variables horas, min y seg de main().
#include <iostream>
#include <string>
using namespace std;

void convertir(int segundos, int &h, int &m, int &s){
    h = segundos/3600;      // cuántas horas completas hay
    segundos %= 3600;       // le "quita" esas horas, dejando el resto en segundos
    m = segundos/60;        // de lo que sobró, cuántos minutos completos hay
    s = segundos%60;        // lo que sobra después de los minutos son los segundos
}

int main(){
    int segundos, horas=0, min=0, seg=0;
    cout << "Segundos: ";
    cin >> segundos;

    convertir(segundos, horas, min, seg);

    cout << "Conversion: ";
    cout << horas << "h " << min << "m " << seg << "s" << endl;
    return 0;
}
