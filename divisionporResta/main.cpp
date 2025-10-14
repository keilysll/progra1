#include <iostream>
using namespace std;

void Division(int n, int k, int cont)
{


    if (n == 0)
    {
        cout <<"error"<<endl;
    }

    else
    {
    Division((n - k), k ,cont++);

    int resultado = 0;
     resultado = cont;
cout<<"El resultado es:"<<resultado<<endl;
    }



}

int main()
{
    int n,k;
    int cont = 0;
    cout << "Ingrese dividendo: " << endl;
    cin>>n;
    cout << "Ingrese divisor: " << endl;
    cin>>k;

    Division(n,k,cont);


    return 0;
}
