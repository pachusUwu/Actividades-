# CHANGELOG — `piedrapapelotijera`

Todas las novedades relevantes de la **Actividad 7: Mini juego «Piedra, papel o
tijera» con persistencia de datos**.

El formato sigue las convenciones de [Keep a Changelog](https://keepachangelog.com/es-ES/1.1.0/)
y el versionado semántico [SemVer](https://semver.org/lang/es/).

---

## [1.1.0] — 2026 — Baseline Aprobado

### Agregado
- **Archivo de historial versionado** en el repositorio:
  `src/historial_partidas.txt` con 4 partidas de ejemplo en formato CSV.
- Documentación de la demostración de persistencia obligatoria en `README.md`.

---

## [1.0.0] — 2026

### Agregado
- Modelo de datos `struct Partida` con cinco miembros: `idPartida`, `jugador`,
  `eleccionJugador`, `eleccionIA` y `resultado`.
- Menú principal en bucle `do...while` con tres opciones (jugar, ver historial,
  salir).
- Función `jugarPartida(int& contadorID)` con paso del contador **por referencia**.
- Generador de jugadas de la IA con `srand(time(0))` y `rand() % 3 + 1`.
- Reglas completas de Victoria / Empate / Derrota.
- Función `guardarEnDisco(const Partida& p)` con `ofstream` en modo **`ios::app`**
  para **no sobrescribir** las partidas previas.
- Función `leerHistorialDisco()` con `ifstream` y lectura delimitada por comas
  mediante `getline(campo, ',')`.
- Archivo `.gitattributes` para normalizar finales de línea entre Windows y Linux.

### Corrección
- `cin.ignore()` antes de `getline(cin, p.jugador)` para evitar la lectura del
  carácter `Enter` pendiente en el búfer de entrada.

### Seguridad
- Verificación `archivo.is_open()` en ambas funciones de archivo, con mensaje de
  error por `cerr` y retorno temprano ante el fallo.

---

[1.1.0]: #110--2026
[1.0.0]: #100--2026