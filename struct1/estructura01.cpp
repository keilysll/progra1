#include <iostream>

using namespace std;

struct perso
{
    string nombre;
    char letrainicial;
    int edad;
    float ci;

};


int main()
{

    perso persona;
    perso persona2;


    persona.nombre = "Carlos ";
    persona.letrainicial = 'C';
    persona.edad = 30 ;
    persona.ci = 28256;
    cout <<"El nombre de la persona es :"<<persona.nombre<<endl;
    cout <<"La inicial del nombre la persona es :"<<persona.letrainicial<<endl;
    cout <<"La edad de la persona es :"<<persona.edad<<endl;
    cout <<"El carnet de la persona es :"<<persona.ci<<endl;

     cout <<"----------------------------------------------"<<endl;



    persona2.nombre = "Kalany ";
    persona2.letrainicial = 'K';
    persona2.edad = 21 ;
    persona2.ci = 47538;
    cout <<"El nombre de la persona es :"<<persona2.nombre<<endl;
    cout <<"La inicial del nombre la persona es :"<<persona2.letrainicial<<endl;
    cout <<"La edad de la persona es :"<<persona2.edad<<endl;
    cout <<"El carnet de la persona es :"<<persona2.ci<<endl;
    return 0;
}
