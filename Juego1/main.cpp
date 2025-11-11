



#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

// ------------------- FUNCIONES AUXILIARES -------------------

void limpiarPantalla() {   /// FUNCION QUE LIMPIA LA PANTALLA
#ifdef _WIN32
    system("cls");
#else
    System("clear");
#endif
}

void mostrarAhorcado(int errores) {  /// FUNCION QUE MUETSRA EL GRAFICO DEL JUEGO
    switch (errores) {
        case 0: cout << "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n"; break;
        case 1: cout << "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n"; break;
        case 2: cout << "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n"; break;
        case 3: cout << "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n"; break;
        case 4: cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n"; break;
        case 5: cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n"; break;
        case 6: cout << "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n"; break;
    }
}

bool letraUsada(char letra, char usadas[], int cantidad) { ///FUNCION QUE REVISA SI LA LETRA YA SE USO O NO
    for (int i = 0; i < cantidad; i++) ///mediande un ciclo for
        if (usadas[i] == letra) return true; ///Si la encuentra, devuelve verdadero
    return false; /// Si no la encuentra devuelve falso
}

void ordenarRanking(char nombres[][30], int puntajes[], int totalJugadores) { /// FUNCION QUE ORDENA A LOS JUGADORES SEGUN SU RANKING
    for (int i = 0; i < totalJugadores-1; i++) {      /// mediante dos ciclos y algoritmo de ordenamiento
        for (int j = 0; j < totalJugadores-i-1; j++) {
            if (puntajes[j] < puntajes[j+1]) {
                int tempP = puntajes[j];
                puntajes[j] = puntajes[j+1];
                puntajes[j+1] = tempP;

                char tempN[30];
                strcpy(tempN, nombres[j]);
                strcpy(nombres[j], nombres[j+1]);
                strcpy(nombres[j+1], tempN);
            }
        }
    }
}

void actualizarRanking(char nombres[][30], int puntajes[], char nombre[], int puntaje, int &totalJugadores) { /// FUNCION QUE ACTUALIZA LOS RANKINGS SEGUN EL PUNTAJE
    bool existe = false;
    for (int i = 0; i < totalJugadores; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            if (puntaje > puntajes[i]) puntajes[i] = puntaje;
            existe = true;
            break;
        }
    }
    if (!existe && totalJugadores < 5) {
        strcpy(nombres[totalJugadores], nombre);
        puntajes[totalJugadores] = puntaje;
        totalJugadores++;
    }
    ordenarRanking(nombres, puntajes, totalJugadores);
}

void mostrarRanking(char nombres[][30], int puntajes[], int totalJugadores, char jugadorActual[]) { /// FUNCION QUE MUESTRA EN PANTALLA EL RANKING DE LOS JUGADORES
    cout << "\n RANKING DE JUGADORES:\n";
    for (int i = 0; i < totalJugadores; i++) {
        if (strcmp(nombres[i], jugadorActual) == 0) {
            // Resaltar jugador actual en verde
            cout << "\033[1;32m"; // verde negrita
            cout << i+1 << ". " << nombres[i] << " - " << puntajes[i] << " puntos";
            cout << "\033[0m\n"; // reset
        } else {
            cout << i+1 << ". " << nombres[i] << " - " << puntajes[i] << " puntos\n";
        }
    }
    cout << endl;
}

// ------------------- PROGRAMA PRINCIPAL -------------------

int main() {
    const int MAX_LONGITUD = 40;
    const int CANT_PALABRAS = 6;

    char listaPalabras[CANT_PALABRAS][MAX_LONGITUD] = { ///FUNCION QUE GUARGA LA LISTA DE PALABRAS
        "gato negro",
        "tigre blanco",
        "perro guardian",
        "raton veloz",
        "pajaro cantor",
        "pez dorado"
    };

    srand(time(0)); /// LANZA PALABRAS AL AZAR

    char jugarDeNuevo;
    char nombreJugador[30];
    int puntaje = 0;

    char rankingNombres[5][30];
    int rankingPuntajes[5];
    int totalJugadores = 0;

    limpiarPantalla();
    cout << " Bienvenido al Ahorcado!\n";
    cout << "Ingresa tu nombre: ";
    cin.getline(nombreJugador, 30);

    do { /// MENU DEL JUEGO
        jugarDeNuevo;
        limpiarPantalla();
        cout << "===  JUEGO DEL AHORCADO ===\n";
        cout << "Jugador: " << nombreJugador << "\n";
        cout << "Selecciona la dificultad:\n";
        cout << "1. Facil   (8 intentos)\n";
        cout << "2. Medio   (6 intentos)\n";
        cout << "3. Dificil (4 intentos)\n";
        cout << " Opcion: ";
        int opcion;
        cin >> opcion;

        cin.ignore();

        int MAX_ERRORES;
        switch (opcion) {  ///MAXIMOS DE ERRORES  // ERROR 1 modificar y añadir case 2
            case 1: MAX_ERRORES = 8; break;
            case 2: MAX_ERRORES = 4; break;
            case 3: MAX_ERRORES = 6; break;
            default: goto jugarDeNuevo;
        }

        int indice = rand() % CANT_PALABRAS;
        char palabraSecreta[MAX_LONGITUD];
        strcpy(palabraSecreta, listaPalabras[indice]);
        int longitud = strlen(palabraSecreta);

        char progreso[MAX_LONGITUD];
        char intento[20];
        char letrasUsadas[26];
        int cantidadUsadas = 0;
        int errores = 0;
        bool ganado = false;

        for (int i = 0; i < longitud; i++)
            progreso[i] = (palabraSecreta[i] == ' ') ? ' ' : '_';
        progreso[longitud] = '\0';

        // ------------------- JUEGO -------------------
        while (errores < MAX_ERRORES && !ganado) {
            limpiarPantalla();
            cout << "===  AHORCADO ===\n";
            cout << "Jugador: " << nombreJugador << "\n";
            mostrarAhorcado(errores);

            cout << "\nFrase: " << progreso << endl;
            cout << "Intentos restantes: " << (MAX_ERRORES - errores) << endl;
            cout << "Puntaje actual: " << puntaje << endl;

            cout << "Letras usadas: ";
            if (cantidadUsadas == 0) cout << "(ninguna)";
            else for (int i = 0; i < cantidadUsadas; i++) cout << letrasUsadas[i] << " ";
            cout << "\n";

            cout << "\n Ingresa una letra o intenta adivinar la frase: ";
            ///cin.ignore(numeric_limits<streamsize>::max(), '\n');
            /// ERROR 2


            cin.getline(intento, 20);

            if (strcmp(intento, palabraSecreta) == 0) {
                strcpy(progreso, palabraSecreta);
                ganado = true;
                break;
            }

            if (strlen(intento) == 1) {
                char letra = intento[0];
                if (letraUsada(letra, letrasUsadas, cantidadUsadas)) {
                    cout << "\n Ya usaste la letra '" << letra << "'.";
                    cin.get();
                    continue;
                }

                letrasUsadas[cantidadUsadas] = letra;
                cantidadUsadas++;

                bool acierto = false;
                for (int i = 0; i < longitud; i++) {
                    if (palabraSecreta[i] == letra && progreso[i] == '_') {
                        progreso[i] = letra;
                        acierto = true;
                    }
                }

                if (!acierto) errores++;
                else puntaje += 2;
            } else {
                errores++;
                puntaje -= 1;
            }

            if (strcmp(progreso, palabraSecreta) == 0) ganado = true;
        }

        limpiarPantalla();
        mostrarAhorcado(errores);
        cout << "Jugador: " << nombreJugador << "\n";

        if (ganado) {
            cout << "\nFelicidades " << nombreJugador << "! Adivinaste: " << palabraSecreta << endl;
            puntaje += 10;
        } else {
            cout << "\n Lo siento " << nombreJugador << ". Te quedaste sin intentos.\n";
            cout << "La frase era: " << palabraSecreta << endl;
            puntaje -= 5;
        }

        cout << "\n Puntaje total de " << nombreJugador << ": " << puntaje << " puntos." << endl;

        actualizarRanking(rankingNombres, rankingPuntajes, nombreJugador, puntaje, totalJugadores);
        mostrarRanking(rankingNombres, rankingPuntajes, totalJugadores, nombreJugador);

        cout << "�Quieres jugar otra vez? (s/n): ";
        cin >> jugarDeNuevo;

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    limpiarPantalla();
    cout << "\n  Gracias por jugar al Ahorcado, " << nombreJugador << "!\n";
    cout << "Puntaje final: " << puntaje << " puntos.\n";
    mostrarRanking(rankingNombres, rankingPuntajes, totalJugadores, nombreJugador);
    cout << "�Hasta la pr�xima! \n";

    return 0;
}
