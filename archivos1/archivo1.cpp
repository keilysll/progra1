#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int var1 = 100;
    float var2 = 6.5;
    fstream miarchivo("datos.dat", ios::binary | ios::out| ios::app);

    miarchivo.write((char *)& var1,sizeof(int));
    miarchivo.write((char *)& var2,sizeof(float));

    miarchivo.close();
    return 0;
}
