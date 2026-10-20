# Actividad 3 — Enfoque Modular y Diseño Top-Down

Cálculo del área de un círculo mediante **funciones modulares** (prototipo +
definición) y bonus de renderizado de una diana en ASCII.

## Estructura de carpetas

```
/calculoarea/
├── .gitignore
├── LICENSE
├── README.md
├── docs/
│   └── InformeProyectoCALCULOAREA.pdf
├── src/
│   └── main.cpp
└── capturas/
    ├── compilacion_area.png
    └── diagrama_flujo.png
```

## Compilar y ejecutar

```powershell
g++ src/main.cpp -o src/area.exe
.\src\area.exe
```

## Regla obligatoria

Modificar la salida de pantalla agregando tu **nombre y apellido reales**
(está como `Ian Quiroga` — cambialo vos).

## Conceptos de la actividad

- **Diseño Top-Down**: dividir el problema en módulos más pequeños.
- **Prototipo de función**: `double calcularAreaCirculo(double radio);` le avisa
  al compilador que la función existe antes de llegar al `main()`.
- **Return**: el valor que la función le devuelve al programa principal.
- **`const`**: `const double PI = 3.1415926535;` bloquea el valor en RAM.

## Capturas obligatorias

- `compilacion_area.png` — terminal compilando y ejecutando el programa.
- `diagrama_flujo.png` — diagrama de flujo o pseudocódigo del programa.

## Fecha de entrega

Prorrogada hasta el **17 de septiembre de 2026**.