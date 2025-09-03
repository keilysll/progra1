#include <iostream>
using namespace std;

void interesA(float v1[], float vec2[], int tam) {
    for (int i = 0; i < tam; i++) {
        vec2[i] = v1[i] * 0.05;
    }
}

void mostrarvector(float vec[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Mes " << i + 1 << " = " << vec[i] << endl;
    }
}

float sumarvector(float vec[], int tam) {
    float suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += vec[i];
    }
    return suma;
}

int main() {
    const int MESES = 12;
    float depositos[MESES] = {0}, intereses[MESES] = {0};
    int trimestre;

    cout << "Ingrese de que trimestre quiere depositar: (1er , 2do , 3er o 4to) ";
    cin >> trimestre;

    if (trimestre < 1 || trimestre > 4) {
        cout << "Trimestre inválido. Debe ser entre 1 y 4.\n";
        return 0;
    }

    int inicio = (trimestre - 1) * 3;
    int fin = inicio + 3;

    for (int i = inicio; i < fin; i++) {
        cout << "Ingrese el deposito del mes " << i + 1 << ": ";
        cin >> depositos[i];
    }

    interesA(depositos, intereses, MESES);

    cout << "\n--- Depositos (12 meses) ---\n";
    mostrarvector(depositos, MESES);

    cout << "\n--- Intereses (5%) ---\n";
    mostrarvector(intereses, MESES);

    cout << "\nTotal de depositos = " << sumarvector(depositos, MESES) << endl;
    cout << "Total de intereses = " << sumarvector(intereses, MESES) << endl;
    cout << "Total acumulado (Depositos + Intereses) = "
         << sumarvector(depositos, MESES) + sumarvector(intereses, MESES)
         << endl;

    return 0;
}
