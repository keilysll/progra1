# STRCPY

#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

int main (){

 char cadena[100],cadena2[100];
 cout<<"Ingrese una cadena de caracteres: ";
 cin.getline(cadena,100);
 strcpy(cadena2,cadena);
 cout<<cadena2;
  getch();
  return 0;
}

#STRLEN

#include<iostream>
#include<string.h>

using namespace std;

int main(){
 char letras[30];
 int longitud = 0;

 cout<<"digite su nombre: ";
 cin.getline(letras,30,'\n');

 cout<<letras<<endl;

 longitud = strlen(letras);

 if(longitud < 10){
  cout<<"numero de elementos de la cadena es: "<<longitud<<endl;
 }
 else{
  cout<<"el numero supera la longitud";
 }


 return 0;
}
#STRCMP

using namespace std;
int main (){
     char palabra[50];
     cout << "escriba palabra 1: "<<endl;
     gets (palabra);
     char palabra2 [50];
     cout << "escriba palabra 2:"<<endl;
     gets (palabra2);

     if(strcmp (palabra , palabra2)== 0){
        cout << "ambas cadenas son iguales "<<endl;
     }else if (strcmp (palabra , palabra2 )> 0){
        cout << "no son iguales , pero:"<<palabra<< "esta despues alfabeticamente "<<endl;
    }else {
        cout << "no son iguales , pero:"<<palabra2<< "esta despues alfabeticamente "<<endl;  }



 return 0;
}

#STRCAT

#include<iostream>
#include<string.h>

using namespace std;
int main (){
    char cad1 [] = "hola que tal  ";
    cout << cad1<<endl;
    char usu[30];
    cout << "ingrese su nombre " << endl;
    gets (usu);
    char cad3 [30];

    strcpy (cad3, cad1);
    strcat (cad3, usu);

    cout << cad3 <<endl;



 return 0;
}


#STRREV

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char palab[20],resolucion[20];

    cout << "Ingrese palabra: " << endl; cin.getline(palab,20,'\n');

    strcpy(resolucion,palab);

    strrev(palab);

    if(strcmp(resolucion,palab)==0)
    {
        cout<< "Es polindroma" <<endl;
    }
    else
    {
        cout<<"No es polindroma"<<endl;
    }


    return 0;}





#include <iostream>
#include <string.h>
using namespace std;

int main()
{
 char frase [50];
 int va = 0, ve = 0 , vi = 0, vo = 0 , vu =0;
 cout << "digite una frse ";
cin.getline (frase , 50);
  for (int i = 0 ; i < 50 ; i ++){
    switch (frase[i]){
        case 'a': va++; break;
        case 'e': ve++; break;
        case 'i': vi++; break;
        case 'o': vo++; break;
        case 'u': vu++; break ;
  }
  }
  cout <<"vocal a :"<<va<<endl;
  cout <<"vocal e :"<<ve<<endl;
   cout <<"vocal i:"<<vi<<endl;
    cout <<"vocal o :"<<vo<<endl;
     cout <<"vocal u :"<<vu<<endl;

    return 0;}









