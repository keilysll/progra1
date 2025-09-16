#include <iostream>

using namespace std;

struct fecha
{
    int dia;
    int mes;
    int anio;

};

struct nota
{
    float parciales [3];
    float notaprimerasesion;
    float notasegundasesion;
    //float promedio;

};

struct carrera
{
    char carrera [20];
    char facultad [15];
    int carsemestres;

};

struct alumno
{
    char nombre [20];
    fecha nacimiento ;
    nota notas;
    carrera alumCarr;


};

void fechanacimiento(fecha &fec)
{
    cout<<"Ingrese el dia de nacimiento: ";
    cin >> fec.dia;
    cout <<"Ingrese el mes de nacimiento: ";
    cin >>fec.mes;
    cout<< "Ingresa el anio de nacimiento: ";
    cin >>fec.anio;

}


void resgistrarnotas(nota &no)
{
    cout <<"Ingrese las notas del alumno de los 3 parciales: "<<endl;
    for (int i = 0 ; i < 3; i ++){
        cin >> no.parciales [i];
    }

    cout<<"Ingrese la nota de la 1ra sesion del alumno: ";
    cin >>no.notaprimerasesion;

    cout<<"Ingrese la nota de la 2da sesion del alumno: ";
    cin >>no.notasegundasesion;
}

void carrera (carrera &carr)
{
    cout <<"Ingrese el nombre de la carrera: ";
    cin>>carr.carrera;
    cout<<"Ingrese el nombre de la facultad: ";
    cin>>carr.facultad;
    cout<<"Ingrese el semestre en el que va: ";
    cin>> carr.carsemestres;

}

void datosAlumnos(alumno &alum1)
{
    cout<<"Ingrese el nombre del alumno: ";
    cin>>alum1.nombre;
    fechanacimiento(alum1.nacimiento);
    resgistrarnotas(alum1.notas);
    carrera(alum1.alumCarr);

}
/*
void Borraralumno(alumno &alum1)
{
    char cero = ' ';
    for (int i = 0 ; i < 20 ; i ++){
        alum1.nombre[i] = cero ;
        alum1.nombre[i] = cero ;
        alum1.alumCarr.carrera[i] = cero ;
        alum1.alumCarr.facultad[i] = cero ;
    }

    alum1.nacimiento.dia = 0;
    alum1.nacimiento.mes = 0 ;
    alum1.nacimiento.anio = 0 ;
    for (int i = 0; i<3 ; i ++){
        alum1.notas.parciales [i] = 0 ;
    }
    alum1.notas.notaprimerasesion = 0;
    alum1.alumCarr.carsemestres = 0;

}
*/



void mostrarAlumno(alumno alum1)
{
    if (alum1.nombre[1]== ' ')
        {
            cout<<"El alumn no existe";
        }else{
            cout<<"El nombre es: ";
            cout<<alum1.nombre<<endl;
            cout<<"La notas del alumno es : "<<endl;
            for (int j = 0 ; j < 3 ; j++){
            cout<<alum1.notas.parciales[j]<<endl;}
/*
            float suma = 0 ;
            suma= suma + alum1.notas.parciales[j];
            float promedio = suma /3;
            cout<<"El promedio del estudiante es: "<< promedio<<endl;
            if (promedio  >= 60){
                cout<<"Habilito para 1ra sesion"<<endl;
            }else{
                cout<<"No habilito para 1ra sesion"<<endl;
            }
            }
*/


        cout<<"La nota del examen primera sesion es: "<<alum1.notas.notaprimerasesion<<endl;
            if (alum1.notas.notaprimerasesion >= 51){
                cout<<"El estudiante habilito la primera sesion "<<endl;
            }else {
                cout<<"El estudiante no habilito la primera sesion"<<endl;
                cout<<"La nota del examen segunda sesion es: "<<alum1.notas.notasegundasesion<<endl;}

            cout<<"La carrera es : "<<alum1.alumCarr.carrera<<endl;
            cout<<"La facultad es : "<<alum1.alumCarr.facultad<<endl;
            cout<<"El semestre es : "<<alum1.alumCarr.carsemestres<<endl;
        }
}

/*
void Buscaralumno(alumno alum1){
    int an ;
    cout <<"Ingrese anio de nacimiento del estudiante: ";
    cin >> an;
    if (alum1.nacimiento == an ) {
        cout<<"Se encontro el estudiante"<<endl;
        mostraralumno (alum1);
    }else{
    cout << "No se encontro al estudiante"<<endl;
    }
    }

*/


int main()
{
    alumno A1,A2;

    datosAlumnos(A1);
    cout<<endl;
    mostrarAlumno(A1);
    cout<<endl;

    datosAlumnos(A2);
    cout<<endl;
    mostrarAlumno(A2);
    cout<<endl;

    //Buscaralumno(A1);
    return 0;
}
