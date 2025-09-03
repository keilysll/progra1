#include <iostream>
using namespace std;

void Llenarmatriz (int M1 [][10], int filas, int columnas)
{
    for(int i = 0; i < filas ; i++)
    {
        for (int j = 0 ; j< columnas ; j++)
        {
            cout << "Ingresar el dato de matriz : ["<<i<<"]["<<j<<"]=";
            cin >> M1[i][j];
        }
    }
}

void Mostrarmatriz (int M1 [][10], int filas, int columnas)
{
    cout << "\nMatriz ingresada:\n";
    for(int i = 0; i < filas ; i++)
    {
        for (int j = 0 ; j< columnas ; j++)
        {
            cout << M1[i][j] << "\t";
        }
        cout << endl;
    }
}

void SumarColumnas (int M1 [][10], int filas, int columnas, int vectorSuma[])
{
    for (int j = 0; j < columnas; j++)
    {
        int suma = 0;
        for (int i = 0; i < filas; i++)
        {
            suma += M1[i][j];
        }
        vectorSuma[j] = suma;
    }
}

void MostrarVector (int vec[], int tam)
{
    cout << "\nSuma de cada columna: \n";
    for (int i = 0; i < tam; i++)
    {
        cout << "Columna " << i << " = " << vec[i] << endl;
    }
}

int main()
{
    int Matriz1[10][10];
    int vectorSuma[10];
    int f, c;

    cout << "Ingrese el tamaño de filas: ";
    cin >> f;
    cout <<"Ingrese el tamaño de columnas: ";
    cin >> c;

    Llenarmatriz(Matriz1, f, c);
    Mostrarmatriz(Matriz1, f, c);
    SumarColumnas(Matriz1, f, c, vectorSuma);
    MostrarVector(vectorSuma, c);

    return 0;
}
