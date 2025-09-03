#include <iostream>
using namespace std;

float obtenerCosto(int origen, int destino) {
    if (origen == 1 && destino == 3) return 2000;
    else if (origen == 2 && destino == 3) return 2800;
    else if (origen == 4 && destino == 6) return 2180;
    else if (origen == 5 && destino == 6) return 1980;
    else if (origen == 1 && destino == 2) return 2150;
    else if (origen == 4 && destino == 2) return 3150;
    else return 0;
}

float obtenerDescuento(int origen, int destino, float costo) {
    if ((origen == 1 || origen == 2) && destino == 3) {
        return costo * 0.22; // 22%
    }
    else if ((origen == 4 || origen == 5) && destino == 6) {
        return costo * 0.35; // 35%
    }
    else if ((origen == 1 || origen == 4) && destino == 2) {
        return costo * 0.35; // 35%
    }
    else {
        return 0;
    }
}

void mostrarMenu() {
    cout << "------ ORIGEN / DESTINO ------" << endl;
    cout << "1. Bolivia\n2. Brasil\n3. Peru\n4. Argentina\n5. Chile\n6. Colombia\n";
}

int main() {
    int origen, destino, cantidadPasajes;
    float costo, descuento;
    float totalRecaudado = 0, totalDescuento = 0, totalFinal = 0;

    cout << "Ingrese la cantidad de pasajes que desea comprar: ";
    cin >> cantidadPasajes;

    for (int i = 1; i <= cantidadPasajes; i++) {
        cout << "Pasajero " << i << endl;
        mostrarMenu();
        cout << "Seleccione su origen: ";
        cin >> origen;
        mostrarMenu();
        cout << "Seleccione su destino: ";
        cin >> destino;

        costo = obtenerCosto(origen, destino);

        if (costo == 0) {
            cout << "RUTA NO DISPONIBLE\n";
        } else {
            descuento = obtenerDescuento(origen, destino, costo);
            float totalPagar = costo - descuento;

            totalRecaudado += costo;
            totalDescuento += descuento;
            totalFinal += totalPagar;

            cout << "Costo del pasaje: " << costo << " Bs\n";
            cout << "Descuento: " << descuento << " Bs\n";
            cout << "Total a pagar: " << totalPagar << " Bs\n";
        }
    }

    cout << "\n------ RESUMEN ------\n";
    cout << "Total recaudado (sin descuentos): " << totalRecaudado << " Bs\n";
    cout << "Total de descuentos: " << totalDescuento << " Bs\n";
    cout << "Total final recaudado: " << totalFinal << " Bs\n";

    return 0;
}
