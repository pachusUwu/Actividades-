# Manual del Usuario — RepasoGeneral

**Proyecto:** `repasogeneral` — Actividad 6 (LPR 5.º 3.ª)
**Versión:** 1.0.0
**Autor:** Ian Quiroga
**Fecha:** 2026

---

## 1. ¿Qué es este programa?

`repasogeneral.exe` es una **consola educativa** que muestra en pantalla tres
demostraciones de programación de bajo nivel en C++:

1. **Suma recursiva** — cómo una función puede llamarse a sí misma.
2. **Búsqueda secuencial** — cómo se recorre un arreglo en memoria.
3. **Intercambio con punteros** — cómo se modifican variables reales.

No pide ningún dato: se ejecuta y muestra toda la información.

## 2. Requisitos

- Windows 10 u 11.
- No requiere conexión a internet ni instalación adicional.

## 3. Cómo ejecutarlo

### Opción A — Con Visual Studio Code

1. Abrí la carpeta `repasogeneral/` en VS Code.
2. Presioná `Ctrl + Ñ` para abrir la terminal.
3. Ejecutá:

```powershell
g++ src/main.cpp -o src/repasogeneral.exe
.\src\repasogeneral.exe
```

### Opción B — Doble clic

Hacé doble clic sobre `src/repasogeneral.exe`. Para cerrar la ventana, presioná
una tecla cuando aparezca `Presione cualquier tecla para continuar`.

## 4. Qué vas a ver en pantalla

```
=====================================================
 TALLER INTEGRADOR REPASO - ESTUDIANTE: Ian Quiroga
=====================================================

=== RETO 1: SUMA RECURSIVA ===
Suma acumulada de 1 hasta 5: 15

=== RETO 2: BUSQUEDA EN MEMORIA CONTIGUA ===
[SISTEMA] Valor 18 hallado en el indice [5]
 Direccion RAM Hexadecimal: 0x61ff18

=== RETO 3: INTERCAMBIO DE CELDAS ===
Valores previos -> X: 100 | Y: 500
Valores actuales -> X: 500 | Y: 100
=====================================================
```

## 4.1 Significado de cada sección

| Sección | Qué demuestra |
|---|---|
| **Reto 1** | Una función recursiva acumula `5 + 4 + 3 + 2 + 1 + 0 = 15`. |
| **Reto 2** | El valor `18` está en la posición `[5]` del arreglo. La dirección `0x...` es la ubicación física en la RAM. |
| **Reto 3** | Antes de intercambiar, `X = 100` e `Y = 500`. Después, `X = 500` e `Y = 100`. |

> La dirección hexadecimal (`0x61ff18`) **cambia en cada ejecución**: depende de
> dónde el sistema operativo asigne la memoria. Es normal que no coincida con la
> de tu compañero.

## 5. Preguntas frecuentes

**¿El programa pide algo?**
No. Se ejecuta y muestra todo automáticamente. Para cerrarlo, presioná una tecla.

**¿Por qué el número `0x61ff18` es distinto al de otra persona?**
Porque es la dirección física real que el sistema operativo asignó a tu arreglo
en esa ejecución. Cambia cada vez que se abre el programa.

**¿Qué pasa si no tengo Visual Studio Code?**
Podés usar la terminal de Windows (PowerShell) con el mismo comando `g++`.

**¿Necesito conexión a internet?**
No, salvo que quieras consultar los enlaces de referencia del informe.

## 6. Capturas para la entrega

1. `ejecucion_repasogeneral.png` — la salida completa de los 3 retos.
2. `traza_memoria.png` — el diagrama de la RAM hecho a mano.
3. Captura de `git remote -v` mostrando GitHub y GitLab.