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
    float parciales[3];
    float notaprimerasesion;
    float notasegundasesion;
};

struct carrera
{
    char carrera[20];
    char facultad[15];
    int carsemestres;
};

struct alumno
{
    char nombre[20];
    fecha nacimiento;
    nota notas;
    carrera alumCarr;
};


void fechanacimiento(fecha &fec)
{
    cout << "Ingrese el dia de nacimiento: ";
    cin >> fec.dia;
    cout << "Ingrese el mes de nacimiento: ";
    cin >> fec.mes;
    cout << "Ingrese el anio de nacimiento: ";
    cin >> fec.anio;
}


void registrarnotas(nota &no)
{
    cout << "Ingrese las notas de los 3 parciales: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cin >> no.parciales[i];
    }

    cout << "Ingrese la nota de la 1ra sesion: ";
    cin >> no.notaprimerasesion;

    cout << "Ingrese la nota de la 2da sesion: ";
    cin >> no.notasegundasesion;
}

void registrarCarrera(carrera &carr)
{
    cout << "Ingrese el nombre de la carrera: ";
    cin >> carr.carrera;
    cout << "Ingrese la facultad: ";
    cin >> carr.facultad;
    cout << "Ingrese el semestre: ";
    cin >> carr.carsemestres;
}


void datosAlumnos(alumno &alum1)
{
    cout << "Ingrese el nombre del alumno: ";
    cin >> alum1.nombre;
    fechanacimiento(alum1.nacimiento);
    registrarnotas(alum1.notas);
    registrarCarrera(alum1.alumCarr);
}


float promedioParciales(alumno alum1)
{
    float suma = 0;
    for (int i = 0; i < 3; i++)
    {
        suma += alum1.notas.parciales[i];
    }
    return suma / 3;
}


void mostrarAlumno(alumno alum1)
{
    cout << "\n------ DATOS DEL ALUMNO ------" << endl;
    cout << "Nombre: " << alum1.nombre << endl;
    cout << "Fecha de nacimiento: " << alum1.nacimiento.dia << "/"
         << alum1.nacimiento.mes << "/" << alum1.nacimiento.anio << endl;

    cout << "Notas parciales: ";
    for (int i = 0; i < 3; i++)
    {
        cout << alum1.notas.parciales[i] << " ";
    }
    cout << endl;

    float prom = promedioParciales(alum1);
    cout << "Promedio de parciales: " << prom << endl;
    if (prom >= 60)
        cout << "Estado: Habilitado" << endl;
    else
        cout << "Estado: No habilitado" << endl;

    cout << "Nota primera sesion: " << alum1.notas.notaprimerasesion << endl;
    if (alum1.notas.notaprimerasesion >= 51)
        cout << "Resultado primera sesion: Aprobado" << endl;
    else
    {
        cout << "Resultado primera sesion: No aprobado" << endl;

        cout << "Nota segunda sesion: " << alum1.notas.notasegundasesion << endl;
        if (alum1.notas.notasegundasesion >= 51)
            cout << "Resultado segunda sesion: Aprobado" << endl;
        else
            cout << "Resultado segunda sesion: No aprobado" << endl;
    }

    cout << "Carrera: " << alum1.alumCarr.carrera << endl;
    cout << "Facultad: " << alum1.alumCarr.facultad << endl;
    cout << "Semestre: " << alum1.alumCarr.carsemestres << endl;
}

int main()
{
    alumno A1, A2;

    cout << "--- Ingresar datos del primer alumno ---" << endl;
    datosAlumnos(A1);
    mostrarAlumno(A1);

    cout << "\n--- Ingresar datos del segundo alumno ---" << endl;
    datosAlumnos(A2);
    mostrarAlumno(A2);

    return 0;
}
