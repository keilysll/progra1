#include <iostream>
#include <cstring>

using namespace std;

// =======================
//      STRUCTS
// =======================

struct producto
{
    char nombre[40];
    int cantidadAlmacen;     // ← agregado según el enunciado
    double precio;
};

struct venta
{
    char nombre[40];
    int cantidad;
};

// Variables globales de totales
double totalDescuento = 0;
double totalSinDescuento = 0;

// ==========================
//   INGRESO DE PRODUCTOS
// ==========================

void Coolocarprecios(producto p[])
{
    for(int i = 0; i < 4; i++)
    {
        cout << "\n---PRODUCTO " << i+1 << "-------\n";
        cout << "Nombre: ";
        cin.getline(p[i].nombre, 40, '\n');

        cout << "Precio: ";
        cin >> p[i].precio;

        cout << "Cantidad en almacén: ";
        cin >> p[i].cantidadAlmacen;

        cin.ignore();
    }
}

// =====================================
//   REGISTRO DE VENTAS (CON CONTROL)
// =====================================

void Registrar(venta v[][5], producto p[])
{
    for(int i = 0; i < 4; i++)
    {
        cout << "\nRegistro de ventas del producto: " << p[i].nombre << endl;

        for(int j = 0; j < 5; j++)
        {
            cout << "Dia " << j+1 << " - Cantidad vendida: ";
            cin >> v[i][j].cantidad;
            cin.ignore();
            strcpy(v[i][j].nombre, p[i].nombre);  // siempre asignar nombre

            // Venta mínima de 300 unidades
            if(v[i][j].cantidad < 300)
            {
                cout << "Error: la venta debe ser de al menos 300 unidades.\n";
                v[i][j].cantidad = 0;
                continue;
            }

            // Verificación de almacén
            if(v[i][j].cantidad > p[i].cantidadAlmacen)
            {
                cout << "No hay suficiente cantidad en el almacen.\n";
                v[i][j].cantidad = 0;
                continue;
            }

            // Descontar del almacén
            p[i].cantidadAlmacen -= v[i][j].cantidad;

            // Calcular total
            double total = v[i][j].cantidad * p[i].precio;

            // Aplicar descuento si corresponde
            if(v[i][j].cantidad > 1500)
            {
                total = total - (total * 0.15);
                totalDescuento += total;
                cout << "Venta con descuento. Total pagado: " << total << endl;
            }
            else
            {
                totalSinDescuento += total;
                cout << "Venta sin descuento. Total pagado: " << total << endl;
            }
        }
    }
}

// ==============================
// MOSTRAR MATRIZ DE CANTIDADES
// ==============================

void mostrar(venta v[][5])
{
    cout << "\n=== MATRIZ DE VENTAS ===\n";
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << v[i][j].cantidad << " ";
        }
        cout << endl;
    }
}

// ==============================
// GANANCIA POR PRODUCTO
// ==============================

void PorProducto(venta v[][5], producto p[])
{
    cout << "\n=== GANANCIA POR PRODUCTO ===\n";

    for(int i = 0; i < 4; i++)
    {
        int sumaCant = 0;

        for(int j = 0; j < 5; j++)
            sumaCant += v[i][j].cantidad;

        cout << p[i].nombre << ": " << (sumaCant * p[i].precio) << " Bs\n";
    }
}

// ==============================
// GANANCIA POR DÍA
// ==============================

void PorDia(venta v[][5], producto p[])
{
    cout << "\n=== GANANCIA POR DÍA ===\n";

    for(int j = 0; j < 5; j++)
    {
        double suma = 0;

        for(int i = 0; i < 4; i++)
            suma += v[i][j].cantidad * p[i].precio;

        cout << "Día " << j+1 << ": " << suma << " Bs\n";
    }
}

// ===============================
//      RESUMEN GENERAL
// ===============================

void ResumenGeneral()
{
    double totalGeneral = totalDescuento + totalSinDescuento;

    cout << "\n==== RESUMEN GENERAL ====\n";
    cout << "Total sin descuento: " << totalSinDescuento << " Bs\n";
    cout << "Total con descuento: " << totalDescuento << " Bs\n";
    cout << "TOTAL GENERAL GANADO: " << totalGeneral << " Bs\n";
}

// =====================
//        MAIN
// =====================

int main()
{
    producto p[4];
    venta v[4][5];

    Coolocarprecios(p);
    Registrar(v, p);
    mostrar(v);
    PorProducto(v, p);
    PorDia(v, p);
    ResumenGeneral();

    return 0;
}
