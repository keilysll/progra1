#include <iostream>
using namespace std;

void Llenarmatriz (int M1[][10], int filas, int columnas) {
    for(int i = 0; i < filas ; i++) {
        cout << "\n-- Carrera " << i+1 << " --\n";
        for (int j = 0 ; j < columnas ; j++) {
            cout << "Tiempo del corredor " << j+1 << ": ";
            cin >> M1[i][j];
        }
    }
}

void Mostrarmatriz (int M1[][10], int filas, int columnas) {
    cout << "\nTiempos registrados:\n";
    for(int i = 0; i < filas ; i++) {
        cout << "Carrera " << i+1 << ": ";
        for (int j = 0 ; j < columnas ; j++) {
            cout << M1[i][j] << " ";
        }
        cout << endl;
    }
}

void Resultados (int M1[][10], int filas, int columnas) {
    for(int i = 0; i < filas ; i++) {
        int menor = M1[i][0], mayor = M1[i][0];
        int ganador = 1, perdedor = 1;

        for (int j = 1; j < columnas ; j++) {
            if(M1[i][j] < menor) {
                menor = M1[i][j];
                ganador = j+1;
            }
            if(M1[i][j] > mayor) {
                mayor = M1[i][j];
                perdedor = j+1;
            }
        }
        cout << "\nCarrera " << i+1 << ": \n";
        cout << "  Ganador: Corredor " << ganador << " (tiempo " << menor << ") segundos\n";
        cout << "  Ultimo lugar: Corredor " << perdedor << " (tiempo " << mayor << ")segundos \n";
    }
}

int main() {
    int Matriz1[10][10];
    int f, c;

    cout << "Ingresa el nro de carreras: ";
    cin >> f;
    cout << "Ingresa el nro de corredores: ";
    cin >> c;

    Llenarmatriz(Matriz1, f, c);
    Mostrarmatriz(Matriz1, f, c);
    Resultados(Matriz1, f, c);

    return 0;
}
