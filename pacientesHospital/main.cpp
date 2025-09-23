#include <iostream>
using namespace std;

struct nombrecompleto
{
    char nombre[20];
    char apellido [20];
};

struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct doctor
{
    nombrecompleto doc;
    fecha nacimient;
    char especialidad [20];
};

struct tratamiento
{
    fecha inicio;
    int duracionTrat;
    char nombreMedicamento[20];
};

struct paciente
{
    nombrecompleto persona;
    long long CI;
    long long  celular;
    int edad;
    fecha nacimiento;
    tratamiento tipo;
    doctor cabecera;
};


void Cargardatos(paciente P1[], int n)
{
    for (int i = 0 ; i < n ; i ++)
    {
        cout<<"----------INGRESE LOS DATOS DEL PACIENTE "<<i+1<<"-------------"<<endl;
        cout<<"Ingrese el nombre completo del paciente"<<endl;
        cout<<"Nombre: ";
        cin.ignore();
        cin.getline(P1[i].persona.nombre , 20, '\n');
        cout<<"Apellidos: ";
        cin.getline(P1[i].persona.apellido, 20, '\n');

        cout<<"Ingrese el CI del paciente: ";
        cin>>P1[i].CI;
        cout<<"Ingrese el celular del paciente: ";
        cin>>P1[i].celular;
        cout<<"Ingrese la edad del paciente: ";
        cin>>P1[i].edad;

        cout<<"Ingrese la fecha de nacimiento del paciente"<<endl;
        cout<<"Dia: ";
        cin>>P1[i].nacimiento.dia;
        cout<<"Mes: ";
        cin>>P1[i].nacimiento.mes;
        cout<<"Anio: ";
        cin>>P1[i].nacimiento.anio;

        cout<<"Ingrese el tipo de tratamiento del paciente "<<endl;
        cout<<"Fecha de inicio del tratamiento"<<endl;
        cout<<"Dia: ";
        cin>>P1[i].tipo.inicio.dia;
        cout<<"Mes: ";
        cin>>P1[i].tipo.inicio.mes;
        cout<<"Anio: ";
        cin>>P1[i].tipo.inicio.anio;
        cout<<"Duracion del tratamiento: ";
        cin>>P1[i].tipo.duracionTrat;
        cin.ignore();
        cout<<"Nombre del medicamento recetado: ";
        cin.getline(P1[i].tipo.nombreMedicamento,20,'\n');
        cout<<"Doctor cabecera del paciente"<<endl;
        cout<<"Nombre: ";
        cin.getline(P1[i].cabecera.doc.nombre,20,'\n');
        cout<<"Apellido: ";
        cin.getline(P1[i].cabecera.doc.apellido,20,'\n');
        cout<<"Fecha de nacimiento"<<endl;
        cout<<"Dia: ";
        cin>>P1[i].cabecera.nacimient.dia;
        cout<<"Mes: ";
        cin>>P1[i].cabecera.nacimient.mes;
        cout<<"Anio: ";
        cin>>P1[i].cabecera.nacimient.anio;
        cin.ignore();
        cout<<"Especialidad: ";
        cin.getline (P1[i].cabecera.especialidad,20,'\n');

        cout<<endl;
    }
}


void Mostrardatos(paciente P1[], int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        cout << "----------DATOS DEL PACIENTE " << i + 1 << "----------" << endl;
        cout <<"Nombre: "<<P1[i].persona.nombre<<endl;
        cout <<"Apellido: "<<P1[i].persona.apellido<<endl;
        cout <<"CI: "<<P1[i].CI<<endl;
        cout <<"Celular: "<<P1[i].celular<<endl;
        cout <<"Edad: "<<P1[i].edad<<endl;
        cout <<"* Fecha de nacimiento"<<endl ;
        cout <<"Dia: "<<P1[i].nacimiento.dia<<endl;
        cout <<"Mes: "<<P1[i].nacimiento.mes<<endl;
        cout <<"Anio: "<<P1[i].nacimiento.anio<<endl;

        cout << "----------TIPO DE TRATAMIENTO DEL PACIENTE----------" << endl;
        cout <<"* Fecha de inicio del tratamiento"<<endl ;
        cout <<"Dia: "<<P1[i].tipo.inicio.dia<<endl;
        cout <<"Mes: "<<P1[i].tipo.inicio.mes<<endl;
        cout <<"Anio: "<<P1[i].tipo.inicio.anio<<endl;
        cout <<"Duracion del tratamiento: "<<P1[i].tipo.duracionTrat<<endl;
        cout <<"Nombre del medicamento recetado: "<<P1[i].tipo.nombreMedicamento<<endl;

        cout <<"---------DOCTOR CABECERA DEL PACIENTE---------"<<endl ;
        cout <<"Nombre: "<<P1[i].cabecera.doc.nombre<<endl;
        cout <<"Apellido: "<<P1[i].cabecera.doc.apellido<<endl;
        cout <<"* Fecha de nacimiento del doctor"<<endl ;
        cout <<"Dia: "<<P1[i].cabecera.nacimient.dia<<endl;
        cout <<"Mes: "<<P1[i].cabecera.nacimient.mes<<endl;
        cout <<"Anio: "<<P1[i].cabecera.nacimient.anio<<endl;
        cout <<"Especialidad: "<<P1[i].cabecera.especialidad<<endl;
    }
}


void borrarPaciente(paciente P1[], int &cant)
{
    int codigo;
    if(cant==0)
        cout<<"No hay pacientes registrados"<<endl;
    else
    {
        cout<<"Ingrese el numero del paciente que desea eliminar (1-"<<cant<<"): ";
        cin>>codigo;

        if(codigo<1 || codigo>cant)
            cout<<"El numero del paciente no es valido"<<endl;
        else
        {
            for(int i=codigo; i<cant; i++)
            {
                P1[i-1] = P1[i];
            }
            cant--;
            cout<<"Se elimino al paciente con numero: "<<codigo<<endl;
        }
    }
}

int main()
{
    int cant = 2;
    paciente P1[3];
    Cargardatos(P1,cant);

    cout <<"-------------------------------------------------------------"<<endl;
    Mostrardatos(P1,cant);

    cout <<"-------------------------------------------------------------"<<endl;
    borrarPaciente(P1,cant);

    cout <<"-------------------------------------------------------------"<<endl;
    Mostrardatos(P1,cant);

    return 0;
}
