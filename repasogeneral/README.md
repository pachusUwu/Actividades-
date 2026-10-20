# Actividad 6 — Taller Práctico de Repaso y Consolidación en C++

Suite integradora de los tres pilares de bajo nivel de la primera mitad del
ciclo: **recursividad**, **búsqueda secuencial** e **intercambio con punteros**.
Incluye la configuración **Dual-Remote (GitHub + GitLab)**.

## Estructura de carpetas

```
/repasogeneral/
├── .gitignore
├── LICENSE
├── README.md
├── docs/
│   ├── InformeEEST1_LPR2026_ACT06_G03_v1.0.0.pdf
│   └── manuales/
│       ├── manual_programador_v1.0.0.pdf
│       ├── manual_usuario_v1.0.0.pdf
│       └── CHANGELOG.md
├── src/
│   └── main.cpp
└── capturas/
    ├── ejecucion_repasogeneral.png
    └── traza_memoria.png
```

## Compilar y ejecutar

```powershell
g++ src/main.cpp -o src/repasogeneral.exe
.\src\repasogeneral.exe
```

## Regla obligatoria

Modificar la salida de pantalla agregando tu **nombre y apellido reales**
(está como `Ian Quiroga` — cambialo vos).

## Los 3 retos

| # | Reto | Concepto |
|---|---|---|
| 1 | `sumaRecursiva(n)` | Recursividad y **caso base** (evita Stack Overflow) |
| 2 | Búsqueda en arreglo | Complejidad **O(n)** + `break` como interrupción optimizada |
| 3 | `intercambiarValores(&x, &y)` | Pasaje por dirección y desreferenciación |

## Configuración Dual-Remote (GitHub + GitLab)

```powershell
# 1. GitHub como destino principal
git remote set-url origin https://github.com/pachusUwu/repasogeneral.git

# 2. GitHub como PRIMER push
git remote set-url --add --push origin https://github.com/pachusUwu/repasogeneral.git

# 3. GitLab como SEGUNDO push (emergencia)
git remote set-url --add --push origin https://gitlab.com/TU-USUARIO/repasogeneral.git

# Verificar
git remote -v

# Subir a ambos
git branch -M main
git add .
git commit -m "feat: configuro la proteccion Dual-Remote y guardo mis cambios"
git push -u origin main
```

> ⚠️ En GitLab, el proyecto debe crearse **vacío** (sin marcar *"Initialize
> repository with a README"*). Autenticación: *Browser / OAuth* (recomendado) o
> un *Personal Access Token* (`glpat-...`) como contraseña.

## Capturas obligatorias

- `ejecucion_repasogeneral.png` — terminal ejecutando los 3 retos.
- `traza_memoria.png` — diagrama de bloques de la RAM hecho a mano.
- Captura de `git remote -v` mostrando los dos destinos de push.

## Fecha de entrega / prórroga

**1 de octubre de 2026**.