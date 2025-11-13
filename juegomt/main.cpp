#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <windows.h> // Para colores en consola (solo Windows)
using namespace std;

const int MAX_JUGADORES = 10;
const int MAX_PALABRAS = 50;
const int MAX_LONG_PALABRA = 30;

// ------------------------- ESTRUCTURA DEL JUGADOR -------------------------
struct Jugador {
    char nombre[30];
    char nivel[10];
    char palabras[MAX_PALABRAS][MAX_LONG_PALABRA];
    int cantidadPalabras;
    int puntaje;
    int tiempoLimite;

    int puntos;
    int correctas;
    int incorrectas;
    double precision;
    char listaCorrectas[100][30];
    char listaIncorrectas[100][30];
};

// === PROTOTIPOS ===
int cargarPalabrasPorNivel(const char* nombreArchivo, int nivelDeseado, char palabras[][30], int maxPalabras);
void quickSort(Jugador arr[], int izq, int der);
int particion(Jugador arr[], int izq, int der);
void mergeSort(char arr[][MAX_LONG_PALABRA], int izq, int der);
void merge(char arr[][MAX_LONG_PALABRA], int izq, int medio, int der);
int busquedaBinaria(char arr[][MAX_LONG_PALABRA], int izq, int der, const char buscada[]);
void setColor(int color);
void guardarResultado(const Jugador& j);
void mostrarResumen(const Jugador& j);


// === FUNCIONES ===

// Cambia el color del texto en consola
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int cargarPalabrasPorNivel(const char* nombreArchivo, int nivelDeseado, char palabras[][30], int maxPalabras) {
    ifstream archivo(nombreArchivo);
    int nivel;
    char palabra[30];
    int contador = 0;
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo.\n";
        return 0;
    }
    while (archivo >> nivel >> palabra) {
        if (nivel == nivelDeseado && contador < maxPalabras) {
            strcpy(palabras[contador], palabra);
            contador++;
        }
    }
    archivo.close();
    return contador;
}

void quickSort(Jugador arr[], int izq, int der) {
    if (izq < der) {
        int pivote = particion(arr, izq, der);
        quickSort(arr, izq, pivote - 1);
        quickSort(arr, pivote + 1, der);
    }
}

int particion(Jugador arr[], int izq, int der) {
    int pivote = arr[der].cantidadPalabras;
    int i = izq - 1;
    for (int j = izq; j < der; j++) {
        if (arr[j].cantidadPalabras > pivote) {
            i++;
            Jugador temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Jugador temp = arr[i + 1];
    arr[i + 1] = arr[der];
    arr[der] = temp;
    return i + 1;
}

void mergeSort(char arr[][MAX_LONG_PALABRA], int izq, int der) {
    if (izq < der) {
        int medio = (izq + der) / 2;
        mergeSort(arr, izq, medio);
        mergeSort(arr, medio + 1, der);
        merge(arr, izq, medio, der);
    }
}

void merge(char arr[][MAX_LONG_PALABRA], int izq, int medio, int der) {
    char temp[MAX_PALABRAS][MAX_LONG_PALABRA];
    int i = izq, j = medio + 1, k = 0;

    while (i <= medio && j <= der) {
        if (strcmp(arr[i], arr[j]) <= 0) {
            strcpy(temp[k++], arr[i++]);
        } else {
            strcpy(temp[k++], arr[j++]);
        }
    }

    while (i <= medio) strcpy(temp[k++], arr[i++]);
    while (j <= der) strcpy(temp[k++], arr[j++]);

    for (int m = 0; m < k; m++)
        strcpy(arr[izq + m], temp[m]);
}

int busquedaBinaria(char arr[][MAX_LONG_PALABRA], int izq, int der, const char buscada[]) {
    if (izq > der) return -1;
    int medio = (izq + der) / 2;
    int cmp = strcmp(arr[medio], buscada);
    if (cmp == 0)
        return medio;
    else if (cmp > 0)
        return busquedaBinaria(arr, izq, medio - 1, buscada);
    else
        return busquedaBinaria(arr, medio + 1, der, buscada);
}

// --- NUEVAS FUNCIONES ---

void guardarResultado(const Jugador& j) {
    ofstream archivo("resultados.txt", ios::app);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo de resultados.\n";
        return;
    }
    archivo << "Jugador: " << j.nombre
            << " | Nivel: " << j.nivel
            << " | Puntos: " << j.puntos
            << " | Correctas: " << j.correctas
            << " | Incorrectas: " << j.incorrectas
            << " | Precision: " << j.precision << "%\n";
    archivo.close();
}

void mostrarResumen(const Jugador& j) {
    setColor(14);
    cout << "\n=== RESUMEN DE " << j.nombre << " ===\n";
    setColor(7);
    cout << "Nivel: " << j.nivel << endl;
    cout << "Puntos: " << j.puntos << endl;
    cout << "Correctas: " << j.correctas << endl;
    cout << "Incorrectas: " << j.incorrectas << endl;
    cout << "Precision: " << j.precision << "%\n";

    setColor(10);
    cout << "\nPalabras Correctas (" << j.correctas << "): ";
    for (int i = 0; i < j.correctas; i++)
        cout << j.listaCorrectas[i] << " ";
    setColor(12);
    cout << "\n\nPalabras Incorrectas (" << j.incorrectas << "): ";
    for (int i = 0; i < j.incorrectas; i++)
        cout << j.listaIncorrectas[i] << " ";
    setColor(7);
    cout << "\n";
}

void mostrarCronometro(int segundosRestantes) {
    setColor(14);
    cout << "\rTiempo restante: " << segundosRestantes << "s   " << flush;
    setColor(7);
}

// === MAIN ===
int main() {
    Jugador jugadores[MAX_JUGADORES];
    int numJugadores = 0;
    char opcion;

    do {
        srand(time(0));
        Jugador j = {};
        j.cantidadPalabras = 0;
        j.puntaje = j.puntos = j.correctas = j.incorrectas = 0;

        cout << "=== JUEGO DE MECANOGRAFIA ===\n\n";
        cout << "Ingrese su nombre: ";
        cin.getline(j.nombre, 30);

        int nivel;
        cout << "\nSeleccione nivel de dificultad:\n";
        cout << "1) Facil (20s)\n2) Medio (15s)\n3) Dificil (10s)\nOpcion: ";
        cin >> nivel;
        cin.ignore();

        switch (nivel) {
            case 1: strcpy(j.nivel, "facil"); j.tiempoLimite = 20; break;
            case 2: strcpy(j.nivel, "medio"); j.tiempoLimite = 15; break;
            case 3: strcpy(j.nivel, "dificil"); j.tiempoLimite = 10; break;
            default: strcpy(j.nivel, "facil"); j.tiempoLimite = 20; break;
        }

        const int MAX_PALABRAS = 100;
        char palabras[MAX_PALABRAS][30];
        int total = cargarPalabrasPorNivel("palabras.txt", nivel, palabras, MAX_PALABRAS);
        if (total == 0) {
            cout << "\nNo hay palabras para este nivel.\n";
            return 0;
        }

        cout << "\nTendra " << j.tiempoLimite << " segundos para escribir las palabras.\n";
        cout << "Presione ENTER para iniciar...";
        cin.get();
        system("cls");

        cout << "--- Empieza ---\n";
        time_t inicio = time(0);
        char respuesta[30];
        int totalPalabras = 0;

        while (difftime(time(0), inicio) < j.tiempoLimite) {
            int indice = rand() % total;
            char palabraActual[30];
            strcpy(palabraActual, palabras[indice]);

            cout << "\nPalabra #" << totalPalabras + 1 << ": " << palabraActual << endl;
            cout << "Escribela: ";
            cin.getline(respuesta, 30);

            if (difftime(time(0), inicio) >= j.tiempoLimite)
                break;

            if (strcmp(respuesta, palabraActual) == 0) {
                setColor(10);
                cout << "Correcto!\n";
                j.puntaje += 10;
                j.puntos += 10;
                strcpy(j.listaCorrectas[j.correctas++], palabraActual);
            } else {
                setColor(12);
                cout << "Incorrecto. Era: " << palabraActual << endl;
                j.puntaje -= 3;
                if (j.puntos > 0) j.puntos -= 5;
                strcpy(j.listaIncorrectas[j.incorrectas++], palabraActual);
            }
            setColor(7);
            strcpy(j.palabras[j.cantidadPalabras++], respuesta);
            totalPalabras++;
        }

        int totalIntentos = j.correctas + j.incorrectas;
        j.precision = totalIntentos > 0 ? (double)j.correctas / totalIntentos * 100.0 : 0;

        cout << "\n=== FIN DEL RETO ===\n";
        cout << "Puntaje final de " << j.nombre << ": " << j.puntaje << " puntos\n";
        mostrarResumen(j);
        guardarResultado(j);

        jugadores[numJugadores++] = j;

        cout << "\n¿Desea jugar otra vez con otro jugador? (s/n): ";
        cin >> opcion;
        cin.ignore();
        system("cls");

    } while ((opcion == 's' || opcion == 'S') && numJugadores < MAX_JUGADORES);

    // --- RESULTADOS ORIGINALES + ORDENADOS ---
    cout << "\n=== RESULTADOS ORIGINALES ===\n";
    for (int i = 0; i < numJugadores; i++) {
        cout << "\nJugador: " << jugadores[i].nombre;
        cout << " | Palabras escritas: " << jugadores[i].cantidadPalabras;
        cout << " | Puntos: " << jugadores[i].puntos << endl;
    }

    quickSort(jugadores, 0, numJugadores - 1);

    cout << "\n=== JUGADORES ORDENADOS POR CANTIDAD DE PALABRAS ===\n";
    for (int i = 0; i < numJugadores; i++)
        cout << jugadores[i].nombre << " - " << jugadores[i].cantidadPalabras << " palabras (" << jugadores[i].nivel << ")\n";

    cout << "\nGracias por jugar.\n";
    return 0;
}
