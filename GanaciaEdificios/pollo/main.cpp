#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Pollo {
    string tipo;   // Broaster, Spiedo, Leña
    float precio;  // Precio por pollo entero
    int stock;     // Unidades disponibles
    float ventaTotal; // Total vendido de este tipo
};

struct VentasPorcion {
    float entero = 0;
    float medio = 0;
    float cuarto = 0;
    float presa = 0;
};

VentasPorcion ventasPorcion; // Acumula ventas por porción
float totalDia = 0;          // Acumula todo lo ganado del día

// --- FUNCIONES ---
void llenarStock(Pollo p[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el stock disponible para " << p[i].tipo << ": ";
        cin >> p[i].stock;
    }
}

void mostrarStock(Pollo p[], int n) {
    cout << "\n=== STOCK ACTUAL ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i].tipo << ": " << p[i].stock << " unidades (Precio: "
             << p[i].precio << " Bs)" << endl;
    }
}

float realizarPedido(Pollo &pollo, int tipoPollo) {
    int opcion, cantidad;
    float subtotal = 0;

    cout << "\n--- " << pollo.tipo << " ---" << endl;
    cout << "1. Entero (" << pollo.precio << " Bs)" << endl;
    cout << "2. 1/2 (" << pollo.precio / 2 << " Bs)" << endl;
    cout << "3. 1/4 (" << pollo.precio / 4 << " Bs)" << endl;
    cout << "4. 1 presa (" << pollo.precio / 8 << " Bs)" << endl;
    cout << "Seleccione la porción: ";
    cin >> opcion;

    cout << "Ingrese cantidad: ";
    cin >> cantidad;

    if (cantidad > pollo.stock) {
        cout << "No hay suficiente stock." << endl;
        return 0;
    }

    switch (opcion) {
        case 1:
            subtotal = pollo.precio * cantidad;
            ventasPorcion.entero += subtotal;
            break;
        case 2:
            subtotal = (pollo.precio / 2) * cantidad;
            ventasPorcion.medio += subtotal;
            break;
        case 3:
            subtotal = (pollo.precio / 4) * cantidad;
            ventasPorcion.cuarto += subtotal;
            break;
        case 4:
            subtotal = (pollo.precio / 8) * cantidad;
            ventasPorcion.presa += subtotal;
            break;
        default:
            cout << "Opción inválida." << endl;
            return 0;
    }

    pollo.stock -= cantidad;
    pollo.ventaTotal += subtotal;
    totalDia += subtotal;

    cout << "Subtotal agregado: " << subtotal << " Bs" << endl;
    return subtotal;
}

void registrarPedido(Pollo p[], int n) {
    int opcion;
    float totalCliente = 0;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        cout << "\n=== MENU POLLOS ===" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << ". " << p[i].tipo
                 << " (Entero: " << p[i].precio
                 << " Bs, Stock: " << p[i].stock << ")" << endl;
        }
        cout << "Seleccione el pollo: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= n) {
            totalCliente += realizarPedido(p[opcion - 1], opcion - 1);
        } else {
            cout << "Opción inválida." << endl;
        }

        cout << "¿Desea agregar otro pedido? (s/n): ";
        cin >> continuar;
    }

    cout << "\nTOTAL DEL CLIENTE: " << totalCliente << " Bs\n";
}

void guardarReporte(Pollo p[], int n) {
    ofstream archivo("reporte_ventas.txt");

    if (archivo.fail()) {
        cout << "Error al crear el archivo." << endl;
        return;
    }

    archivo << "=== REPORTE DE VENTAS DEL DIA ===\n\n";
    archivo << "Ventas por tipo de pollo:\n";
    for (int i = 0; i < n; i++) {
        archivo << p[i].tipo << ": " << p[i].ventaTotal << " Bs\n";
    }

    archivo << "\nVentas por porción:\n";
    archivo << "Entero: " << ventasPorcion.entero << " Bs\n";
    archivo << "1/2: " << ventasPorcion.medio << " Bs\n";
    archivo << "1/4: " << ventasPorcion.cuarto << " Bs\n";
    archivo << "1 presa: " << ventasPorcion.presa << " Bs\n";

    archivo << "\nTOTAL GANADO EN EL DIA: " << totalDia << " Bs\n";

    archivo.close();
    cout << "\n*** Reporte guardado en 'reporte_ventas.txt' ***" << endl;
}

// --- MENU PRINCIPAL ---
void menuPrincipal() {
    const int n = 3;
    Pollo p[n] = {
        {"Broaster", 80, 0, 0},
        {"Spiedo", 70, 0, 0},
        {"A la leña", 75, 0, 0}
    };

    int opcion;
    do {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Administrar stock" << endl;
        cout << "2. Registrar pedido" << endl;
        cout << "3. Mostrar stock" << endl;
        cout << "4. Finalizar día y guardar reporte" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                llenarStock(p, n);
                break;
            case 2:
                registrarPedido(p, n);
                break;
            case 3:
                mostrarStock(p, n);
                break;
            case 4:
                guardarReporte(p, n);
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 4);
}

int main() {
    menuPrincipal();
    return 0;
}
