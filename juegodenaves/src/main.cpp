/*
=======================================================================================
Materia: Laboratorio de Programación (LPR) — 5° Año
Institución: E.E.S.T. N° 1 "Eduardo Ader" — Vicente López
Archivo: src/main.cpp
Actividad 8: Introducción a POO - Motor de Juego de Naves (Clases, Objetos y
            Constructores)

DESAFÍO OBLIGATORIO - FUNCIONALIDAD EXTRA IMPLEMENTADA:
    "SISTEMA DE POWER-UPS CON DISPARO RÁPIDO (RAPID FIRE) TEMPORAL"

    Detalle funcional:
      1. Cada vez que el jugador destruye un asteroide, tiene un 35% de
         probabilidad de soltar un power-up "RAPID FIRE" en el lugar del
         impacto.
      2. Si la nave choca con ese power-up, se activan 8 segundos de disparo
         rápido: la nave genera 3 balas por pulsación en lugar de 1.
      3. Al expirar el tiempo, el arma vuelve automáticamente a su cadencia
         normal y el power-up desaparece de la pantalla.
      4. HUD en vivo: muestra el estado del power-up (activo / inactivo) y los
         segundos restantes, además del marcador de puntos.

    Justificación técnica (POO): el temporizador del power-up se encapsuló
    dentro de la clase 'DisparoRapido' como atributo privado 'segundosRestantes',
    y nunca se modifica desde main(); solo mediante los métodos públicos
    'activar()', 'tick()' y 'estaActivo()'. Eso demuestra por qué sirve la
    sección 'private:' de una clase y de qué forma un objeto protege su estado
    interno de valores inválidos.

Estudiante: Ian Quiroga
=======================================================================================
*/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <cctype> // Para tolower()

using namespace std;

// ========================================================================================
// UTILIDADES DE CONSOLA (posicionamiento del cursor)
// ========================================================================================
void gotoxy(int x, int y)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void ocultarCursor()
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}

// ========================================================================================
// CLASE NAVE (El Jugador)
// -------------------------------------------------------------------------------
// SECCION 'private:' -> los atributos quedan OCULTOS. Nadie desde main() puede
// hacer 'jugador.x = 999'; hay que pasar por los metodos publicos.
// SECCION 'public:'  -> las acciones que el objeto puede realizar.
// ========================================================================================
class Nave
{
private:
    int x, y;
    int vidas;

public:
    // CONSTRUCTOR: recibe los valores iniciales y los copia a los atributos
    // privados en el momento de crear el objeto con 'new Nave(...)'.
    Nave(int _x, int _y, int _vidas)
    {
        x = _x;
        y = _y;
        vidas = _vidas;
    }

    // --- METODOS DE LECTURA (Getters) ---
    int getX() { return x; }
    int getY() { return y; }
    int getVidas() { return vidas; }

    // --- METODOS DE ACCION (Setters /acciones) ---
    void reducirVida() { vidas--; }

    void pintar()
    {
        gotoxy(x, y);
        cout << "  ^  ";
        gotoxy(x, y + 1);
        cout << " (O) ";
        gotoxy(x, y + 2);
        cout << "^^^^^";
    }

    void borrar()
    {
        gotoxy(x, y);
        cout << "     ";
        gotoxy(x, y + 1);
        cout << "     ";
        gotoxy(x, y + 2);
        cout << "     ";
    }

    void mover(char tecla)
    {
        borrar();

        if (tecla == 'a' && x > 2) x--;
        if (tecla == 'd' && x < 70) x++;
        if (tecla == 'w' && y > 3) y--;
        if (tecla == 's' && y < 20) y++;

        pintar();
    }
};

// ========================================================================================
// CLASE ASTEROIDE Y BALA (Simplificadas)
// ========================================================================================
class Asteroide
{
private:
    int x, y;

public:
    Asteroide(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    int getX() { return x; }
    int getY() { return y; }

    void pintar()
    {
        gotoxy(x, y);
        cout << "O";
    }

    void borrar()
    {
        gotoxy(x, y);
        cout << " ";
    }

    void mover()
    {
        borrar();
        y++;
        if (y > 23)
        {
            y = 4;
            x = (rand() % 70) + 2;
        }
        pintar();
    }
};

class Bala
{
private:
    int x, y;

public:
    Bala(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    int getX() { return x; }
    int getY() { return y; }

    void mover()
    {
        gotoxy(x, y);
        cout << " ";
        y--;
        gotoxy(x, y);
        cout << "|";
    }

    bool fueraDeRango() { return y < 4; }
};

// ========================================================================================
// *** DESAFÍO OBLIGATORIO ***  CLASE POWER-UP / DISPARO RÁPIDO
// -------------------------------------------------------------------------------
// Encapsula por completo el estado del power-up. 'segundosRestantes' es PRIVADO:
// main() no puede escribirlo directamente, solo puede:
//   - activarlo        -> activar()
//   - descontar tiempo -> tick()
//   - consultarlo      -> estaActivo() / getSegundos()
// ========================================================================================
class DisparoRapido
{
private:
    int x, y;                // Posicion del power-up en la consola
    bool activo;             // ¿Esta en pantalla?
    int segundosRestantes;   // Temporizador del efecto (PRIVADO)
    int ciclos;              // Vueltas del bucle desde el ultimo segundo descontado

    static const int DURACION = 8;          // 8 segundos de disparo rapido
    static const int CICLOS_POR_SEG = 33;   // el bucle duerme 30 ms por vuelta

public:
    // Arranca inactivo: el efecto recien empieza al llamar a activar()
    DisparoRapido(int _x, int _y) : x(_x), y(_y), activo(true)
    {
        segundosRestantes = 0;
        ciclos = 0;
    }

    int getX() { return x; }
    int getY() { return y; }
    bool estaEnPantalla() { return activo; }
    bool estaActivo() { return segundosRestantes > 0; }
    int getSegundos() { return segundosRestantes; }

    // El metodo que "abre la puerta": main() activa el efecto SIN poder
    // escribir directamente en la variable interna.
    void activar()
    {
        segundosRestantes = DURACION;
        ciclos = 0;
        activo = false; // El icono desaparece del tablero al ser recolectado
    }

    // Se llama una vez por cada vuelta del bucle de juego (cada ~30 ms) pero
    // solo descuenta un segundo cada CICLOS_POR_SEG vueltas.
    void tick()
    {
        if (segundosRestantes > 0)
        {
            ciclos++;
            if (ciclos >= CICLOS_POR_SEG)
            {
                ciclos = 0;
                segundosRestantes--;
            }
        }
    }

    void pintar()
    {
        gotoxy(x, y);
        cout << "R"; // 'R' = insignia de RAPID FIRE
    }

    void borrar()
    {
        gotoxy(x, y);
        cout << " ";
    }

    void mover()
    {
        borrar();
        y++;
        if (y > 23)
        {
            y = 4;
            x = (rand() % 70) + 2;
        }
        pintar();
    }
};

// ========================================================================================
// PROGRAMA PRINCIPAL
// ========================================================================================
int main()
{
    srand(time(NULL));

    // SISTEMA ANTI-COPIA: Petición de datos
    string nombrePiloto;
    cout << "Ingresa tu Nombre y Apellido (Se mostrara en la captura de pantalla): ";
    getline(cin, nombrePiloto);

    system("cls");
    ocultarCursor();

    bool gameOver = false;
    int vuelta = 0; // cuenta las vueltas del bucle para ir mas lento con los objetos que caen
    int puntos = 0;

    Nave jugador(35, 20, 3);
    DisparoRapido arma(35, 20); // Objeto del modulo "desafío": arranca inactivo

    vector<Asteroide*> asteroides;
    vector<Bala*> balas;
    vector<DisparoRapido*> powerUps;

    for (int i = 0; i < 5; i++)
    {
        asteroides.push_back(new Asteroide((rand() % 70) + 2, (rand() % 5) + 4));
    }

    jugador.pintar();

    while (!gameOver)
    {
        // ------------------------------------------------------------------
        // HUD CON NOMBRE DEL ESTUDIANTE
        // ------------------------------------------------------------------
        gotoxy(2, 1);
        cout << "PILOTO: " << nombrePiloto << "                                  ";
        gotoxy(2, 2);
        cout << "VIDAS: " << jugador.getVidas()
             << "   PUNTOS: " << puntos << "                                  ";

        // ------------------------------------------------------------------
        // HUD DEL DESAFÍO: estado del Disparo Rápido
        // ------------------------------------------------------------------
        gotoxy(40, 1);
        if (arma.estaActivo())
        {
            cout << "[RAPID FIRE ACTIVO: " << arma.getSegundos() << "s]     ";
        }
        else
        {
            cout << "[RAPID FIRE: OFF]                          ";
        }

        // ------------------------------------------------------------------
        // LECTURA DE TECLADO
        // ------------------------------------------------------------------
        if (_kbhit())
        {
            char tecla = tolower(_getch()); // tolower evita el problema del Bloq Mayús

            if (tecla == ' ')
            {
                // --- LÓGICA DEL DISPARO RÁPIDO ---
                // Si el power-up está activo se generan 2 balas (una centrada
                // y otra desplazada) en lugar de una sola.
                balas.push_back(new Bala(jugador.getX() + 2, jugador.getY() - 1));

                if (arma.estaActivo())
                {
                    balas.push_back(new Bala(jugador.getX() + 3, jugador.getY() - 1));
                    balas.push_back(new Bala(jugador.getX() + 1, jugador.getY() - 1));
                }
            }
            else
            {
                jugador.mover(tecla);
            }
        }

        // ------------------------------------------------------------------
        // DESPLAZAMIENTO Y DEPURACIÓN DE BALAS
        // Recorremos el vector en orden inverso porque 'erase' invalida los
        // índices siguientes; asi no se saltea ninguna bala.
        // ------------------------------------------------------------------
        for (int i = (int)balas.size() - 1; i >= 0; i--)
        {
            balas[i]->mover();

            if (balas[i]->fueraDeRango())
            {
                gotoxy(balas[i]->getX(), balas[i]->getY());
                cout << " ";
                delete balas[i];
                balas.erase(balas.begin() + i);
            }
        }

        // ------------------------------------------------------------------
        // LÓGICA DEL POWER-UP: descontar el temporizador y mover los que
        // siguen visibles en pantalla.
        // ------------------------------------------------------------------
        arma.tick();

        for (int k = (int)powerUps.size() - 1; k >= 0; k--)
        {
            if (vuelta % 8 == 0)
                powerUps[k]->mover();
        }

        // ------------------------------------------------------------------
        // ASTEROIDES: movimiento, colisiones y limpieza
        // ------------------------------------------------------------------
        for (int i = (int)asteroides.size() - 1; i >= 0; i--)
        {
            if (vuelta % 5 == 0)
                asteroides[i]->mover();

            // -------- Colisión Asteroide -> Jugador --------
            if ((asteroides[i]->getX() >= jugador.getX() && asteroides[i]->getX() <= jugador.getX() + 4) &&
                (asteroides[i]->getY() >= jugador.getY() && asteroides[i]->getY() <= jugador.getY() + 2))
            {
                jugador.borrar();
                jugador.reducirVida();
                asteroides[i]->borrar();
                delete asteroides[i];
                asteroides[i] = new Asteroide((rand() % 70) + 2, 4);
                jugador.pintar();

                if (jugador.getVidas() == 0) gameOver = true;
            }

            // -------- Colisión Bala -> Asteroide --------
            for (int j = (int)balas.size() - 1; j >= 0; j--)
            {
                if (asteroides[i]->getX() == balas[j]->getX() &&
                    (asteroides[i]->getY() == balas[j]->getY() ||
                     asteroides[i]->getY() + 1 == balas[j]->getY()))
                {
                    gotoxy(balas[j]->getX(), balas[j]->getY());
                    cout << " ";
                    delete balas[j];
                    balas.erase(balas.begin() + j);

                    asteroides[i]->borrar();

                    puntos += 10; // Sumamos puntos por cada asteroide destruido

                    // -------- LÓGICA DEL DESAFÍO: soltar power-up --------
                    // 35% de probabilidad de que el asteroide destruido deje
                    // caer un power-up de Disparo Rápido.
                    if ((rand() % 100) < 35)
                    {
                        powerUps.push_back(new DisparoRapido(asteroides[i]->getX(), asteroides[i]->getY()));
                    }

                    delete asteroides[i];
                    asteroides[i] = new Asteroide((rand() % 70) + 2, 4);
                    break;
                }
            }
        }

        // ------------------------------------------------------------------
        // Colisión Nave -> Power-Up: se recolecta el power-up
        // ------------------------------------------------------------------
        for (int k = (int)powerUps.size() - 1; k >= 0; k--)
        {
            if (powerUps[k]->estaEnPantalla() &&
                powerUps[k]->getX() >= jugador.getX() && powerUps[k]->getX() <= jugador.getX() + 4 &&
                powerUps[k]->getY() >= jugador.getY() && powerUps[k]->getY() <= jugador.getY() + 2)
            {
                powerUps[k]->activar(); // Marca el item como recolectado
                powerUps[k]->borrar();  // y lo saca del tablero
                arma.activar();         // Activa los 8 segundos de disparo rapido
                puntos += 5;
                delete powerUps[k];
                powerUps.erase(powerUps.begin() + k);
            }
        }

        vuelta++;
        Sleep(30);
    }

    // ----------------------------------------------------------------------
    // LIMPIEZA DE MEMORIA: liberamos todos los 'new' antes de terminar
    // ----------------------------------------------------------------------
    for (int i = 0; i < (int)asteroides.size(); i++) delete asteroides[i];
    for (int i = 0; i < (int)balas.size(); i++) delete balas[i];
    for (int i = 0; i < (int)powerUps.size(); i++) delete powerUps[i];

    system("cls");
    gotoxy(24, 8);
    cout << "G A M E   O V E R . . . Perdiste, " << nombrePiloto << "!";
    gotoxy(26, 10);
    cout << "PUNTUACION FINAL: " << puntos << " puntos";
    gotoxy(20, 13);
    system("pause");

    return 0;
}