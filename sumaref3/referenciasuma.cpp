#include <iostream>

using namespace std;

float suma (float a , float b )
{
    float c;
    c = a + b;
    return c;
}

void Suma2 (float a , float &b , float &c)
{
    c = a +b ;
    b = 56 ;
}
int main()
{
    float n1 , n2;
    float resu1,resu2;
    cout <<"INGRESE UN NRO ";
    cin >>n1;
    cout <<"INGRESE OTRO NRO ";
    cin >>n2;

    resu1= suma (n1,n2);
    cout <<"EL RESULTADO ES :"<<resu1<<endl;
    Suma2(n1 , n2 , resu2);
    cout << "EL RESULTADO ES : " << resu2<<endl;
    cout << "EL RESULTADO ACTUALIZADO ES : " << n2<<endl;

    return 0;
}
