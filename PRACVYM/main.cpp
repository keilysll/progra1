#include <iostream>
using namespace std;
void cargarV (int v[], int n)
{
    for (int i=0; i<n ; i++)
    {
        cout<<"Dato"<<"["<<i+1<<"] ";
        cin>>v[i];
    }
}

void mostrarV( int v[], int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}

void MayMen (int v[], int n,int &may , int &men)
{
    may = v[0];
    men = v[0];

    for (int i=1;i<n;i++)
    {
        if(v[i]>may)may = v[i];
        if(v[i]<men)men = v[i];
    }

}

void OrdenarDes(int v[],int n)
{
    for(int i=0; i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        if (v[j]<v[j+1]){
        int temp = v[j];
        v[j]=v[j+1];
        v[j+1] = temp;
        }

    }
}

void OrdenarAsc (int v[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(v[i]>v[j+1])
            {
                int temp = v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
}

void SumaV(int v[],int n)
{
    int suma =0;
    for(int i=0;i<n;i++)
        {
            suma+=v[i];
        }
    cout<<"La suma es: "<<suma<<endl;
}

void cargarM(int m[][100],int f, int c)
{
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<"Dato"<<"["<<i<<"]"<<"["<<j<<"]";
            cin>>m[i][j];

    }
}

}
void mostraM(int m[][100], int f, int c)
{
    for (int i = 0; i<f;i++)
    {
        for (int j = 0; j<c; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void DiagonalM(int m[][100],int f,int c)
{
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==j)
            {
                cout<<m[i][j]<<" ";
            }
        }
    }
}

void sumaM(int m[][100],int f,int c)
{
    int suma =0;
    for (int i=0;i<f;i++)
    {
        for(int j=0;j<c;j++)
        {
            suma+=m[i][j];
        }
    }
    cout<<"La suma de la matriz es: "<<suma<<endl;
}


void Sumafilas(int m[][100],int f,int c)
{
    for(int i=0;i<f;i++)
    {
        int suma =0;
        for(int j=0;j<c;j++)
        {
            suma+=m[i][j];
        }
        cout<<"Fila"<<i+1<<" "<<suma<<endl;
    }
}

void SumaColumnas(int m[][100],int f , int c)
{
    for(int j=0;j<c;j++)
    {
        int suma=0;
        for(int i=0;i<f;i++)
        {
            suma+=m[i][j];
        }
        cout<<"Columna"<<j+1<<" "<<suma<<endl;
    }
}

void MayorM(int m[][100],int f,int c,int &may,int&men)
{
    may = m[0][0];
    men= m[0][0];

    for(int i=0;i<f;i++)
    {
        for(int j =0;j<c;j++)
        {
            if(m[i][j]>may)may = m[i][j];
            if(m[i][j]<men)men=m[i][j];
        }
    }
}
int main()
{
    int v[100];
    int m[100][100];
    int n,mass,menoss,f,c;
    cout<<"INGRESE TAMANIO DEL VECTOR: ";
    cin>>n;
    cargarV(v,n);
    mostrarV(v,n);
    cout <<endl;

    cout <<"--MAYOR Y MENOR VEC----"<<endl;
    MayMen(v,n,mass,menoss);
    cout<<"MAYOR: "<<mass<<endl;
    cout<<"MENOR: "<<menoss<<endl;

    cout <<"----ORDEN DESCENDENTE----"<<endl;
    OrdenarDes(v,n);
    mostrarV(v,n);cout <<endl;

    cout <<"----ORDEN ASCENDENTE----"<<endl;
    OrdenarAsc(v,n);
    mostrarV(v,n);cout <<endl;

    cout<<"SUMA DE VECTOR"<<endl;
    SumaV(v,n);

    cout<<"INGRESE TAMANIO DE MATRIZ: "<<endl;
    cout<<"FILAS: ";
    cin>>f;
    cout<<"COLUMNAS: ";
    cin>>c;

    cargarM(m,f,c);
    mostraM(m,f,c);

     cout<<"DIAGONAL"<<endl;
     DiagonalM(m,f,c);
     cout <<endl;

     cout<<"SUMA DE MATRIZ"<<endl;
    sumaM(m,f,c);

    cout<<"SUMA DE MATRRIZ FILAS"<<endl;
    Sumafilas(m,f,c);

    cout<<"SUMA DE MATRRIZ FILAS"<<endl;
    SumaColumnas(m,f,c);

    cout <<"--MAYOR Y MENOR VEC----"<<endl;
    MayorM(m,f,c,mass,menoss);
    cout<<"MAYOR: "<<mass<<endl;
    cout<<"MENOR: "<<menoss<<endl;

    return 0;
}
