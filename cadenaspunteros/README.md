# Actividad 4 — Manipulación de Cadenas y Punteros en C/C++

Control de acceso por edad operando **directamente sobre la RAM** mediante
punteros (`&` dirección, `*` desreferenciación) y direcciones hexadecimales.

## Estructura de carpetas

```
/cadenaspunteros/
├── .gitignore
├── LICENSE
├── README.md
├── docs/
│   └── InformeProyectoCADENASPUNTEROS.pdf
├── src/
│   └── main.cpp
└── capturas/
    ├── ejecucion_punteros.png
    └── esquema_ram.png
```

## Compilar y ejecutar

```powershell
g++ src/main.cpp -o src/cadenaspunteros.exe
.\src\cadenaspunteros.exe
```

## Regla obligatoria

Modificar la salida agregando tu **nombre y apellido reales** (está como
`Ian Quiroga` — cambialo vos).

## Conceptos clave

| Concepto | Significado |
|---|---|
| `int edad = 0;` | Variable alojada en un casillero de la RAM |
| `int* p = &edad;` | `p` guarda la **dirección física** de `edad` |
| `cin >> *p;` | Escribe **directamente** en el casillero de `edad` |
| `cout << p;` | Imprime la dirección en hexadecimal (ej: `0x61fe1c`) |
| `cout << *p;` | Imprime el **valor** almacenado |

> ⚠️ Escribir `cin >> p;` (sin `*`) intentaría sobrescribir la dirección de
> memoria del puntero. Es un error crítico de compilación.

## Capturas obligatorias

- `ejecucion_punteros.png` — terminal mostrando las direcciones hexadecimales.
- `esquema_ram.png` — **diagrama de memoria hecho a mano** en la carpeta de campo.

## Fecha de entrega

Prorrogada hasta el **17 de septiembre de 2026**.