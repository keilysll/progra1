#include <iostream>

using namespace std;
void DecimalaBinario(int n)
{
    if (n == 0)
    {
        return;

    }
    DecimalaBinario(n / 2),
    cout << n % 2;
}

int main()
{
    int n;
    cout<<"Introduzca numero: "<<endl;
    cin>>n;

    if (n < 0)
    {
        cout<<"Introduzca nros positivos"<<endl;
    } else if (n == 0)
    {
        cout<<"El nro binario de es: 0"<<endl;
    }
    else
    {

    cout<<"El nro binario de es: ";
    DecimalaBinario(n);
    cout<<endl;

    }


    return 0;
}
