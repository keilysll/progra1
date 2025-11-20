// JUEGO 2
#include <iostream>     // para entrada y salida estándar (cout, cin)
#include <fstream>      // para manejo de archivos (ifstream, ofstream)
#include <cstdlib>      // para funciones generales (rand, srand)
#include <windows.h>    // para características de Windows (opcional)
#include <ctime>        // para manejo de tiempo (time)
#include <cstring>      // para funciones de cadenas C (strcmp, strcpy)
using namespace std;
// ESTRUCTURA DEL JUGADOR  Guarda el nombre y los puntos acumulados del jugador.
struct Jugador {
    char nombre[50];
    int puntos;
};
// CARGAR ARCHIVO: lee jugadores existentes y devuelve cuántos hay
int cargarArchivo(Jugador lista[]) {
    ifstream archivo("datos_juego2.txt");   // abre el archivo en modo lectura
    int i = 0;                              // contador de jugadores encontrados

    if (archivo.is_open()) {                // verifica que el archivo existe
        // lee línea por línea: nombre y puntos
        while (archivo >> lista[i].nombre >> lista[i].puntos) {
            i++;                            // avanza al siguiente jugador
        }
    }
    return i; // retorna la cantidad total de registros leídos
}
// ORDENAR JUGADORES: ordena por puntos de mayor a menor (bubble sort)
// ---------------------------------------------------------------------------
// Ordena un arreglo de jugadores de mayor a menor puntaje usando el método burbuja
void ordenarJugadores(Jugador arr[], int n) {

    // Ciclo externo: controla cuántas pasadas se hacen sobre el arreglo
    // Después de cada pasada, el valor más grande entre los no ordenados
    // queda colocado en su posición correcta.
    for (int i = 0; i < n - 1; i++) {

        // Ciclo interno: compara elementos adyacentes
        // Recorre hasta porque los últimos ya están ordenados.
        for (int j = 0; j < n - 1; j++) {

            // Si el jugador en la posición j tiene menos puntos
            // que el jugador en la posición j+1, deben intercambiarse
            // para que los puntajes queden ordenados de mayor a menor.
            if (arr[j].puntos < arr[j + 1].puntos) {

                // Se utiliza una variable temporal para realizar el intercambio
                Jugador temp = arr[j];  // guarda el jugador actual
                arr[j] = arr[j + 1];    // pasa el jugador siguiente a la posición actual
                arr[j + 1] = temp;      // coloca el jugador guardado en la siguiente posición
            }
        }
    }
}

// GUARDAR ARCHIVO: sobrescribe el archivo ordenado
// ---------------------------------------------------------------------------
void guardarArchivo(Jugador arr[], int n) {
    ordenarJugadores(arr, n);                   // ordena antes de guardar
    ofstream archivo("datos_juego2.txt");       // abre archivo en modo escritura

    // guarda cada jugador en formato "nombre puntos"
    for (int i = 0; i < n; i++)
        archivo << arr[i].nombre << " " << arr[i].puntos << "\n";

    archivo.close();                            // cierra el archivo
}
// BUSCAR JUGADOR: devuelve índice del jugador o -1 si no existe
// ---------------------------------------------------------------------------
int buscarJugador(Jugador lista[], int total, char nombre[]) {
    for (int i = 0; i < total; i++)
        if (strcmp(lista[i].nombre, nombre) == 0) // compara cadenas
            return i;                             // encontrado

    return -1; // no existe
}
// ACTUALIZAR JUGADOR: reescribe el archivo con un jugador actualizado
// ---------------------------------------------------------------------------
void actualizarJugador(const Jugador &j) {

    // Abre el archivo original donde están guardados todos los jugadores
    ifstream archivoIn("datos_juego2.txt");

    // Crea un archivo temporal donde se guardarán los datos actualizados
    ofstream archivoOut("temp.txt");

    Jugador temp;           // Variable auxiliar para leer jugador por jugador del archivo
    bool actualizado = false;   // Bandera para saber si el jugador ya existía en el archivo

    // Lee cada jugador guardado en el archivo original
    while (archivoIn >> temp.nombre >> temp.puntos) {

        // Compara si el jugador leído es el mismo que queremos actualizar
        if (strcmp(temp.nombre, j.nombre) == 0) {

            // Si es el jugador buscado, escribe su nombre y SUS NUEVOS PUNTOS
            archivoOut << j.nombre << " " << j.puntos << endl;

            // Marca que ya fue actualizado para no agregarlo dos veces
            actualizado = true;

        } else {
            // Si no es el jugador buscado, simplemente copia sus datos tal cual
            archivoOut << temp.nombre << " " << temp.puntos << endl;
        }
    }

    // Si el jugador NO se encontró en el archivo original, se agrega nuevo
    if (!actualizado)
        archivoOut << j.nombre << " " << j.puntos << endl;

    // Cierra ambos archivos antes de reemplazar
    archivoIn.close();
    archivoOut.close();

    // Elimina el archivo viejo de jugadores
    remove("datos_juego2.txt");

    // Renombra el archivo temporal como archivo definitivo
    rename("temp.txt", "datos_juego2.txt");
}

// FUNCIONES RECURSIVAS
// ---------------------------------------------------------------------------
// Multiplicación por sumas sucesivas
int multiplicarRec(int a, int b) {
    if (b == 0) return 0;                 // caso base:
                                          // Si el multiplicador b es 0, el resultado de a*0 es 0.
    if (b > 0) return a + multiplicarRec(a, b - 1);
                                          // Caso recursivo para b positivo:
                                          // Se suma 'a' y se llama recursivamente con b-1.
                                          // Matemáticamente: a*b = a + a*(b-1).
                                          // Cada llamada reduce b en 1 acercándose al caso base.
    return -multiplicarRec(a, -b);        // Manejo de b negativo:
                                          // multiplicador positivo (-b) y luego negamos el resultado.
                                          // Esto implementa la regla a * (-b) = -(a * b).
}

// División como restas sucesivas
int dividirRec(int a, int b) {
    if (b == 0) return 0;                 // protección contra división por cero:
                                          // Aquí simplemente devuelve 0 para evitar error/CRASH.

    if (a < b) return 0;                  // caso base:
                                          // Si el dividendo 'a' es menor que el divisor 'b',
                                          // ya no se puede restar b de a ni una vez más,
                                          // por lo tanto el cociente entero es 0.
    return 1 + dividirRec(a - b, b);      // caso recursivo:
                                          // Restamos 'b' de 'a' (una "resta sucesiva") y contamos 1.
                                          // Matemáticamente: floor(a/b) = 1 + floor((a-b)/b)
                                          // siempre que a >= b. Cada llamada reduce 'a' acercándola al caso base.

}

// Factorial
int factorial(int a) {
    if (a == 0 || a == 1) return 1;       // caso base:
                                          // 0! y 1! se definen como 1; esto evita la recursión infinita.
    return a * factorial(a - 1);          // caso recursivo:
                                          // a! = a * (a-1)!. Se multiplica 'a' por el factorial
                                          // de 'a-1'. Cada llamada reduce 'a' en 1 hasta llegar a 1 o 0.
                                          // Notas: no hay manejo de valores negativos; para a < 0
                                          // esta implementación recursiva entraría en recursión infinita.
}

// Exponenciación recursiva
int exponencial(int a, int b) {
    if (b == 0) return 1;                 // caso base:
                                          // Cualquier número elevado a la potencia 0 es 1.
    return a * exponencial(a, b - 1);
                                          // a^b = a * a^(b-1). Se multiplica 'a' por la potencia
                                          // recursiva con exponente reducido en 1.
                                          // Cada llamada acerca b a 0.
}

// Conversión decimal a binario (método recursivo)
int DecimalaBinario(int n) {
    if (n == 0) return 0;                 // caso base:
                                          // Si n es 0, la representación en binario (como número entero)
    return DecimalaBinario(n / 2) * 10 + (n % 2);
                                          // - n/2: reduce el número desplazando sus bits a la derecha.
                                          // - Recursivamente obtenemos los dígitos binarios de n/2.
                                          // - Multiplicamos el resultado por 10 y sumamos (n % 2)
                                          //   para "adjuntar" el bit menos significativo actual al final.
                                          //
                                          // Ejemplo rápido (n = 6):
                                          // DecimalaBinario(6) = DecimalaBinario(3) * 10 + (6%2=0)
                                          // DecimalaBinario(3) = DecimalaBinario(1) * 10 + 1
                                          // DecimalaBinario(1) = DecimalaBinario(0) * 10 + 1 = 1
                                          // => DecimalaBinario(3) = 1*10 + 1 = 11
                                          // => DecimalaBinario(6) = 11*10 + 0 = 110
}

// FUNCIONES VISUALES: explican procedimientos paso a paso
// ---------------------------------------------------------------------------
// Explica multiplicación por descomposición
void demoMultiplicacion(int a, int b) {
    cout << "\n=== EXPLICACIÓN DE MULTIPLICACIÓN ===\n";
    int resultadoFinal = 0, factor = 1, multiplicador = b;

    // procesa cada dígito del multiplicador
    while (multiplicador > 0) {
        int dig = multiplicador % 10;
        int parcial = a * dig;
        cout << a << " x " << dig << " = " << parcial << endl;

        resultadoFinal += parcial * factor;
        multiplicador /= 10;
        factor *= 10;
    }

    cout << "Resultado final: " << resultadoFinal << "\n";
}
// Explica división como restas sucesivas
void demoDivision(int a, int b) {
   cout << "\n=== EXPLICACIÓN VISUAL DE DIVISIÓN ===\n";
    int resto = a;       // Empieza con el dividendo completo
    int cociente = 0;    // Contara cuántas veces se resta b

    cout << "División mediante restas sucesivas:\n";
    while (resto >= b) {               // Mientras el resto sea mayor o igual al divisor
        resto -= b;                    // Resta b al resto
        cociente++;                    // Aumenta el cociente
        cout << "Restamos " << b << " → Resto: " << resto << "\n";
    }

    cout << "Cociente: " << cociente << " | Resto: " << resto << "\n";
}
// Explica factorial mostrando la multiplicación
void demoFactorial(int a) {
    cout << "\n=== EXPLICACIÓN FACTORIAL ===\n";
    cout << "Factorial mediante multiplicaciones sucesivas:\n";
    cout<<"Se multiplica"<<endl;
    int factor=a;
    while(factor>0)
    {
        cout<<factor<<"x";
        factor--;
    }
    cout<<endl;
}
// Explica exponenciación
void demoExponencial(int a, int b) {
    cout << "\n=== EXPLICACIÓN VISUAL DE EXPONENTES ===\n";
    cout << "Exponencial mediante multiplicaciones sucesivas:\n";
    cout<<"Se multiplica "<< a << "un total de "  << b<< " veces" <<endl;
    int factor=a;
    int exponente=b;
    while(exponente>0)
    {
        cout<<factor<<"x";
        exponente--;
    }
    cout<<endl;

}
// Explica conversión a binario
void demoBinario(int a) {
     cout << "\n=== EXPLICACION VISUAL DE CONVERSION DECIMAL A BINARIO ===\n";
    if (a == 0) { // si el nro es 0 se devolvera 0
        cout << "El numero es 0, su binario es: 0\n";
        return;
    }
    int original = a; // variable que contendra el numero
    int pasos[100]; // Crea un arreglo de elementos para almacenar los residuos de las divisiones
    int contador = 0;// Inicializa un contador para llevar registro de cuántos residuos se han almacenado

    cout << "Dividimos sucesivamente entre 2 y anotamos el residuo:\n";
    while (a > 0) { //Mientras a sea mayor a 0 se calculara el residuo de a / 2
        int residuo = a % 2;
        pasos[contador] = residuo; //Guarda el residuo en el arreglo
        contador++; //Incrementa el contador para pasar al siguiente índice del arreglo

        cout << a << " / 2 = " << a / 2 << " - residuo: " << residuo << "\n";
        a /= 2; //Actualiza a dividiéndolo entre 2 para continuar el proceso

    }
    cout << "\nAhora escribimos los residuos en orden inverso:\n";
    cout << original << " en binario es: ";
    for (int i = contador - 1; i >= 0; i--) { // Inicia un for inverso para recorrer el arreglo desde el último residuo hasta el primero.

        cout << pasos[i];
    }
    cout << "\n";
}
// GENERADORES DE NÚMEROS POR NIVEL (ajustan dificultad)
// ---------------------------------------------------------------------------
int generarNumeroPorNivel(int nivel) {
    switch (nivel) {
        case 1: return rand() % 10 + 1;      // 1–10
        case 2: return rand() % 90 + 10;     // 10–99
        case 3: return rand() % 900 + 100;   // 100–999
        default: return rand() % 10 + 1;
    }
}
// Genera números pequeños para factorial
int generarNumeroPorNivelFactorial(int nivel) {
    switch (nivel) {
        case 1: return rand() % 5 + 1;     // 1–5
        case 2: return rand() % 6 + 5;     // 5–10
        case 3: return rand() % 3 + 10;    // 10–12
        default: return rand() % 5 + 1;
    }
}
// Genera números pequeños para exponentes
int generarNumeroPorNivelExponencial(int nivel) {
    switch (nivel) {
        case 1: return rand() % 3 + 1;     // 1–3
        case 2: return rand() % 4 + 3;     // 3–6
        case 3: return rand() % 4 + 6;     // 6–9
        default: return rand() % 3 + 1;
    }
}
// TURNO DEL JUGADOR: ejecuta una operación y actualiza puntaje
// ---------------------------------------------------------------------------
void turnoJugador(Jugador &jugador, int nivel) {
    int opcion, a, b, respuesta, resultado;
    char ver;

    // genera dos números según nivel
    a = generarNumeroPorNivel(nivel);
    b = generarNumeroPorNivel(nivel);
    if (b == 0) b = 1; // evitar divisiones entre 0

    cout << "\nTurno de " << jugador.nombre << " (Puntos: " << jugador.puntos << ")\n";
    cout << "1. Multiplicación\n2. División\n3. Factorial\n4. Exponencial\n5. Decimal a Binario\nElige: ";
    cin >> opcion;

    switch (opcion) {

    ///////////////////////////
    //      MULTIPLICACIÓN
    ///////////////////////////
    case 1:
        cout << "¿Cuánto es " << a << " x " << b << "? ";
        cin >> respuesta;
        resultado = multiplicarRec(a, b);

        if (nivel >= 2) {                     // explicación opcional
            cout << "¿Ver explicación? (s/n): "; cin >> ver;
            if (ver == 's' || ver == 'S') demoMultiplicacion(a, b);
        }
        break;

    ///////////////////////////
    //        DIVISIÓN
    ///////////////////////////
    case 2:
        cout << "¿Cuánto es " << a << " ÷ " << b << "? (parte entera) ";
        cin >> respuesta;
        resultado = dividirRec(a, b);

        if (nivel >= 2) {
            cout << "¿Ver explicación? (s/n): "; cin >> ver;
            if (ver == 's' || ver == 'S') demoDivision(a, b);
        }
        break;

    ///////////////////////////
    //        FACTORIAL
    ///////////////////////////
    case 3: {
        int n = generarNumeroPorNivelFactorial(nivel);
        cout << "¿Cuánto es " << n << "! ? ";
        cin >> respuesta;

        resultado = factorial(n);

        if (nivel >= 2) {
            cout << "¿Ver explicación? (s/n): "; cin >> ver;
            if (ver == 's' || ver == 'S') demoFactorial(n);
        }
        } break;

    ///////////////////////////
    //      EXPONENCIAL
    ///////////////////////////
    case 4: {
        int base = generarNumeroPorNivelExponencial(nivel);
        int expo = generarNumeroPorNivelExponencial(nivel);

        cout << "¿Cuánto es " << base << "^" << expo << "? ";
        cin >> respuesta;

        resultado = exponencial(base, expo);

        if (nivel >= 2) {
            cout << "¿Ver explicación? (s/n): "; cin >> ver;
            if (ver == 's' || ver == 'S') demoExponencial(base, expo);
        }
        } break;

    ///////////////////////////
    //      BINARIO
    ///////////////////////////
    case 5:
        cout << "¿Cuál es el binario de " << a << "? ";
        cin >> respuesta;
        resultado = DecimalaBinario(a);

        if (nivel >= 2) {
            cout << "¿Ver explicación? (s/n): "; cin >> ver;
            if (ver == 's' || ver == 'S') demoBinario(a);
        }
        break;

    default:
        cout << "Opción no válida.\n";
        return;
    }
    // EVALUACIÓN Y PUNTAJE
    // -------------------------------------------------------------------
    if (respuesta == resultado) {
        cout << "¡Correcto!\n";
        jugador.puntos += 15 * nivel;       // mayor nivel, mayor puntaje
    } else {
        cout << "Incorrecto. Era: " << resultado << "\n";
        jugador.puntos -= 5;                // penalización
    }

    actualizarJugador(jugador);             // guarda cambios en archivo
}
// MAIN: controla el flujo del juego
// ---------------------------------------------------------------------------
int main() {
    srand(time(NULL));                      // inicializa aleatorios

    Jugador lista[200];                     // lista de jugadores
    int total = cargarArchivo(lista);       // carga inicial

    int nuevos;
    cout << "¿Cuántos jugadores jugarán? ";
    cin >> nuevos;

    // registro o carga de cada jugador
    for (int i = 0; i < nuevos; i++) {
        char nombre[50];
        cout << "Nombre del jugador " << i + 1 << ": ";
        cin >> nombre;

        int pos = buscarJugador(lista, total, nombre);

        // Si no existe, lo crea
        if (pos == -1) {
            strcpy(lista[total].nombre, nombre);
            lista[total].puntos = 0;
            pos = total;
            total++;
        }

        // Ciclo de juego para ese jugador
        int seguir = 1, nivel;
        while (seguir) {
            cout << "\nNIVELES:\n1. Fácil\n2. Medio\n3. Difícil\n4. Salir\nElige: ";
            cin >> nivel;

            if (nivel == 4) break;         // sale al menú

            turnoJugador(lista[pos], nivel);  // juega

            cout << "¿Seguir jugando este jugador? (1=Si / 0=No): ";
            cin >> seguir;
        }
    }
    // guarda archivo final
    guardarArchivo(lista, total);

    cout << "\nArchivo actualizado.\nGracias por jugar.\n";
    return 0;
}
