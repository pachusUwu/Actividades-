# CHANGELOG — `juegodenaves`

Todas las novedades relevantes de la **Actividad 8: Programación Orientada a
Objetos en C++ — juego de naves en consola**.

El formato sigue las convenciones de [Keep a Changelog](https://keepachangelog.com/es-ES/1.1.0/)
y el versionado semántico [SemVer](https://semver.org/lang/es/).

---

## [1.1.0] — 2026 — Desafío Obligatorio implementado

### Agregado
- **Clase `DisparoRapido`** — nueva clase con estado completamente encapsulado:
  - Atributos privados `x`, `y`, `activo` y `segundosRestantes`.
  - Constante `static const int DURACION = 8` (8 segundos de efecto).
  - Métodos públicos `activar()`, `tick()`, `estaActivo()`, `estaEnPantalla()`,
    `getSegundos()`, `pintar()`, `borrar()` y `mover()`.
- **Generación de power-ups** con un **35 % de probabilidad** al destruir un
  asteroide, en la posición exacta del impacto.
- **Detección de colisión `Nave -> PowerUp`** con bonus de **5 puntos**.
- **Disparo triples temporal**: cuando el power-up está activo, cada pulsación de
  la barra espaciadora genera **3 balas** en lugar de 1.
- **HUD ampliado** con el estado del arma (`[RAPID FIRE ACTIVO: Xs]` /
  `[RAPID FIRE: OFF]`) y un marcador de **puntos**.
- **Limpieza de memoria** explícita (`delete`) de asteroides, balas y power-ups al
  finalizar la partida.

### Corrección
- Recorrido de los vectores en **orden inverso** (`size() - 1` → `0`) para evitar
  que `erase()` provoque que se salte elementos en la misma vuelta.
- Se corrigió `borrar()` de la clase `Nave`, que no limpiaba la celda central
  (`gotoxy(x, y + 1)`) y dejaba un carácter residual en pantalla.
- Se restauró `borrar()` de la clase `Bala`, que no limpiaba la posición de origen.

### Seguridad
- El atributo `segundosRestantes` es **privado** y solo puede modificarse a través
  de `activar()` y `tick()`, garantizando que nunca sea negativo ni supere `DURACION`.

---

## [1.0.0] — 2026 — Motor base

### Agregado
- Clase `Nave` con atributos privados (`x`, `y`, `vidas`) y constructor.
- Clase `Asteroide` con reposicionamiento aleatorio al salir de pantalla.
- Clase `Bala` con método `fueraDeRango()`.
- Utilidades de consola `gotoxy()` y `ocultarCursor()` sobre `windows.h`.
- Detección de colisiones `Asteroide -> Nave` y `Bala -> Asteroide`.
- Sistema de vidas y condición de `gameOver`.
- Pedido del nombre del piloto como **medida anti-copia**: debe ser visible en la
  captura de pantalla.

[1.1.0]: #110--2026
[1.0.0]: #100--2026