#include <iostream>

using namespace std;

int main()
{
    int edad;
    cout << "INGRESE SU EDAD"<<endl;
    cin >> edad;

    if (edad >= 1 && edad <= 10) {
        cout << "El paciente debe realizarse el analisis A, B y C" << endl;
        cout << "El costo es de: 300bs" << endl;
    } else if (edad >= 11 && edad <= 24) {
        cout << "El paciente debe realizarse el analisis A, C, D y E" << endl;
        cout << "El costo es de: 750bs" << endl;
    } else if (edad >= 25 && edad <= 54) {
        cout << "El paciente debe realizarse el analisis A, C, E y F" << endl;
        cout << "El costo es de: 1500bs" << endl;
    } else if (edad >= 55) {
        cout << "El paciente debe realizarse el analisis A, B, D, E y F" << endl;
        cout << "El costo es de: 2500bs" << endl;
    } else {
        cout << "Edad inválida." << endl;
    }

    return 0;
}






















