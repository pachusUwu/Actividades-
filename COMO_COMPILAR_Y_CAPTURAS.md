# Cómo compilar y cómo sacar las capturas

Guía práctica para **Windows 10/11** con **VS Code + MSYS2 (MinGW/GCC)**.

Cada actividad del repositorio pide evidencia fotográfica (`capturas/*.png`).
Esta guía te dice, paso a paso, cómo compilar cada programa, cómo ejecutarlo y
qué ventana exacta tenés que capturar para que el profe la apruebe.

---

## 1. Instalación del compilador (una sola vez)

Si `g++` no está instalado, instalá **MSYS2**:

1. Descargalo de <https://www.msys2.org/> y ejecutá el instalador.
2. Abrí **MSYS2 UCRT64** (menú Start → *MSYS2 UCRT64*).
3. En esa terminal ejecutá:

```bash
pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
```

4. En la terminal de **VS Code** (PowerShell, `Ctrl + Ñ`) verificá:

```powershell
g++ --version
```

Debe mostrar la versión del GCC (por ejemplo `g++ (GCC) 13.2.0`). Guardá esa
ventana: es una de las capturas de la **Actividad 2**.

### Si las PCs del laboratorio te bloquean la compilación

Usá **OnlineGDB** (<https://www.onlinegdb.com/online_c_compiler>):

1. Language → `C++`, Standard → `C++11` (o `C++17`).
2. Pegá el código de `src/main.cpp`.
3. Click en **Run** y hacé captura de la salida.

---

## 2. Configuración de VS Code (una sola vez)

Instalá estas extensiones con `Ctrl + Shift + X`:

1. **C/C++** (Microsoft) — sintaxis e inteligencia de código.
2. **C/C++ Extension Pack** — incluye el depurador (Debugger).
3. **Code Runner** (opcional) — ejecutar con un clic.

Además, abrí la terminal integrada con **`Ctrl + Ñ`** y verificá que
`g++ --version` responda ahí (eso confirma que el compilador está en el `Path`).

---

## 3. Regla de oro: la terminal debe estar en la raíz de la actividad

Todos los comandos de abajo asumen que estás parado **dentro de la carpeta de la
actividad** (por ejemplo `...\Actividades\calculoarea\`), no en la raíz del
repo.

```powershell
cd .\calculoarea
```

Si no lo hacés, el `.exe` se genera en el lugar equivocado y las rutas relativas
del Actividad 7 (que lee `src/historial_partidas.txt`) no van a funcionar.

---

## 4. Comandos por actividad

| # | Actividad | Carpeta | Compilar | Ejecutar |
|---|---|---|---|---|
| 1 | Calculadora de edad | `calculadoraedad/` | `g++ proyecto_cpp/calculadoraEdad.cpp -o proyecto_cpp/calculadoraEdad.exe` | `.\proyecto_cpp\calculadoraEdad.exe` |
| 2 | Hola Mundo | `holamundo/` | `g++ src/main.cpp -o src/holamundo.exe` | `.\src\holamundo.exe` |
| 3 | Área de círculo | `calculoarea/` | `g++ src/main.cpp -o src/area.exe` | `.\src\area.exe` |
| 4 | Cadenas y punteros | `cadenaspunteros/` | `g++ src/main.cpp -o src/cadenaspunteros.exe` | `.\src\cadenaspunteros.exe` |
| 5 | Struct y punteros | `sistemaproyecto/` | `g++ src/main.cpp -o src/sistemaproyecto.exe` | `.\src\sistemaproyecto.exe` |
| 6 | Taller de repaso | `repasogeneral/` | `g++ src/main.cpp -o src/repasogeneral.exe` | `.\src\repasogeneral.exe` |
| 7 | Piedra, papel o tijera | `piedrapapelotijera/` | `g++ -std=c++11 src/main.cpp -o src/piedrapapelotijera.exe` | `.\src\piedrapapelotijera.exe` |
| 8 | Juego de naves | `juegodenaves/` | `g++ src/main.cpp -o src/juegodenaves.exe` | `.\src\juegodenaves.exe` |

**Python (Actividad 1)** no necesita compilación:

```powershell
python .\proyecto_python\calculadoraEdad.py
```

### Ejemplo completo (Actividad 3)

```powershell
cd .\calculoarea
g++ src/main.cpp -o src/area.exe
.\src\area.exe
```

Si todo está bien, vas a ver:

```
=====================================================
 CALCULADORA DE AREA MODULAR - ESTUDIANTE: Ian Quiroga
=====================================================
=> Ingrese el radio del circulo/diana (en cm): 8

[SISTEMA] Area del circulo = 201.062 cm2

[SISTEMA] Dibujando escala de la Diana en la RAM...
    .-----.
   /  .-.  \
  |  ( O )  |   -> [DIANA ESTANDAR DE TIRO]
   \  '-'  /
    '-----'
=====================================================
```

---

## 5. Capturas obligatorias, actividad por actividad

> Para capturar la ventana: `Win + Shift + S` (Recortes) o `Print Screen`.
> Guardá el archivo con el **nombre exacto** en la carpeta `capturas/` de la
> actividad correspondiente.

### Actividad 2 → `holamundo/capturas/`

| Archivo | Qué tiene que verse |
|---|---|
| `gpp_version.png` | La terminal con `g++ --version` y la versión del GCC |
| `extensiones_vscode.png` | El panel de extensiones de VS Code con C/C++ y Code Runner instalados |
| `ejecucion_hola_mundo.png` | La terminal con el comando `g++`, el comando de ejecución y tu nombre en la salida |

### Actividad 3 → `calculoarea/capturas/`

| Archivo | Qué tiene que verse |
|---|---|
| `compilacion_area.png` | Terminal con la compilación, la ejecución y tu nombre y apellido |
| `diagrama_flujo.png` | Tu diagrama de flujo o pseudocódigo (a mano o en un diagrador) |

### Actividad 4 → `cadenaspunteros/capturas/`

| Archivo | Qué tiene que verse |
|---|---|
| `ejecucion_punteros.png` | La salida con `Direccion fisica en RAM Hexadecimal: 0x...` y tu nombre |
| `esquema_ram.png` | **Diagrama de memoria RAM hecho a mano** (con la dirección y el valor de `edad` y `p`) |

### Actividad 5 → `sistemaproyecto/capturas/`

| Archivo | Qué tiene que verse |
|---|---|
| `ejecucion_struct.png` | Los datos cargados + `Direccion RAM Hexadecimal: 0x...` y tu nombre |

### Actividad 6 → `repasogeneral/capturas/`

| Archivo | Qué tiene que verse |
|---|---|
| `ejecucion_repasogeneral.png` | La salida completa de los 3 retos (recursiva, búsqueda, intercambio) |
| `traza_memoria.png` | Diagrama de bloques de la RAM hecho a mano |
| *(extra)* `git_remote.png` | La salida de `git remote -v` con GitHub y GitLab |

### Actividad 7 → `piedrapapelotijera/capturas/`

| Archivo | Qué tiene que verse |
|---|---|
| `jugada_consola.png` | El menú principal + una partida jugada con el resultado |
| `archivo_disco.png` | **Demostración de persistencia**: (1) jugá, (2) cerrá la consola, (3) volvé a abrirla, (4) elegí la Opción 2 → historial leído desde el `.txt` |

> Para la segunda captura, también podés abrir `src/historial_partidas.txt`
> en el Bloc de notas y capturarlo con el contenido acumulado.

### Actividad 8 → `juegodenaves/capturas/`

| Archivo | Qué tiene que verse |
|---|---|
| `combate_consola.png` | El juego corriendo con `PILOTO: <tu nombre y apellido>` en el HUD, y de ser posible el power-up `R` con `[RAPID FIRE ACTIVO]` |

> ⚠️ El juego pide el nombre por consola al arrancar. **Escribí tu nombre y
> apellido reales**, porque eso es lo que se tiene que ver en la captura.
> Solo funciona en **Windows** (usa `windows.h` y `conio.h`).

---

## 6. Antes de entregar: checklist

- [ ] Reemplacé `Ian Quiroga` por mi nombre y apellido real en **todos** los `.cpp` y `.py`.
- [ ] Compilé y ejecuté cada una de las 8 actividades sin errores.
- [ ] Las capturas están guardadas con el **nombre exacto** pedido, dentro de `capturas/`.
- [ ] El informe **APA v7** está en PDF dentro de `docs/`.
- [ ] Los manuales están en `docs/manuales/` (Actividades 5 a 8).
- [ ] El `CHANGELOG.md` está actualizado (Actividades 6, 7 y 8).
- [ ] Subí todo con `git push` a **GitHub** y **GitLab** (Dual-Remote, Act. 6 en adelante).
- [ ] Las URLs públicas de los repositorios están anotadas en el informe APA.
- [ ] La carpeta de campo del P.I.A. tiene los campos completos (no vacíos).

---

## 7. Problemas frecuentes

| Síntoma | Causa probable | Solución |
|---|---|---|
| `g++ no se reconoce como comando` | MinGW no está en el `Path` | Reinstalá MSYS2 y agregá `C:\msys64\ucrt64\bin` al `Path` |
| `no such file or directory` | La terminal no está en la raíz de la actividad | `cd` a la carpeta correcta |
| El `.exe` no aparece en `src/` | Compilaste desde otra carpeta | Volvé a la raíz y repetí el comando |
| `historial_partidas.txt` no se crea | Corriste el `.exe` desde otro directorio | Ejecutá desde `piedrapapelotijera/` |
| El nombre se lee vacío en el Act. 7 | Falta `cin.ignore()` antes de `getline()` | Ya está en el código base; no lo borres |
| El juego de naves no compila | No estás en Windows | Actividad 8 requiere `windows.h` |