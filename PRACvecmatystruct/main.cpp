#include <iostream>
using namespace std;

// ---------------- ESTRUCTURAS -------------------
struct Vector {
    int ventas[100];   // ventas por día
    int n;             // cantidad de días
};

struct Matriz {
    int ventas[100][100]; // ventas por producto y día
    int f, c;             // f = productos, c = días
};

// ---------------- FUNCIONES PARA VECTOR (VENTAS DIARIAS) -------------------

void cargarV(Vector &v)
{
    for (int i = 0; i < v.n; i++) {
        cout << "Ingrese ventas del dia " << i + 1 << ": ";
        cin >> v.ventas[i];
    }
}

void mostrarV(const Vector &v)
{
    cout << "Ventas ingresadas: ";
    for (int i = 0; i < v.n; i++) {
        cout << v.ventas[i] << " ";
    }
    cout << endl;
}

void MayMen(const Vector &v, int &may, int &men)
{
    may = v.ventas[0];
    men = v.ventas[0];

    for (int i = 1; i < v.n; i++) {
        if (v.ventas[i] > may) may = v.ventas[i];
        if (v.ventas[i] < men) men = v.ventas[i];
    }
}

void OrdenarDes(Vector &v)
{
    for (int i = 0; i < v.n - 1; i++) {
        for (int j = 0; j < v.n - 1; j++) {
            if (v.ventas[j] < v.ventas[j+1]) {
                int temp = v.ventas[j];
                v.ventas[j] = v.ventas[j+1];
                v.ventas[j+1] = temp;
            }
        }
    }
}

void OrdenarAsc(Vector &v)
{
    for (int i = 0; i < v.n - 1; i++) {
        for (int j = 0; j < v.n - 1; j++) {
            if (v.ventas[j] > v.ventas[j+1]) {
                int temp = v.ventas[j];
                v.ventas[j] = v.ventas[j+1];
                v.ventas[j+1] = temp;
            }
        }
    }
}

void SumaV(const Vector &v)
{
    int suma = 0;
    for (int i = 0; i < v.n; i++)
        suma += v.ventas[i];

    cout << "Total de ventas del producto: " << suma << endl;
}

// ---------------- FUNCIONES PARA MATRIZ (VENTAS PRODUCTO/DÍA) -------------------

void cargarM(Matriz &m)
{
    for (int i = 0; i < m.f; i++) {
        for (int j = 0; j < m.c; j++) {
            cout << "Ventas del producto " << i + 1 << " en el dia " << j + 1 << ": ";
            cin >> m.ventas[i][j];
        }
    }
}

void mostrarM(const Matriz &m)
{
    cout << "\n--- TABLA DE VENTAS (Productos x Dias) ---\n";
    for (int i = 0; i < m.f; i++) {
        for (int j = 0; j < m.c; j++)
            cout << m.ventas[i][j] << " ";
        cout << endl;
    }
}

void DiagonalM(const Matriz &m)
{
    cout << "Diagonal principal (producto i en dia i): ";
    for (int i = 0; i < m.f && i < m.c; i++)
        cout << m.ventas[i][i] << " ";
    cout << endl;
}

void sumaM(const Matriz &m)
{
    int suma = 0;
    for (int i = 0; i < m.f; i++)
        for (int j = 0; j < m.c; j++)
            suma += m.ventas[i][j];

    cout << "Total general de ventas: " << suma << endl;
}

void SumaFilas(const Matriz &m)
{
    cout << "\nVentas por producto:\n";
    for (int i = 0; i < m.f; i++) {
        int suma = 0;
        for (int j = 0; j < m.c; j++)
            suma += m.ventas[i][j];

        cout << "Producto " << i + 1 << ": " << suma << endl;
    }
}

void SumaColumnas(const Matriz &m)
{
    cout << "\nVentas por dia:\n";
    for (int j = 0; j < m.c; j++) {
        int suma = 0;
        for (int i = 0; i < m.f; i++)
            suma += m.ventas[i][j];

        cout << "Dia " << j + 1 << ": " << suma << endl;
    }
}

void MayorM(const Matriz &m, int &may, int &men)
{
    may = m.ventas[0][0];
    men = m.ventas[0][0];

    for (int i = 0; i < m.f; i++) {
        for (int j = 0; j < m.c; j++) {
            if (m.ventas[i][j] > may) may = m.ventas[i][j];
            if (m.ventas[i][j] < men) men = m.ventas[i][j];
        }
    }
}

// ---------------- MAIN -------------------

int main()
{
    Vector v;
    Matriz m;
    int may, men;

    // ----- VENTAS DIARIAS DE UN PRODUCTO -----
    cout << "Ingrese la cantidad de dias de ventas del producto: ";
    cin >> v.n;

    cargarV(v);
    mostrarV(v);

    cout << "\n--- Mayor y menor venta diaria ---\n";
    MayMen(v, may, men);
    cout << "Mayor venta: " << may << endl;
    cout << "Menor venta: " << men << endl;

    cout << "\n--- Ventas ordenadas (Descendente) ---\n";
    OrdenarDes(v);
    mostrarV(v);


    cout << "--- Ventas ordenadas (Ascendente) ---\n";
    OrdenarAsc(v);
    mostrarV(v);
    SumaV(v);

    // ----- MATRIZ DE VENTAS -----
    cout << "\nIngrese cantidad de productos: ";
    cin >> m.f;
    cout << "Ingrese cantidad de dias: ";
    cin >> m.c;

    cargarM(m);
    mostrarM(m);

    DiagonalM(m);
    sumaM(m);
    SumaFilas(m);
    SumaColumnas(m);

    MayorM(m, may, men);
    cout << "\nMayor venta registrada en la matriz: " << may << endl;
    cout << "Menor venta registrada en la matriz: " << men << endl;

    return 0;
}
