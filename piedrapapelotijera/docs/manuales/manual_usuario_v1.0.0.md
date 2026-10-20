# Manual del Usuario — PiedraPapelTijera

**Proyecto:** `piedrapapelotijera` — Actividad 7 (LPR 5.º 3.ª)
**Versión:** 1.0.0
**Autor:** Ian Quiroga
**Fecha:** 2026

---

## 1. ¿Qué es este programa?

Un juego de **Piedra, Papel o Tijera** contra la computadora. Cada partida que
jugás **queda guardada en un archivo del disco**, así que podés ver tu historial
incluso después de cerrar y volver a abrir el programa.

## 2. Requisitos

- Windows 10 u 11.
- No requiere conexión a internet.

## 3. Cómo ejecutarlo

⚠️ **Importante:** el programa busca el archivo `src/historial_partidas.txt`
usando una ruta relativa. Por eso hay que ejecutarlo **desde la carpeta
`piedrapapelotijera/`**, no con doble clic sobre el `.exe`.

### Opción A — Con Visual Studio Code (recomendado)

1. Abrí la carpeta `piedrapapelotijera/` en VS Code.
2. Presioná `Ctrl + Ñ` para abrir la terminal.
3. Ejecutá:

```powershell
g++ -std=c++11 src/main.cpp -o src/piedrapapelotijera.exe
.\src\piedrapapelotijera.exe
```

### Opción B — Con PowerShell

Abrí PowerShell, movete a la carpeta del proyecto y repetí los mismos comandos.

## 4. Las 3 opciones del menú

Al iniciar, el programa muestra un menú con tres opciones:

```
--- MENU PRINCIPAL DE JUEGO Y PERSISTENCIA ---
1. Jugar Partida (Piedra, Papel o Tijera)
2. Ver Historial de Partidas Guardadas en Disco (.txt)
3. Salir del Sistema
Ingrese una opcion (1-3):
```

| Opción | Qué hace |
|---|---|
| **1** | Juega una partida contra la computadora y la guarda en el archivo. |
| **2** | Muestra todas las partidas guardadas desde ejecuciones anteriores. |
| **3** | Sale del programa. Tus datos quedan resguardados en el archivo. |

## 5. Cómo jugar una partida

1. Elegí la **opción 1**.
2. El programa te pide tu **nombre o apodo**. Escribilo y presioná Enter.
3. Elegí tu jugada:
   - `1` → **Piedra** 🪨
   - `2` → **Papel** 📄
   - `3` → **Tijera** ✂️
4. La computadora elige al azar y el programa anuncia el resultado.

**Reglas:** Piedra le gana a Tijera · Papel le gana a Piedra · Tijera le gana a
Papel. Si ambos eligen lo mismo, es Empate.

Ejemplo de salida:

```
--- NUEVA PARTIDA #1 ---
Ingrese su Nombre / Nickname: Ian
Elija su jugada:
1. Piedra
2. Papel
3. Tijera
Opcion (1-3): 1

[JUGADA] Ian eligio: Piedra
[JUGADA] La IA eligio: Tijera
=> RESULTADO: Victoria!
[DISCO] Partida resguardada con exito en 'historial_partidas.txt'.
```

## 6. Cómo ver el historial

1. Elegí la **opción 2**.
2. El programa lee el archivo del disco y muestra todas las partidas:

```
 HISTORIAL DE PARTIDAS RECUPERADO DESDE DISCO
=====================================================
Partida #1 | Jugador: Ian | Piedra vs Tijera | Resultado: Victoria
Partida #2 | Jugador: Ian | Papel vs Tijera | Resultado: Derrota
[SISTEMA] Total de registros leidos desde disco: 2
```

> La primera vez que jugues, el archivo **se crea solo**. Si consultás la opción 2
> antes de haber jugado ninguna partida, el programa te avisa que todavía no hay
> partidas guardadas.

## 7. ¿Dónde queda guardado el historial?

En el archivo:

```
piedrapapelotijera\src\historial_partidas.txt
```

Es un archivo de texto común. Podés abrirlo con el **Bloc de notas** para ver
todos los registros. Está en formato CSV:

```
id,jugador,eleccionJugador,eleccionIA,resultado
1,Ian,Piedra,Tijera,Victoria
```

Como está separado por comas, también podés abrirlo en **Excel** o
**Google Sheets** para ver tus estadísticas.

## 8. Preguntas frecuentes

**¿Se borra mi historial si cierro el programa?**
No. Justamente para eso el archivo existe: los datos quedan en el disco.

**Eligí la opción 2 y dice «Aun no existen partidas guardadas».**
Todavía no jugaste ninguna partida. Elegí la opción 1 primero.

**El nombre se lee en blanco.**
Debés presionar Enter después de elegir la opción 1 del menú.

**El archivo no aparece.**
Seguro ejecutaste el `.exe` con doble clic. Volvé a ejecutarlo desde la terminal
de VS Code parado en la carpeta `piedrapapelotijera/`.

**¿Puedo cambiar mi nombre a mitad de juego?**
Sí: cada partida pide el nombre de nuevo.

## 9. Capturas para la entrega

| Captura | Cómo se hace |
|---|---|
| `jugada_consola.png` | Menú principal + una partida jugada con su resultado. |
| `archivo_disco.png` | **Paso a paso:** (1) jugá una partida → (2) cerrá la consola → (3) volvé a abrirla → (4) elegí la opción 2 → capturá el historial. |