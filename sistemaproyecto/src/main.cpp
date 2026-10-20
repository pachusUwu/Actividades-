/*
================================================================================
Materia: Laboratorio de Programación (LPR) — 5° Año
Archivo: src/main.cpp
Actividad 5: Modelado de datos con Structs y Punteros
Estudiante: Ian Quiroga
================================================================================
*/

#include <iostream>
#include <cstring>
using namespace std;

// =============================================================================
// 1. DEFINICIÓN DE LA ESTRUCTURA
// -----------------------------------------------------------------------------
// Modelo sugerido para el Proyecto Integrador Anual.
// Un 'struct' agrupa variables de distintos tipos bajo una misma entidad
// lógica, reservando un bloque contiguo de memoria RAM.
// =============================================================================
struct EntidadProyecto
{
    int id;
    char nombre[50];
    float metrica; // Representa lecturas de sensores, consumo, avance, etc.
};

// Prototipo de función con pasaje por dirección mediante puntero
void cargarDatos(EntidadProyecto* ptr);

int main()
{
    // Inicialización de seguridad en la memoria Stack
    EntidadProyecto miEntidad = {0, "Vacio - Ian Quiroga", 0.0f};

    // ========================================================================
    // REGLA OBLIGATORIA (EVITA EL PLAGIO):
    // Modifiquen la salida de pantalla agregando su Nombre y Apellido reales.
    // ========================================================================
    cout << "=====================================================" << endl;
    cout << " MODELADO STRUCT - ESTUDIANTE: Ian Quiroga "
         << endl;
    cout << "=====================================================" << endl;

    // Invocación enviando la dirección física de memoria con '&'
    cargarDatos(&miEntidad);

    cout << "\n=== DATOS VERIFICADOS EN LA MEMORIA RAM ===" << endl;
    cout << "ID Registrado: " << miEntidad.id << endl;
    cout << "Nombre Registrado: " << miEntidad.nombre << endl;
    cout << "Metrica Guardada: " << miEntidad.metrica << endl;
    cout << "Direccion RAM Hexadecimal: " << &miEntidad << endl;
    cout << "=====================================================" << endl;

    return 0; // Código 0: Finalización exitosa
}

// =============================================================================
// 2. DESARROLLO DE LA FUNCIÓN
// -----------------------------------------------------------------------------
// Recibe un PUNTERO a la estructura. Por eso, para leer o escribir en los
// campos usamos el operador FLECHA (->) en lugar del punto (.)
// =============================================================================
void cargarDatos(EntidadProyecto* ptr)
{
    cout << "\n--- INGRESO DE DATOS MEDIANTE OPERADOR FLECHA ---" << endl;

    cout << "=> Ingrese el ID de la entidad (entero): ";
    cin >> ptr->id;

    // Limpieza del buffer obligatoria antes de cin.getline: queda pendiente
    // el Enter (\n) del cin anterior y getline leeria una cadena vacia.
    cin.ignore();

    cout << "=> Ingrese el Nombre o Descripcion: ";
    cin.getline(ptr->nombre, 50);

    cout << "=> Ingrese la Metrica de Operacion (decimal/float): ";
    cin >> ptr->metrica;
}