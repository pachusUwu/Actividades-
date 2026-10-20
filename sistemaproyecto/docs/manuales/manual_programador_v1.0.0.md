# Manual del Programador — SistemaProyecto

**Proyecto:** `sistemaproyecto` — Actividad 5 (LPR 5.º 3.ª)
**Versión:** 1.0.0
**Autor:** Ian Quiroga
**Fecha:** 2026

---

## 1. Descripción del sistema

Programa de consola en C++ que permite **registrar una entidad** (un sensor, un
módulo de hardware, un usuario o un componente del Proyecto Integrador Anual)
solicitando sus campos por teclado y **verificando los datos directamente en la
memoria RAM** mediante un `struct` y un puntero.

El sistema existe para demostrar el modelado de datos con estructuras y el acceso
a sus miembros mediante el operador flecha (`->`).

## 2. Arquitectura del sistema

```
┌─────────────────────────────────────────────────────┐
│  main()                                             │
│  ┌───────────────────────────────────────────────┐  │
│  │ EntidadProyecto miEntidad = {0, "Vacio", 0}   │  │
│  └───────────────────┬───────────────────────────┘  │
│                      │  &miEntidad  (dirección)     │
│                      ▼                              │
│  ┌───────────────────────────────────────────────┐  │
│  │ cargarDatos(EntidadProyecto* ptr)             │  │
│  │   cin >> ptr->id          (operador flecha)    │  │
│  │   cin.ignore()            (limpieza de búfer)  │  │
│  │   cin.getline(ptr->nombre, 50)                 │  │
│  │   cin >> ptr->metrica                         │  │
│  └───────────────────────────────────────────────┘  │
│                      │                              │
│  Se modifican los MISMOS casilleros de RAM           │
└─────────────────────────────────────────────────────┘
```

## 3. Estructura de datos

```cpp
struct EntidadProyecto
{
    int   id;          // 4 bytes
    char  nombre[50];  // 50 bytes
    float metrica;     // 4 bytes
};
```

- **Tamaño total:** 58 bytes alineados por el compilador en un bloque contiguo.
- **Alineación:** los tres campos residen en **casillas consecutivas** de la RAM,
  lo que garantiza un acceso eficiente a caché.

## 4. Funciones públicas

### 4.1 `void cargarDatos(EntidadProyecto* ptr)`

| Parámetro | Tipo | Descripción |
|---|---|---|
| `ptr` | `EntidadProyecto*` | Puntero a la estructura destino. |

**Contrato:** escribe `id`, `nombre` y `metrica` en la estructura apuntada.
**Precondición:** `ptr` debe ser una dirección válida (no `nullptr`).
**Postcondición:** la estructura contiene los datos ingresados por el usuario.

**Secuencia interna:**

1. `cin >> ptr->id;` — lee el entero.
2. `cin.ignore();` — **obligatorio**, descarta el `\n` pendiente.
3. `cin.getline(ptr->nombre, 50);` — lee la cadena, con tope de seguridad.
4. `cin >> ptr->metrica;` — lee el decimal.

## 5. Compilación

```powershell
g++ src/main.cpp -o src/sistemaproyecto.exe
```

Flags recomendados: `-Wall -Wextra -pedantic` para activarlos advertencias.

## 6. Errores conocidos y soluciones

| Síntoma | Causa | Solución |
|---|---|---|
| `nombre` aparece vacío | Falta `cin.ignore()` | Colocar `cin.ignore()` entre `cin >>` y `getline` |
| `id` queda con el valor anterior | El usuario ingressó texto | Validar la entrada con un `while` y `cin.clear()` |
| Caracteres raros en pantalla | `nombre` no es `std::string` | Usar `std::string` o `cin.ignore()` tras la lectura |
| Error de linker | Falta el prototipo | Declarar `cargarDatos` **antes** de `main()` |

## 7. Extensiones posibles

- Reemplazar `char nombre[50]` por `std::string` para eliminar el límite fijo.
- Agregar un menú que permita registrar **varias** entidades en un arreglo.
- Serializar las entidades a un archivo `.csv` con `ofstream` (Actividad 7).

## 8. Control de versiones

| Versión | Descripción |
|---|---|
| `v1.0.0` | Línea base: `struct EntidadProyecto` + `cargarDatos` por puntero. |