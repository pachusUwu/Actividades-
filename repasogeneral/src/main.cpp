/*
================================================================================
Materia: Laboratorio de Programación (LPR) — 5° Año
Institución: E.E.S.T. N° 1 "Eduardo Ader" - Vicente López
Archivo: src/main.cpp
Actividad 6: Suite de Taller de Repaso e Integración
Estudiante: Ian Quiroga
================================================================================
*/

#include <iostream>
using namespace std;

// Prototipos de funciones modulares
int sumaRecursiva(int n);
void intercambiarValores(int* ptrA, int* ptrB);

int main()
{
    // ========================================================================
    // REGLA OBLIGATORIA (EVITA EL PLAGIO):
    // Modifiquen la salida de pantalla agregando su Nombre y Apellido reales.
    // ========================================================================
    cout << "=====================================================" << endl;
    cout << " TALLER INTEGRADOR REPASO - ESTUDIANTE: Ian Quiroga "
         << endl;
    cout << "=====================================================" << endl;

    // --- RETO 1: RECURSIVIDAD ---
    cout << "\n=== RETO 1: SUMA RECURSIVA ===" << endl;
    int num = 5;
    cout << "Suma acumulada de 1 hasta " << num << ": " << sumaRecursiva(num)
         << endl;

    // --- RETO 2: ARRAYS Y BUSQUEDA SECUENCIAL ---
    cout << "\n=== RETO 2: BUSQUEDA EN MEMORIA CONTIGUA ===" << endl;

    const int TAM = 10;
    int vectorDatos[TAM] = {12, 45, 78, 90, 122, 5, 18, 33, 67, 99};
    int numeroBuscar = 18;
    bool hallado = false;

    for (int i = 0; i < TAM; i++)
    {
        if (vectorDatos[i] == numeroBuscar)
        {
            cout << "[SISTEMA] Valor " << numeroBuscar << " hallado en el indice ["
                 << i << "]" << endl;
            cout << " Direccion RAM Hexadecimal: " << &vectorDatos[i] << endl;
            hallado = true;
            break; // Interrupción optimizada del ciclo O(n)
        }
    }

    if (!hallado)
    {
        cout << "[SISTEMA] El valor " << numeroBuscar
             << " no existe en el arreglo." << endl;
    }

    // --- RETO 3: INTERCAMBIO CON PUNTEROS ---
    cout << "\n=== RETO 3: INTERCAMBIO DE CELDAS ===" << endl;

    int x = 100, y = 500;
    cout << "Valores previos -> X: " << x << " | Y: " << y << endl;

    // Invocación pasando direcciones de memoria
    intercambiarValores(&x, &y);

    cout << "Valores actuales -> X: " << x << " | Y: " << y << endl;

    cout << "=====================================================" << endl;

    return 0; // Código 0: Ejecución exitosa
}

// =============================================================================
// DESARROLLO DE LA FUNCIÓN RECURSIVA
// -----------------------------------------------------------------------------
// Cada llamada abre un nuevo marco en el Stack (pila de memoria). El 'Caso Base'
// es OBLIGATORIO: sin el, la pila se desborda (Stack Overflow) y el proceso
// termina con un error de segmentación.
// =============================================================================
int sumaRecursiva(int n)
{
    if (n <= 0)
        return 0; // Caso base obligatorio para prevenir Stack Overflow

    return n + sumaRecursiva(n - 1); // Llamada recursiva
}

// =============================================================================
// DESARROLLO DEL INTERCAMBIO FÍSICO MEDIANTE DESREFERENCIACIÓN
// -----------------------------------------------------------------------------
// Guardamos el valor de A en una variable temporal, copiamos B en A y luego
// el temporal en B. Como trabajamos sobre las direcciones, las variables
// originales x e y quedan realmente modificadas en la RAM.
// =============================================================================
void intercambiarValores(int* ptrA, int* ptrB)
{
    int temporal = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temporal;
}