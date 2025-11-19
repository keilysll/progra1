
#include <iostream> //incluye libreria iostream la cual permite realizar operaciones de entrada y salida
#include <fstream> //incluye libreria fstream la cual permite manejar archivos y realizar operaciones con estos(abrir,cerrar,leer,etc)
#include <cstdlib> //incluye la libreria cstdlib que proporciona funciones para tareas generale(conversión de tipos, generación de números aleatorios, gestión de memoria y control del programa)
#include <ctime> //incluye la libreria ctime la cual permite trabajar con funciones de fechas y horas
#include <cstring> //incluye la libreria cstring la cual permite utilizar cadenas de caracteres
using namespace std; //es un comando que permite el no tener que usar std::
// -----------------------------
// ESTRUCTURA DE JUGADOR
// -----------------------------
struct Jugador //creacion del struct jugador
{
char nombre[30]; //el struct contiene un tipo de dato char llamado nombre de un maximo de 30 caracteres
int puntaje; //el struct jugador tambien tiene un puntaje determinado de tipo entero
};
// -----------------------------
// FUNCIONES RECURSIVAS
// -----------------------------

int multiplicarRec(int a, int b) { //creacion de una funcion de tipo entero que permitira la multiplicacion de forma recursiva, esta funcion recibe y trabaja con dos datos de tipo enteros(a y b)
if (b == 0) return 0; //la funcion analiza si el valor b es igual a cero, si lo es entonces se retorna un valor de cero
if (b > 0) return a + multiplicarRec(a, b - 1); //la funcion comprueba si el valor b es mayor a cero, si lo es se retorna el valor a y se vuelve a aplicar la recursividad reduciendo el valor b en uno hasta que se llegue al cero y se salga de la recursividad
return -multiplicarRec(a, -b); //se retorna el valor negativo de la funcion y se trabaja con un valor b de tipo negativo, este return solo se da si se tiene un valor negativo
}

int dividirRec(int a, int b) { //se crea la funcion de tipo entero dividir recursivamente, estar recibe dos valores enteros(a y b)
if (b == 0) return 0; // si el valor b es igual a cero entonces se devuelve un valor de cero
if (a < b) return 0;  // si el valor a es menor al valor b entonces se devuelve cero
return 1 + dividirRec(a - b, b); // si ninguna de estas se cumple se devuelve 1 mas la funcion recursiva donde lo que se modifica es el valor a que ahora sera a-b y esto se repetira hasta obtener el caso base
}

int factorial(int a)
{

    if (a==0)
    {
        return 1;
    }
    if (a==1)
    {
        return 1;
    }
    return a*factorial(a-1);

}

int exponencial(int a, int b)
{
    if (b==0)
    {
        return 1;
    }
    return a*exponencial(a,b-1);
}

// Funcion recursiva que combierte nro decimal a binario
int DecimalaBinario(int n)
{
    if (n == 0) // condición base de la recursión Si el número de entrada n es 0
    {
        return 0; // la funcion devuelve 0
    }
    return DecimalaBinario(n / 2) * 10 + (n % 2);
    /*Realiza una división entera del numero por 2 llama recursivamente a la funcion con el resultado de la division anterior
     Esto continúa dividiendo el numero por 2 hasta que el numero base sea 0
     Calcula el residuo del numero dividido por 2 el residuo será 0 o 1 que es un digito del número binario
     Multiplica el resultado de la llamada recursiva anterior por 10 para desplazar los dígitos binarios ya calculados hacia la izquierda
     Suma el dígito binario actual el residuo a la posicion correcta mas a la derecha del numero binario acumulado */
}
// -----------------------------
// FUNCIONES DE EXPLICACIÓN VISUAL
// -----------------------------

void explicarMultiplicacionColumna(int a, int b) { //creacion de una funcion vacia que recibe dos valores enteros a y b
cout << "\n=== EXPLICACIÓN DE MULTIPLICACIÓN EN COLUMNA ===\n"; // muestra por pantalla un texto dado
int resultadoFinal = 0;  // se define la variable como entera y se la iguala a cero
int factor = 1; //se define la variable factor como entera y se la iguala a 1
int multiplicador = b; // se define la variable multiplicador y se iguala al valor b
while (multiplicador > 0) { // se usa una funcion while con la condicion de que multiplicador debe ser mayor a cero
int digito = multiplicador % 10; //dentro del while se define la variable digito y se extrae el ultimo digito de la variable multiplicador
int parcial = digito * a; //se define la variable parcial y se iguala a el valor del digito obtenida anteriormente y se multiplica con el valor "a"
cout << a << " x " << digito << " = " << parcial; // se imprime e valor a, digito y parcial
if (factor > 1) cout << " (posicion " << factor << ")"; //se tiene una funcion if donde si la variable factor tiene un valor superior a 1 se imprime la posicion del factor
cout << "\n";  // se imprime el valor de a, el dígito actual y el resultado parcial de la multiplicación
resultadoFinal += parcial * factor; // se acumula el resultado parcial multiplicado por su factor en la variable resultado final
multiplicador /= 10; // se elimina el último dígito del multiplicador dividiendo entre 10
factor *= 10;  // se actualiza el factor multiplicador para la siguiente posición decimal
}
cout << "Suma de resultados parciales = " << resultadoFinal << "\n"; // se imprime la suma de los resultados parciales
cout << "Resultado final: " << resultadoFinal << "\n";  // se imprime el resultado final
}

void explicarDivisionVisual(int a, int b) {  //se nombre una funcion vacia como explicardivisionvisual y se le dan dos valores enteros a y b
cout << "\n=== EXPLICACIÓN VISUAL DE DIVISIÓN ===\n"; // se imprime un encabezado para indicar que se explicará visualmente una división
int resto = a; // se inicializa la variable resto con el valor de a
int cociente = 0; // se inicializa el cociente en cero
cout << "División mediante restas sucesivas:\n"; // se imprime un mensaje indicando que se usará el método de restas sucesivas
while (resto >= b) { // mientras el resto sea mayor o igual al divisor b, se repite el proceso
resto -= b; // se resta b del resto actual
cociente++;  // se imprime cuánto se restó y el nuevo valor del resto
cout << "Restamos " << b << " ? Resto: " << resto << "\n"; // se imprime el resto
}
cout << "Cociente: " << cociente << " | Resto: " << resto << "\n"; // se imprime el cociente final y el resto que quedó después de las restas
}

void explicarFactorialVisual(int a)
{
    cout << "\n=== EXPLICACIÓN VISUAL DE FACTORIAL ===\n";
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

void explicarExponencialVisual(int a,int b)
{
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

void explicarDecimalABinario(int a) {
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
// -----------------------------
// FUNCIONES DE ARCHIVO
// -----------------------------
void guardarJugador(Jugador j) { // se define una función que recibe un valor de jugador j
ofstream archivo("jugadores.txt", ios::app); // se abre el archivo jugadores.txt en modo de añadir al final
if (archivo.is_open()) { // se verifica si el archivo se abrió correctamente
archivo << j.nombre << " " << j.puntaje << endl; // se escribe el nombre y puntaje del jugador separados por un espacio y seguidos de un salto de línea
archivo.close(); // se cierra el archivo después de guardar los datos
}
}

bool buscarJugador(Jugador &j) { // se define una función que busca un jugador en el archivo y actualiza su puntaje si lo encuentra
ifstream archivo("jugadores.txt"); // se abre el archivo jugadores.txt en modo lectura
Jugador temp; // se declara una variable temporal para leer los datos del archivo
if (archivo.is_open()) { // se verifica si el archivo se abrió correctamente
while (archivo >> temp.nombre >> temp.puntaje) { // se recorre el archivo leyendo nombre y puntaje de cada jugador
if (strcmp(temp.nombre, j.nombre) == 0) { // se compara el nombre leído con el nombre del jugador buscado
j.puntaje = temp.puntaje; // si los nombres coinciden, se actualiza el puntaje del jugador original con el del archivo
archivo.close(); // se cierra el archivo después de encontrar el jugador
return true; // se retorna true indicando que el jugador fue encontrado
}
}
archivo.close(); // se cierra el archivo si no se encontró el jugador
}
return false; // se retorna false indicando que el jugador no está en el archivo
}

void actualizarJugador(Jugador j) { // se define una función que actualiza los datos de un jugador en el archivo jugadores.txt
ifstream archivoIn("jugadores.txt"); // se abre el archivo jugadores.txt en modo lectura
ofstream archivoOut("temp.txt"); // se abre un archivo temporal temp.txt en modo escritura
Jugador temp; // se declara una variable temporal para leer los datos del archivo original
if (archivoIn.is_open() && archivoOut.is_open()) { // se verifica que ambos archivos se hayan abierto correctamente
bool actualizado = false; // se inicializa una variable y se la declara flasa
while (archivoIn >> temp.nombre >> temp.puntaje) { // se recorre el archivo original leyendo nombre y puntaje de cada jugador
if (strcmp(temp.nombre, j.nombre) == 0) { // si el nombre coincide con el jugador a actualizar
archivoOut << j.nombre << " " << j.puntaje << endl; //se escribe el nuevo puntaje en el archivo temporal
actualizado = true; // se marca que el jugador fue actualizado
} else {
archivoOut << temp.nombre << " " << temp.puntaje << endl; // si el nombre no coincide, se copia el jugador tal como está al archivo temporal
}
}
if (!actualizado) // si el jugador no fue encontrado en el archivo original
archivoOut << j.nombre << " " << j.puntaje << endl; //se agrega al final del archivo temporal
archivoIn.close(); // se cierran ambos archivos después de procesar los datos
archivoOut.close(); // se cierran ambos archivos después de procesar los datos
remove("jugadores.txt"); // se elimina el archivo original jugadores.txt
rename("temp.txt", "jugadores.txt"); // se renombra el archivo temporal como jugadores.txt para completar la actualización
}
}

void mostrarPuntajes() { // se define una función que muestra los puntajes guardados en el archivo jugadores.txt
ifstream archivo("jugadores.txt"); // se abre el archivo jugadores.txt en modo lectura
Jugador temp; // se declara una variable temporal para leer los datos del archivo
cout << "\nTabla de puntuaciones:\n"; // se imprime el encabezado de la tabla de puntuaciones
cout << "--------------------------\n"; // se imprime una línea divisoria para separar visualmente la tabla
if (archivo.is_open()) { // se verifica si el archivo se abrió correctamente
while (archivo >> temp.nombre >> temp.puntaje) { // se recorre el archivo leyendo nombre y puntaje de cada jugador
cout << temp.nombre << " ? " << temp.puntaje << " puntos\n"; // se imprime el nombre y puntaje del jugador
}
archivo.close(); // se cierra el archivo después de leer todos los datos
} else {
cout << "No hay datos guardados.\n"; // si no se pudo abrir el archivo, se muestra un mensaje indicando que no hay datos guardados
}
cout << "--------------------------\n"; // se imprime una línea divisoria al final de la tabla
}

// -----------------------------
// FUNCIONES DEL JUEGO
// -----------------------------

int generarNumeroPorNivel(int nivel) { // se define una función que genera un número aleatorio según el nivel de dificultad
switch (nivel) { // se utiliza una estructura switch para decidir el rango del número según el nivel
case 1: return rand() % 10 + 1; // si el nivel es 1, se genera un número entre 1 y 10
case 2: return rand() % 90 + 10; // si el nivel es 2, se genera un número entre 10 y 99
case 3: return rand() % 900 + 100; // si el nivel es 3, se genera un número entre 100 y 999
default: return rand() % 10 + 1; // si el nivel no coincide con ninguno de los casos anteriores, se genera un número entre 1 y 10 por defecto
}
}
int generarNumeroPorNivelFactorial(int nivel) {
switch (nivel) {
case 1: return rand() % 5 + 1;
case 2: return rand() % 6 + 5;
case 3: return rand() % 3 + 10;
default: return rand() % 5 + 1;
}
}
int generarNumeroPorNivelExponencial(int nivel) {
switch (nivel) {
case 1: return rand() % 3 + 1;
case 2: return rand() % 4 + 3;
case 3: return rand() % 4 + 6;
default: return rand() % 3 + 1;
}
}
void turnoJugador(Jugador &jugador, int nivel) { // se define una función que ejecuta el turno de un jugador según el nivel de dificultad
int opcion, a, b, respuesta, resultado; // se declaran las variables necesarias para la operación, los operandos, la respuesta y el resultado
int valorfactorial;
int factor, exponente;
char verExplicacion; // se declara una variable para preguntar si se desea ver la explicación
cout << "\nTurno de " << jugador.nombre << " (Puntaje: " << jugador.puntaje << ")\n"; // se imprime el nombre del jugador y su puntaje actual
cout << "1. Multiplicación\n2. División\n 3. Factorial\n 4.Exponencial\n 5.-De decimal a binario\n Elige una opción: "; // se muestran las opciones disponibles: multiplicación o división
cin >> opcion; // se lee la opción elegida por el jugador
a = generarNumeroPorNivel(nivel); // se generan dos números aleatorios según el nivel de dificultad
b = generarNumeroPorNivel(nivel);
valorfactorial=generarNumeroPorNivelFactorial(nivel);
factor= generarNumeroPorNivelExponencial(nivel);
exponente= generarNumeroPorNivelExponencial(nivel);

if (b == 0) b = 1; // se evita que el divisor sea cero en caso de división
if (opcion == 1) { // verifica si la opción elegida es multiplicación
cout << "\n¿Cuánto es " << a << " x " << b << "? "; //se formula la pregunta considerando imprimiendo los valores a y b
cin >> respuesta; // se lee la respuesta del jugador
resultado = multiplicarRec(a, b); // se calcula el resultado usando la función de multiplicación recursiva
if (nivel >= 2) { // si el nivel es mayor o igual a 2, se pregunta si desea ver la explicación paso a paso
cout << "¿Quieres ver la explicación paso a paso? (s/n): ";
cin >> verExplicacion; // se lee la respuesta del jugador sobre la explicación
if (verExplicacion == 's' || verExplicacion == 'S') //verifica si la respuesta es afirmativa
explicarMultiplicacionColumna(a, b); // se muestra la explicación de la multiplicación por columnas
}

} else if (opcion == 2) { // se verifica si la opción elegida es división
cout << "\n¿Cuánto es " << a << " ÷ " << b << "? (parte entera) "; //se formula la pregunta con parte entera considerando los valores a y b
cin >> respuesta; // se lee la respuesta del jugador
resultado = dividirRec(a, b); // se calcula el resultado usando la función de división recursiva
if (nivel >= 2) { //se verifica si el nivel es mayor o igual a 2
cout << "¿Quieres ver la explicación paso a paso? (s/n): "; //se pregunta si desea ver la explicación paso a paso
cin >> verExplicacion; // se lee la respuesta del jugador sobre la explicación
if (verExplicacion == 's' || verExplicacion == 'S') //se verifica si la respuesta es afirmativa
explicarDivisionVisual(a, b); //se muestra la explicación visual de la división al llamar a la funcion de explicardivisionvisual
}
}

else if (opcion==3)
{
    cout<<"¿Cuanto es el factorial de "<<valorfactorial<<" ?"<<endl;
    cin>>respuesta;
    resultado=factorial(valorfactorial);
    cin.ignore();
    if (nivel >= 2)
    {
    cout << "¿Quieres ver la explicación paso a paso? (s/n): ";
    cin >> verExplicacion;
    if (verExplicacion == 's' || verExplicacion == 'S')
    explicarFactorialVisual(valorfactorial);
    }
}
else if(opcion==4)
{
    cout<<"¿Cuanto es el resultado de "<<factor<<" elevado a la "<<exponente<<" ?"<<endl;
    cin>>respuesta;
    resultado=exponencial(factor,exponente);
    cin.ignore();
    if (nivel >= 2)
    {
    cout << "¿Quieres ver la explicación paso a paso? (s/n): ";
    cin >> verExplicacion;
    if (verExplicacion == 's' || verExplicacion == 'S')
    explicarExponencialVisual(factor,exponente);
    }
}

else if (opcion == 5)
{
        cout << "\nCuanto es  " << a << " en numero binario? "; // Muestra la pregunta de decimal a binario al jugador
        cin >> respuesta;  // El jugador ingresa su respuesta
        resultado = DecimalaBinario(a);  // Calcula el resultado correcto usando la función recursiva de decimal a binario
        if (nivel >= 2)
        {
            cout << "Quieres ver la explicacion paso a paso? (s/n): ";
            cin >> verExplicacion; // Guarda la respuesta del jugador
            if (verExplicacion == 's' || verExplicacion == 'S')
            {
                explicarDecimalABinario(a); // Muestra la explicación paso a paso
            }

        }
}

else
{ //si no se cumple ninguna condicion
cout << "Opción no válida.\n"; //muestra un mensaje de error por pantalla
return; // finaliza el proceso
}
if (respuesta == resultado)
{ // si la respuesta del jugador es igual al resultado
cout << "¡Correcto!\n"; //imprime un texto de correcto junto a un salto de lineo
jugador.puntaje += 15 * nivel; // se incrementa el puntaje del jugador según el nivel y se almacena en el puntaje del jugfador
} else { //caso donde la respuesta es incorrecta
cout << "Incorrecto. La respuesta era " << resultado << ".\n";
jugador.puntaje -= 5; // se descuenta puntaje por error y se guarda en el puntaje del jugador
}
actualizarJugador(jugador); // se actualiza el puntaje del jugador mediante la funcion de actualizar jugador
}
// -----------------------------
// PROGRAMA PRINCIPAL
// -----------------------------
int main() { // se define la función principal del programa
Jugador jugador1, jugador2; // se declaran dos jugadores para el modo doble
char continuar = 's'; // se inicializa la variable continuar con s para controlar el ciclo del juego
int nivel; // se declara la variable nivel para elegir la dificultad
srand(time(0)); // se inicializa el generador de números aleatorios con el tiempo actual
cout << "=== DESAFÍO MATEMÁTICO – MODO DOBLE CON NIVELES ===\n"; // se imprime el título del juego con modo doble y niveles
// Registro / carga de jugador 1
cout << "\nJugador 1, ingresa tu nombre: "; // se solicita el nombre del jugador 1
cin >> jugador1.nombre; // se lee el nombre del jugador 1
if (!buscarJugador(jugador1)) { // se verifica si el jugador ya existe en el archivo
jugador1.puntaje = 0; // si no existe, se inicializa su puntaje en cero
guardarJugador(jugador1); // se guarda el nuevo jugador en el archivo
cout << "Nuevo jugador registrado.\n"; // se muestra mensaje de registro exitoso
} else { //si no se cumple la anterior condicion entonces el jugador ya existe
cout << "Bienvenido de nuevo, " << jugador1.nombre << "! Puntaje actual: " << jugador1.puntaje << "\n"; //se muestra mensaje de bienvenida y su puntaje actual
}
// Registro / carga de jugador 2
cout << "\nJugador 2, ingresa tu nombre: "; // se solicita el nombre del jugador 2
cin >> jugador2.nombre; // se lee el nombre del jugador 2
if (!buscarJugador(jugador2)) { // se verifica si el jugador ya existe en el archivo
jugador2.puntaje = 0; // si no existe, se inicializa su puntaje en cero
guardarJugador(jugador2); // se guarda el nuevo jugador en el archivo
cout << "Nuevo jugador registrado.\n"; // se muestra mensaje de registro
} else { //en caso de que el jugador ya exista
cout << "Bienvenido de nuevo, " << jugador2.nombre << "! Puntaje actual: " <<jugador2.puntaje << "\n"; //se muestra mensaje de bienvenida y su puntaje actual junto al nombre del jugador
}
// Selección de nivel
cout << "\nElige nivel de dificultad:\n1. Fácil (1 dígito)\n2. Medio (2 dígitos)\n3. Difícil (3dígitos)\nSelecciona: "; // se muestra el menú para elegir el nivel de dificultad
cin >> nivel; // se lee el nivel elegido por el usuario
// Ciclo principal del juego
while (continuar == 's' || continuar == 'S') { // mientras los jugadores ingresen s o S la funcion while continuara ejecutandose
turnoJugador(jugador1, nivel); // se ejecuta el turno del jugador 1 con el nivel seleccionado
turnoJugador(jugador2, nivel); // se ejecuta el turno del jugador 2 con el mismo nivel
cout << "\n¿Desean seguir jugando? (s/n): "; // se pregunta si desean seguir jugando
cin >> continuar; // se lee la respuesta para continuar o terminar
}
// Resultados finales
cout << "\nPuntajes finales:\n"; // se imprime el encabezado
cout << jugador1.nombre << ": " << jugador1.puntaje << " puntos\n"; // se muestra el puntaje final del jugador 1 junto a su nombre
cout << jugador2.nombre << ": " << jugador2.puntaje << " puntos\n"; //muestra el puntaje final del jugador 2 junto a su nombre
mostrarPuntajes(); // se muestran todos los puntajes acumuladoes historicos
cout << "\nProgreso guardado. ¡Gracias por jugar!\n"; // se imprime mensaje de cierre y agradecimiento
return 0; // se finaliza el programa con retorno cero
}
