#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    char texto1 [40], texto2 [40];
    cout << "introduce tu nombre  ";
    cin >>texto1;
    cout << "introduce tu apellido ";
    cin >>texto2;
    strcat(texto1 , " ");
    strcat(texto1 , texto2);
    cout << "te llamas  :" <<texto1<<endl;
    return 0;
}
