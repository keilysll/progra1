#include <iostream>
using namespace std;

struct Producto {
    int codigo;
    char nombre[30];
    float precio;
    int totalUnidades;
    float totalVendido;
};

struct Compra {
    int codigoProducto;
    int cantidad;
};

struct Cliente {
    char nombre[30];
    long long CI;
    int nCompras;
    Compra compras[10];
};

void registrarProductos(Producto productos[], int nProd) {
    for (int i = 0; i < nProd; i++) {
        productos[i].codigo = i;
        cin.ignore();
        cout << "Ingrese el nombre del producto " << i + 1 << ": ";
        cin.getline(productos[i].nombre, 30);
        cout << "Ingrese el precio unitario del producto: ";
        cin >> productos[i].precio;
        productos[i].totalUnidades = 0;
        productos[i].totalVendido = 0;
    }
}

void registrarClientes(Cliente clientes[], int nCli, Producto productos[], int nProd) {
    for (int i = 0; i < nCli; i++) {
        cout << "\n--- Registro del cliente " << i + 1 << " ---\n";
        cin.ignore();
        cout << "Nombre: ";
        cin.getline(clientes[i].nombre, 30);
        cout << "CI: ";
        cin >> clientes[i].CI;
        cout << "Cuantos productos va a comprar este cliente?: ";
        cin >> clientes[i].nCompras;

        for (int j = 0; j < clientes[i].nCompras; j++) {
            cout << "Ingrese el codigo del producto (0-" << nProd - 1 << "): ";
            cin >> clientes[i].compras[j].codigoProducto;
            cout << "Cantidad a comprar: ";
            cin >> clientes[i].compras[j].cantidad;

            int cod = clientes[i].compras[j].codigoProducto;
            int cant = clientes[i].compras[j].cantidad;


            productos[cod].totalUnidades += cant;
            productos[cod].totalVendido += cant * productos[cod].precio;

            if (cant > 100)
                cout << "Compra al por MAYOR.\n";
            else
                cout << "Compra al por MENOR.\n";
        }
    }
}

void mostrarResultados(Producto productos[], int nProd) {
    float totalGeneral = 0.0;
    cout << "\n===== RESULTADOS DE LAS VENTAS =====\n";
    for (int i = 0; i < nProd; i++) {
        cout << "Producto: " << productos[i].nombre << endl;
        cout << "Codigo: " << productos[i].codigo << endl;
        cout << "Unidades vendidas: " << productos[i].totalUnidades << endl;
        cout << "Total vendido: " << productos[i].totalVendido << endl;
        cout << "-----------------------------------\n";
        totalGeneral += productos[i].totalVendido;
    }
    cout << "TOTAL GANADO EN TODAS LAS VENTAS: " << totalGeneral << endl;
}

int main() {
    int nProd, nCli;

    cout << "Cuantos productos desea registrar?: ";
    cin >> nProd;
    Producto productos[nProd];
    registrarProductos(productos, nProd);

    cout << "\nCuantos clientes desea registrar?: ";
    cin >> nCli;
    Cliente clientes[nCli];
    registrarClientes(clientes, nCli, productos, nProd);

    mostrarResultados(productos, nProd);

    return 0;
}
