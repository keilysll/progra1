#include <iostream>
#include <string>

using namespace std;

// Struct para representar la venta de pollo

struct Venta {
    string tipoPollo; // Tipo de pollo: entero, medio, cuarto o por presa
    int cantidad;     // Cantidad de pollos vendidos
    double precio;    // Precio por unidad (por ejemplo, por pollo entero, medio, etc.)
};

// Función para realizar una venta de pollo
void realizarVenta(Venta &venta) {
    cout << "Ingrese el tipo de pollo de forma textual (entero, medio, cuarto, presa): ";
    cin >> venta.tipoPollo;

    // Determinamos el precio según el tipo de pollo
    if (venta.tipoPollo == "entero") {
        venta.precio = 68; // Precio por pollo entero
    } else if (venta.tipoPollo == "medio") {
        venta.precio = 34; // Precio por medio pollo
    } else if (venta.tipoPollo == "cuarto") {
        venta.precio = 15; // Precio por cuarto pollo
    } else if (venta.tipoPollo == "presa") {
        venta.precio = 8; // Precio por presa
    } else {
        cout << "Tipo de pollo no válido. Asignando precio por defecto (pollo entero)." << endl;
        venta.precio = 68;
    }

    cout << "Ingrese la cantidad de pollos vendidos: ";
    cin >> venta.cantidad;
}

// Función para mostrar los detalles de una venta
void mostrarVenta(const Venta &venta) {
    cout << "\nResumen de la venta:" << endl;
    cout << "Tipo de Pollo: " << venta.tipoPollo << endl;
    cout << "Cantidad: " << venta.cantidad << endl;
    cout << "Precio por unidad: $" << venta.precio << endl;
    cout << "Total de la venta: $" << venta.precio * venta.cantidad << endl;
}

int main()

{
    Venta venta;  // Creamos una variable venta que será de tipo Venta


    		 realizarVenta(venta);
   		 mostrarVenta(venta); 	// Mostramos el resumen de la venta

    return 0;
}
