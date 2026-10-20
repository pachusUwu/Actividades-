# Manual del Usuario — JuegoDeNaves

**Proyecto:** `juegodenaves` — Actividad 8 (LPR 5.º 3.ª)
**Versión:** 1.0.0
**Autor:** Ian Quiroga
**Fecha:** 2026

---

## 1. ¿Qué es este juego?

Un **simulador de combate espacial en la consola de Windows**. Manejás una nave,
esquivás asteroides que caen desde arriba y disparás para destruirlos. Tenés
**3 vidas**. Cuando se acaban, la partida termina.

## 2. Requisitos

- 🪟 **Solo Windows 10 u 11** (usa librerías propias de Windows).
- Consola que admita caracteres ASCII.
- No requiere conexión a internet.

## 3. Cómo ejecutarlo

1. Abrí la carpeta `juegodenaves/` en Visual Studio Code.
2. Presioná `Ctrl + Ñ` para abrir la terminal.
3. Compilá y ejecutá:

```powershell
g++ src/main.cpp -o src/juegodenaves.exe
.\src\juegodenaves.exe
```

## 4. Paso obligatorio antes de jugar

Al arrancar, el juego te pide tu nombre:

```
Ingresa tu Nombre y Apellido (Se mostrara en la captura de pantalla):
```

**Escribí tu nombre y apellido reales** y presioná Enter. Aparece arriba a la
izquierda como `PILOTO: <tu nombre>` y es justamente eso lo que debe verse en la
captura de pantalla que se entrega.

## 5. Controles

| Tecla | Acción |
|---|---|
| `W` | ⬆️ Subir |
| `A` | ⬅️ Mover a la izquierda |
| `S` | ⬇️ Bajar |
| `D` | ➡️ Mover a la derecha |
| `ESPACIO` | 🔫 Disparar |

No hace falta mantener la tecla presionada: se controla por pulsaciones.

## 6. Qué hay en pantalla

```
PILOTO: Ian Quiroga                    [RAPID FIRE: OFF]
VIDAS: 3   PUNTOS: 0

                    O           O
                       O
                          |          O
              O
                    ^                   O
                   (O)
                  ^^^^
```

| Elemento | Significado |
|---|---|
| `^ (O) ^^^` | Tu nave |
| `O` | Asteroide |
| `\|` | Bala que disparaste |
| `R` | Power-up de Disparo Rápido |
| `PILOTO:` | Tu nombre (debe ser el real) |
| `VIDAS:` | Vidas restantes |
| `PUNTOS:` | Asteroides destruidos × 10 |
| `[RAPID FIRE]` | Estado del arma |

## 7. Las reglas

- Tenés **3 vidas**. Cada choque con un asteroide resta una.
- Cada asteroide destruido suma **10 puntos**.
- La partida termina cuando las vidas llegan a **0**.
- La nave no puede salir de los límites de la pantalla.

## 8. 🚀 Eligence bonus: Disparo Rápido (Rapid Fire)

| Qué | Cómo funciona |
|---|---|
| **Aparece** | Cada vez que destruís un asteroide hay un **35 %** de probabilidad de que suelte un power-up con la letra `R`. |
| **Se recoge** | Chocás con él llevando la nave encima. |
| **Efecto** | Se activan **8 segundos** de disparo rápido: cada pulsación dispara **3 balas** en lugar de 1. |
| **Se termina** | Cuando el contador llega a `0`, el arma vuelve a su cadencia normal automáticamente. |
| **Puntos** | Recogerlo suma **5 puntos** extra. |

Cuando está activo, arriba a la derecha se ve:

```
[RAPID FIRE ACTIVO: 7s]
```

El número va bajando segundo a segundo. Cuando llega a cero, vuelve a decir
`[RAPID FIRE: OFF]`.

## 9. Terminar la partida

Cuando te quedás sin vidas:

1. La pantalla se limpia.
2. Aparece: `G A M E   O V E R . . . Perdiste, <tu nombre>!`
3. Debajo se muestra la **puntuación final**.
4. El programa espera: presioná una tecla para salir.

## 10. Problemas frecuentes

**No compila / errores de `_kbhit` o `conio.h`.**
El juego **solo funciona en Windows**. Si te marca error, estás en Linux, macOS o
con un compilador que no incluye las librerías de Windows.

**No veo nada en la pantalla.**
Probá hacer clic dentro de la ventana de la consola para que le dé el foco.

**Se ve todo borroso o con caracteres raros.**
Aumentá el tamaño de la fuente de la consola (clic derecho en la barra de título →
Propiedades → Fuente → 16 o 20).

**¿Puedo jugar con el Bloq Mayús activado?**
Sí. El código convierte la tecla a minúscula con `tolower()` antes de compararla.

**La captura sale sin mi nombre.**
Escribilo cuando el programa te lo pida, **antes** de que empiece la partida.

## 11. Captura para la entrega

| Archivo | Qué tiene que verse |
|---|---|
| `combate_consola.png` | El juego en marcha con `PILOTO: <tu nombre y apellido>` arriba a la izquierda. Idealmente también con un power-up `R` en pantalla y `[RAPID FIRE ACTIVO]` a la derecha. |