#include <iostream>
#include <cstring>
using namespace std;

struct Producto {
    char nombre[20];
    int stock;
    float precio;
};

struct Compra {
    char nombre[20];
    int cantidad;
};

// Buscar producto por nombre
int buscarProducto(Producto prod[], int n, char nombre[]) {
    for (int i = 0; i < n; i++)
        if (strcmp(prod[i].nombre, nombre) == 0)
            return i;
    return -1; // no encontrado
}

// Cargar productos
void cargarProductos(Producto prod[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nombre producto: ";
        cin >> prod[i].nombre;
        cout << "Stock: ";
        cin >> prod[i].stock;
        cout << "Precio: ";
        cin >> prod[i].precio;
        cout << endl;
    }
}

// Cargar compras con validación
void cargarCompras(Compra comp[], int n, Producto prod[], int numProd) {
    for (int i = 0; i < n; i++) {
        int pos = -1;

        // Validar producto
        while (pos == -1) {
            cout << "Producto a comprar: ";
            cin >> comp[i].nombre;
            pos = buscarProducto(prod, numProd, comp[i].nombre);
            if (pos == -1)
                cout << "Producto no existe. Intente nuevamente.\n";
        }

        // Validar cantidad
        cout << "Cantidad: ";
        cin >> comp[i].cantidad;
        while (comp[i].cantidad <= 0 || comp[i].cantidad > prod[pos].stock) {
            cout << "Cantidad inválida o insuficiente. Stock: " << prod[pos].stock << ". Ingrese nuevamente: ";
            cin >> comp[i].cantidad;
        }
    }
}

// Procesar compras: calcular totales y descontar stock
void procesarCompras(Producto prod[], Compra comp[], int n,
                     float totalSinDesc[], float totalConDesc[]) {

    for (int i = 0; i < n; i++) {
        int pos = buscarProducto(prod, n, comp[i].nombre);

        float sinDesc = prod[pos].precio * comp[i].cantidad;
        float conDesc;

        // Aplicar descuento si cantidad > 1500
        if (comp[i].cantidad > 1500)
            conDesc = sinDesc * 0.85; // 15% descuento
        else
            conDesc = sinDesc;        // sin descuento

        prod[pos].stock -= comp[i].cantidad;

        if (prod[pos].stock == 0)
            cout << prod[pos].nombre << " se ha agotado.\n";

        totalSinDesc[pos] += sinDesc;
        totalConDesc[pos] += conDesc;

        cout << "Compra registrada.\n\n";
    }
}

// Mostrar totales
void mostrarTotales(Producto prod[], int n, float sinDesc[], float conDesc[]) {
    float totalGeneral = 0;
    cout << "\n=== TOTALES ===\n";
    for (int i = 0; i < n; i++) {
        cout << "Producto: " << prod[i].nombre << endl;
        cout << "Total sin descuento: " << sinDesc[i] << endl;
        cout << "Total con descuento: " << conDesc[i] << endl;
        cout << endl;
        totalGeneral += conDesc[i];
    }
    cout << "TOTAL GENERAL: " << totalGeneral << endl;
}

int main() {
    const int N = 3;

    Producto productos[N];
    Compra compras[N];
    float totalSinDesc[N] = {0};
    float totalConDesc[N] = {0};

    cout << "=== REGISTRO DE PRODUCTOS ===\n";
    cargarProductos(productos, N);

    cout << "=== REGISTRO DE COMPRAS ===\n";
    cargarCompras(compras, N, productos, N);

    cout << "=== PROCESANDO COMPRAS ===\n";
    procesarCompras(productos, compras, N, totalSinDesc, totalConDesc);

    mostrarTotales(productos, N, totalSinDesc, totalConDesc);

    return 0;
}

