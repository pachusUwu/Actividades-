# Actividad 1 — Calculadora de Edad (Python & C++)

Repaso integral de lógica de programación: bisiestos, cantidad de días por mes y
cálculo de la edad **exacta** (no solo la diferencia de años).

## Estructura de carpetas

```
/calculadoraedad/
├── .gitignore
├── README.md
├── LICENSE
├── docs/
│   └── InformeProyectoCalculadoraEdad.pdf
├── proyecto_cpp/
│   └── calculadoraEdad.cpp
└── proyecto_python/
    └── calculadoraEdad.py
```

## Qué hay que completar

| Archivo | Bloque a completar |
|---|---|
| `proyecto_cpp/calculadoraEdad.cpp` | El `if` que resta 1 a la edad si todavía no se cumplió años |
| `proyecto_python/calculadoraEdad.py` | El `if` que resta 1 a la edad si todavía no se cumplió años |

> La lógica de la resta ya está implementada y comentada. Revisala y ajustala a
> tu criterio, pero mantené el filtro de consistencia de calendario
> (`esFechaValida` / `es_fecha_valida`) intacto.

## Compilar y ejecutar

```powershell
# C++
g++ proyecto_cpp/calculadoraEdad.cpp -o proyecto_cpp/calculadoraEdad.exe
.\proyecto_cpp\calculadoraEdad.exe

# Python
python proyecto_python/calculadoraEdad.py
```

## Regla obligatoria

En ambos archivos hay que reemplazar el nombre de ejemplo por tu **nombre y
apellido reales** (queda marcado como `Ian Quiroga` — cambialo vos).

## Fecha de entrega

Prorrogada hasta el **31 de agosto de 2026**.