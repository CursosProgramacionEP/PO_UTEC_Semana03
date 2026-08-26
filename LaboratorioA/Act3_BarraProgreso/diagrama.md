<title>Barra de Progreso</title>

# Diagrama principal — Parte1_BarraFinal

```mermaid
flowchart TD
    INICIO(["Inicio"])
    LLAMAR1[["ingresar_nota(nota)"]]
    LLAMAR2[["imprimir_barra(nota)"]]
    FIN(["Fin"])

    INICIO --> LLAMAR1 --> LLAMAR2 --> FIN
```

# Diagrama de detalle — ingresar_nota()

Idéntica en Parte1 y Parte2: valida con un `do-while` que la nota esté entre 0 y 20.

```mermaid
flowchart TD
    INICIO2(["Inicio: ingresar_nota(nota)"])
    LEER@{ shape: manual-input, label: "Ingresar nota (0-20)" }
    COND{"nota &lt; 0 O nota &gt; 20?"}
    FIN2(["Fin: retorna nota por referencia"])

    INICIO2 --> LEER --> COND
    COND -->|Si, invalida| LEER
    COND -->|No, valida| FIN2
```

# Diagrama de detalle — imprimir_barra() (version Parte1)

```mermaid
flowchart TD
    INICIO3(["Inicio: imprimir_barra(nota)"])
    CALC1["porcentaje ← (nota * 100) / 20"]
    CALC2["cantidadBarras ← porcentaje / 2"]
    MOSTRAR1@{ shape: curv-trap, label: "Mostrar '0 % '" }
    INIT["i ← 0"]
    CONDFOR{"i &lt; cantidadBarras?"}
    BODY@{ shape: curv-trap, label: "Mostrar '|'" }
    INC["i ← i + 1"]
    CONDIF{"cantidadBarras &gt; 0?"}
    MOSTRAR2@{ shape: curv-trap, label: "Mostrar ' '" }
    MOSTRAR3@{ shape: curv-trap, label: "Mostrar porcentaje + ' %/100 %'" }
    FIN3(["Fin"])

    INICIO3 --> CALC1 --> CALC2 --> MOSTRAR1 --> INIT --> CONDFOR
    CONDFOR -->|Si| BODY --> INC --> CONDFOR
    CONDFOR -->|No| CONDIF
    CONDIF -->|Si| MOSTRAR2 --> MOSTRAR3
    CONDIF -->|No| MOSTRAR3
    MOSTRAR3 --> FIN3
```

# Diagrama principal — Parte2_Progreso

```mermaid
flowchart TD
    INICIO4(["Inicio"])
    LLAMAR3[["ingresar_nota(nota)"]]
    LLAMAR4[["imprimir_progreso(nota)"]]
    FIN4(["Fin"])

    INICIO4 --> LLAMAR3 --> LLAMAR4 --> FIN4
```

# Diagrama de detalle — imprimir_progreso()

Llama a `imprimir_barra()` repetidamente, subiendo el porcentaje de 5 en 5, desde 0 hasta el porcentaje final.

```mermaid
flowchart TD
    INICIO5(["Inicio: imprimir_progreso(nota)"])
    CALC3["porcentajeFinal ← (nota * 100) / 20"]
    INIT2["p ← 0"]
    COND2{"p &lt;= porcentajeFinal?"}
    LLAMAR5[["imprimir_barra(p)"]]
    INC2["p ← p + 5"]
    FIN5(["Fin"])

    INICIO5 --> CALC3 --> INIT2 --> COND2
    COND2 -->|Si| LLAMAR5 --> INC2 --> COND2
    COND2 -->|No| FIN5
```

# Teoría: declaración adelantada vs. archivo `.h`

## Declaración adelantada (forward declaration)

En **Parte1_BarraFinal**, todo el programa vive en un único `main.cpp`. Los prototipos se escriben arriba, antes de `main()`, y las implementaciones reales se escriben después:

```cpp
void ingresar_nota(int&);   // declaracion adelantada
void imprimir_barra(int);   // declaracion adelantada

int main(){
    ingresar_nota(nota);    // el compilador ya conoce la firma
    imprimir_barra(nota);
    return 0;
}

void ingresar_nota(int &nota){ ... }   // implementacion real, mas abajo
void imprimir_barra(int nota){ ... }
```

El compilador lee de arriba hacia abajo, una sola vez, dentro del mismo archivo. Si `main()` llamara a una función que el compilador aún no conoce, sería un error de "función no declarada" — igual que pasaría con un `.h`. La declaración adelantada resuelve esto **sin salir del mismo archivo**: basta con escribir el prototipo antes de usarlo.

## Archivo `.h`

En **Parte2_Progreso**, el programa se divide en tres archivos (`funciones.h`, `funciones.cpp`, `main.cpp`). Ahí ya no alcanza con una declaración adelantada dentro de un solo archivo, porque **dos archivos distintos** (`main.cpp` y `funciones.cpp`) necesitan conocer las mismas firmas. La declaración compartida se saca a un archivo aparte (`funciones.h`) que ambos incluyen con `#include "funciones.h"`.

## La diferencia real

Es exactamente el mismo concepto — "avisarle al compilador que una función existe antes de usarla" — aplicado en dos escalas distintas:

| | Declaración adelantada | Archivo `.h` |
|---|---|---|
| Dónde vive la declaración | Arriba, en el mismo `.cpp` | En un archivo `.h` aparte |
| Cuántos archivos la comparten | Solo ese `.cpp` | Todos los `.cpp` que lo incluyan |
| Cuándo conviene | El programa cabe en un solo archivo | Varios `.cpp` necesitan llamar a las mismas funciones |

**Por qué Parte1 no necesita `.h` y Parte2 sí:** en Parte1 solo existe `main.cpp` — nadie más necesita conocer `ingresar_nota()` ni `imprimir_barra()`. En Parte2, `main.cpp` necesita llamar a funciones que están *implementadas* en `funciones.cpp`, un archivo distinto que se compila por separado — ahí una declaración adelantada dentro de `main.cpp` no alcanza, porque el compilador de `funciones.cpp` también necesita ver esas mismas firmas para verificar que la implementación coincide con lo prometido. Por eso se comparte vía `.h`, en vez de repetir el prototipo a mano en cada archivo.
