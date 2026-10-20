/*
================================================================================
Materia: Laboratorio de Programación (LPR)
E.E.S.T. N° 1 "Eduardo Ader" — Vicente López
Curso: 5° Año — 3° División
Profesor: Mansilla Muñoz York Elías
Archivo: proyecto_cpp/calculadoraEdad.cpp
Actividad: 1 — De revisión integral (Python & C++)
Objetivo: Calcular la edad exacta de una persona validando la fecha de
          nacimiento contra el calendario real (bisiestos y días por mes).
================================================================================
*/

#include <iostream>
using namespace std;

// =============================================================================
// 1. EVALÚA SI UN AÑO ES BISIESTO
// -----------------------------------------------------------------------------
// Regla del calendario gregoriano:
//   - Es bisiesto si es divisible por 4, PERO no por 100...
//   - ...salvo que además sea divisible por 400.
// Ejemplo: 1900 NO es bisiesto (divisible por 4 y 100, pero no por 400).
//          2000 SI  es bisiesto (divisible por 4, 100 y 400).
// =============================================================================
bool esBisiesto(int anio)
{
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// =============================================================================
// 2. FILTRO DE CONSISTENCIA DE CALENDARIO
// -----------------------------------------------------------------------------
// Devuelve false si la fecha no existe en el calendario real.
// Primero acota el rango del anio, luego el mes, luego el dia, y por ultimo
// aplica la cantidad de dias reales de cada mes (incluido el caso de febrero).
// =============================================================================
bool esFechaValida(int d, int m, int a)
{
    if (a < 1900 || a > 2026)
        return false;

    if (m < 1 || m > 12)
        return false;

    if (d < 1 || d > 31)
        return false;

    // Meses de 30 dias: abril(4), junio(6), septiembre(9), noviembre(11)
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return false;

    // Caso especial de febrero: depende de si el anio es bisiesto
    if (m == 2)
    {
        if (esBisiesto(a))
        {
            if (d > 29)
                return false;
        }
        else
        {
            if (d > 28)
                return false;
        }
    }

    return true;
}

// =============================================================================
// MAIN — PUNTO DE ENTRADA DEL PROGRAMA
// =============================================================================
int main()
{
    int diaN, mesN, anioN;

    // Fecha actual de referencia para el ejercicio
    int diaA = 8, mesA = 7, anioA = 2026;

    // ========================================================================
    // REGLA OBLIGATORIA (EVITA EL PLAGIO):
    // Reemplacen "Estudiante" por su nombre y apellido reales
    // en la salida.
    // ========================================================================
    cout << "=====================================================" << endl;
    cout << " CALCULADORA DE EDAD DE: Ian Quiroga "
         << endl;
    cout << "=====================================================" << endl;

    cout << "Ingrese Dia, Mes y Anio de nacimiento (separados por espacios): ";
    cin >> diaN >> mesN >> anioN;

    if (!esFechaValida(diaN, mesN, anioN))
    {
        cout << "[ERROR] La fecha ingresada no existe en el calendario."
             << endl;
        return 1;
    }

    // Se resta el anio de nacimiento del anio actual.
    int edad = anioA - anioN;

    // COMPLETADO: Si todavia NO cumplio anios en el mes o dia actual, la edad
    // real es una unidad menor. Por eso solo se descuenta 1 cuando el mes de
    // nacimiento es posterior al mes actual, o cuando es el mismo mes pero el
    // dia de nacimiento todavia no llego.
    if (mesN > mesA || (mesN == mesA && diaN > diaA))
    {
        edad = edad - 1;
    }

    cout << "\n[SISTEMA] Fecha de hoy: " << diaA << "/" << mesA << "/" << anioA
         << endl;
    cout << "[SISTEMA] Fecha de nacimiento: " << diaN << "/" << mesN << "/"
         << anioN << endl;
    cout << "[SISTEMA] Edad calculada: " << edad << " anos." << endl;
    cout << "=====================================================" << endl;

    return 0;
}