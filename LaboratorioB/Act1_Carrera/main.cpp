// Actividad 1 - La carrera (Sesion 3B)
// Compara el tiempo de ejecucion de la version recursiva vs la iterativa
// del factorial.
#include <iostream>
#include <string>
#include <chrono>
#include "factorial.h"

int main() {
    long long int m;
    long long int n;

    std::cout << "Ingrese un entero positivo: ";
    std::cin >> n;

    auto inicio = std::chrono::high_resolution_clock::now();
    m = version_recursiva(n);
    auto fin = std::chrono::high_resolution_clock::now();

    auto tiempo1 = std::chrono::duration<double, std::nano>(fin - inicio);
    std::cout << n << "! = " << m << "\n";
    std::cout << "Recursivo: " << tiempo1.count() << " ns" << std::endl;

    inicio = std::chrono::high_resolution_clock::now();
    m = version_iterativa(n);
    fin = std::chrono::high_resolution_clock::now();

    auto tiempo2 = std::chrono::duration<double, std::nano>(fin - inicio);
    std::cout << n << "! = " << m << "\n";
    std::cout << "Iterativo: " << tiempo2.count() << " ns" << std::endl;

    return 0;
}
