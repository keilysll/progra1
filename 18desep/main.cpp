#include <iostream>

using namespace std;

struct direccionE
{
    char direccion [20];
    char ciudad [20];
    char provincia [25];

};

struct empleado
{
    char nombre [20];
    direccionE direccEmp;
    float salario ;
    long long cellphone;
    float estatura;
    float peso;


};

void Cargardatos (empleado E1[], int n)
{
    for (int i = 0 ; i < n ; i ++)
    {
        cout <<"-----INGRESE LOS DATOS DEL EMPLEADO "<<i +1<<"------"<<endl;

        cout << "Ingrese el nombre del empleado: ";
        cin.getline(E1[i].nombre, 20, '\n');
        cout<<"Ingrese la direccion del empleado:";
        cin.getline(E1[i].direccEmp.direccion,20,'\n');
        cout << "Ingrese la ciudad: ";
        cin.getline(E1[i].direccEmp.ciudad,20,'\n');
        cout << "Ingrese la provincia: ";
        cin.getline(E1[i].direccEmp.provincia,20,'\n');
        cout<<"Ingrese salario del empleado :";
        cin >> E1[i].salario;
        cout << "Ingrese el nro de celular : ";
        cin >> E1[i].cellphone;
        cout << "Ingrese la estatura : ";
        cin >> E1[i].estatura;
        cout << "Ingrese el peso : ";
        cin >> E1[i].peso;
        cin.ignore();
        cout<<endl;

    }


}

 void Mostrardatos(empleado E1[], int n)
 {

 for (int i = 0 ; i < n ; i ++)
    {
        cout << "----------DATOS DEL EMPLEADO " << i + 1 << "----------" << endl;
        cout <<"Nombre del empleado: "<<E1[i].nombre<<endl;
        cout <<"Direccion: "<<E1[i].direccEmp.direccion<<endl;
        cout <<"Ciudad: "<<E1[i].direccEmp.ciudad<<endl;
        cout <<"Provincia: "<<E1[i].direccEmp.provincia<<endl;
        cout <<"Salario: "<<E1[i].salario<<endl;
        cout <<"Nro de celular : "<<E1[i].cellphone<<endl;
        cout <<"Estatura: "<<E1[i].estatura<<endl;
        cout <<"Peso: "<<E1[i].peso<<endl;

    }
 }



int main()

{

    empleado E1 [3];
    /*
    for (int i = 0 ; i < 3 ; i ++)
    {
        cout <<"-----INGRESE LOS DATOS DEL EMPLEADO "<<i +1<<"------"<<endl;
        cout<<"Ingrese el nombre del empleado: ";
        cin.getline(E1[i].nombre,20,'\n');
        cout<<"Ingrese la direccion del empleado:";
        cin.getline(E1[i].direccEmp.direccion,20,'\n');
        cout << "Ingrese la ciudad: ";
        cin.getline(E1[i].direccEmp.ciudad,20,'\n');
        cout << "Ingrese la provincia: ";
        cin.getline(E1[i].direccEmp.provincia,20,'\n');
        cout<<"Ingrese salario del empleado :";
        cin >> E1[i].salario;
        datos(E1[i]);
        cout<<endl;
        cin.ignore();
    }


    for (int i = 0 ; i < 3 ; i ++)
    {
        cout <<"----------DATOS DEL EMPLEADO "<<i+1<<"------"<<end;
        cout <<"Nombre del empleado: "<<E1[i].nombre<<endl;
        cout <<"Direccion: "<<E1[i].direccEmp.direccion<<endl;
        cout <<"Ciudad: "<<E1[i].direccEmp.ciudad<<endl;
        cout <<"Provincia: "<<E1[i].direccEmp.provincia<<endl;
        cout <<"Salario: "<<E1[i].salario<<endl;
       mostrardatos(E1[i]);

    }
    */
    Cargardatos(E1,3);
    cout <<"-------------------------------------------------------------"<<endl;
    Mostrardatos(E1,3);
    return 0;
}
