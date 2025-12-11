#include <iostream>    // Incluye la biblioteca estándar de entrada/salida (cout, cin).
#include <cstring>     // Incluye funciones para manejo de cadenas en estilo C (strcpy, strcmp, etc.).

using namespace std;   // Usa el espacio de nombres std para evitar escribir std:: antes de cout, cin, string, etc.

// Definición de una estructura llamada 'producto' que representa un producto con nombre y precio.
struct producto
{
    char nombre [40];  // Arreglo de caracteres para almacenar el nombre del producto (máx 39 caracteres + '\0').
    double precio;     // Precio del producto (tipo double para permitir decimales).
};

// Definición de una estructura llamada 'venta' que representa una venta de un producto (nombre y cantidad vendida).
struct venta
{
    char nombre[40];   // Nombre del producto vendido (se copia el nombre desde 'producto' para tener registro).
    int cantidad;      // Cantidad vendida (entero).
};

// Función que pide al usuario ingresar los nombres y precios de 4 productos.
// Recibe un arreglo de 'producto' (se asume que tiene al menos 4 elementos).
void Coolocarprecios(producto p[])
{
    for(int i=0;i<4;i++)                     // Bucle para iterar sobre 4 productos (índices 0..3).
    {
        cout<<"---PRODUCTO "<<i+1<<"-------"<<endl;
        cout<<"Ingresa nombre del producto:";
        cin.getline(p[i].nombre,40,'\n');
        cout<<"Ingresa su precio: ";
        cin>>p[i].precio;
        cin.ignore();
    }
}

// Función para registrar las ventas de cada producto durante 5 días.
// Recibe una matriz bidimensional v[4][5] de 'venta' y el arreglo de productos p[].
void Registrar(venta v [][5], producto p[])
{
    for(int i = 0; i < 4; i++)                                  // Recorre los 4 productos (filas).
    {
        cout << "\n=== REGISTRO DE VENTAS DEL PRODUCTO: " << p[i].nombre << " ===\n";

        for(int j = 0; j < 5; j++)                              // Recorre los 5 días (columnas).
        {
            cout << "Día " << j + 1 << ": Ingrese cantidad vendida: "; // Pide la cantidad vendida ese día.
            cin >> v[i][j].cantidad;                            // Lee la cantidad y la guarda en la celda v[i][j].
            cin.ignore();
            strcpy(v[i][j].nombre, p[i].nombre);                // Copia el nombre del producto al registro de venta.
            // Esto permite saber a qué producto corresponde cada venta aunque se trabaje con la matriz.
        }
    }
}
/*
// Función que muestra la cantidad vendida (números) por producto y por día en forma de matriz.
void mostrar (venta v [][5])
{
    for (int i =0;i<4;i++)                 // Recorre las 4 filas (productos).
    {
        for(int j =0;j<5;j++)              // Recorre las 5 columnas (días).
        {
            cout<<v[i][j].cantidad<<" ";   // Imprime la cantidad vendida en la posición [i][j] seguida de un espacio.
        }
        cout<<"\n";                        // Salto de línea al terminar una fila (siguiente producto).
    }
}
*/
// Calcula y muestra la ganancia total por cada producto (suma de cantidades vendidas * precio del producto).
void PorProducto(venta v[][5], producto p[])
{
    cout << "\n=== GANANCIA POR PRODUCTO ===\n";

    for(int i = 0; i < 4; i++)                   // Recorre cada producto.
    {
        int sumaFila = 0;                        // Acumula la cantidad total vendida del producto i.

        for(int j = 0; j < 5; j++)               // Recorre los 5 días para sumar cantidades vendidas.
        {
            sumaFila += v[i][j].cantidad;        // Acumula la cantidad vendida ese día.
        }

        double ganancia = sumaFila * p[i].precio; // Calcula la ganancia multiplicando cantidad total por precio.

        cout << "Ganancia del producto " << p[i].nombre<< ": " << ganancia << endl;
        // Muestra la ganancia del producto i.
    }
}

// Calcula y muestra la ganancia total por cada día (suma de ventas de todos los productos ese día).
void PorDia(venta v[][5], producto p[])
{
    cout << "\n=== GANANCIA POR DÍA ===\n";

    for(int j = 0; j < 5; j++)   // Itera por días (columnas).
    {
        double sumaColumna = 0;  // Acumula la ganancia total del día j (dinero).

        for(int i = 0; i < 4; i++)   // Recorre los productos (filas) para el día j.
        {
            sumaColumna += v[i][j].cantidad * p[i].precio;
            // Suma (cantidad vendida del producto i en el día j) * (precio del producto i).
        }

        cout << "Ganancia del Día " << j + 1 << ": " << sumaColumna << endl;
        // Muestra la ganancia total del día j+1.
    }
}

void ResumenGeneral(venta v[][5], producto p[])   // Función que recibe la matriz de ventas y el arreglo de productos.
{
    double totalGeneral = 0;                      // Guarda la suma total de dinero ganado entre todos los productos.

    double mayor = -1;                            // Aquí se guardará la ganancia más alta encontrada.
    double menor = 999999;                        // Aquí se guardará la ganancia más baja encontrada.
    char nombreMayor[40];                         // Nombre del producto con mayor ganancia.
    char nombreMenor[40];                         // Nombre del producto con menor ganancia.

    double ventasDia[5] = {0};                    // Arreglo para guardar el dinero ganado en cada uno de los 5 días.
    // ============================================================
    //       RECORRER CADA PRODUCTO Y CALCULAR SUS GANANCIAS
    // ============================================================
    for (int i = 0; i < 4; i++)                   // Recorre cada uno de los 4 productos.
    {
        double sumaProducto = 0;                  // Acumula la ganancia total del producto i.

        for (int j = 0; j < 5; j++)               // Recorre los 5 días para el producto actual.
        {
            double dinero = v[i][j].cantidad * p[i].precio;   // Calcula dinero = cantidad vendida * precio del producto.

            sumaProducto += dinero;               // Suma este dinero al total del producto.
            ventasDia[j] += dinero;               // También suma este dinero al total del día correspondiente.
        }

        totalGeneral += sumaProducto;             // Suma la ganancia del producto al total general del programa.
        // ---------------------- MAYOR GANANCIA --------------------
        if (sumaProducto > mayor)                 // Si este producto ganó más que el que tenía el "mayor"...
        {
            mayor = sumaProducto;                 // Actualizamos el valor mayor.
            strcpy(nombreMayor, p[i].nombre);     // Guardamos el nombre de este producto.
        }
        // ---------------------- MENOR GANANCIA --------------------
        if (sumaProducto < menor)                 // Si este producto ganó menos que el que tenía el "menor"...
        {
            menor = sumaProducto;                 // Actualizamos el valor menor.
            strcpy(nombreMenor, p[i].nombre);     // Guardamos el nombre de este producto.
        }
    }
    // ============================================================
    //                BUSCAR EL DÍA CON MENOS GANANCIA
    // ============================================================
    int diaMenos = 0;                             // Empezamos suponiendo que el día 1 es el de menor ganancia.

    for (int j = 1; j < 5; j++)                   // Recorremos desde el día 2 hasta el 5.
    {
        if (ventasDia[j] < ventasDia[diaMenos])   // Si este día tiene menos dinero que el guardado como menor...
        {
            diaMenos = j;                         // Lo guardamos como el nuevo día con menor ganancia.
        }
    }
    // ============================================================
    //                    MOSTRAR LOS RESULTADOS
    // ============================================================
    cout << "\n==== RESUMEN GENERAL ====\n";
    cout << "Total ganado: " << totalGeneral << " Bs.\n";            // Muestra el total de dinero.
    cout << "Producto con mayor ganancia: " << nombreMayor            // Muestra el producto más rentable.
         << " (" << mayor << " Bs.)\n";
    cout << "Producto con menor ganancia: " << nombreMenor            // Muestra el producto menos rentable.
         << " (" << menor << " Bs.)\n";
    cout << "Día con menos ganancia: Día " << diaMenos + 1            // Muestra el día con menos ventas.
         << " (" << ventasDia[diaMenos] << " Bs.)\n";
}

int main()
{
    producto p[4];         // Declara un arreglo de 4 productos.
    venta v [4][5];        // Declara una matriz 4x5 de ventas: 4 productos x 5 días.

    Coolocarprecios(p);    // Llama a la función para ingresar los datos de los productos (nombres y precios).
    Registrar(v,p);        // Registra las cantidades vendidas por producto y por día (rellena v).
    //mostrar(v);            // Muestra la matriz de cantidades vendidas (solo cantidades).
    PorProducto(v,p);      // Calcula y muestra la ganancia por producto.
    PorDia(v,p);           // Calcula y muestra la ganancia por cada día.
    ResumenGeneral(v,p);   // Muestra el resumen general con totales, mayor/menor y día con menos ventas.

    return 0;              // Retorna 0 indicando finalización exitosa del programa.
}
