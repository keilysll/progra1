///JUEGO 2
#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <cstring>
using namespace std;
struct Jugador {
    char nombre[50];
    int puntos;
};

// ---------- CARGAR ARCHIVO EXISTENTE ----------
int cargarArchivo(Jugador lista[]){
    // Se abre el archivo de texto en modo lectura
    ifstream archivo("datos_juego2.txt");

    // Contador que indica cuántos jugadores se han leído del archivo
    int count = 0;
    // Verifica si el archivo se abrió correctamente
    if(archivo.is_open()){
        // Mientras no se llegue al final del archivo
        while(!archivo.eof()){
            // Se leen los datos del jugador (nombre y puntos) desde el archivo
            archivo >> lista[count].nombre >> lista[count].puntos;
            // Si hubo un error al leer (fin real del archivo o dato inválido), se sale del ciclo
            if(archivo.fail()) break;
            // Se incrementa count para pasar a la siguiente posición del arreglo
            count++;
        }
    }

    // Devuelve cuántos jugadores fueron cargados correctamente
    return count;
}

// ---------- ORDENAR DESCENDENTE ----------
void ordenarJugadores(Jugador arr[], int n){

    // Bucle externo: recorre todos los elementos menos el último
    for(int i = 0; i < n - 1; i++){
        // Bucle interno: compara elementos adyacentes
        for(int j = 0; j < n - i - 1; j++){
            // Si el jugador actual tiene menos puntos que el siguiente
            // entonces se intercambian (para ordenar de mayor a menor)
            if(arr[j].puntos < arr[j+1].puntos){
                // Se guarda temporalmente un jugador para hacer el intercambio
                Jugador temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


// ---------- GUARDAR TODO AL ARCHIVO ----------
void guardarArchivo(Jugador arr[], int n){

    // Ordena los jugadores antes de guardar (mayor → menor)
    ordenarJugadores(arr, n);
    // Abre el archivo en modo escritura (se sobrescribe)
    ofstream archivo("datos_juego2.txt");
    // Recorre todos los jugadores y los escribe en el archivo
    for(int i = 0; i < n; i++){
        archivo << arr[i].nombre << " " << arr[i].puntos << "\n";
    }
    // Cierra el archivo para guardar los cambios
    archivo.close();
}

bool buscarJugador(Jugador &j) {// se define una función que busca un jugador en el archivo y actualiza su puntaje si lo encuentra
    ifstream archivo("datos_juego2.txt");// se abre el archivo jugadores.txt en modo lectura
    Jugador temp;// se declara una variable temporal para leer los datos del archivo
    if (archivo.is_open()) {  // se verifica si el archivo se abrió correctamente
        while (archivo >> temp.nombre >> temp.puntos) {// se recorre el archivo  leyendo nombre y puntaje de cada jugador
            if (strcmp(temp.nombre, j.nombre) == 0) { // se compara el nombre leído con el nombre del jugador buscado
                j.puntos = temp.puntos;// si los nombres coinciden, se actualiza el puntaje del jugador original con el del archivo
                archivo.close();// se cierra el archivo después de encontrar el jugador
                return true;// se retorna true indicando que el jugador fue encontrado
            }
        }
    }
    return false;
}

int buscarJugador(Jugador lista[], int total, char nombre[]) {
    for(int i = 0; i < total; i++){
        if(strcmp(lista[i].nombre, nombre) == 0)
            return i;
    }
    return -1;
}

void actualizarJugador(Jugador j) { // se define una función que actualiza los datos de un jugador en el archivo jugadores.txt
    ifstream archivoIn("datos_juego2.txt"); // se abre el archivo jugadores.txt en modo lectura
    ofstream archivoOut("temp.txt"); // se abre un archivo temporal temp.txt en modo escritura
    Jugador temp; // se declara una variable temporal para leer los datos del archivo original
if (archivoIn.is_open() && archivoOut.is_open()) { // se verifica que ambos archivos se hayan abierto correctamente
    bool actualizado = false; // se inicializa una variable y se la declara flasa
    while (archivoIn >> temp.nombre >> temp.puntos) { // se recorre el archivo original leyendo nombre y puntaje de cada jugador
if (strcmp(temp.nombre, j.nombre) == 0) { // si el nombre coincide con el jugador a actualizar
    archivoOut << j.nombre << " " << j.puntos<< endl; //se escribe el nuevo puntaje en el archivo temporal
    actualizado = true; // se marca que el jugador fue actualizado
} else {
    archivoOut << temp.nombre << " " << temp.puntos << endl; // si el nombre no coincide, se copia el jugador tal como está al archivo temporal
}
}
if (!actualizado){ // si el jugador no fue encontrado en el archivo original
    archivoOut << j.nombre << " " << j.puntos << endl; //se agrega al final del archivo temporal
    archivoIn.close(); // se cierran ambos archivos después de procesar los datos
    archivoOut.close(); // se cierran ambos archivos después de procesar los datos
    remove("datos_juego2.txt"); // se elimina el archivo original jugadores.txt
    rename("temp.txt", "datos_juego2.txt"); // se renombra el archivo temporal como jugadores.txt para completar la actualización
}
}
}




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
{// Caso base: 0! está definido como 1
if (a==0)
{return 1;
}// Caso base alternativo: 1! = 1 (evita llamadas recursivas extra)
if (a==1)
{return 1;
}// Paso recursivo: devuelve a * factorial(a-1)
return a*factorial(a-1);
}
int exponencial(int a, int b)
{
// Caso base: cualquier número elevado a 0 es 1
    if (b==0)
    {
        return 1;
    }
// Paso recursivo: multiplica 'a' por a^(b-1)
// Reduce el exponente en 1 en cada llamada hasta llegar a 0
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

// Muestra como se realiza la multiplicacion en columna paso a paso
void demoMultiplicacion(int a, int b) {
    cout << "\n=== EXPLICACIÓN DE MULTIPLICACIÓN EN COLUMNA ===\n";

    int resultadoFinal = 0;  // Almacenara el resultado total
    int factor = 1;          // Indica la posición (unidades, decenas, centenas)
    int multiplicador = b;   // Copia de b para descomponerlo en digitos

    while (multiplicador > 0) {
        int digito = multiplicador % 10;       // Obtiene el ultimo digito de b
        int parcial = digito * a;              // Multiplica a por ese digito
        cout << a << " x " << digito << " = " << parcial;
        if (factor > 1) cout << " (posición " << factor << ")";
        cout << "\n";
        resultadoFinal += parcial * factor;    // Acumula el resultado considerando la posicion
        multiplicador /= 10;                   // Elimina el ultimo dígito
        factor *= 10;                          // Pasa a la siguiente posicion
    }

    cout << "Suma de resultados parciales = " << resultadoFinal << "\n";
    cout << "Resultado final: " << resultadoFinal << "\n";
}

// Explica la division mediante restas sucesivas
void demoDivision(int a, int b) {
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

void demoFactorial(int a)
{
    cout << "\n=== EXPLICACION VISUAL DE FACTORIAL ===\n";
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

void demoExponencial(int a,int b)
{
    cout << "\n=== EXPLICACION VISUAL DE EXPONENTES ===\n";
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


// ------------------ TURNO DE JUEGO -----------------------------

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
cout << "\nTurno de " << jugador.nombre << " (Puntaje: " << jugador.puntos << ")\n"; // se imprime el nombre del jugador y su puntaje actual
cout << "1. Multiplicacion\n2. Division\n 3. Factorial\n 4.Exponencial\n 5.-De decimal a binario\n Elige una opcion: "; // se muestran las opciones disponibles: multiplicación o división
cin >> opcion; // se lee la opción elegida por el jugador
a = generarNumeroPorNivel(nivel); // se generan dos números aleatorios según el nivel de dificultad
b = generarNumeroPorNivel(nivel);
valorfactorial=generarNumeroPorNivelFactorial(nivel);
factor= generarNumeroPorNivelExponencial(nivel);
exponente= generarNumeroPorNivelExponencial(nivel);

if (b == 0) b = 1; // se evita que el divisor sea cero en caso de división
if (opcion == 1) { // verifica si la opción elegida es multiplicación
cout << "\n¿Cuanto es " << a << " x " << b << "? "; //se formula la pregunta considerando imprimiendo los valores a y b
cin >> respuesta; // se lee la respuesta del jugador
resultado = multiplicarRec(a, b); // se calcula el resultado usando la función de multiplicación recursiva
if (nivel >= 2) { // si el nivel es mayor o igual a 2, se pregunta si desea ver la explicación paso a paso
cout << "¿Quieres ver la explicacion paso a paso? (s/n): ";
cin >> verExplicacion; // se lee la respuesta del jugador sobre la explicación
if (verExplicacion == 's' || verExplicacion == 'S') //verifica si la respuesta es afirmativa
demoMultiplicacion(a, b); // se muestra la explicación de la multiplicación por columnas
}

} else if (opcion == 2) { // se verifica si la opción elegida es división
cout << "\n¿Cuanto es " << a << " ÷ " << b << "? (parte entera) "; //se formula la pregunta con parte entera considerando los valores a y b
cin >> respuesta; // se lee la respuesta del jugador
resultado = dividirRec(a, b); // se calcula el resultado usando la función de división recursiva
if (nivel >= 2) { //se verifica si el nivel es mayor o igual a 2
cout << "¿Quieres ver la explicacion paso a paso? (s/n): "; //se pregunta si desea ver la explicación paso a paso
cin >> verExplicacion; // se lee la respuesta del jugador sobre la explicación
if (verExplicacion == 's' || verExplicacion == 'S') //se verifica si la respuesta es afirmativa
demoDivision(a, b); //se muestra la explicación visual de la división al llamar a la funcion de explicardivisionvisual
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
    cout << "¿Quieres ver la explicacion paso a paso? (s/n): ";
    cin >> verExplicacion;
    if (verExplicacion == 's' || verExplicacion == 'S')
    demoFactorial(valorfactorial);
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
    cout << "¿Quieres ver la explicacion paso a paso? (s/n): ";
    cin >> verExplicacion;
    if (verExplicacion == 's' || verExplicacion == 'S')
    demoExponencial(factor,exponente);
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
                demoBinario(a); // Muestra la explicación paso a paso
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
jugador.puntos += 15 * nivel; // se incrementa el puntaje del jugador según el nivel y se almacena en el puntaje del jugfador
} else { //caso donde la respuesta es incorrecta
cout << "Incorrecto. La respuesta era " << resultado << ".\n";
jugador.puntos -= 5; // se descuenta puntaje por error y se guarda en el puntaje del jugador
}
actualizarJugador(jugador); // se actualiza el puntaje del jugador mediante la funcion de actualizar jugador
}


int main(){
    srand(time(NULL));

    Jugador listaTotal[200];
    int total = cargarArchivo(listaTotal);

    int nuevos;
    cout << "¿Cuantos jugadores jugaran? ";
    cin >> nuevos;

    for(int i = 0; i < nuevos; i++){
        char nombre[50];
        cout << "Nombre del jugador " << i+1 << ": ";
        cin >> nombre;

        int pos = buscarJugador(listaTotal, total, nombre);
        if(pos == -1){
            // jugador nuevo
            strcpy(listaTotal[total].nombre, nombre);
            listaTotal[total].puntos = 0;
            pos = total;
            total++;
        }

        // Jugar
        int seguir = 1;
        while(seguir){
            cout << "\nNIVELES:\n1. Facil\n2. Medio\n3. Dificil\n4. Salir\nElige: ";
            int nivel;
            cin >> nivel;
            if(nivel == 4) break;
            turnoJugador(listaTotal[pos], nivel);
            cout << "¿Seguir jugando este jugador? (1 = Si, 0 = No): ";
            cin >> seguir;
        }
    }

    // Guardar todos ordenados
    guardarArchivo(listaTotal, total);

    cout << "\nArchivo actualizado. \nGracias por jugar.\n";

    return 0;
}
