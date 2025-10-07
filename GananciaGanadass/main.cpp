#include <iostream>
#include <fstream>
using namespace std;

struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct datos
{
    char nombre[20];
    char apellido[20];
    fecha nacimiento;
    int edad;
    char ciudad[20];
    float sueldo;
    float CI;
};

struct producto
{
    float proc1;
    float proc2;
    float proc3;
};

struct empleado
{
    datos emp;
    producto vendido;
};



void Cargar(empleado Em1[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n---------- INGRESE LOS DATOS DEL EMPLEADO " << i + 1 << " -------------\n";
        cin.ignore();
        cout << "Nombre: ";
        cin.getline(Em1[i].emp.nombre, 20, '\n');
        cout << "Apellidos: ";
        cin.getline(Em1[i].emp.apellido, 20, '\n');

        cout << "Ingrese la fecha de nacimiento del empleado:\n";
        cout << "Dia: ";
        cin >> Em1[i].emp.nacimiento.dia;
        cout << "Mes: ";
        cin >> Em1[i].emp.nacimiento.mes;
        cout << "Anio: ";
        cin >> Em1[i].emp.nacimiento.anio;

        cout << "Ingrese el CI del empleado: ";
        cin >> Em1[i].emp.CI;
        cout << "Ingrese la edad del empleado: ";
        cin >> Em1[i].emp.edad;
        cout << "Ingrese el sueldo del empleado: ";
        cin >> Em1[i].emp.sueldo;
        cin.ignore();
        cout << "Ingrese la ciudad donde vive el empleado: ";
        cin.getline(Em1[i].emp.ciudad, 20, '\n');

        cout << "\n* Ingrese la ganancia de los productos *\n";
        cout << "Producto 1: ";
        cin >> Em1[i].vendido.proc1;
        cout << "Producto 2: ";
        cin >> Em1[i].vendido.proc2;
        cout << "Producto 3: ";
        cin >> Em1[i].vendido.proc3;
    }
}



void Mostrar(empleado Em1[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\n---------- DATOS DEL EMPLEADO " << i + 1 << " -------------\n";
        cout << "Nombre: " << Em1[i].emp.nombre << " " << Em1[i].emp.apellido << endl;
        cout << "Fecha de nacimiento: " << Em1[i].emp.nacimiento.dia << "/"
             << Em1[i].emp.nacimiento.mes << "/" << Em1[i].emp.nacimiento.anio << endl;
        cout << "CI: " << Em1[i].emp.CI << endl;
        cout << "Edad: " << Em1[i].emp.edad << endl;
        cout << "Ciudad: " << Em1[i].emp.ciudad << endl;
        cout << "Sueldo: " << Em1[i].emp.sueldo << endl;

        cout << "* Ganancias de los productos *\n";
        cout << "Producto 1: " << Em1[i].vendido.proc1 << endl;
        cout << "Producto 2: " << Em1[i].vendido.proc2 << endl;
        cout << "Producto 3: " << Em1[i].vendido.proc3 << endl;

        float total = Em1[i].vendido.proc1 + Em1[i].vendido.proc2 + Em1[i].vendido.proc3;
        cout << "TOTAL GANADO POR EL EMPLEADO: " << total << endl;
    }
}



void guardarBinario(empleado Em1[], int n)
{
    ofstream archivo("empleados.dat", ios::binary);
    if (!archivo)
    {
        cout << "Error al crear el archivo binario.\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        archivo.write((char *)&Em1[i], sizeof(empleado));
    }

    archivo.close();
    cout << "\nDatos personales guardados en 'empleados.dat' correctamente.\n";
}


void guardarTexto(empleado Em1[], int n)
{
    ofstream archTexto("ganancias.txt");
    if (!archTexto)
    {
        cout << "Error al crear el archivo de texto.\n";
        return;
    }

    archTexto << "====== REGISTRO DE GANANCIAS ======\n";
    for (int i = 0; i < n; i++)
    {
        float total = Em1[i].vendido.proc1 + Em1[i].vendido.proc2 + Em1[i].vendido.proc3;
        archTexto << "\nEmpleado: " << Em1[i].emp.nombre << " " << Em1[i].emp.apellido << endl;
        archTexto << "Producto 1: " << Em1[i].vendido.proc1 << endl;
        archTexto << "Producto 2: " << Em1[i].vendido.proc2 << endl;
        archTexto << "Producto 3: " << Em1[i].vendido.proc3 << endl;
        archTexto << "TOTAL GANADO: " << total << endl;
        archTexto << "-----------------------------------\n";
    }

    archTexto.close();
    cout << "\nGanancias guardadas en 'ganancias.txt' correctamente.\n";
}


int main()
{
    empleado emp1[100];
    int n;
    cout << "Ingrese la cantidad de empleados: ";
    cin >> n;

    Cargar(emp1, n);
    Mostrar(emp1, n);

    guardarBinario(emp1, n);
    guardarTexto(emp1, n);

    cout << "\nProceso finalizado correctamente \n";
    return 0;
}
