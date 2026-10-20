/*
================================================================================
Materia: Laboratorio de Programación (LPR)
E.E.S.T. N° 1 "Eduardo Ader" — Vicente López
Curso: 5° Año
Profesor: Mansilla Muñoz York Elías
Estudiante: Ian Quiroga
Archivo: src/main.cpp
Objetivo: Calcular el area de un circulo mediante funciones modulares y
          simular una diana de tiro en ASCII.
================================================================================
*/

#include <iostream>
using namespace std;

// =============================================================================
// 1. PROTOTIPO DE LA FUNCIÓN (Firma de la función)
// -----------------------------------------------------------------------------
// Le avisamos al compilador la existencia del módulo de cálculo antes del main
// =============================================================================
double calcularAreaCirculo(double radio);

int main()
{
    double radioEstudiante;

    // ========================================================================
    // REGLA OBLIGATORIA (EVITA EL PLAGIO):
    // Modifiquen la salida de pantalla agregando su Nombre y Apellido reales.
    // ========================================================================
    cout << "=====================================================" << endl;
    cout << " CALCULADORA DE AREA MODULAR - ESTUDIANTE: Ian Quiroga "
         << endl;
    cout << "=====================================================" << endl;

    cout << "=> Ingrese el radio del circulo/diana (en cm): ";
    cin >> radioEstudiante;

    // FILTRO DE CONSISTENCIA (Validación del dato geométrico)
    if (radioEstudiante <= 0)
    {
        cout << "[ERROR] El radio debe ser un valor positivo y mayor a cero."
             << endl;
        return 1; // Salida controlada del sistema indicando error en consola
    }

    // ========================================================================
    // 2. LLAMADA / INVOCACIÓN DE LA FUNCIÓN
    // -----------------------------------------------------------------------------
    // Convocamos al módulo 'calcularAreaCirculo' pasándole 'radioEstudiante'
    // y guardamos el resultado en la variable decimal 'areaFinal'.
    // ========================================================================
    double areaFinal = calcularAreaCirculo(radioEstudiante);

    // ========================================================================
    // 3. SALIDA DE DATOS
    // -----------------------------------------------------------------------------
    // Mostramos en pantalla el área calculada utilizando 'areaFinal'.
    // ========================================================================
    cout << "\n[SISTEMA] Area del circulo = " << areaFinal << " cm2"
         << endl;

    // ========================================================================
    // BONUS GAMIFICACIÓN: RENDER DE LA DIANA EN CONSOLA
    // Dependiendo del radio, la consola simula un blanco de tiro.
    // ========================================================================
    cout << "\n[SISTEMA] Dibujando escala de la Diana en la RAM..." << endl;

    if (radioEstudiante <= 5.0)
    {
        cout << "   .-.   " << endl;
        cout << "  ( X )   -> [DIANA MINI / COMPACTA]" << endl;
        cout << "   '-'   " << endl;
    }
    else if (radioEstudiante <= 12.0)
    {
        cout << "    .-----.    " << endl;
        cout << "   /  .-.  \\   " << endl;
        cout << "  |  ( O )  |   -> [DIANA ESTANDAR DE TIRO]" << endl;
        cout << "   \\  '-'  /   " << endl;
        cout << "    '-----'    " << endl;
    }
    else
    {
        cout << "      .-------.      " << endl;
        cout << "    /   .---.   \\    " << endl;
        cout << "   |   /     \\   |   " << endl;
        cout << "   |  |  (X)  |  |   -> [DIANA GIGANTE DE COBERTURA]" << endl;
        cout << "   |   \\     /   |   " << endl;
        cout << "    \\   '---'   /    " << endl;
        cout << "      '-------'      " << endl;
    }

    cout << "=====================================================" << endl;

    return 0; // Finalización exitosa de Windows (Código 0)
}

// =============================================================================
// 4. DEFINICIÓN / DESARROLLO DE LA FUNCIÓN
// -----------------------------------------------------------------------------
// Implementamos la fórmula matemática de la geometría A = PI * r^2 usando
// variables locales y la constante de PI bloqueada en memoria con 'const'.
// =============================================================================
double calcularAreaCirculo(double r)
{
    const double PI = 3.1415926535; // Constante universal bloqueada en RAM

    double area = PI * r * r;

    return area;
}