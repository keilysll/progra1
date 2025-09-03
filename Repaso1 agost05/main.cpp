#include <iostream>

using namespace std;

int main() {
    int opcion;
    int cantidad;

    int totalLaPaz = 0;
    int totalOruro = 0;
    int totalSantaCruz = 0;
    int pasajesLaPaz = 0;
    int pasajesOruro = 0;
    int pasajesSantaCruz = 0;

    cout << "=== SISTEMA DE VENTA DE PASAJES ===" << endl;

    do {
        cout << "\nSeleccione el destino:" << endl;
        cout << "1. La Paz (550 Bs)" << endl;
        cout << "2. Santa Cruz (820 Bs)" << endl;
        cout << "3. Oruro (550 Bs)" << endl;
        cout << "4. Salir y mostrar resumen" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "¿Cuantos pasajes desea comprar para La Paz? ";
            cin >> cantidad;
            pasajesLaPaz = pasajesLaPaz + cantidad;
            totalLaPaz = totalLaPaz + (cantidad * 550);
        }

        if (opcion == 2) {
            cout << "¿Cuantos pasajes desea comprar para Santa Cruz? ";
            cin >> cantidad;
            pasajesSantaCruz = pasajesSantaCruz + cantidad;
            totalSantaCruz = totalSantaCruz + (cantidad * 820);
        }

        if (opcion == 3) {
            cout << "¿Cuantos pasajes desea comprar para Oruro? ";
            cin >> cantidad;
            pasajesOruro = pasajesOruro + cantidad;
            totalOruro = totalOruro + (cantidad * 550);
        }

        if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4) {
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }

    } while (opcion != 4);

    int totalGeneral = totalLaPaz + totalSantaCruz + totalOruro;

    cout << "\n=== RESUMEN DE VENTAS ===" << endl;
    cout << "Total ganado: " << totalGeneral << " Bs" << endl;
    cout << "Pasajes vendidos por destino:" << endl;
    cout << " - La Paz: " << pasajesLaPaz << " pasajes (Total: " << totalLaPaz << " Bs)" << endl;
    cout << " - Santa Cruz: " << pasajesSantaCruz << " pasajes (Total: " << totalSantaCruz << " Bs)" << endl;
    cout << " - Oruro: " << pasajesOruro << " pasajes (Total: " << totalOruro << " Bs)" << endl;

    return 0;
}
