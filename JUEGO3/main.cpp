#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

const int MAX_JUGADORES = 10;
const int MAX_PALABRAS = 50;
const int MAX_LONG_PALABRA = 30;

struct Jugador {
    char nombre[30];
    char nivel[10];
    char palabras[MAX_PALABRAS][MAX_LONG_PALABRA];
    int cantidadPalabras;
    int tiempoLimite;
};

// === PROTOTIPOS ===
void quickSort(Jugador arr[], int izq, int der);
int particion(Jugador arr[], int izq, int der);
void mergeSort(char arr[][MAX_LONG_PALABRA], int izq, int der);
void merge(char arr[][MAX_LONG_PALABRA], int izq, int medio, int der);
int busquedaBinaria(char arr[][MAX_LONG_PALABRA], int izq, int der, const char buscada[]);

int main() {
    Jugador jugadores[MAX_JUGADORES];
    int numJugadores = 0;
    char opcion;

    do {
        system("cls");
        cout << "=== JUEGO DE MECANOGRAFIA ===\n\n";

        Jugador j;
        cout << "Ingrese su nombre: ";
        cin.getline(j.nombre, 30);

        int nivel;
        cout << "\nSeleccione nivel de dificultad:\n";
        cout << "1. Facil (20 segundos)\n";
        cout << "2. Medio (15 segundos)\n";
        cout << "3. Dificil (10 segundos)\n";
        cout << "Opcion: ";
        cin >> nivel;
        cin.ignore();

        switch (nivel) {
            case 1:
                strcpy(j.nivel, "Facil");
                j.tiempoLimite = 20;
                break;
            case 2:
                strcpy(j.nivel, "Medio");
                j.tiempoLimite = 15;
                break;
            case 3:
                strcpy(j.nivel, "Dificil");
                j.tiempoLimite = 10;
                break;
            default:
                strcpy(j.nivel, "Facil");
                j.tiempoLimite = 20;
                break;
        }

        cout << "\nTendra " << j.tiempoLimite << " segundos para escribir palabras.\n";
        cout << "Presione ENTER cuando este listo...";
        cin.get();

        time_t inicio = time(0);
        j.cantidadPalabras = 0;

        cout << "\n--- Empiece a escribir palabras ---\n";
        while (difftime(time(0), inicio) < j.tiempoLimite && j.cantidadPalabras < MAX_PALABRAS) {
            cout << "Palabra #" << j.cantidadPalabras + 1 << ": ";
            cin.getline(j.palabras[j.cantidadPalabras], MAX_LONG_PALABRA);
            if (strlen(j.palabras[j.cantidadPalabras]) > 0)
                j.cantidadPalabras++;
        }

        cout << "\n¡Tiempo terminado!\n";
        cout << "Usted escribio " << j.cantidadPalabras << " palabras.\n";

        jugadores[numJugadores++] = j;

        cout << "\n¿Desea jugar otra vez con otro jugador? (s/n): ";
        cin >> opcion;
        cin.ignore();

    } while ((opcion == 's' || opcion == 'S') && numJugadores < MAX_JUGADORES);

    // === RESULTADOS SIN ORDENAR ===
    system("cls");
    cout << "\n=== RESULTADOS ORIGINALES ===\n";
    for (int i = 0; i < numJugadores; i++) {
        cout << "\nJugador: " << jugadores[i].nombre;
        cout << "\nNivel: " << jugadores[i].nivel;
        cout << "\nPalabras escritas (" << jugadores[i].cantidadPalabras << "): ";
        for (int p = 0; p < jugadores[i].cantidadPalabras; p++)
            cout << jugadores[i].palabras[p] << " ";
        cout << "\n-----------------------------------\n";
    }

    // === ORDENAR JUGADORES POR PUNTOS (Quick Sort) ===
    quickSort(jugadores, 0, numJugadores - 1);

    cout << "\n=== JUGADORES ORDENADOS POR CANTIDAD DE PALABRAS (Quick Sort) ===\n";
    for (int i = 0; i < numJugadores; i++) {
        cout << jugadores[i].nombre << " - " << jugadores[i].cantidadPalabras << " palabras (" << jugadores[i].nivel << ")\n";
    }

    // === ORDENAR PALABRAS (Merge Sort) ===
    int idx;
    cout << "\nSeleccione el numero del jugador para ordenar sus palabras alfabéticamente (0-" << numJugadores - 1 << "): ";
    cin >> idx;
    cin.ignore();

    if (idx >= 0 && idx < numJugadores && jugadores[idx].cantidadPalabras > 0) {
        mergeSort(jugadores[idx].palabras, 0, jugadores[idx].cantidadPalabras - 1);

        cout << "\nPalabras ordenadas de " << jugadores[idx].nombre << ":\n";
        for (int i = 0; i < jugadores[idx].cantidadPalabras; i++)
            cout << jugadores[idx].palabras[i] << " ";
        cout << "\n";

        // === BUSQUEDA BINARIA ===
        char palabraBuscada[MAX_LONG_PALABRA];
        cout << "\nIngrese palabra a buscar en la lista: ";
        cin.getline(palabraBuscada, MAX_LONG_PALABRA);

        int pos = busquedaBinaria(jugadores[idx].palabras, 0, jugadores[idx].cantidadPalabras - 1, palabraBuscada);
        if (pos != -1)
            cout << "Palabra encontrada en la posicion " << pos + 1 << "!\n";
        else
            cout << "Palabra NO encontrada.\n";
    }

    cout << "\nGracias por jugar.\n";
    return 0;
}

// === FUNCIONES RECURSIVAS ===

// Quick Sort (ordenar por cantidadPalabras)
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
        if (arr[j].cantidadPalabras > pivote) { // orden descendente
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

// Merge Sort (ordenar palabras alfabéticamente)
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

// Búsqueda binaria recursiva
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
