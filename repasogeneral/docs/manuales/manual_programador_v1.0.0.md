# Manual del Programador — RepasoGeneral (Suite de Taller)

**Proyecto:** `repasogeneral` — Actividad 6 (LPR 5.º 3.ª)
**Versión:** 1.0.0
**Autor:** Ian Quiroga
**Fecha:** 2026

---

## 1. Descripción del sistema

Suite unificada en consola que integra los tres pilares de programación de bajo
nivel del primer cuatrimestre:

| Reto | Módulo | Concepto |
|---|---|---|
| 1 | `sumaRecursiva(int n)` | Recursividad y caso base |
| 2 | Búsqueda secuencial | Complejidad `O(n)` y `break` |
| 3 | `intercambiarValores(int*, int*)` | Pasaje por dirección y desreferenciación |

## 2. Arquitectura del sistema

```
main()
 ├── Cabecera + nombre del estudiante
 ├── RETO 1 ─► sumaRecursiva(5)
 │              └── Stack: [5]→[4]→[3]→[2]→[1]→[0] caso base
 ├── RETO 2 ─► for (i=0; i<TAM; i++) sobre vectorDatos[10]
 │              └── break en la coincidencia
 └── RETO 3 ─► intercambiarValores(&x, &y)
                └── temporal = *ptrA; *ptrA = *ptrB; *ptrB = temporal
```

## 3. Especificación de las funciones

### 3.1 `int sumaRecursiva(int n)`

- **Precondición:** `n >= 0`.
- **Postcondición:** devuelve la suma de los enteros de `1` a `n`.
- **Caso base:** `if (n <= 0) return 0;` — **obligatorio**. Sin él se produce
  *Stack Overflow*.
- **Complejidad:** tiempo `O(n)`, espacio `O(n)` por la pila de llamadas.

```cpp
int sumaRecursiva(int n)
{
    if (n <= 0) return 0;
    return n + sumaRecursiva(n - 1);
}
```

### 3.2 `void intercambiarValores(int* ptrA, int* ptrB)`

- **Precondición:** `ptrA` y `ptrB` apuntan a `int` válidos.
- **Postcondición:** el valor de `*ptrA` y `*ptrB` quedan intercambiados.
- **Memoria:** usa una variable local (`temporal`) en el Stack.

## 4. Datos del reto 2

```cpp
const int TAM = 10;
int vectorDatos[TAM] = {12, 45, 78, 90, 122, 5, 18, 33, 67, 99};
int numeroBuscar = 18;   // se encuentra en el índice 5
```

La búsqueda puede probarse cambiando `numeroBuscar` por `77` para ejercitar la
ruta del `if (!hallado)`.

## 5. Compilación y ejecución

```powershell
g++ src/main.cpp -o src/repasogeneral.exe
.\src\repasogeneral.exe
```

## 6. Integración con Git — Dual-Remote

```powershell
git remote set-url origin https://github.com/pachusUwu/repasogeneral.git
git remote set-url --add --push origin https://github.com/pachusUwu/repasogeneral.git
git remote set-url --add --push origin https://gitlab.com/TU-USUARIO/repasogeneral.git
git remote -v     # debe mostrar 3 líneas: 1 fetch + 2 push
```

## 7. Errores conocidos y soluciones

| Síntoma | Causa | Solución |
|---|---|---|
| *Segmentation fault* | Falta el caso base en la recursión | Agregar `if (n <= 0) return 0;` |
| No encuentra un valor que sí está | Falta el `break` y se imprime el último | Agregar `break` dentro del `if` |
| Los valores no se intercambian | Se pasaron valores, no direcciones | Invocar con `&x`, `&y` |
| `git push` sube a un solo servidor | Falta `--add --push` | Repetir el comando 3 con `--add --push` |

## 8. Extensiones posibles

- Reemplazar la búsqueda secuencial por una **binaria** sobre el arreglo ordenado
  (`O(log n)`).
- Agregar lectura del valor a buscar por teclado.
- Recursión de cola con `tail call optimization` para reducir el Stack.

## 9. Control de versiones

| Versión | Estado | Descripción |
|---|---|---|
| `v1.0.0` | **Baseline Aprobado** | Suite unificada de los 3 retos. |