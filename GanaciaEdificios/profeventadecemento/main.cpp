#include <iostream>
using namespace std;

// Struct que representa la información de una sucursal

struct Sucursal {
    string nombre;    // Nombre de la sucursal
    int cantidad;     // Cantidad de cemento vendida
    float precio;     // Precio del cemento
    float descuento;  // Descuento aplicado
    float total;      // Total a pagar después del descuento
};

// Función para ingresar los datos de una sucursal

void ingresarDatosSucursal(Sucursal& sucursal) {
    cout << "Ingrese el nombre de la sucursal: ";
    cin >> sucursal.nombre;
    cout << "Ingrese la cantidad de cemento vendida: ";
    cin >> sucursal.cantidad;
    cout << "Ingrese el precio del cemento: ";
    cin >> sucursal.precio;
}

// Función para calcular el descuento y el total

void calcularDescuentoYTotal(Sucursal& sucursal) {
    // Descuentos según la cantidad vendida
    if (sucursal.cantidad >= 1000) {
        sucursal.descuento = 0.20;  // 20% de descuento
    } else if (sucursal.cantidad >= 500) {
        sucursal.descuento = 0.10;  // 10% de descuento
    } else {
        sucursal.descuento = 0.0;   // Sin descuento
    }

    // Calculando el total

    float totalSinDescuento = sucursal.cantidad * sucursal.precio;
    sucursal.total = totalSinDescuento - (totalSinDescuento * sucursal.descuento);
}

// Función para mostrar la información de una sucursal
void mostrarReporteSucursal(const Sucursal& sucursal) {
    cout << "\nSucursal: " << sucursal.nombre << endl;
    cout << "Cantidad vendida: " << sucursal.cantidad << endl;
    cout << "Precio por unidad: " << sucursal.precio << endl;
    cout << "Descuento aplicado: " << (sucursal.descuento * 100) << "%" << endl;
    cout << "Total a pagar: " << sucursal.total << endl;
}



int main()
{
    Sucursal sucursales[3];  // Arreglo de 3 sucursales— variable sucursales de tipo Sucursal

    // Ingresar los datos de las 3 sucursales

	 for (int i = 0; i < 3; i++) {
        ingresarDatosSucursal(sucursales[i]);
        calcularDescuentoYTotal(sucursales[i]);
    }

    // Mostrar el reporte de cada sucursal
    for (int i = 0; i < 3; i++) {
        mostrarReporteSucursal(sucursales[i]);
    }

    return 0;
}
