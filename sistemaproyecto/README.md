# Actividad 5 — Modelado de Datos con Struct y Punteros

Modelar una entidad del mundo real (sensores, módulos de hardware, usuarios)
con `struct`, controlando sus miembros por referencia con punteros y el operador
flecha (`->`).

## Estructura de carpetas

```
/sistemaproyecto/
├── .gitignore
├── LICENSE
├── README.md
├── docs/
│   ├── InformeEEST1_LPR2026_ACT05_G03_v1.0.0.pdf
│   └── manuales/
│       ├── manual_programador_v1.0.0.pdf
│       └── manual_programador_v1.0.0.md
├── src/
│   └── main.cpp
└── capturas/
    └── ejecucion_struct.png
```

## Compilar y ejecutar

```powershell
g++ src/main.cpp -o src/sistemaproyecto.exe
.\src\sistemaproyecto.exe
```

## Regla obligatoria

Modificar la salida de pantalla agregando tu **nombre y apellido reales**
(está como `Ian Quiroga` — cambialo vos).

## Conceptos clave

```cpp
struct EntidadProyecto {
    int   id;
    char  nombre[50];
    float metrica;
};

void cargarDatos(EntidadProyecto* ptr);   // pasaje por referencia
cargarDatos(&miEntidad);                  // '&' pasa la dirección
cin >> ptr->id;                           // flecha: acceso vía puntero
```

- **Operador flecha (`->`)**: obligatorio porque la variable es de tipo puntero.
- **Pasaje por referencia**: evita duplicar la estructura entera en la RAM.
- **`cin.ignore()`**: limpia el `Enter` (`\n`) que queda en el búfer antes de
  `cin.getline()`, de lo contrario el nombre se lee vacío.

## Git

Cada ejercicio debe estar respaldado por un commit descriptivo, y el
repositorio debe mostrar historial ramificado (`main` y `development`).

## Fecha de entrega / prórroga

**25 de septiembre de 2026**.