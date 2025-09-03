#include <iostream>
using namespace std;

void cargarMatriz(int M[][7], int filas, string categoria) {
    cout << "\nCargando ventas de " << categoria << ":\n";
    for (int i = 0; i < filas; i++) {
        cout << "Producto " << i+1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << " Dia " << j+1 << ": ";
            cin >> M[i][j];
        }
    }
}

void mostrarMatriz(int M[][7], int filas, string categoria) {
    cout << "\nMatriz de ventas (" << categoria << "):\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < 7; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

void totalPorProducto(int M[][7], int filas, int precios[], string categoria) {
    cout << "\nTotal vendido por producto (" << categoria << "):\n";
    for (int i = 0; i < filas; i++) {
        int totalUnidades = 0;
        for (int j = 0; j < 7; j++) {
            totalUnidades += M[i][j];
        }
        cout << "Producto " << i+1 << ": " << totalUnidades
             << " unidades -> " << totalUnidades * precios[i] << " Bs\n";
    }
}

void mostrarVector(int vect[], int n) {
    for (int i = 0; i < n; i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
}

void ordenarVector(int vect[], int n, bool asc = true) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if ((asc && vect[i] > vect[j]) || (!asc && vect[i] < vect[j])) {
                int temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
}

void buscarPrecio(int vect[], int n, int dato) {
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (vect[i] == dato) {
            cout << "Precio " << dato << " encontrado en posicion " << i << endl;
            encontrado = true;
        }
    }
    if (!encontrado) cout << "Precio " << dato<< " NO encontrado.\n";
}

int main() {
    const int dias = 7;
    const int helados = 4;
    const int masitas = 2;

    // MATRICES
    int ventasHelados[helados][dias];
    int ventasMasitas[masitas][dias];

    // PRECIOS
    int preciosHelados[helados] = {85, 45, 25, 15};
    int preciosMasitas[masitas] = {8, 10};

    // MENÚ DE PRODUCTOS
    cout << "MENU DE HELADOS:\n";
    cout << "1. Helado 1 kilo - 85 Bs\n";
    cout << "2. Helado 1/2 kilo - 45 Bs\n";
    cout << "3. Helado 1/4 kilo - 25 Bs\n";
    cout << "4. Cono - 15 Bs\n";
    cout << "\nMENU DE MASITAS:\n";
    cout << "1. Empanada - 8 Bs\n";
    cout << "2. Queque - 10 Bs\n";

    // CARGAR DATOS
    cargarMatriz(ventasHelados, helados, "Helados");
    cargarMatriz(ventasMasitas, masitas, "Masitas");

    // MOSTRAR MATRICES
    mostrarMatriz(ventasHelados, helados, "Helados");
    mostrarMatriz(ventasMasitas, masitas, "Masitas");

    // TOTALES
    totalPorProducto(ventasHelados, helados, preciosHelados, "Helados");
    totalPorProducto(ventasMasitas, masitas, preciosMasitas, "Masitas");

    // VECTORES DE PRECIOS
    cout << "\nVector precios helados: ";
    mostrarVector(preciosHelados, helados);
    cout << "Vector precios masitas: ";
    mostrarVector(preciosMasitas, masitas);

    // ORDENAR Y MOSTRAR
    cout << "\nPrecios de helados (ascendente): ";
    ordenarVector(preciosHelados, helados, true);
    mostrarVector(preciosHelados, helados);

    cout << "Precios de helados (descendente): ";
    ordenarVector(preciosHelados, helados, false);
    mostrarVector(preciosHelados, helados);

    cout << "\nPrecios de masitas (ascendente): ";
    ordenarVector(preciosMasitas, masitas, true);
    mostrarVector(preciosMasitas, masitas);

    cout << "Precios de masitas (descendente): ";
    ordenarVector(preciosMasitas, masitas, false);
    mostrarVector(preciosMasitas, masitas);

    // BUSCAR PRECIO
    buscarPrecio(preciosHelados, helados, 25);
    buscarPrecio(preciosMasitas, masitas, 25);

    return 0;
}
