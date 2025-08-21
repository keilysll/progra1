#include <iostream>
using namespace std;

void interesA (float v1[], float vec2[], int tam) {
    for (int i = 0; i < tam ; i++) {
        vec2[i] = v1[i] * 0.05;
    }
}

void cargarvector(float vec[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese un deposito: ";
        cin >> vec[i];
    }
}

void mostrarvector(float vec[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Deposito[" << i+1 << "] = " << vec[i] << endl;
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
    int n;
    cout << "Cuantos depositos desea ingresar?: ";
    cin >> n;

    float depositos[n], intereses[n];

    cargarvector(depositos, n);

    cout << "\n--- Depositos ---\n";
    mostrarvector(depositos, n);

    interesA(depositos, intereses, n);

    cout << "\n--- Intereses (5%) ---\n";
    mostrarvector(intereses, n);

    cout << "\nSuma total de depositos = " << sumarvector(depositos, n) << endl;
    cout << "Suma total de intereses = " << sumarvector(intereses, n) << endl;

    return 0;
}
