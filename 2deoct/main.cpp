#include <iostream>
#include <fstream>
using namespace std;

struct fecha
{
    int dia;
    int mes;
    int anio;
};

struct carreraA
{
    char carreraAlum[20];
    char facultad [15];
    int cantsemestres;
};

struct alumno
{
    char Nombre[30];
    fecha nacimiento;
    float Notas [5];
    carreraA alumCarr;
    int mensualidad;
};

struct listaAlumno
{
    alumno vec[30];
    int ultimo;
};

void carrerallenar(alumno& alum1)
{
    cout <<"Ingresa la carrera: "<<endl;
    cin>>alum1.alumCarr.carreraAlum;
}

void Registrarfecha (fecha& Fec)
{
    cout <<"----Ingrese la fecha de nacimiento----"<<endl;
    cout<<endl;
    cout<<"Ingrese el dia: "<<endl;
    cin>>Fec.dia;
    cout<<"Ingrese el mes: "<<endl;
    cin>>Fec.mes;
    cout<<"Ingrese el anio: "<<endl;
    cin>>Fec.anio;
}

void mostrar(fecha F)
{
    cout<<F.dia<<"/"<<F.mes<<"/"<<F.anio<<endl;

}

void RegistrarAlumno(alumno &alumno1)
{
    int i ;
    cout<<"Ingrese el nombre del alumno: "<<endl;
    cin>>alumno1.Nombre;
    Registrarfecha(alumno1.nacimiento);
    cout<<"Ingrese 3 notas del alumno : "<<endl;
    for (i = 0 ; i < 3 ; i++)
    {
        cout <<"ingrese nota: "<<i+1<<endl;
        cin>>alumno1.Notas[i];
    }

}

void MostrarAlumno(alumno alumno1)
{
    int pos;
    cout<<endl<<"*Nombre del alumno: ";
    cout<<alumno1.Nombre<<endl;
    mostrar(alumno1.nacimiento);
    cout<<"Las 3 notas del alumno son: "<<endl;
    for (pos = 0 ; pos < 3; pos ++)
    {
        cout<<alumno1.Notas[pos]<<endl;
    }
}

listaAlumno InsertarAlumno(listaAlumno LA, alumno a1)
{
    LA.ultimo++; LA.vec[LA.ultimo] = a1 ;
    return LA;
}


void mostrarLista(listaAlumno LA)
{
    int pos;
    for(pos = 0 ; pos <=LA.ultimo; pos++)
        MostrarAlumno(LA.vec[pos]);

}

void guardarArchivo(alumno a)
{
    ofstream archivo;
    archivo.open("datos.dat", ios:: binary | ios::app); /// out crear y actualiza
    archivo.write((char*)&a,sizeof (alumno));
    archivo.close();

}

void leerArchivo(alumno a )
{
    ifstream archivo("datos.dat", ios:: binary);
    while (!archivo.eof()) ///recorre tod el archivo
    {
        archivo.read((char*)&a,sizeof (alumno));
        if (archivo.good())
        {
            MostrarAlumno(a);
        }
    }
    archivo.close();

}






int main()
{
    alumno a1, a2,a3; ///Variables de tipo alumno

    RegistrarAlumno(a1);
    cin.ignore();
    guardarArchivo(a1);

    RegistrarAlumno(a2);
    cin.ignore();
    guardarArchivo(a2);

    RegistrarAlumno(a3);
    cin.ignore();
    guardarArchivo(a3);

/*
    MostrarAlumno(a1);
    MostrarAlumno(a2);
    MostrarAlumno(a3);
*/
    leerArchivo(a3);

    return 0;
}
