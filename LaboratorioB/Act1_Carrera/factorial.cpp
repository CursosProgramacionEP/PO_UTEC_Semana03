#include "factorial.h"

long long int version_iterativa(long long int n){
    long long int resultado = 1;
    for (long long int i = 2; i <= n; i++){
        resultado *= i;
    }
    return resultado;
}

long long int version_recursiva(long long int n){
    if (n <= 1){
        return 1;
    }
    return n * version_recursiva(n - 1);
}
