# =============================================================================
# Materia: Laboratorio de Programación (LPR)
# E.E.S.T. N° 1 "Eduardo Ader" — Vicente López
# Curso: 5° Año — 3° División
# Profesor: Mansilla Muñoz York Elías
# Archivo: proyecto_python/calculadoraEdad.py
# Actividad: 1 — De revisión integral (Python & C++)
# Objetivo: Calcular la edad exacta de una persona validando la fecha de
#           nacimiento contra el calendario real (bisiestos y días por mes).
# =============================================================================


def es_bisiesto(anio):
    """Devuelve True si el año es bisiesto según el calendario gregoriano.

    Regla: divisible por 4 y no por 100, o bien divisible por 400.
    Ejemplos: 1900 -> False | 2000 -> True | 2024 -> True
    """
    return (anio % 4 == 0 and anio % 100 != 0) or (anio % 400 == 0)


def es_fecha_valida(d, m, a):
    """Filtro de consistencia: valida que la fecha exista en el calendario."""
    if a < 1900 or a > 2026:
        return False

    if m < 1 or m > 12:
        return False

    if d < 1 or d > 31:
        return False

    # Meses de 30 días
    if m in [4, 6, 9, 11] and d > 30:
        return False

    # Febrero depende del bisiesto
    if m == 2:
        if es_bisiesto(a):
            if d > 29:
                return False
        else:
            if d > 28:
                return False

    return True


# Código principal
# REGLA OBLIGATORIA:
# Cambien el nombre de la salida por el suyo real
print("=====================================================")
print("   CALCULADORA EN PYTHON DE: Ian Quiroga     ")
print("=====================================================")

try:
    diaN = int(input("Ingrese Dia de nacimiento: "))
    mesN = int(input("Ingrese Mes de nacimiento: "))
    anioN = int(input("Ingrese Anio de nacimiento: "))

    diaA, mesA, anioA = 8, 7, 2026

    if not es_fecha_valida(diaN, mesN, anioN):
        print("[ERROR] La fecha ingresada no es valida.")
    else:
        edad = anioA - anioN

        # COMPLETADO: se descuenta 1 si todavia no cumplio anios en el
        # mes o dia actual.
        if mesN > mesA or (mesN == mesA and diaN > diaA):
            edad = edad - 1

        print(f"\n[SISTEMA] Fecha de hoy: {diaA}/{mesA}/{anioA}")
        print(f"[SISTEMA] Fecha de nacimiento: {diaN}/{mesN}/{anioN}")
        print(f"[SISTEMA] Edad calculada: {edad} anos.")

except ValueError:
    print("[ERROR] Deben ingresar numeros enteros.")