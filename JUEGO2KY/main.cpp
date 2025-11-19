#include <iostream>
#include<windows.h>
#include<fstream>
#include<ctime>
#include<cstring>

using namespace std;

struct jugador {
char nombre [50];
int puntos;
};

int cargarArchivo(jugador lista[])
{
    ifstream archivo("datos.txt");
    int count = 0 ;
    if (archivo.is_open())
    {
        while(!archivo.eof())
        {
            archivo>>lista[count].nombre>>lista[count].puntos;
            if (archivo.fail())break;
            count ++;
        }
    }
    return count;
}

void ordenar(jugador arr[], int n)
{
    for(int i = 0 ; i < n -1; i++)
    {
        for (int j = 0 ; j < n-i; j ++)
        {
            if(arr[j].puntos < arr[j+1].puntos)
                {
                    jugador temp = arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]= temp;
                }
        }
    }
}

void guardarArchivo( jugador arr[], int i)
{
    ordenar(arr,n);
    ifstream archivo("datos.txt");
    for (int i = 0 ; i < n ; i++)
    {
        archivo<<arr[i].nombre<<" "<<arr[i].puntos<<"\n";
    }
    archivo.close();
}

bool buscar (jugador &j)
{
    ifstream archivo ("datos.txt");
    jugador temp;
    if (archivo.open())
    {
        while(archivo>>temp.nombre>>temp.puntos)
        {
            if (strcmp(temp.nombre,j.nombre)== 0)
            {
                j.puntos = temp.puntos;
                archivo.close();
                return true;
            }

        }
    }

    return false;
}

int buscarJugador(jugador lista[], int total , char nombre[])
{
    for (int i = 0 ; i < n ; i++)
    {
        if (strcmp(lista[i].nombre,nombre)== 0)
        {
            return 1;
        }
    }
    return -1;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
