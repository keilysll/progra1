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
    char facultad[15];
    int cantsemestres;
};
struct Alumno
{
    char Nombre[30];
    fecha Nacimiento;
    float Notas[5];
    carreraA alumCarr;
} ;
struct ListaAlumno
{
    Alumno vec[30];
    int ultimo;
};

void carrerallenar(Alumno& alum1)
{
    cout<<"Ingresar la Carrera: "<<endl;
    cin>> alum1.alumCarr.carreraAlum;
}
void pedir(fecha &Fec)
{
	cout<<"Ingrese la fecha:";
	cin>>Fec.dia;
	cin>>Fec.mes;
	cin>>Fec.anio;
}
void mostrar(fecha F)
{
    cout<<F.dia <<"/ "<<F.mes<<"/ "<<F.anio<<endl;
}
void PedirAlum(Alumno &alumno1)
{
    int i;
    cout<<"Ingrese el nombre del alumno"<<endl;
    cin>>alumno1.Nombre;
    pedir (alumno1.Nacimiento);
    cout<<"Ingrese 3 notas del alumno : "<<endl;
    	for(i=0; i<3; i++)
    	{
       	   cout<<"ingrese nota: "<<i+1<<endl;
        	   cin>>alumno1.Notas[i];  // se carga la nota [i] de acuerdo a i en la variable alumno1 de tipo estructura Alumno
   	 }
}
void MostrarAlum(Alumno alumno1)
{ int pos;
    cout<<endl<<"Nombre del alumno : ";
    cout<<alumno1.Nombre<<endl;
    mostrar(alumno1.Nacimiento);
    cout<<"Las 3 notas del alumno son: "<<endl;
    for(pos=0; pos<3; pos++)
        cout<<alumno1.Notas[pos] <<endl;
}
//Inserta al final de la lista LA a un alumno al, retorna LA llena
ListaAlumno InsertarAlumno(ListaAlumno LA, Alumno al)
{
	LA.ultimo++; LA.vec[LA.ultimo]=al;
	return LA;
}

void MostrarLista(ListaAlumno LA)
{   	int pos;
	for( pos=0; pos<=LA.ultimo; pos++)
	MostrarAlum(LA.vec[pos]); //llama a la función MostrarAlum
}

void guardarArchi(char nombre[50], Alumno a)
{

    ofstream archivo;
    archivo.open(nombre,ios::binary|ios::app);
    archivo.write((char *)&a,sizeof(Alumno));
    archivo.close();
}

void leerArchi(char nombre[50])
{
    ifstream archivo(nombre, ios::binary);
     Alumno a;
    while(!archivo.eof())//recorre todo ael archivo
    {
        archivo.read((char *)&a,sizeof(Alumno));
       if(archivo.good())
       {
	MostrarAlum(a);
        }

    }
    archivo.close();
}
//}
//-------------------------PROGRAMA PRINCIPAL ------------------------------------------
int main()
{
	// Hacer pruebas con los resultados creando mas de una variable de tipo Alumno

    Alumno al;

   // Alumno a2; // hacer la prueba creando mas variables a2, a3 y guardando sus datos como la otra variable a1
   // Alumno a3:

    ListaAlumno LA; //variable LA de tipo estructura ListaAlumno

    LA.ultimo=-1;
    PedirAlum(al);

    guardarArchi("alumnitos.dat",al);

    LA=InsertarAlumno(LA, al);

   leerArchi("alumnitos.dat");

    //LA=InsertarAlumno (LA, al);  //Hacer la prueba con la inserción de un alumno
   // MostrarLista(LA); // Hacer la prueba mostrando la lista

   //  PedirAlum(al);
   // guardarArchi("alumnitos.dat",al)
}
