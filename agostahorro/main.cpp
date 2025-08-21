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


    float ahorro [12];
    int trimestre;
    float intereses [12];
    cout << "Ingrese de que trimestre quiere depositar: (1er , 2do , 3er o 4to) ";
    cin>>trimestre;
    switch(trimestre)
    {
    case 1:
        cargarvector(ahorro,3,0);
        break;
    case 2:
        cargarvector(ahorro,3,3);
        break;
    case 3:
        cargarvector(ahorro,3,6);
        break;
    case 4:
         cargarvector(ahorro,3,9);
         break;

    default:
        cout << "Su eleccion es erronea"<<endl;
        break;
    }
    cout << "\n--- Depositos ---\n";
    mostrarvector(ahorro,12);
    cout<<endl;

    interesA(ahorro, intereses, 12);

    cout << "\n--- Intereses (5%) ---\n";
    mostrarvector(intereses,12);
    cout << "\nSuma total de depositos = " << sumarvector(depositos, n) << endl;
    cout << "Suma total de intereses = " << sumarvector(intereses, n) << endl;

}












