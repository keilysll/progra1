#include <iostream>
 /// LLENAR MATRIZ  5 X 6 Y MOTRAR TOTAL DE TODOS LOS ELEMENTOS

using namespace std;

void Llenarmatriz (int M1 [][10],int filas, int columnas)
{
    for(int i = 0; i < filas ; i++)
{
    for (int j = 0 ; j< columnas ; j++)
{
    cout << "ingresar el dato de matriz : ["<<i<<"]["<<j<<"]=";
    cin >>M1[i][j];
        }
    }

}


void Mostrarmatriz (int M1 [][10],int filas, int columnas)
{
    for(int i = 0; i < filas ; i++)
{
    for (int j = 0 ; j< columnas ; j++)
{
    cout << "ingresar el dato de matriz : ["<<i<<"]["<<j<<"]="<<M1 [i][j]<<endl;

        }
    }

}

int Sumarmatriz (int M1 [][10],int filas, int columnas)
{
    int suma = 0;
    for(int i = 0; i < filas ; i++)
{
    for (int j = 0 ; j< columnas ; j++)
{

    suma = suma + M1[i][j];
        }
    }
    return suma;

}



int main()
{
    int Matriz1[10][10];
    int Matriz2[5][5];
    int resultado;
    int f,c;

    cout << " ingrese el tamaño de filas ";
    cin>>f;
    cout <<"ingrese el tamaño de columnas ";
    cin>>c;

  Llenarmatriz (Matriz1,f,c);
  Mostrarmatriz(Matriz1,f,c);
  resultado = Sumarmatriz(Matriz1,f,c);
    cout<<"La suma de los valores de la matriz es: " <<resultado<<endl;

    return 0 ;

}
