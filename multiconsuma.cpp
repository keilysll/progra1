#include <iostream>
using namespace std;

int multiplicar(int a, int b)
{
    if (b == 0)
    {
    return 0;
    }

    else
    return a + multiplicar(a , b-1);

}

int main()
{
    int a, b;
    cout << "Ingrese multiplicando: ";
    cin >> a;
    cout << "Ingrese multiplicador: ";
    cin >> b;

    int resultado = multiplicar(a,b);
    cout<<"El resultado es: "<<resultado<<endl;

    return 0;
}


