#include <iostream>
using namespace std;

int main()
{
    int nro,cont = 0;
cout << "ingrese nro";
cin >> nro;
for (int i = 1 ; i <= nro; i++ ) {
    if (nro % i == 0){
        cont ++;
    }
}if (cont == 2 ){
    cout << "es primo ";
}else{
cout << "no es primo ";
}
return 0;
}
