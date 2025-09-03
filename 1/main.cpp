#include <iostream>
using namespace std;

int calcularTotal(int nroem) {
    int tipo, horas, pago, total = 0;

    for (int i = 1; i <= nroem; i++) {
        cout << "\nEmpleado #" << i << endl;
        cout << "Introduzca tipo de empleado (1, 2 o 3): ";
        cin >> tipo;
        cout << "Introduzca horas trabajadas: ";
        cin >> horas;

        if (tipo == 1) {
            pago = 30;
        } else if (tipo == 2) {
            pago = 50;
        } else if (tipo == 3) {
            pago = 100;
        } else {
            cout << "Tipo inválido. Se omite este empleado.\n";
            continue;
        }

        total += pago * horas;
    }

    return total;
}

int main() {
    int nroem;
    cout << "Introduzca número de empleados: ";
    cin >> nroem;

    int total = calcularTotal(nroem);
    cout << "\nEl total a pagar es: " << total << endl;

    return 0;
}








