#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int VAR;
    float VAR2;
    ifstream archivo("D:/Documentos/kyprogra1/archivos1 datos.dat", ios::binary | ios::in);

    archivo.read((char *)& VAR,sizeof(int));
    archivo.read((char *)& VAR2,sizeof(float));

    cout<<"El contenido de la variable VAR es: "<<VAR<<endl;
    cout<<"El contenido de la variable VAR2 es: "<<VAR2<<endl;
    archivo.close();
    return 0;
}
