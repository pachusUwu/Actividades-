# Actividad 7 — Mini Juego Piedra, Papel o Tijera con Persistencia

Juego contra la IA de consola donde **cada partida se guarda en disco**
(`struct` + `fstream`) en `src/historial_partidas.txt`.

## Estructura de carpetas

```
/piedrapapelotijera/
├── .gitattributes
├── .gitignore
├── LICENSE
├── README.md
├── docs/
│   ├── InformeEEST1_LPR2026_ACT07_G03_Informe_v1.0.0.pdf
│   ├── CHANGELOG.md
│   └── manuales/
│       ├── manual_programador_v1.0.0.pdf
│       ├── manual_programador_v1.0.0.md
│       ├── manual_usuario_v1.0.0.pdf
│       └── manual_usuario_v1.0.0.md
├── src/
│   ├── main.cpp
│   └── historial_partidas.txt
└── capturas/
    ├── jugada_consola.png
    └── archivo_disco.png
```

## Compilar y ejecutar

```powershell
g++ -std=c++11 src/main.cpp -o src/piedrapapelotijera.exe
.\src\piedrapapelotijera.exe
```

## Regla obligatoria

Modificar la salida de pantalla agregando tu **nombre y apellido reales**
(está como `Ian Quiroga` — cambialo vos).

## Conceptos clave

| Concepto | Uso en el código |
|---|---|
| `struct Partida` | Agrupa `idPartida`, `jugador`, `eleccionJugador`, `eleccionIA`, `resultado` |
| `ofstream archivo(..., ios::app)` | **Escribe** en disco **agregando** al final (no borra) |
| `ifstream archivo(...)` | **Lee** el historial completo desde el disco |
| `cin.ignore()` | Limpia el `Enter` del búfer antes de `getline()` |
| `srand(time(0))` | Siembra la semilla del `rand()` de la IA |

> ⚠️ **Importante:** el archivo se escribe y se lee en `src/historial_partidas.txt`.
> Ejecutá el programa **desde la raíz de la carpeta** (`piedrapapelotijera/`),
> porque la ruta es relativa a ese directorio.

## Demostración de persistencia (obligatoria en el informe)

1. Jugá una partida (Opción 1) y capturá la consola.
2. Cerrá la ventana de consola por completo.
3. Volvé a abrir y ejecutá el `.exe` de nuevo.
4. Elegí la **Opción 2** y capturá el historial persistido.
5. Guardá ambas capturas en `capturas/`.

## Fecha límite de entrega

**16 de octubre de 2026**.