#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct edificio
{
    float enero;
    float febrero;
    float marzo;
    float abril;
    float mayo;
    float junio;
};

void cargar (edificio ed[], int n)
{
    for (int i = 0 ; i < n ; i ++)
    {
    cout<<"Ingresa las ganacias del edificio  "<<i + 1<<endl;
    cout<<"Enero: ";cin>>ed[i].enero;
    cout<<"Febrero: ";cin>>ed[i].febrero;
    cout<<"Marzo: ";cin>>ed[i].marzo;
    cout<<"Abril: ";cin>>ed[i].abril;
    cout<<"Mayo: ";cin>>ed[i].mayo;
    cout<<"Junio: ";cin>>ed[i].junio;
    }

    cin.ignore();

}

/*
void mostrar (edificio ed[], int n )
{
    for (int i=0 ; i<n ;i++ )
    {
        cout<<"Las ganacias del edificio  "<<i + 1<<endl;
    cout<<"Enero: "<<ed[i].enero<<endl;
    cout<<"Febrero: "<<ed[i].febrero<<endl;
    cout<<"Marzo: "<<ed[i].marzo<<endl;
    cout<<"Abril: "<<ed[i].abril<<endl;
    cout<<"Mayo: "<<ed[i].mayo<<endl;
    cout<<"Junio: "<<ed[i].junio<<endl;

    }
}
*/

void GuardarTexto(edificio ed[], int n)
{
    ofstream archivo;
    string nombre_archivo;
    cout <<"Ingrese el nombre del archivo mas su extesion"<<endl;
    getline(cin,nombre_archivo);

    archivo.open(nombre_archivo.c_str(),ios::out);

    if (archivo.fail())
    {
        cout<<"Error al crear el archivo";
        return;
    }

    for (int i = 0; i < n ; i ++)
    {
        archivo<<ed[i].enero<<endl;
        archivo<<ed[i].febrero<<endl;
        archivo<<ed[i].marzo<<endl;
        archivo<<ed[i].abril<<endl;
        archivo<<ed[i].mayo<<endl;
        archivo<<ed[i].junio<<endl;

    }

    archivo.close();
    cout<<"Se guardo en el archivo"<<endl;

}

void leerTexto()
{
    istream archivo;
    string nombre_archivo;

    cout<<"Ingrese el nombre del texto que le gustaria leer"<<endl;
    getline(cin,nombre_archivo);
    archivo.open(nombre_archivo.c_str(),ios::in);

    if (archivo.fail())
    {
        cout<<"Hubo un error al buscar el archvo";
        return;
    }

    edificio e;
    int contado = 0;

    while (!archivo.eof())
    {
    archivo>>e.enero>>e.febrero>>e.marzo>>e.abril>>e.mayo>>e.junio;
    }

    contado++;

    float meses [6]={e.enero,e.febrero,e.marzo,e.abril,e.mayo,e.junio};

    float total = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        total+=meses[i];

    }

    cout<<"Edificio"<<contado<<"TOTAL: "<<total<<endl;
}
int main()
{
    edificio ed [2];
    cargar(ed,2);
//    mostrar(ed,2);
    GuardarTexto(ed,2);
    leerTexto();



    return 0;
}
