#include <iostream>
using namespace std;

void cargarMatriz2x2(int A[2][2]) {
    cout << "Ingrese valores para la matriz A (2x2):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
}


void cargarMatriz2x3(int B[2][3]) {
    cout << "Ingrese valores para la matriz B (2x3):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }
}

void multiplicarMatrices(int A[2][2], int B[2][3], int C[2][3]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


void mostrarMatriz2x3(int C[2][3]) {
    cout << "\nMatriz resultado C (2x3):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int A[2][2], B[2][3], C[2][3];


    cargarMatriz2x2(A);
    cargarMatriz2x3(B);

    multiplicarMatrices(A, B, C);
    mostrarMatriz2x3(C);

    return 0;
}
