<title>Conversión Temporal</title>

# Diagrama principal (main) — igual para ambas versiones

```mermaid
flowchart TD
    INICIO(["Inicio"])
    MOSTRAR1@{ shape: curv-trap, label: "Mostrar 'Segundos: '" }
    LEER@{ shape: manual-input, label: "Ingresar segundos" }
    LLAMAR[["convertir(segundos)"]]
    NOTA@{ shape: brace, label: "Este llamado es identico en ambas versiones.\nLa diferencia (por valor vs por referencia) esta\nDENTRO de convertir(), no en este flujo principal." }
    MOSTRAR2@{ shape: curv-trap, label: "Mostrar 'Conversion: ' + horas + 'h ' + min + 'm ' + seg + 's'" }
    FIN(["Fin"])

    INICIO --> MOSTRAR1 --> LEER --> LLAMAR --> MOSTRAR2 --> FIN
    LLAMAR -.- NOTA
```

# Diagrama de detalle — convertir() versión DEFECTUOSA

```mermaid
flowchart TD
    INICIO(["Inicio: convertir(segundos)"])
    INIT["horas ← 0, min ← 0, seg ← 0"]
    NOTA1@{ shape: brace, label: "horas, min, seg se declaran AQUI,\nlocales a convertir(). No son\nlas mismas variables de main()." }
    CALC1["horas ← segundos / 3600"]
    MOD["segundos ← segundos % 3600"]
    CALC2["min ← segundos / 60"]
    CALC3["seg ← segundos % 60"]
    FIN(["Fin de convertir()"])
    NOTA2@{ shape: brace, label: "horas, min y seg locales se destruyen aqui.\nmain() nunca se entera de estos valores:\npor eso siempre imprime 0h 0m 0s." }

    INICIO --> INIT --> CALC1 --> MOD --> CALC2 --> CALC3 --> FIN
    INIT -.- NOTA1
    FIN -.- NOTA2
```

# Diagrama de detalle — convertir() versión CORREGIDA

```mermaid
flowchart TD
    INICIO2(["Inicio: convertir(segundos, h, m, s)"])
    NOTA1B@{ shape: brace, label: "h, m, s son parametros POR REFERENCIA (&):\nson alias directos de horas, min, seg de main().\nNo se declaran ni inicializan aqui." }
    CALC1B["h ← segundos / 3600"]
    MODB["segundos ← segundos % 3600"]
    CALC2B["m ← segundos / 60"]
    CALC3B["s ← segundos % 60"]
    FIN2(["Fin de convertir()"])
    NOTA2B@{ shape: brace, label: "Estos cambios SI se reflejan en main():\nh, m, s ocupan la misma memoria que\nhoras, min, seg. Por eso funciona correctamente." }

    INICIO2 --> CALC1B --> MODB --> CALC2B --> CALC3B --> FIN2
    INICIO2 -.- NOTA1B
    FIN2 -.- NOTA2B
```

Nota que, comparado con el diagrama defectuoso, este ya no tiene el nodo de inicialización (`h`, `m`, `s` no se declaran, ya existen como alias) y la nota final cambia de significado: en vez de "se pierden los valores", ahora "los cambios sí se reflejan en `main()`".

# Teoría: paso por valor vs. paso por referencia

## Paso por valor (`tipo nombre`)

Cuando un parámetro se pasa **por valor**, la función recibe una **copia** del dato original. Cualquier cambio que se haga dentro de la función afecta solo a esa copia; la variable original (la que existe fuera de la función) **nunca se entera** de esos cambios.

```cpp
void convertir(int segundos){       // "segundos" es una copia
    int horas=0, min=0, seg=0;      // variables LOCALES, nuevas, propias de esta función
    horas = segundos/3600;
    ...
}                                    // al terminar la función, horas/min/seg desaparecen
```

En la versión defectuosa, `horas`, `min` y `seg` ni siquiera son parámetros: son variables declaradas dentro de `convertir()`. Existen solo mientras la función se ejecuta y se destruyen al terminar. Por eso el programa siempre imprime `0h 0m 0s`: los valores calculados nunca llegan a `main()`.

## Paso por referencia (`tipo &nombre`)

Cuando un parámetro se pasa **por referencia** (con el símbolo `&`), la función no recibe una copia, sino un **alias** de la variable original. Es literalmente "otro nombre" para la misma casilla de memoria. Modificar el parámetro dentro de la función modifica directamente la variable original en `main()`.

```cpp
void convertir(int segundos, int &h, int &m, int &s){
    h = segundos/3600;   // esto modifica DIRECTAMENTE "horas" de main()
    ...
}
```

Aquí `h`, `m`, `s` son alias de `horas`, `min`, `seg` de `main()`. Por eso esta versión sí funciona: los cálculos hechos dentro de `convertir()` se reflejan afuera.

## ¿Cuándo usar cada uno?

| Situación | Usar |
|---|---|
| Solo necesito **leer** un valor dentro de la función, sin modificarlo afuera | Por valor |
| La función necesita **devolver más de un resultado** (parámetros de salida) | Por referencia |
| Quiero evitar copiar datos grandes (arreglos, structs, strings) por eficiencia | Por referencia (usualmente `const &` si no se debe modificar) |

**Idea clave:** `return` solo puede devolver **un** valor. Cuando una función necesita entregar varios resultados (como horas, minutos y segundos a la vez), la solución es usar **parámetros de salida por referencia**, tal como se hace en la versión corregida de `convertir()`.
