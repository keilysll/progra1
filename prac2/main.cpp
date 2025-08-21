#include <iostream>

using namespace std;

int main()
{
    int edad;
    cin >> edad;
    if (edad >= 1 && edad <= 10 ){
        cout << "El paciente debe realizarse el analisis A ,B y C "<<endl;
        cout<< "el costo es de : 300bs "<< endl;

        }else if (edad >= 11 && edad <= 25 ){
        cout << "El paciente debe realizarse el analisis A ,C, D y E "<<endl;
        cout<< "el costo es de : 750s "<< endl;

        }else if (edad >= 25 && edad <= 55 ){
        cout << "El paciente debe realizarse el analisis A ,C, E y F "<<endl;
        cout<< "el costo es de : 1500s "<< endl;
        }
    else(edad >= 55){
        cout << "El paciente debe realizarse el analisis A ,B, E, D ,E y F "<<endl;
        cout<< "el costo es de : 2500s "<< endl;}


    return 0;
}
