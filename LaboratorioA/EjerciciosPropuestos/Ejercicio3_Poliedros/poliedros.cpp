#include <cmath>
#include "poliedros.h"

// Formulas de volumen de los 5 poliedros regulares (solidos platonicos),
// en funcion de la longitud de arista "a".

double volumenTetraedro(double a){
    return (sqrt(2.0) / 12.0) * a * a * a;
}

double volumenCubo(double a){
    return a * a * a;
}

double volumenOctaedro(double a){
    return (sqrt(2.0) / 3.0) * a * a * a;
}

double volumenDodecaedro(double a){
    return ((15.0 + 7.0 * sqrt(5.0)) / 4.0) * a * a * a;
}

double volumenIcosaedro(double a){
    return ((15.0 + 5.0 * sqrt(5.0)) / 12.0) * a * a * a;
}
