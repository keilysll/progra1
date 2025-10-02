#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void escribir(float sueldo[], int n)
{
    ofstream arch;
    float total = 0;
    string nuevo_archivo;

    cout <<"Ingresa el nombre del archivo que deseas crear (ej: sueldos.txt): "<<endl;
    getline(cin, nuevo_archivo);

    arch.open(nuevo_archivo.c_str(), ios::out);

    cout << "---------- INGRESO DE SUELDOS ----------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Sueldo " << i + 1 << ": ";
        cin >> sueldo[i];
        arch << "Sueldo " << i+1 << ": " << sueldo[i] << endl;
        total += sueldo[i];
    }

    arch << "------------------------" << endl;
    arch << "TOTAL GANADO: " << total << endl;

    cout << "\nEl total ganado en medio anio es: " << total << endl;

    arch.close();
    cin.ignore();
}

void leer()
{
    string cadenapantalla, nombre_archivo;
    ifstream archivo;

    cout <<"\nIngresa el nombre del archivo que deseas leer: "<<endl;
    getline(cin, nombre_archivo);

    archivo.open(nombre_archivo.c_str(), ios::in);

    if (archivo.fail())
    {
        cout << "No existe el archivo" << endl;
        return;
    }

    cout << "\n----- CONTENIDO DEL ARCHIVO -----\n";
    while (getline(archivo, cadenapantalla))
    {
        cout << cadenapantalla << endl;
    }

    archivo.close();
}

int main()
{
    float sueldo[6];

    escribir(sueldo, 6);
    leer();

    return 0;
}
