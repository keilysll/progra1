#include <iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main()
{
    fstream origen ("imagen1.jpg", ios :: in | ios ::binary);
    fstream destino ("copiaimagen.jpg",ios :: out| ios:: binary);
    char b;
    while (!origen.eof()&& !origen.fail())
    {
        origen.read((char *)&b , sizeof (char));
        if (origen.good())
        {
            destino.write((char*)&b , sizeof(char));
        }
    }

    destino.close();
    origen.close();
    system("pause");

}
