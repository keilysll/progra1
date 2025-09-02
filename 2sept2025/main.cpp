#include <iostream>
using namespace std;

void llenarVector(int vect[], int n) {
    for (int i = 0; i < n; i++) {
    }
}

void mostrarVector(int vect[], int n) {
    for (int i = 0; i < n; i++) {
        cout << vect[i] << " ";
    }


    cout << endl;
}

void CargarVentaHelados(int M1 [][10],int filas, int columnas)

{
    for(int i = 0; i < filas ; i++)
{
    for (int j = 0 ; j< columnas ; j++)
{
   cout << "Dia " << j+1 << ": ";
            cin >> M1[i][j];
        }
    }

}

void Mostrarmatriz (int M1[][10], int filas, int columnas) {
    for(int i = 0; i < filas ; i++) {
        for (int j = 0 ; j < columnas ; j++) {
            cout << M1[i][j] << " ";
        }
        cout << endl;
    }
}





int main()
{

    int Matriz1[10][10];
    int f, c;
    int vectPreciosHelados[4]= {85,45,25,15};
    int vcetPreciosMasas[2] = {8,10};

    cout << "Ingresa el nro de productos: ";
    cin >> f;
    cout << "Ingresa el nro de dias: ";
    cin >> c;

    CargarVentaHelados(Matriz1, f, c);
    Mostrarmatriz(Matriz1, f, c);


    return 0;
}
