//Alexander Uriona Zurita
//Mateo Andrew Rojas Vargas
//Keily Sanchez LLanque
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <fstream>
using namespace std;

// ------------------- FUNCIONES AUXILIARES -------------------
/*Limpia la pantalla de la consola según el sistema operativo detectado*/
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*La función recibe un numero de error dado, y dependiendo de que número de error recibe, compara con los casos dados
  dentro del switch e imprime una parte del cuerpo del ahorcado*/
void mostrarAhorcado(int errores) {
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

/*
  Función letraUsada
  Verifica si una letra ya ha sido utilizada por el jugador.
  letra = la letra que se quiere comprobar.
  usadas[] = arreglo que contiene las letras que ya se usaron.
  cantidad = cantidad actual de letras registradas en el arreglo.
  Retorna: true si la letra ya fue usada, false en caso contrario.
*/
bool letraUsada(char letra, char usadas[], int cantidad) {
    for (int i = 0; i < cantidad; i++)
        if (usadas[i] == letra) return true;
    return false;
}

/* Función: ordenarRanking
Ordena los puntajes de los jugadores de forma descendente
utilizando el algoritmo de ordenamiento burbuja (bubble sort).
A la vez intercambia los nombres*/
void ordenarRanking(char nombres[][30], int puntajes[], int totalJugadores) {
    for (int i = 0; i < totalJugadores - 1; i++) {
        for (int j = 0; j < totalJugadores - i - 1; j++) {
            if (puntajes[j] < puntajes[j + 1]) {
                int tempP = puntajes[j];
                puntajes[j] = puntajes[j + 1];
                puntajes[j + 1] = tempP;

                char tempN[30];
                strcpy(tempN, nombres[j]);
                strcpy(nombres[j], nombres[j + 1]);
                strcpy(nombres[j + 1], tempN);
            }
        }
    }
}

/*Función: actualizarRanking
  Añade o actualiza el puntaje del jugador actual en el ranking.*/
void actualizarRanking(char nombres[][30], int puntajes[], char nombre[], int puntaje, int &totalJugadores) {
    bool existe = false;
    for (int i = 0; i < totalJugadores; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            if (puntaje > puntajes[i]) puntajes[i] = puntaje;
            existe = true;
            break;
        }
    }
    if (!existe) {
        strcpy(nombres[totalJugadores], nombre);
        puntajes[totalJugadores] = puntaje;
        totalJugadores++;
    }
    ordenarRanking(nombres, puntajes, totalJugadores);
}

/* Función: mostrarRanking
Muestra la tabla de posiciones con los puntajes de todos los jugadores.*/
void mostrarRanking(char nombres[][30], int puntajes[], int totalJugadores, char jugadorActual[]) {
    cout << "\n RANKING DE JUGADORES:\n";
    for (int i = 0; i < totalJugadores; i++) {
        if (strcmp(nombres[i], jugadorActual) == 0) {
            cout << "\033[1;32m" << i + 1 << ". " << nombres[i] << " - " << puntajes[i] << " puntos" << "\033[0m\n";
        } else {
            cout << i + 1 << ". " << nombres[i] << " - " << puntajes[i] << " puntos\n";
        }
    }
    cout << endl;
}

void cargarpuntaje(int puntaje, const char nombreJugador[30]) {
    ofstream archivo("datos.txt", ios::app);
    if (archivo.is_open()) {
        archivo << nombreJugador << " " << puntaje << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para guardar.\n";
    }
}

void mostrarpuntajes() {
    string linea;
    ifstream archivo("datos.txt", ios::in);
    if (archivo.fail()) {
        cout << "No se encontro el archivo.\n";
        return;
    }
    cout << "\n=== HISTORIAL DE PUNTAJES ===\n";
    while (getline(archivo, linea))
        cout << linea << endl;
    archivo.close();
}

/* se limpian las posiciones vacías para evitar basura*/
void extraerFrases(int MAX_LONGITUD, int CANT_PALABRAS, char matriz[][60]) {
    ifstream archivo("palabras.txt");
    if (archivo.is_open()) {
        string linea;
        int i = 0;
        while (getline(archivo, linea) && i < CANT_PALABRAS) {
            strncpy(matriz[i], linea.c_str(), MAX_LONGITUD - 1);
            matriz[i][MAX_LONGITUD - 1] = '\0';
            i++;
        }
        archivo.close();

        // Limpia las filas que no se usen (evita caracteres basura)
        for (int j = i; j < CANT_PALABRAS; j++) {
            matriz[j][0] = '\0';
        }
    } else {
        cout << "No se pudo abrir el archivo palabras.txt\n";
    }
}

/*permite al usuario cargar frases al archivo palabras.txt */
void cargarFrasesAlArchivo() {
    ofstream archivo("palabras.txt", ios::app);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo palabras.txt\n";
        system("pause");
        return;
    }

    string frase;
    char opcion;
    do {
        limpiarPantalla();
        cout << "=== CARGAR NUEVAS FRASES ===\n";
        cout << "Escribe una palabra o frase: ";
        cin.ignore();
        getline(cin, frase);
        archivo << frase << endl;
        cout << "Frase guardada.\n";
        cout << "¿Deseas ingresar otra? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    archivo.close();
    cout << "Frases guardadas correctamente.\n";
    system("pause");
}

// ------------------- JUEGO DEL AHORCADO -------------------
void jugarAhorcado() {
    int opcionSubmenu;
    do {
        limpiarPantalla();
        cout << "=== SUBMENU AHORCADO ===\n";
        cout << "1. Jugar\n";
        cout << "2. Cargar frases al archivo\n";
        cout << "3. Volver al menu principal\n";
        cout << "Elige una opcion: ";
        cin >> opcionSubmenu;

        if (opcionSubmenu == 2) {
            cargarFrasesAlArchivo();
        } else if (opcionSubmenu == 1) {

            const int MAX_LONGITUD = 60;
            const int CANT_PALABRAS = 20;
            char listaPalabras[CANT_PALABRAS][MAX_LONGITUD];
            srand(time(0));
            char jugarDeNuevo;
            char nombreJugador[30];

            extraerFrases(MAX_LONGITUD, CANT_PALABRAS, listaPalabras);

            // Verificación si no se cargó nada, evitar error
            if (strlen(listaPalabras[0]) == 0) {
                cout << " No se cargaron palabras. Verifica el archivo palabras.txt\n";
                system("pause");
                return;
            }

            char rankingNombres[50][30];
            int rankingPuntajes[50];
            int totalJugadores = 0;

            int puntaje = 0;
            limpiarPantalla();
            cout << "Bienvenido al Ahorcado!\n";
            cout << "Ingresa tu nombre: ";
            cin.ignore();
            cin.getline(nombreJugador, 30);

            do {
                limpiarPantalla();
            denuevo:
                cout << "===  JUEGO DEL AHORCADO ===\n";
                cout << "Jugador: " << nombreJugador << "\n";
                cout << "Selecciona la dificultad:\n";
                cout << "1. Facil (8 intentos)\n";
                cout << "2. Medio (6 intentos)\n";
                cout << "3. Dificil (4 intentos)\n";
                cout << "Opcion: ";
                int opcion;
                cin >> opcion;
                cin.ignore();

                int MAX_ERRORES;
                switch (opcion) {
                    case 1: MAX_ERRORES = 8; break;
                    case 2: MAX_ERRORES = 6; break;
                    case 3: MAX_ERRORES = 4; break;
                    default: goto denuevo;
                }

                // Seleccionar aleatoriamente una palabra secreta
                int indice = rand() % CANT_PALABRAS;

                // Evita seleccionar palabra vacía
                while (strlen(listaPalabras[indice]) == 0) {
                    indice = rand() % CANT_PALABRAS;
                }

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

                    cout << "\nIngresa una letra o intenta adivinar la frase: ";
                    cin.getline(intento, 20);

                    if (strcmp(intento, palabraSecreta) == 0) {
                        strcpy(progreso, palabraSecreta);
                        ganado = true;
                        break;
                    }

                    if (strlen(intento) == 1) {
                        char letra = intento[0];
                        if (letraUsada(letra, letrasUsadas, cantidadUsadas)) continue;

                        letrasUsadas[cantidadUsadas++] = letra;
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
                    cout << "\nLo siento " << nombreJugador << ". Te quedaste sin intentos.\n";
                    cout << "La frase era: " << palabraSecreta << endl;
                    puntaje -= 5;
                }

                cout << "\nPuntaje total: " << puntaje << " puntos.\n";
                actualizarRanking(rankingNombres, rankingPuntajes, nombreJugador, puntaje, totalJugadores);
                mostrarRanking(rankingNombres, rankingPuntajes, totalJugadores, nombreJugador);

                cout << "¿Quieres jugar otra vez? (s/n): ";
                cin >> jugarDeNuevo;

            } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

            cargarpuntaje(puntaje, nombreJugador);
            mostrarpuntajes();
        }

    } while (opcionSubmenu != 3);
}

// ------------------- MENÚ PRINCIPAL -------------------
int main() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "=============================\n";
        cout << "     MENU PRINCIPAL          \n";
        cout << "=============================\n";
        cout << "1. Jugar Ahorcado\n";
        cout << "2. Juego 2 \n";
        cout << "3. Juego 3 \n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugarAhorcado();
                break;
            case 2:
                cout << "Juego 2 \n";
                system("pause");
                break;
            case 3:
                cout << "Juego 3 \n";
                system("pause");
                break;
            case 4:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
                system("pause");
        }
    } while (opcion != 4);

    return 0;
}



