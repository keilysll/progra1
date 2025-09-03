#include <iostream>
using namespace std;

void Llenarmatriz (int M1[][10], int filas, int columnas) {
    for(int i = 0; i < filas ; i++) {
        cout << "\n-- PRODUCTO " << i+1 << " --\n";
        for (int j = 0 ; j < columnas ; j++) {
            cout << "Ventas realizadas del producto " << j+1 << ": ";
            cin >> M1[i][j];
        }
    }
}

void Mostrarmatriz (int M1[][10], int filas, int columnas) {
    cout << "\n=== MATRIZ DE VENTAS ===\n";
    for(int i = 0; i < filas ; i++) {
        for (int j = 0 ; j < columnas ; j++) {
            cout << M1[i][j] << " ";
        }
        cout << endl;
    }
}

void Resultados (int M1[][10], int filas, int columnas) {
    int totalGeneral = 0;

    for(int i = 0; i < filas ; i++) {
        int menor = M1[i][0], mayor = M1[i][0];
        int vendedorMenor = 1, vendedorMayor = 1;
        int sumaProducto = M1[i][0];

        for (int j = 1; j < columnas ; j++) {
            sumaProducto += M1[i][j];

            if(M1[i][j] < menor) {
                menor = M1[i][j];
                vendedorMenor = j+1;
            }
            if(M1[i][j] > mayor) {
                mayor = M1[i][j];
                vendedorMayor = j+1;
            }
        }

        totalGeneral += sumaProducto;

        cout << "\n PRODUCTO " << i+1 << ":\n";
        cout << "  Vendedor que vendio mas: Vendedor " << vendedorMayor
             << " con " << mayor << " ventas.\n";
        cout << "  Total vendido de este producto: " << sumaProducto << "\n";
    }

    cout << "\n=== TOTAL GENERAL DE TODOS LOS PRODUCTOS ===\n";
    cout << "  " << totalGeneral << " ventas en total.\n";
}

int main() {
    int Matriz1[10][10];
    int f, c;

    cout << "Ingresa el nro de productos: ";
    cin >> f;
    cout << "Ingresa el nro de empleados: ";
    cin >> c;

    Llenarmatriz(Matriz1, f, c);
    Mostrarmatriz(Matriz1, f, c);
    Resultados(Matriz1, f, c);

    return 0;
}
