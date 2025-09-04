#include <iostream>

using namespace std;


void llenarVector (int vect[], int tam)
{
    for (int i = 0 ; i < tam ; i ++)
    {
    cout<<"Digite nro  "<< i + 1<<" =" ;
    cin >> vect[i];
    }
}

void MostrarVector(int vect [] , int tam)
{
    for (int i = 0 ; i < tam ; i ++)
    {
        cout <<vect [i]<<" ";
    }
    cout<<endl;
}

void MayorMenorVector(int vec[], int tam, int &mayor, int &menor)
{
    mayor = vec[0];
    menor = vec[0];
    for (int i = 1; i < tam; i++)
    {
        if (vec[i] > mayor) mayor = vec[i];
        if (vec[i] < menor) menor = vec[i];
    }
}







void busquedasecuencial(int vect[], int tam, int dato) {
    bool encontrado = false;
    int pos = -1;

    for (int i = 0; i < tam; i++) {
        if (vect[i] == dato) {
            encontrado = true;
            pos = i;
            break;
        }
    }

    if (!encontrado) {
        cout << "EL DATO NO EXISTE EN EL ARREGLO" << endl;
    } else {
        cout << "EL DATO HA SIDO ENCONTRADO EN LA POSICION: " << pos << endl;
    }
}




void ordenarAscendente(int v[],int tam)
{   int i,j,aux;
    for(i=0;i<tam;i++){
        for(j=i+1;j<tam;j++){
           if(v[i]>v[j]){
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
           }
        }
    }
}




void ordenarDescendente(int v[], int tam) {
   {   int i,j,aux;
    for(i=0;i<tam;i++){
        for(j=i+1;j<tam;j++){
           if(v[i]<v[j]){
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
           }
        }
    }
}
}

void cargarMatriz(int matru[][100], int f, int c)
{
    for (int i = 0; i <f; i++)
    {
        for (int j = 0 ; j < c; j ++)
        {
            cout<<"digite nro"<<"["<<i<<"]["<<j<<"]";
            cin >> matru[i][j];
        }
    }

}

void mostraMatriz(int matru[][100], int f, int c)
{
    for (int i = 0; i<f;i++)
    {
        for (int j = 0; j<c; j++)
        {
            cout<<matru[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void DiagonalMatriz (int matriz[][100],int f, int c)
{
    cout<<"La diagonal primcipal es:";
    for (int i = 0 ; i<f ;  i++)
        {
            for(int j = 0; j< c; j++)
            {
                if (i == j){
                cout<<matriz[i][j]<<" ";
                }

            }
        }
}


int Sumarmatriz (int M1 [][100],int filas, int columnas)
{
    int suma = 0;
    for(int i = 0; i < filas ; i++)
{
    for (int j = 0 ; j< columnas ; j++)
{

    suma = suma + M1[i][j];
        }
    }
    return suma;

}


void SumarColumnas (int M1 [][100], int filas, int columnas, int vectorSuma[])
{
    for (int j = 0; j < columnas; j++)
    {
        int suma = 0;
        for (int i = 0; i < filas; i++)
        {
            suma += M1[i][j];
        }
        vectorSuma[j] = suma;
    }
}

void MostrarVectorSuma (int vec[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << i << " = " << vec[i] << endl;
    }
}


void SumarFilas(int M1 [][100], int filas, int columnas, int vectorSuma[])
{
    for (int i = 0; i < filas; i++)

    {
        int suma = 0;
        for (int j = 0; j < columnas; j++)
        {
            suma += M1[i][j];
        }
        vectorSuma[i] = suma;
    }
}


void MayorMenorMatriz(int mat[][100], int filas, int columnas, int &mayor, int &menor)
{
    mayor = mat[0][0];
    menor = mat[0][0];
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (mat[i][j] > mayor) mayor = mat[i][j];
            if (mat[i][j] < menor) menor = mat[i][j];
        }
    }
}
int main()
{
    int vect[100];
    int matriz[100][100];
    int n,f,c,k,mass,menoss;
    int vectorSuma[100];

    cout <<"Ingrese tamaño de del vector"<<endl ;
    cin>>n;
    llenarVector(vect, n);
    MostrarVector(vect, n);
    cout << "Dato que se gustaria buscar"<<endl;
    cin >>k;
    busquedasecuencial(vect,n,k);
    cout <<"----ORDEN ASCENDENTE----"<<endl;
    ordenarAscendente(vect,n);
    MostrarVector(vect,n);

     cout <<"----ORDEN DESCENDENTE----"<<endl;
     ordenarDescendente(vect,n);
    MostrarVector(vect,n);

     cout <<"--MAYOR Y MENOR VEC----"<<endl;
     MayorMenorVector(vect,n,mass,menoss);
     cout << "Mayor del vector: " << mass << endl;
    cout << "Menor del vector: " << menoss << endl;


    cout<<"Ingrese nro de filas"<<endl;
    cin>>f;
    cout<< "Ingrese nro de columnas"<<endl;
    cin>>c;

    cargarMatriz(matriz,f,c);
    mostraMatriz(matriz,f,c);

    DiagonalMatriz(matriz, f,c);

    int resultado = Sumarmatriz(matriz,f,c);
    cout <<"La suma de la matriz es :"<<resultado<<endl;

    cout <<"----SUMA COLUMNAS----"<<endl;
    SumarColumnas(matriz, f, c, vectorSuma);
    MostrarVectorSuma(vectorSuma,n);

    cout <<"----SUMA FILAS----"<<endl;
    SumarFilas(matriz, f, c, vectorSuma);
    MostrarVectorSuma(vectorSuma,n);

    cout <<"--MAYOR Y MENOR MATRIZ----"<<endl;
     MayorMenorMatriz(matriz,f,c,mass,menoss);
     cout << "Mayor de la matriz: " << mass << endl;
    cout << "Menor de la matriz: " << menoss << endl;
    return 0;
}
