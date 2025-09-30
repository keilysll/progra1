#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<string>
#include<cstring>

using namespace std;

void escribir()
{

    ofstream arch;
    string cadenatexto;
    string nuevo_archivo;

    cout <<"Ingresa el nombre del archivo que desea crear , junto a la extension"<<endl;
    getline(cin,nuevo_archivo);
    arch.open(nuevo_archivo.c_str(), ios::out);
    cout <<"Mencione un videojuego que le guste"<<endl;
    getline(cin,cadenatexto);
    arch<<"Videojuego favorito: "<<cadenatexto<<endl;
    arch.close();
}


void leer()
{
    string cadenapantalla,nuevo_archivo;
    ifstream archivo;
    ///archivo.open("prueba1.txt",ios :: in);

    cout <<"Ingresa el nombre del archivo que desea abrir, junto a la extension"<<endl;
    getline(cin,nuevo_archivo);
    archivo.open(nuevo_archivo.c_str(),ios :: in);

    if (archivo.fail())
    {
        cout << "No existe el archivo"<<endl;
        exit(1);
    }
    while (!archivo.eof())
    {
        getline(archivo,cadenapantalla);
        cout<<cadenapantalla<<endl;
        archivo.close();
    }
}

void agregar()
{
    ofstream archivo,nuevo_archivo;// modo app para actualizar el archivo
    string aniadirtexto;
    cout <<"Ingresa el nombre del archivo que desea agreagar algun dato, junto a la extension"<<endl;
    getline(cin,nuevo_archivo);
    archivo.open(nuevo_archivo.c_str(),ios :: app);

    ///archivo.open("prueba1.txt",ios::app);///Modo actualizar
    if (archivo.fail())
    {
        cout<<"No existe el archivo"<<endl;
        exit(1);
    }
    cout << "Agregar el texto que desea guardar en el archivo "<<endl;
    getline(cin,aniadirtexto);
    archivo<<aniadirtexto<<endl;

    archivo.close();
}

using namespace std;

int main()
{
   escribir();
   leer();
   agregar();
   leer();
   system("pause");
    return 0;
}
