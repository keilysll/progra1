// === Juego de Mecanografía ===
// Versión básica con arreglos de char para palabras correctas e incorrectas

#include <iostream>     // Para entrada y salida estándar (cin, cout)
#include <fstream>      // Para manejo de archivos (ifstream, ofstream)
#include <ctime>        // Para obtener la hora del sistema (time)
#include <cstring>      // Para funciones de manipulación de cadenas (strcpy, strcmp, strlen)
#include <cstdlib>      // Para funciones generales (rand, srand)
#include <conio.h>      // Para _kbhit() y _getch(), captura de teclas sin esperar enter
#include <windows.h>    // Para cambiar colores de texto en consola
using namespace std;    // Evita tener que escribir std:: antes de cada objeto o función

// --- Constantes ---
const int MAX_PALABRAS = 50;       // Máximo número de palabras que puede almacenar un jugador
const int MAX_LONG_PALABRA = 30;   // Máximo número de caracteres por palabra

// --- Estructura para almacenar los datos de un jugador ---
struct Jugador {
    char nombre[30];                               // Nombre del jugador
    char nivel[10];                                // Nivel de dificultad seleccionado
    int tiempoLimite;                              // Tiempo límite para jugar (en segundos)
    int puntos;                                    // Puntos obtenidos en el juego
    int correctas;                                 // Cantidad de palabras correctamente escritas
    int incorrectas;                               // Cantidad de palabras incorrectas
    double precision;                              // Porcentaje de precisión (correctas / total * 100)
    char listaCorrectas[MAX_PALABRAS][MAX_LONG_PALABRA];   // Arreglo que guarda palabras correctas
    char listaIncorrectas[MAX_PALABRAS][MAX_LONG_PALABRA]; // Arreglo que guarda palabras incorrectas
};

// --- Prototipos de funciones ---
// Permiten que las funciones se usen antes de ser declaradas completamente
void cargarPalabras(char palabras[][MAX_LONG_PALABRA], int &numPalabras, const char* nombreArchivo);
void jugar(Jugador& j, char palabras[][MAX_LONG_PALABRA], int numPalabras);
void guardarResultado(const Jugador& j);
void mostrarResumen(const Jugador& j);
void setColor(int color);
void mostrarCronometro(int segundosRestantes);

// === Función principal ===
int main() {
    srand(time(0)); // Inicializa la semilla del generador de números aleatorios usando la hora actual

    char opcion; // Variable para almacenar la opción de repetir el juego
    do {
        system("cls"); // Limpia la pantalla de la consola
        cout << "=== JUEGO DE MECANOGRAFIA ===\n\n";

        Jugador j; // Crea un objeto Jugador
        cout << "Ingrese su nombre: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracteres pendientes en el buffer
        cin.getline(j.nombre, 30); // Lee el nombre del jugador (máximo 30 caracteres)

        int nivel; // Variable para almacenar la opción de nivel
        cout << "\nSeleccione nivel de dificultad:\n";
        cout << "1. Facil (20 segundos)\n";
        cout << "2. Medio (15 segundos)\n";
        cout << "3. Dificil (10 segundos)\n";
        cout << "Opcion: ";
        cin >> nivel; // Lee la opción de nivel
        cin.ignore();  // Limpia buffer después de cin

        // --- Cargar palabras desde archivo según nivel ---
        char palabras[MAX_PALABRAS][MAX_LONG_PALABRA]; // Arreglo que guardará las palabras del nivel
        int numPalabras = 0; // Número de palabras cargadas

        switch (nivel) { // Selecciona el archivo según el nivel
            case 1:
                strcpy(j.nivel, "Facil"); // Guarda el nivel como texto
                j.tiempoLimite = 20;      // Tiempo límite en segundos
                cargarPalabras(palabras, numPalabras, "facil.txt"); // Carga palabras del archivo
                break;
            case 2:
                strcpy(j.nivel, "Medio");
                j.tiempoLimite = 15;
                cargarPalabras(palabras, numPalabras, "medio.txt");
                break;
            case 3:
                strcpy(j.nivel, "Dificil");
                j.tiempoLimite = 10;
                cargarPalabras(palabras, numPalabras, "dificil.txt");
                break;
            default:
                strcpy(j.nivel, "Facil");
                j.tiempoLimite = 20;
                cargarPalabras(palabras, numPalabras, "facil.txt");
                break;
        }

        // Verifica que se cargaron palabras
        if (numPalabras == 0) {
            cout << "\nNo se pudieron cargar las palabras. Asegúrese de tener los archivos facil.txt, medio.txt y dificil.txt\n";
            system("pause"); // Pausa hasta que el usuario presione una tecla
            return 0; // Termina el programa si no hay palabras
        }

        // --- Jugar ---
        jugar(j, palabras, numPalabras); // Ejecuta la función principal del juego

        // --- Guardar resultados en archivo ---
        guardarResultado(j); // Guarda los resultados del jugador en "resultados.txt"

        // --- Mostrar resumen en pantalla ---
        mostrarResumen(j); // Muestra los resultados detallados del jugador

        // --- Preguntar si desea jugar otra vez ---
        cout << "\n¿Desea jugar otra vez? (s/n): ";
        cin >> opcion; // Lee la respuesta
        cin.ignore();  // Limpia buffer
    } while (opcion == 's' || opcion == 'S'); // Repite si el usuario ingresa 's' o 'S'

    cout << "\nGracias por jugar. ¡Hasta pronto!\n";
    return 0; // Termina el programa
}

// === FUNCIONES ===

// Función para cargar palabras desde un archivo
void cargarPalabras(char palabras[][MAX_LONG_PALABRA], int &numPalabras, const char* nombreArchivo) {
    ifstream archivo(nombreArchivo); // Abre el archivo en modo lectura
    string linea;                    // Variable temporal para leer cada línea
    numPalabras = 0;                 // Inicializa contador
    while (getline(archivo, linea) && numPalabras < MAX_PALABRAS) { // Lee cada línea
        if (!linea.empty()) {        // Ignora líneas vacías
            strncpy(palabras[numPalabras], linea.c_str(), MAX_LONG_PALABRA - 1); // Copia la palabra al arreglo
            palabras[numPalabras][MAX_LONG_PALABRA - 1] = '\0'; // Asegura terminador nulo
            numPalabras++;            // Incrementa contador
        }
    }
    archivo.close(); // Cierra el archivo
}

// Función para cambiar el color del texto en consola
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); // Cambia color del texto
}

// Función para mostrar cronómetro en vivo
void mostrarCronometro(int segundosRestantes) {
    setColor(14); // Amarillo
    cout << "\rTiempo restante: " << segundosRestantes << "s   " << flush; // \r sobreescribe la misma línea
    setColor(7); // Vuelve al color por defecto
}

// Función principal del juego
void jugar(Jugador& j, char palabras[][MAX_LONG_PALABRA], int numPalabras) {
    // Inicializar estadísticas
    j.puntos = 0;
    j.correctas = 0;
    j.incorrectas = 0;

    cout << "\nPresione ENTER para comenzar...";
    cin.get(); // Espera que el jugador presione ENTER

    time_t inicio = time(0); // Marca el inicio del juego
    cout << "\n--- COMIENZA EL JUEGO ---\n";

    // Bucle principal: se ejecuta mientras no se acabe el tiempo
    while (difftime(time(0), inicio) < j.tiempoLimite) {
        int idx = rand() % numPalabras;             // Selecciona una palabra aleatoria
        char original[MAX_LONG_PALABRA];
        strcpy(original, palabras[idx]);            // Copia palabra original
        char entrada[MAX_LONG_PALABRA] = "";        // Almacena lo que el jugador escribe

        cout << "\nPalabra: ";
        setColor(11); // Azul claro
        cout << original << endl; // Muestra palabra a teclear
        setColor(7); // Color por defecto
        cout << "Teclee: ";

        bool finPalabra = false; // Marca si el jugador terminó la palabra

        // Bucle para capturar la palabra mientras no termine el tiempo
        while (!finPalabra && difftime(time(0), inicio) < j.tiempoLimite) {
            int tiempoRestante = j.tiempoLimite - (int)difftime(time(0), inicio);
            mostrarCronometro(tiempoRestante); // Muestra cronómetro en vivo

            if (_kbhit()) { // Si el jugador presionó una tecla
                char c = _getch(); // Captura tecla sin mostrarla automáticamente

                if (c == '\r') { // Enter -> termina la palabra
                    cout << endl;
                    finPalabra = true;
                }
                else if (c == '\b' && strlen(entrada) > 0) { // Backspace
                    entrada[strlen(entrada) - 1] = '\0'; // Elimina último carácter
                    cout << "\b \b"; // Borra visualmente
                }
                else if (isprint(c) && strlen(entrada) < MAX_LONG_PALABRA - 1) { // Carácter imprimible
                    int len = strlen(entrada);
                    entrada[len] = c; // Añade letra a entrada
                    entrada[len + 1] = '\0';
                    cout << c; // Muestra letra
                }
            }
        }

        if (difftime(time(0), inicio) >= j.tiempoLimite) // Si se acabó el tiempo, sale del bucle
            break;

        // --- Evaluar palabra ---
        if (strcmp(entrada, original) == 0) { // Correcta
            setColor(10); // Verde
            cout << "Correcto!\n";
            j.puntos += 10; // Suma puntos
            j.correctas++;  // Incrementa contador de correctas
            strcpy(j.listaCorrectas[j.correctas - 1], entrada); // Guarda palabra correcta
        } else { // Incorrecta
            setColor(12); // Rojo
            cout << "Error! La palabra era: " << original << endl;
            j.puntos -= 5; // Resta puntos
            j.incorrectas++; // Incrementa contador de incorrectas
            strcpy(j.listaIncorrectas[j.incorrectas - 1], original); // Guarda palabra incorrecta
        }
        setColor(7); // Color por defecto
    }

    // Calcula precisión total
    int total = j.correctas + j.incorrectas;
    j.precision = total > 0 ? (double)j.correctas / total * 100.0 : 0.0;
}

// Función para guardar resultados en archivo
void guardarResultado(const Jugador& j) {
    ofstream archivo("resultados.txt", ios::app); // Abre archivo en modo append
    archivo << "Jugador: " << j.nombre
            << " | Nivel: " << j.nivel
            << " | Puntos: " << j.puntos
            << " | Correctas: " << j.correctas
            << " | Incorrectas: " << j.incorrectas
            << " | Precision: " << j.precision << "%\n"; // Escribe resultados
    archivo.close(); // Cierra archivo
}

// Función para mostrar resumen completo en pantalla
void mostrarResumen(const Jugador& j) {
    setColor(14); // Amarillo
    cout << "\n=== RESULTADOS ===\n";
    setColor(7); // Color por defecto

    cout << "Jugador: " << j.nombre << endl;
    cout << "Nivel: " << j.nivel << endl;
    cout << "Puntos: " << j.puntos << endl;
    cout << "Correctas: " << j.correctas << endl;
    cout << "Incorrectas: " << j.incorrectas << endl;
    cout << "Precision: " << j.precision << "%\n";

    // Mostrar palabras correctas
    cout << "\nPalabras Correctas (" << j.correctas << "): ";
    setColor(10); // Verde
    for (int i = 0; i < j.correctas; i++)
        cout << j.listaCorrectas[i] << " "; // Muestra cada palabra correcta
    setColor(7);

    // Mostrar palabras incorrectas
    cout << "\n\nPalabras Incorrectas (" << j.incorrectas << "): ";
    setColor(12); // Rojo
    for (int i = 0; i < j.incorrectas; i++)
        cout << j.listaIncorrectas[i] << " "; // Muestra cada palabra incorrecta
    setColor(7);

    cout << "\n"; // Salto de línea final
}
