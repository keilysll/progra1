
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
