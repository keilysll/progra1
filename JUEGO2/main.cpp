#include <iostream>   // Para entrada/salida estandar (cout, cin)
#include <fstream>    // Para leer y escribir archivos
#include <cstdlib>    // Para usar rand(), srand(), system()
#include <ctime>      // Para inicializar el generador de numeros aleatorios con la hora actual
#include <cstring>    // Para comparar cadenas (strcmp)
using namespace std;
// -----------------------------
// ESTRUCTURA DE JUGADOR
// -----------------------------

// Estructura que almacena los datos de cada jugador
struct Jugador {
    char nombre[30];  // Nombre del jugador
    int puntaje;      // Puntaje acumulado
};

// -----------------------------
// FUNCIONES RECURSIVAS
// -----------------------------

// Funcion recursiva que multiplica usando sumas sucesivas
int multiplicarRec(int a, int b) {
    if (b == 0) return 0;                       // Caso base: cualquier numero por 0 es 0
    if (b > 0) return a + multiplicarRec(a, b - 1); // Si b > 0, suma 'a' b veces
    return -multiplicarRec(a, -b);              // Si b < 0, cambia el signo
}

// Funcion recursiva que divide usando restas sucesivas (solo cociente entero)
int dividirRec(int a, int b) {
    if (b == 0) return 0;       // Evita division entre cero
    if (a < b) return 0;        // Si el dividendo es menor, resultado es 0
    return 1 + dividirRec(a - b, b);  // Resta b a a y cuenta las veces que puede hacerlo
}

// Funcion recursiva que combierte nro decimal a binario
int DecimalaBinario(int n)
{
    if (n == 0) // condicion base de la recursion Si el numero de entrada n es 0
    {
        return 0; // la funcion devuelve 0
    }
    return DecimalaBinario(n / 2) * 10 + (n % 2);

    /*Realiza una division entera del numero por 2 llama recursivamente a la funcion con el resultado de la division anterior
     Esto continua dividiendo el numero por 2 hasta que el numero base sea 0
     Calcula el residuo del numero dividido por 2 el residuo sera 0 o 1 que es un digito del numero binario
     Multiplica el resultado de la llamada recursiva anterior por 10 para desplazar los digitos binarios ya calculados hacia la izquierda
     Suma el digito binario actual el residuo a la posicion correcta mas a la derecha del numero binario acumulado*/
}

// -----------------------------
// FUNCIONES DE EXPLICACION VISUAL
// -----------------------------


// Muestra como se realiza la multiplicacion en columna paso a paso
void explicarMultiplicacionColumna(int a, int b) {
    cout << "\n=== EXPLICACION DE MULTIPLICACION EN COLUMNA ===\n";

    int resultadoFinal = 0;  // Almacenara el resultado total
    int factor = 1;          // Indica la posición (unidades, decenas, centenas)
    int multiplicador = b;   // Copia de b para descomponerlo en digitos


    while (multiplicador > 0) {
        int digito = multiplicador % 10;       // Obtiene el ultimo digito de b
        int parcial = digito * a;              // Multiplica a por ese digito
        cout << a << " x " << digito << " = " << parcial;
        if (factor > 1) cout << " (posicion " << factor << ")";
        cout << "\n";
        resultadoFinal += parcial * factor;    // Acumula el resultado considerando la posicion
        multiplicador /= 10;                   // Elimina el ultimo digito
        factor *= 10;                          // Pasa a la siguiente posicion
    }

    cout << "Suma de resultados parciales = " << resultadoFinal << "\n";
    cout << "Resultado final: " << resultadoFinal << "\n";
}

// Explica la division mediante restas sucesivas
void explicarDivisionVisual(int a, int b) {
    cout << "\n=== EXPLICACION VISUAL DE DIVISION ===\n";
    int resto = a;       // Empieza con el dividendo completo
    int cociente = 0;    // Contara cuántas veces se resta b

    cout << "Division mediante restas sucesivas:\n";
    while (resto >= b) {               // Mientras el resto sea mayor o igual al divisor
        resto -= b;                    // Resta b al resto
        cociente++;                    // Aumenta el cociente
        cout << "Restamos " << b << " → Resto: " << resto << "\n";
    }

    cout << "Cociente: " << cociente << " | Resto: " << resto << "\n";
}
// Explica la transformacion de numeros decimales a binarios

void explicarDecimalABinario(int a) {

    cout << "\n=== EXPLICACION VISUAL DE CONVERSION DECIMAL A BINARIO ===\n";
    if (a == 0) { // si el nro es 0 se devolvera 0
        cout << "El numero es 0, su binario es: 0\n";
        return;
    }
    int original = a; // variable que contendra el nro
    int pasos[100]; // Crea un arreglo para almacenar los residuos de las divisiones
    int contador = 0;// Inicializa un contador para llevar registro de cuantos residuos se han almacenado

    cout << "Dividimos sucesivamente entre 2 y anotamos el residuo:\n";
    while (a > 0) { //Mientras a sea mayor a 0 se calculara el residuo de a / 2
        int residuo = a % 2;
        pasos[contador] = residuo; //Guarda el residuo en el arreglo
        contador++; //Incrementa el contador para pasar al siguiente indice del arreglo

        cout << a << " / 2 = " << a / 2 << " - residuo: " << residuo << "\n";
        a /= 2; //Actualiza a dividiendolo entre 2 para continuar el proceso

    }
    cout << "\nAhora escribimos los residuos en orden inverso:\n";
    cout << original << " en binario es: ";
    for (int i = contador - 1; i >= 0; i--) { // Inicia un for inverso para recorrer el arreglo desde el ultimo residuo hasta el primero

        cout << pasos[i];
    }
    cout << "\n";
}
// -----------------------------
// FUNCIONES DE ARCHIVO
// -----------------------------

// Guarda el jugador y su puntaje en un archivo.txt

void guardarJugador(Jugador j) {
    ofstream archivo("jugadores.txt", ios::app);   // Abre el archivo para añadir datos
    if (archivo.is_open()) {
        archivo << j.nombre << " " << j.puntaje << endl;  // Escribe nombre y puntaje
        archivo.close();                                   // Cierra el archivo
    }
}

// Busca si el jugador ya existe en el archivo
bool buscarJugador(Jugador &j) {
    ifstream archivo("jugadores.txt")
    ;  // Abre archivo para lectura
    Jugador temp;
    if (archivo.is_open()) {
        while (archivo >> temp.nombre >> temp.puntaje) {  // Lee linea por línea
            if (strcmp(temp.nombre, j.nombre) == 0) {     // Compara nombres
                j.puntaje = temp.puntaje;                 // Si existe, recupera el puntaje
                archivo.close();
                return true;                              // Jugador encontrado
            }
        }
        archivo.close();
    }
    return false;  // Si no se encontro
}

// Actualiza el puntaje de un jugador (reemplaza su línea en el archivo)
void actualizarJugador(Jugador j) {
    ifstream archivoIn("jugadores.txt");  // Archivo original abre el archivo original 'jugadores.txt' para leer los datos existentes
    ofstream archivoOut("temp.txt");      // Archivo temporal donde se guardarán los datos actualizados
    Jugador temp;   // Variable temporal para almacenar cada jugador leido del archivo

    if (archivoIn.is_open() && archivoOut.is_open()) { // Verifica que ambos archivos se hayan abierto correctamente
        bool actualizado = false;
        while (archivoIn >> temp.nombre >> temp.puntaje) {   // Lee cada linea del archivo original (nombre y puntaje de cada jugador)
            if (strcmp(temp.nombre, j.nombre) == 0) { // Compara el nombre leido con el nombre del jugador que queremos actualizar
                archivoOut << j.nombre << " " << j.puntaje << endl; // Si coincide, escribe el nombre y el nuevo puntaje en el archivo temporal
                actualizado = true; // Marca que el jugador fue actualizado
            } else {
                archivoOut << temp.nombre << " " << temp.puntaje << endl;  // Copia sin cambios
            } // Si no coincide, copia la información del jugador tal cual al archivo temporal
        }
        if (!actualizado)  // Si el jugador no estaba en el archivo original, significa que es nuevo
            archivoOut << j.nombre << " " << j.puntaje << endl; // Agrega al jugador con su puntaje al final del archivo temporal

        archivoIn.close(); // Cierra el archivo original
        archivoOut.close(); // Cierra el archivo temporal
        remove("jugadores.txt");            // Borra el archivo viejo
        rename("temp.txt", "jugadores.txt"); // Renombra el archivo temporal con el nombre del archivo original, quedando actualizado
    }
    }


// Muestra todos los puntajes guardados
void mostrarPuntajes() {
    ifstream archivo("jugadores.txt");// Abre el archivo jugadores.txt en modo lectura para acceder a los puntajes guardado
    Jugador temp;  // Variable temporal para almacenar cada jugador leído del archivo

    cout << "\nTabla de puntuaciones:\n";
    cout << "--------------------------\n";
    if (archivo.is_open()) {  // Verifica que el archivo se haya abierto correctamente
        while (archivo >> temp.nombre >> temp.puntaje) {  // Lee linea por linea: nombre y puntaje de cada jugador
            cout << temp.nombre << " - " << temp.puntaje << " puntos\n";  // Muestra en pantalla el nombre del jugador y su puntaje
        }
        archivo.close(); // Cierra el archivo despues de leer todos los datos
    } else {
        cout << "No hay datos guardados.\n";
    }
    cout << "--------------------------\n";
}

// -----------------------------
// FUNCIONES DEL JUEGO
// -----------------------------

// Genera numeros aleatorios segun el nivel de dificultad
int generarNumeroPorNivel(int nivel) {
    switch (nivel) {
        case 1: return rand() % 10 + 1;      // Numeros de 1 dígito
        case 2: return rand() % 90 + 10;     // Numeros de 2 dígitos
        case 3: return rand() % 900 + 100;   // Numeros de 3 dígitos
        default: return rand() % 10 + 1;     // Por defecto, nivel 1
    }
}

// Ejecuta un turno para un jugador
void turnoJugador(Jugador &jugador, int nivel) {
    int opcion, a, b, respuesta, resultado;
    char verExplicacion;  // Variable que almacena si el jugador quiere ver la explicacióon paso a paso

    cout << "\nTurno de " << jugador.nombre << " (Puntaje: " << jugador.puntaje << ")\n";
    cout << "1. Multiplicacion\n2. Division\n3.Nro Decimal a Binario\n Elige una opcion: ";
    cin >> opcion;

    // Genera los dos numeros aleatorios segun el nivel
    a = generarNumeroPorNivel(nivel);
    b = generarNumeroPorNivel(nivel);
    if (b == 0) b = 1;   // Evita que b sea cero, ya que no se puede dividir entre cero

    // Opcion 1: Multiplicacion
    if (opcion == 1) {
        cout << "\nCuanto es " << a << " x " << b << "? ";// Muestra la pregunta de multiplicacion al jugador
        cin >> respuesta; // El jugador ingresa su respuest
        resultado = multiplicarRec(a, b);  // Calcula el resultado correcto usando la funcion recursiva de multiplicacion


        // En niveles 2 y 3 se ofrece explicacion
        if (nivel >= 2) {
            cout << "Quieres ver la explicacion paso a paso? (s/n): ";
            cin >> verExplicacion;
/* Si el jugador responde “s” o “S”, se llama a la función explicarMultiplicacionColumna(a, b),
que muestra visualmente cómo se hace la multiplicacion paso a paso*/
            if (verExplicacion == 's' || verExplicacion == 'S')
                explicarMultiplicacionColumna(a, b);
        }

    // Opcion 2: Division
    } else if (opcion == 2) {
        cout << "\nCuanto es " << a << " / " << b << "? (parte entera) "; // Muestra la pregunta de division al jugador (solo parte entera)
        cin >> respuesta;  // El jugador ingresa su respuesta
        resultado = dividirRec(a, b);  // Calcula el resultado correcto usando la funcion recursiva de division
        if (nivel >= 2) {
            cout << "Quieres ver la explicacion paso a paso? (s/n): ";
            cin >> verExplicacion; // Guarda la respuesta del jugador
            if (verExplicacion == 's' || verExplicacion == 'S')
                explicarDivisionVisual(a, b);  // Muestra la explicación paso a paso de la división
        }

        // Opcion 3 : Decimal a Binario
    } else if (opcion == 3){
        cout << "\nCuanto es  " << a << " en numero binario? "; // Muestra la pregunta de decimal a binario al jugador
        cin >> respuesta;  // El jugador ingresa su respuesta
        resultado = DecimalaBinario(a);  // Calcula el resultado correcto usando la funcion recursiva de decimal a binario

        if (nivel >= 2) {
            cout << "Quieres ver la explicacion paso a paso? (s/n): ";
            cin >> verExplicacion; // Guarda la respuesta del jugador
            if (verExplicacion == 's' || verExplicacion == 'S')
               explicarDecimalABinario(a); // Muestra la explicacion paso a paso

        }

    }else {
        cout << "Opcion no valida.\n";
        return;  // Sale si la opcion no es correcta
    }

    // Verifica si la respuesta es correcta
    if (respuesta == resultado) {
        cout << "Correcto!\n";
        jugador.puntaje += 15 * nivel;  // Aumenta puntaje segun el nivel
    } else {
        cout << "Incorrecto. La respuesta era " << resultado << ".\n";
        jugador.puntaje -= 5;           // Penalizacion
    }

    actualizarJugador(jugador);  // Guarda el puntaje actualizado en el archivo de jugadores

// -----------------------------
// FUNCION PRINCIPAL
// -----------------------------
}

int main() {
    Jugador jugador1, jugador2;   // Se crean dos jugadores
    char continuar = 's';         // Control del bucle principal
    int nivel;                    // Nivel de dificultad

    srand(time(0));  // Inicializa el generador aleatorio con la hora actual

    cout << "=== DESAFIO MATEMATICO = MODO DOBLE CON NIVELES ===\n";

    //  Registro o carga del jugador 1
    cout << "\nJugador 1, ingresa tu nombre: ";
    cin >> jugador1.nombre;
    if (!buscarJugador(jugador1)) {  // Si la funcion buscarJugador devuelve false, significa que no lo encontro
        jugador1.puntaje = 0;  // Se inicializa su puntaje en 0, ya que es un nuevo jugador
        guardarJugador(jugador1);  // Se guarda su nombre y puntaje inicial 0 en el archivo jugadores.txt
        cout << "Nuevo jugador registrado.\n";  // Mensaje informando que el jugador se ha registrado por primera vez
    } else {  // En caso contrario, si buscarJugador devolvio true, el jugador ya existia

        cout << "Bienvenido de nuevo, " << jugador1.nombre << "! Puntaje actual: " << jugador1.puntaje << "\n"; // Muestra un saludo y el puntaje que tenía guardado
    }

    //  Registro o carga del jugador 2
    cout << "\nJugador 2, ingresa tu nombre: ";
    cin >> jugador2.nombre;
    if (!buscarJugador(jugador2)) { // Si la funcion buscarJugador devuelve false, significa que no lo encontro
        jugador2.puntaje = 0; // Se inicializa su puntaje en 0, ya que es un nuevo jugador
        guardarJugador(jugador2);  // Se guarda su nombre y puntaje inicial 0 en el archivo jugadores.txt
        cout << "Nuevo jugador registrado.\n";
    } else {  // En caso contrario, si buscarJugador devolvio true, el jugador ya existia

        cout << "Bienvenido de nuevo, " << jugador2.nombre << "! Puntaje actual: " << jugador2.puntaje << "\n";
    }

    // Seleccion de nivel
    cout << "\nElige nivel de dificultad:\n1. Facil (1 digito)\n2. Medio (2 digitos)\n3. Dificil (3 digitos)\nSelecciona: ";
    cin >> nivel;

    // Ciclo principal del juego
    while (continuar == 's' || continuar == 'S') {
        turnoJugador(jugador1, nivel);  // Turno del primer jugador
        turnoJugador(jugador2, nivel);  // Turno del segundo jugador

        cout << "\nDesean seguir jugando? (s/n): ";
        cin >> continuar;
    }

    //  Mostrar resultados finales
    cout << "\nPuntajes finales:\n";
    cout << jugador1.nombre << ": " << jugador1.puntaje << " puntos\n";
    cout << jugador2.nombre << ": " << jugador2.puntaje << " puntos\n";

    // Muestra tabla completa de puntuaciones guardadas
    mostrarPuntajes();

    cout << "\nProgreso guardado. Gracias por jugar!\n";
    return 0;
}
