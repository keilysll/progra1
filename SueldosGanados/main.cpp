//Crear un prog que solicite los sueldos ganados de un determinado empleado en medio año

#include <iostream>
#include <fstream>
using namespace std;


void escribir(float sueldo[], float n)
{
    ofstream arch;
    float total;
    string nuevo_archivo;
    cout <<"Ingresa el nombre del archivo que desea crear , junto a la extension"<<endl;
    getline(cin,nuevo_archivo);
    arch.open(nuevo_archivo.c_str(), ios::out);

    cout << "----------SUELDOS----------" << endl;
    cout << "Ingrese los sueldos:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << "Sueldo " << i + 1 << ": ";
        arch>>sueldo[i];
        total += sueldo[i];
    }
    arch.close();
}





int main()

    float sueldo[6];
    int n ;
    escribir(sueldo,6);

    return 0;
}
