#include <iostream>

using namespace std;

int main()
{
    int a = 550;
    int b = 820;
    int op;
    int cont = 0;
    cout<< "DESTINO"<< endl;
    cout<<"1. La Paz"<< endl;
    cout<<"2. Santa cruz"<< endl;
    cout<<"3. Oruro"<< endl;
    cout<< "ELIGE TU DESTINO"<< endl;
    cin>>op;

    if ((op == 1) || (op == 3)){
        cout<<a<<endl;
        cont == a ;
        cout << "¿Cuantos pasajes quiere?"<<endl;
        int n;
        cin >> n;
        cont=cont*n;
        cout << "el total a pagar es"<<endl;
        cout<<cont<<endl;

    } else (op == 2){
        cout <<b << endl;
        int cont = b;
        cout << "¿Cuantos pasajes quiere?"<<endl;
        int n;
        cin >> n;
        cont=cont*n;
        cout << "el total a pagar es"<<endl;
        cout<<cont<<endl;
        }


    return 0;
}
