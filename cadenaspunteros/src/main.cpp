/*
================================================================================
Materia: Laboratorio de Programación (LPR)
E.E.S.T. N° 1 "Eduardo Ader" — Vicente López
Curso: 5° Año — 3° División
Profesor: Mansilla Muñoz York Elías
Estudiante: Ian Quiroga
Archivo: src/main.cpp
Objetivo: Control de accesos operando directamente sobre la RAM con punteros.
================================================================================
*/

#include <iostream>
using namespace std;

int main()
{
    int edad = 0;
    int* p = &edad; // El puntero 'p' guarda la dirección de memoria física de 'edad'

    // ========================================================================
    // REGLA OBLIGATORIA (EVITA EL PLAGIO):
    // Modifiquen la salida agregando su Nombre y Apellido reales.
    // ========================================================================
    cout << "=====================================================" << endl;
    cout << " CONTROL DE ACCESO RAM - ESTUDIANTE: Ian Quiroga "
         << endl;
    cout << "=====================================================" << endl;

    cout << "=> Ingrese su edad: ";

    // ========================================================================
    // 1. CAPTURA MEDIANTE DESREFERENCIACIÓN (CÓDIGO EXPLICADO)
    // -----------------------------------------------------------------------------
    // Usamos 'cin >> *p;' porque el asterisco '*' desreferencia al puntero.
    // Esto le indica al compilador que debe guardar el número ingresado
    // directamente en el casillero de memoria original de 'edad'.
    // Si pusiéramos 'cin >> p;' sin asterisco, intentaríamos sobrescribir
    // la dirección hexadecimal física de la RAM, provocando un error grave.
    // ========================================================================
    cin >> *p; // Captura el dato guardándolo directo en la memoria apuntada

    cout << "\n--- ANALIZANDO ACCESO SEGURO EN MEMORIA ---" << endl;

    // ========================================================================
    // 2. CONDICIONAL CON PUNTERO DESREFERENCIADO
    // -----------------------------------------------------------------------------
    // Evaluamos el valor alojado en la memoria usando '*p >= 18'.
    // Si mostramos solo 'p', la consola imprimirá la dirección hexadecimal
    // (ej: 0x61fe1c).
    // ========================================================================
    if (*p >= 18)
    {
        cout << "[ACCESO APROBADO] El usuario es mayor de edad." << endl;
        cout << "Edad registrada: " << *p << " anos." << endl;
        cout << "Direccion fisica en RAM Hexadecimal: " << p << endl;
    }
    else
    {
        cout << "[ACCESO RECHAZADO] Menor de edad." << endl;
        cout << "Edad registrada: " << *p << " anos." << endl;
        cout << "Direccion fisica en RAM Hexadecimal: " << p << endl;
    }

    cout << "=====================================================" << endl;

    return 0; // Finalización exitosa de Windows (Código 0)
}