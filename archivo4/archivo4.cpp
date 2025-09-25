//Crear un prog qu eguarde el total de salarios pagados para tres tipos de empleados

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    float salario[3],total;

    cout << "----------SALARIOS----------" << endl;

    cout<<"Empleado 1 - TEMPORAL"<<endl;
    cout<<"Empleado 2 - MEDIO TIEMPO"<<endl;
    cout<<"Empleado 3 - TIEMPO COMPLETO"<<endl;
    cout << "Ingrese los salarios:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Empleado " << i + 1 << ": ";
        cin >>salario[i];
    }
    total = (salario[0] + salario[1] + salario[2]);

    ofstream archivo("dato.dat", ios::binary);
    archivo.write((char*)salario, sizeof(salario));
    archivo.write((char*)&total, sizeof(total));
    archivo.close();

    ifstream leer("dato.dat", ios::binary);
    leer.read((char*)salario, sizeof(salario));
    leer.read((char*)&total, sizeof(total));


    cout << "\nDatos guardados en el archivo:" << endl;
    cout<<"Empleado 1 - TEMPORAL: "<< salario[0]<<endl;
    cout<<"Empleado 2 - MEDIO TIEMPO: "<< salario[1]<<endl;
    cout<<"Empleado 3 - TIEMPO COMPLETO: "<< salario[2]<<endl;
    cout << " | TOTAL: " << total << endl;
    leer.close();
    return 0;
}
