#include <iostream>
#include<string.h>
using namespace std;


void menu (){
cout << "-----------------------------"<< endl;
cout << "       MENU DE OPCIONES      " <<endl;
cout << "-----------------------------"<< endl;
cout << " 1. TAMANIO CADENA "<<endl;
cout << " 2. COMPARAR DOS CADENAS "<<endl;
cout << " 3. INVERTIR CADENA  "<<endl;
cout << " 4. LLENAR VECTOR CON PRIMOS   "<<endl;
cout << " 5. SALIR  "<<endl;
cout << "-----------------------------"<< endl;
}


///FUNCION PARA DTERMINAR EL TAM DE LA CADENA
int tamCadena(char cad[]){
int longi;
longi= strlen (cad);///LLAMADO DE LA FUNCION STRLEN ();
return longi;

}




/// FUNCION PARA DETERMINAR SI ES PRIMO O NO
bool esPrimo (int num){
int cdiv = 0;/// INICIAR CON CERO PARA EVITAR QUE OBTENGAS DATOS BASURA
    for (int c = 1; c <= num ; c ++){
        if (num % c == 0){
            cdiv+=1;

        }
    }
 if (cdiv == 2){
    return true ;
 }else {
 return false;
}

}



/// FUNCION LLENADO DE PRIMOS

int llenarPrimos(int primos [], int mini , int maxi){
bool primo;
int k = 0;
    for (int i = mini ; i <= maxi; i ++ ){
        primo = esPrimo(i);///LlAMADO A LA FUNCION PRIMO
        if (primo == true){
            primos[k]= i;
            k+=1;
        }
    }
    return k;
}
void mostrarPrimo (int primos [], int n){
cout << "Numeros primos en el rango:\n";
for (int i = 0 ; i <= n ; i++){
    cout << primos[i] << " |";
    }
    cout <<endl;
}
///COMPARAR CADENAS
int comparaCadenas(char cade1[], char cade2[]){
int resul;
resul = strcmp (cade1,cade2);///COMPARA 2 CADENAS
return resul;
}


/// FUNCION INVERTIR DE CADENAS
void invertirCad (char cade[]) {
int i = 0 , j, tam;
char aux;
tam = strlen (cade);
j = tam -1;
while (i < tam/ 2){
    aux = cade[i];
    cade [i]= cade[j];
    cade [j]= aux;
i+=1;
j-=1;
}
}

/// FUNCION ADMINISTRAR MENU
void opcionesMenu(){
    int opcion , resultado , mini , maxi;
    char cadena[50];/// DECLARACION DE LA CADENA
    int primos[100];///DECLARACION DEL VECTOR
    char cadena2[50];
    char cade[50];
    do{
    menu();
cout << "Elige una opcion del menu:";
cin >>opcion;


switch(opcion){
case 1 : cout <<"INGRESE TEXTO";
        fflush (stdin);/// LIBERA ESPACIO EN MEMORIA BUFFER
        gets(cadena);///LEE UNA CADENA DE TECLADO
        resultado = tamCadena(cadena);/// LLAMADO A LA FUNCION
        cout << "El tamaño de la cadena es de: "<<resultado<<"Caracteres "<<endl;
        break;

case 2 :
        cout <<"UN NOMBRE DE LENGUAJE DE PROGRAMACION";
        fflush (stdin);
        gets(cadena);
        cout <<"OTRO NOMBRE DE LENGUAJE DE PROGRAMACION";
        fflush (stdin);
        gets(cadena2);
        resultado = comparaCadenas(cadena , cadena2);
        if (resultado == 0){
            cout << "Las cadenas son iguales "<<endl;
        }else {
        cout << "Las cadenas son distintas"<<endl;
        }

         break;


case 3 :cout <<"INGRESA TEXTO ";
        fflush (stdin);
        gets(cadena);
        invertirCad(cadena);
        cout<<"Cadena invertida es: "<<cadena<<endl;
    break;


case 4 :cout << "Ingrese el limite inferior: ";
    cin >> mini;
    cout << "Ingrese el limite superior: ";
    cin >> maxi;
    resultado = llenarPrimos(primos , mini , maxi );///LLAMADO A FUNCION LLENA PRIMOS
    mostrarPrimo(primos ,resultado );
    cout << endl;


     break;
case 5 : break;
}}while (opcion != 5);
}




int main()
{
    opcionesMenu();

    return 0;
}
