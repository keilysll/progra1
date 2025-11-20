#include <iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<ctime>
#include<windows.h>
using namespace std;

struct jugador {
char nombre[50];
int puntos;
};

int cargarArch(jugador lista[])
{
    ifstream archivo ("datos.txt");
    int i = 0;
    while (archivo>>lista[i].nombre>>lista[i].puntos)
    {
        i++;
    }
    return i;
}

void ordenar( jugador arr[], int n)
{
    for (int i = 0 ; i < n-1; i++)
    {
        for (int j = 0 ; j < n-1; j ++)
        {
            if (arr[j].puntos< arr[j+1].puntos)
            {
                jugador temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}

void guardar(jugador arr[], int n )
{
    ordenar(arr, n);
    ofstream archivo ("datos.txt");
    for (int i = 0 ; i < n ; i ++)
    {
        archivo<<arr[i].nombre<<" "<<arr[i].puntos<<endl;
    }

    archivo.close();
}

int buscarJu(jugador lista [], int total , char nombre[])
{
    for (int i = 0 ; i < total; i++)

    if(strcmp(lista[i].nombre,nombre)== 0)
    return i;

    return -1;

}

void actualizarJuga( jugador &j)
{
    ifstream archivoIn ("datos.txt");
    ofstream archivoOut ("temp.txt");

    jugador temp;
    bool actualizar = false;
    while (archivoIn>>temp.nombre>>temp.puntos)
    {
        if (strcmp(temp.nombre,j.nombre)== 0)
        {
            archivoOut<<j.nombre<<" "<<j.puntos<<endl;
            actualizar = true ;
        } else {
        archivoOut<<temp.nombre<<" "<<temp.puntos<<endl;}
    }

    if (!actualizar)
    archivoOut<<j.nombre<<" "<<j.puntos<<endl;
    archivoIn.close();
    archivoOut.close();

    remove("datos.txt");
    rename ("temp.txt", "datos.txt");

}
 ///RECURSIVIDAD

 int multiplicacion (int a , int b)
 {
     if (b == 0)return 0;
     if (b > 0)return a + multiplicacion(a, b-1);
     return - multiplicacion(a, -b);
 }

 int division (int a , int b)
 {
     if (b == 0)return 0;
     if (a<b)return 0;
     return 1 + division(a-b , b);
 }

 int factorial (int a)
 {
     if (a == 0 || a == 1)return 1;
     return a * factorial(a-1);
 }

 int exponecial(int a , int b)
 {
     if (b == 0)return 1;
     return a*exponecial(a,b-1);
 }

 int binario (int a)
 {
     if (a == 0)return 0;
     return binario(a / 2) * 10+(a % 2);
 }

 int generarNros(int nivel)
 {
     switch(nivel){
     case 1: return rand()% 10 +1;
     case 2:return rand() % 90 + 10;
     case 3 : return rand ()% 900 + 100;
     default: return rand()% 10 +1;
     }
 }

 int generarExpo(int nivel)
 {
     switch(nivel)
     {
         case 1: return rand () % 5+1;
         case 2: return rand () % 6+5;
         case 3 : return rand () % 3+10;
         default: return rand () % 5+1;
     }
 }

 int generarFac (int nivel)
 {
     switch(nivel)
     {
         case 1 : return rand ()% 3+1;
         case 2 : return rand ()% 4+3;
         case 3 : return rand ()% 4 +6;
         default: return rand () % 3+1;
     }
 }

 void turnoJugador( jugador &jugador, int nivel)
 {
     int opcion, a, b, resultado, respuesta;
     a = generarNros(nivel);
     b = generarNros(nivel);

     if (b == 0) b = 1;

     cout<<"Turno de :"<<jugador.nombre<<"Puntaje de :"<<jugador.puntos<<endl;
    cout << "1. Multiplicación\n2. División\n3. Factorial\n4. Exponencial\n5. Decimal a Binario\nElige: ";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
        cout<< "CUANTO ES "<<a<<" x "<<b<< "?  ";
        cin>>respuesta;
        resultado = multiplicacion(a,b);
        break;

    case 2:
        cout <<"CUANTO ES "<<a<<" / "<<b<<" ?  ";
        cin>>respuesta;
        resultado = division(a, b);
        break;
    case 3:
        cout <<"CUANTO ES EL FACTORIAL DE "<<a<<" ?  ";
        cin>> respuesta;
        resultado = factorial(a);
        break;
    case 4:
        cout <<"CUANTO ES "<<a<<"ELEVADO "<<b<<" ?  ";
        cin>>respuesta;
        resultado = exponecial(a, b);
        break;
    case 5 :
        cout<<"CUANTO ES "<<a<<" EN BINARIO ?  ";
        cin>>respuesta;
        resultado=binario(a);
        break;
    default:
        cout<<"Opcion invalida"<<endl;
        return;
    }

if (respuesta == resultado)
{
    cout<<"CORRECTO!"<<endl;
    jugador.puntos += 15 * nivel;
} else
{
    cout<<"INCORRECTO"<<"La respuesta correcta era: "<<resultado<<endl;
    jugador.puntos -= 15 *nivel;
}
actualizarJuga(jugador);
 }
int main()
{
    srand (time(NULL));
    jugador lista [500];
    int total = cargarArch(lista);

    int nuevos;
    cout <<"Cuantas personas jugaran ?";
    cin>>nuevos;
    for (int i = 0; i < nuevos; i++) {
        char nombre[50];
        cout << "Nombre del jugador " << i + 1 << ": ";
        cin >> nombre;
    int pos = buscarJu(lista, total, nombre);

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
    guardar(lista, total);

    cout << "\nArchivo actualizado.\nGracias por jugar.\n";
    return 0;
}
