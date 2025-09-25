//Crear un programa que lea 3 notas y guarde en un archivo binario las 3 notas el promedio y muestre por pantalla los datos guardados

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    float notas[3], promedio;
    cout<<"------------NOTAS---------"<<endl;
    cout << "Ingrese 3 notas:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    promedio = (notas[0] + notas[1] + notas[2]) / 3;


    ofstream archivo("dato.dat", ios::binary);
    archivo.write((char*)notas, sizeof(notas));
    archivo.write((char*)&promedio, sizeof(promedio));
    archivo.close();


    ifstream leer("dato.dat", ios::binary);
    leer.read((char*)notas, sizeof(notas));
    leer.read((char*)&promedio, sizeof(promedio));


    cout << "\nDatos guardados en el archivo:" << endl;
    cout << "Notas: " << notas[0] << " " << notas[1] << " " << notas[2];
    cout << " | Promedio: " << promedio << endl;
    leer.close();
    return 0;
}




















