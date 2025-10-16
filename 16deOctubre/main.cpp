#include <iostream>
using namespace std;

void multiplicar(int n, int k)
{
    if (k == 0 | n == 0)
    {
        cout << "Resultado es 0" << endl;
        return;
    }

    n = n + k;
    k = k - 1;
    multiplicar(n,k);

    cout<<"Resultado de la multiplicacion es: "<<n<<endl;

}


int main()
{
    int n, k;
    cout << "Ingrese multiplicando: ";
    cin >> n;
    cout << "Ingrese multiplicador: ";
    cin >> k;

    multiplicar(n, k);

    return 0;
}


