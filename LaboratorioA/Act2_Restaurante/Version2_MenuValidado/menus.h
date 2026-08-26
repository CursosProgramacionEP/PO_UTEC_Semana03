#ifndef MENUS_H
#define MENUS_H

#include <string>

// Imprime el menu del dia (cartilla 2) y numero de platos disponibles.
void menu2();
int cantidadPlatos();
std::string nombrePlato(int opcion);

// Pide una opcion al usuario y la valida contra la cantidad de platos,
// volviendo a preguntar mientras la opcion sea incorrecta.
int elegirOpcion();

#endif
