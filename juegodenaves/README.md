# Actividad 8 — POO en C++: Juego de Naves en Consola

Simulador de combate espacial definiendo la clase `Nave` (atributos `private:`
y métodos `public:`), con el **Desafío Obligatorio** ya implementado.

## Estructura de carpetas

```
/juegodenaves/
├── .gitignore
├── LICENSE
├── README.md
├── docs/
│   ├── InformeEEST1_LPR2026_ACT08_G03_v1.0.0.pdf
│   ├── CHANGELOG.md
│   └── manuales/
│       ├── manual_programador_v1.0.0.pdf
│       └── manual_usuario_v1.0.0.pdf
├── src/
│   └── main.cpp
└── capturas/
    └── combate_consola.png
```

## Compilar y ejecutar

> 🪟 Solo funciona en **Windows** (usa `windows.h` y `conio.h`).

```powershell
g++ src/main.cpp -o src/juegodenaves.exe
.\src\juegodenaves.exe
```

## Controles

| Tecla | Acción |
|---|---|
| `W` | Subir |
| `A` | Izquierda |
| `S` | Bajar |
| `D` | Derecha |
| `ESPACIO` | Disparar |

## Regla obligatoria

Al iniciar, el juego **te pide tu nombre y apellido** y lo muestra en el HUD
(`PILOTO: ...`). Ese texto es el que tiene que aparecer en la captura de
pantalla.

## 🚀 Desafío obligatorio implementado

**Sistema de power-ups con Disparo Rápido (Rapid Fire) temporal**

1. Cada asteroide destruido tiene un **35 %** de probabilidad de soltar un
   power-up `R` en el lugar del impacto.
2. Si la nave choca con él, se activan **8 segundos** de disparo rápido
   (3 balas por pulsación en lugar de 1).
2. Al expirar el temporizador, el arma vuelve automáticamente a su cadencia
   normal.
4. HUD en vivo con el estado del power-up y los segundos restantes, más un
   marcador de puntos.

**Dónde se insertó en el código:**

| Zona de `main.cpp` | Qué se agregó |
|---|---|
| Clase `DisparoRapido` | Nueva clase con `segundosRestantes` **privado** |
| `int puntos = 0;` | Marcador de puntos |
| `vector<DisparoRapido*> powerUps;` | Colección de power-ups en pantalla |
| Rama `if (tecla == ' ')` | Disparo triple si `arma.estaActivo()` |
| Colisión `Bala -> Asteroide` | Suma puntos y genera el power-up (35 %) |
| Colisión `Nave -> PowerUp` | Activa el efecto y borra el icono |
| Final de `while` | `delete` de todos los objetos para no filtrar memoria |

## Captura obligatoria

- `combate_consola.png` — consola con tu nombre y apellido visible en el HUD,
  idealmente con el power-up `R` en pantalla y `[RAPID FIRE ACTIVO]` en el HUD.

## Fecha límite de entrega

**21 de octubre de 2026**.