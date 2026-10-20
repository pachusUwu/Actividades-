/*
================================================================================
Materia: Laboratorio de Programación (LPR) — 5° Año
Institución: E.E.S.T. N° 1 "Eduardo Ader" — Vicente López
Archivo: src/main.cpp
Actividad 7: Mini Juego Piedra, Papel o Tijera + Persistencia en Disco
Estudiante: Ian Quiroga
================================================================================
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// =============================================================================
// 1. ESTRUCTURA DE DATOS PARA REPRESENTAR UNA PARTIDA
// -----------------------------------------------------------------------------
// Un 'struct' agrupa todas las variables heterogéneas de una partida en un
// solo bloque contiguo de memoria, en vez de pasar 5 variables sueltas.
// =============================================================================
struct Partida
{
    int idPartida;
    string jugador;
    string eleccionJugador;
    string eleccionIA;
    string resultado;
};

// Prototipos de funciones modulares
void jugarPartida(int& contadorID);
void guardarEnDisco(const Partida& p);
void leerHistorialDisco();
int proximoID();

int main()
{
    // Inicializar la semilla para los números aleatorios de la IA
    srand(time(0));

    int contadorID = proximoID(); // sigue la numeracion del archivo en disco
    int opcion = 0;

    // ========================================================================
    // REGLA OBLIGATORIA (EVITA EL PLAGIO):
    // Modifiquen la salida de pantalla agregando su Nombre y Apellido reales.
    // ========================================================================
    cout << "=====================================================" << endl;
    cout << " LPR 2026 - ACTIVIDAD 7: PIEDRA, PAPEL O TIJERA " << endl;
    cout << " Estudiante / Grupo: Ian Quiroga " << endl;
    cout << "=====================================================" << endl;

    do
    {
        cout << "\n--- MENU PRINCIPAL DE JUEGO Y PERSISTENCIA ---" << endl;
        cout << "1. Jugar Partida (Piedra, Papel o Tijera)" << endl;
        cout << "2. Ver Historial de Partidas Guardadas en Disco (.txt)" << endl;
        cout << "3. Salir del Sistema" << endl;
        cout << "Ingrese una opcion (1-3): ";
        cin >> opcion;

        // Si el usuario escribe letras, cin queda en estado de error: lo
        // limpiamos para no caer en un bucle infinito.
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            opcion = 0;
        }

        if (opcion == 1)
        {
            jugarPartida(contadorID);
        }
        else if (opcion == 2)
        {
            leerHistorialDisco();
        }
        else if (opcion == 3)
        {
            cout << "\n[SISTEMA] Saliendo del programa... Datos resguardados en disco."
                 << endl;
        }
        else
        {
            cout << "\n[ERROR] Opcion invalida. Reintente." << endl;
        }

    } while (opcion != 3);

    return 0;
}

// =============================================================================
// FUNCIÓN PARA PROCESAR LA JUGADA CONTRA LA IA
// =============================================================================
void jugarPartida(int& contadorID)
{
    Partida p;
    p.idPartida = contadorID++;

    cout << "\n--- NUEVA PARTIDA #" << p.idPartida << " ---" << endl;

    cout << "Ingrese su Nombre / Nickname: ";
    cin.ignore(); // Limpieza de búfer: elimina el Enter (\n) pendiente
    getline(cin, p.jugador);

    int opcJugador = 0;
    cout << "\nElija su jugada:" << endl;
    cout << "1. Piedra" << endl;
    cout << "2. Papel" << endl;
    cout << "3. Tijera" << endl;

    // Se repite la pregunta hasta que ingrese un 1, 2 o 3
    do
    {
        cout << "Opcion (1-3): ";
        cin >> opcJugador;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            opcJugador = 0;
        }
    } while (opcJugador < 1 || opcJugador > 3);

    // Asignar selección del usuario
    if (opcJugador == 1)
        p.eleccionJugador = "Piedra";
    else if (opcJugador == 2)
        p.eleccionJugador = "Papel";
    else
        p.eleccionJugador = "Tijera";

    // Elección aleatoria de la IA (1 a 3)
    int opcIA = (rand() % 3) + 1;

    if (opcIA == 1)
        p.eleccionIA = "Piedra";
    else if (opcIA == 2)
        p.eleccionIA = "Papel";
    else
        p.eleccionIA = "Tijera";

    // Evaluar reglas del juego
    cout << "\n[JUGADA] " << p.jugador << " eligio: " << p.eleccionJugador
         << endl;
    cout << "[JUGADA] La IA eligio: " << p.eleccionIA << endl;

    if (p.eleccionJugador == p.eleccionIA)
    {
        p.resultado = "Empate";
    }
    else if ((p.eleccionJugador == "Piedra" && p.eleccionIA == "Tijera") ||
             (p.eleccionJugador == "Papel" && p.eleccionIA == "Piedra") ||
             (p.eleccionJugador == "Tijera" && p.eleccionIA == "Papel"))
    {
        p.resultado = "Victoria";
    }
    else
    {
        p.resultado = "Derrota";
    }

    cout << "=> RESULTADO: " << p.resultado << "!" << endl;

    // Persistir el resultado inmediatamente en el archivo
    guardarEnDisco(p);
}

// =============================================================================
// FUNCIÓN PARA ESCRIBIR EN EL ARCHIVO DE TEXTO EN DISCO
// -----------------------------------------------------------------------------
// 'ofstream' = flujo de salida: escribe datos del PROGRAMA hacia el DISCO.
// =============================================================================
void guardarEnDisco(const Partida& p)
{
    // ios::app permite agregar al final sin borrar partidas anteriores
    ofstream archivo("src/historial_partidas.txt", ios::app);

    if (!archivo.is_open())
    {
        cerr << "[ERROR] No se pudo abrir el archivo para guardar la partida."
             << endl;
        return;
    }

    // Guardado de datos separados por comas (Formato CSV)
    archivo << p.idPartida << "," << p.jugador << "," << p.eleccionJugador
            << "," << p.eleccionIA << "," << p.resultado << endl;

    archivo.close();

    cout << "[DISCO] Partida resguardada con exito en 'historial_partidas.txt'."
         << endl;
}

// =============================================================================
// DEVUELVE EL NUMERO QUE LE TOCA A LA PROXIMA PARTIDA
// -----------------------------------------------------------------------------
// Cuenta las lineas que ya hay en el archivo, asi la numeracion no se reinicia
// en 1 cada vez que se abre el programa.
// =============================================================================
int proximoID()
{
    ifstream archivo("src/historial_partidas.txt");
    string linea;
    int cantidad = 0;

    while (getline(archivo, linea))
    {
        if (!linea.empty())
            cantidad++;
    }

    return cantidad + 1;
}

// =============================================================================
// FUNCIÓN PARA LEER EL HISTORIAL PERSISTIDO DESDE EL ARCHIVO
// -----------------------------------------------------------------------------
// 'ifstream' = flujo de entrada: lee datos del DISCO hacia el PROGRAMA.
// =============================================================================
void leerHistorialDisco()
{
    ifstream archivo("src/historial_partidas.txt");

    if (!archivo.is_open())
    {
        cout << "\n[AVISO] Aun no existen partidas guardadas en disco." << endl;
        return;
    }

    cout << "\n=====================================================" << endl;
    cout << " HISTORIAL DE PARTIDAS RECUPERADO DESDE DISCO " << endl;
    cout << "=====================================================" << endl;

    string idStr, jugador, elJug, elIA, resultado;
    int total = 0;

    // Lectura secuencial delimitada por comas
    while (getline(archivo, idStr, ',') && getline(archivo, jugador, ',') &&
           getline(archivo, elJug, ',') && getline(archivo, elIA, ',') &&
           getline(archivo, resultado))
    {
        total++;
        cout << "Partida #" << idStr << " | Jugador: " << jugador << " | "
             << elJug << " vs " << elIA << " | Resultado: " << resultado
             << endl;
    }

    archivo.close();

    if (total == 0)
    {
        cout << "[AVISO] El archivo de historial esta vacio." << endl;
    }
    else
    {
        cout << "\n[SISTEMA] Total de registros leidos desde disco: " << total
             << endl;
    }

    cout << "=====================================================" << endl;
}