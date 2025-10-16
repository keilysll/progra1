#include <iostream>
using namespace std;

void Division(int n, int k, int &cont)
{
    if (k == 0)
    {
        cout << "Error: no se puede dividir entre 0." << endl;
        return;
    }

    if (n < k)
    {
        cout << "El resultado es: " << cont << endl;
        cout << "El residuo es: " << n << endl;
        return;
    }

    n = n - k;
    cont++;

    Division(n, k, cont);
}

int main()
{
    int n, k;
    int cont = 0;

    cout << "Ingrese dividendo: ";
    cin >> n;
    cout << "Ingrese divisor: ";
    cin >> k;

    Division(n, k, cont);

    return 0;
}
