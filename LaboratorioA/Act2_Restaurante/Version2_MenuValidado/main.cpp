// Nuevo problema: se valida la opcion ingresada por el cliente para que el
// programa no se cierre ante una opcion incorrecta.
#include <iostream>
#include <string>
#include "menus.h"
using namespace std;

int main(){
    menu2();
    int opcion = elegirOpcion();
    cout << "Ha elegido: " << nombrePlato(opcion) << endl;
    return 0;
}
