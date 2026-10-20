# CHANGELOG — `repasogeneral`

Todas las novedades relevantes de la **Actividad 6: Taller Práctico de Repaso y
Consolidación en C++**.

El formato sigue las convenciones de [Keep a Changelog](https://keepachangelog.com/es-ES/1.1.0/)
y el versionado semántico [SemVer](https://semver.org/lang/es/).

---

## [1.0.0] — 2026 — Baseline Aprobado

### Agregado
- Función recursiva `sumaRecursiva(int n)` con **caso base** para prevenir el
  desbordamiento de la pila (Stack Overflow).
- Arreglo contiguo de 10 enteros (`vectorDatos`) y **búsqueda secuencial** con
  interrupción optimizada mediante `break`.
- Función `intercambiarValores(int* ptrA, int* ptrB)` con **pasaje por dirección** y
  variable temporal.
- Menú de salida con nombre y apellido del estudiante.
- Impresión de la **dirección RAM hexadecimal** de los elementos del arreglo.

### Seguridad
- Filtrado de consistencia sobre el valor buscado: si no existe, se informa en lugar
  de devolver un índice inválido (`hallado = false`).

### Documentación
- Manual del Programador (`manual_programador_v1.0.0`).
- Manual del Usuario (`manual_usuario_v1.0.0`).
- Informe técnico en normas APA v7 (`InformeEEST1_LPR2026_ACT06_G03_v1.0.0`).

---

## Configuración de Git — Dual-Remote

- Se configuraron **dos destinos de escritura**: GitHub (principal) y GitLab
  (emergencia), de modo que cada `git push` sube a ambos servidores.

```powershell
git remote set-url origin https://github.com/pachusUwu/repasogeneral.git
git remote set-url --add --push origin https://github.com/pachusUwu/repasogeneral.git
git remote set-url --add --push origin https://gitlab.com/TU-USUARIO/repasogeneral.git
```

- Verificación con `git remote -v`: deben aparecer 3 líneas (1 fetch + 2 push).
- Rama principal renombrada a `main`.

[1.0.0]: #100--2026