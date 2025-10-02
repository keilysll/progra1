/// CREAR UN PROG

#include <iostream>
#include <fstream>
using namespace std;

struct fecha
{
    int dia;
    int mes;
    int anio;
};
struct datos
{
    char nombre[20];
    char apellido[20];
    fecha nacimiento;
    int edad;
    char ciudad[20];
    int sueldo;
    float CI;


};

struct producto
{
    float proc1 ;
    float  proc2 ;
    float proc3 ;

};


struct empleado
{
    datos emp;
    producto vendido;
};

void Cargar(empleado Em1[], int n )
{
    for (int i = 0 ; i < n ; i ++)
    {
        cout<<"----------INGRESE LOS DATOS DEL EMPLEADO "<<i+1<<"-------------"<<endl;
        cout<<"Ingrese el nombre completo del empleado"<<endl;
        cout<<"Nombre: ";
        cin.ignore();
        cin.getline(Em1[i].emp.nombre , 20, '\n');
        cout<<"Apellidos: ";
        cin.getline(Em1[i].emp.apellido, 20, '\n');

        cout<<"Ingrese la fecha de necimiento del empleado"<<endl;
        cout<<"Dia: ";
        cin>> Em1[i].emp.nacimiento.dia;
        cout<<"Mes: ";
        cin>> Em1[i].emp.nacimiento.mes;
        cout<<"Anio: ";
        cin>> Em1[i].emp.nacimiento.anio;

        cout<<"Ingrese el CI del empleado:  ";
        cin>>Em1[i].emp.CI;
        cout<<"Ingrese la edad del empleado: ";
        cin>>Em1[i].emp.edad;
        cout<<"Ingrese la ciudad donde vive el empleado: ";
        cin.ignore();
        cin.getline(Em1[i].emp.ciudad , 20, '\n');



        cout<<"* Ingrese la ganacia de los productos * "<<endl;
        cout<<"Producto 1: ";
        cin>> Em1[i].vendido.proc1;
        cout<<"Producto 2: ";
        cin>> Em1[i].vendido.proc2;
        cout<<"Producto 3: ";
        cin>> Em1[i].vendido.proc3;

        }


    }



/*
float CalcularTotal(empleado Prod[], const 3)

{
    int total = 0 ;
    for (int i = 0 ; i < 3 ; i ++)
    {
        total += Prod[i];
    }

    return total;
}
*/

void Mostrar(empleado Em1[], int n )
{
    for (int i = 0 ; i < n ; i ++)
    {
        cout<<"---------- DATOS DEL EMPLEADO "<<i+1<<"-------------"<<endl;
        cout<<"Nombre: "<<Em1[i].emp.nombre<<endl;
        cout<<"Apellidos: "<<Em1[i].emp.apellido<<endl;

        cout<<"fecha de necimiento del empleado"<<endl;

        cout<<Em1[i].emp.nacimiento.dia<<"/"<<Em1[i].emp.nacimiento.mes<<"/"<<Em1[i].emp.nacimiento.anio<<endl;

        cout<<"CI del empleado: "<<Em1[i].emp.CI<<endl;
        cout<<"Edad del empleado: "<<Em1[i].emp.edad<<endl;
        cout<<"La ciudad donde vive el empleado: "<<Em1[i].emp.ciudad<<endl;

        cout<<"* Ganacia de los productos * "<<endl;
        cout<<"Producto 1: "<<Em1[i].vendido.proc1;
        cout<<"Producto 2"<<Em1[i].vendido.proc2<<endl;
        cout<<"Producto 3"<<Em1[i].vendido.proc3<<endl;


    }
}

void guardarArchivo(empleado e)
{
    ofstream archivo;
    archivo.open("datos.dat", ios:: binary | ios::app);
    archivo.write((char*)&e,sizeof (empleado));
    archivo.close();

}

void leerArchivo(empleado e )
{
    ifstream archivo("datos.dat", ios:: binary);
    while (!archivo.eof())
    {
        archivo.read((char*)&e,sizeof (empleado));
        if (archivo.good())
        {
            Mostrar(e);
        }
    }
    archivo.close();

}







int main()
{

    empleado emp1[2];
    Cargar(emp1,2);
    cin.ignore();
    guardarArchivo(emp1,2);
    cout <<"-------------------------------------------------------------"<<endl;
    Mostrar(emp1,2);




    return 0;
}
