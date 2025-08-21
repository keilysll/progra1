#include <iostream>
using namespace std;

void cargarvector (int vec[], int tam, string etiquetas[] ){
    for (int i = 0 ; i < tam ; i++) {
        cout <<"Ingrese valor para " << etiquetas[i] << ": ";
        cin >> vec[i];
    }
}

void mostrarvector (int vec[], int tam, string etiquetas[]){
    for (int i = 0 ; i < tam ; i++) {
        cout << etiquetas[i] << " = " << vec[i] << endl;
    }
}

int sumarvector (int vec[], int tam){
    int suma = 0;
    for (int i = 0 ; i < tam ; i++) {
        suma = suma + vec[i];
    }
    return suma;
}

void menuOpciones() {
    int opcion;
    do {
        cout << "\n--------------OPCIONES----------------\n";
        cout << "1. Registro de sueldos de empleados\n";
        cout << "2. Registro de ganancias de toda la semana de un supermercado\n";
        cout << "3. Registro de alumnos incritos desde 1ro y 5to de primaria\n";
        cout << "0. Salir\n";
        cout << "-------------------------------------\n";
        cout << "Seleccione una opcion : ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int n;
                cout << "Ingrese cantidad de empleados: ";
                cin >> n;
                int vec1[n];
                string etiquetas[n];
                for (int i = 0; i < n; i++) {
                    etiquetas[i] = "Empleado " + to_string(i+1);
                }
                cargarvector(vec1, n, etiquetas);
                mostrarvector(vec1, n, etiquetas);
                int resultado = sumarvector(vec1, n);
                cout<< "El total de pagos de sueldo es de: " << resultado << endl;
                break;
            }
            case 2: {
                int vec1[7];
                string dias[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
                cargarvector(vec1, 7, dias);
                mostrarvector(vec1, 7, dias);
                int resultado = sumarvector(vec1, 7);
                cout<< "El total ganado en el supermercado es de: " << resultado << endl;
                break;
            }
            case 3: {
                int vec1[5];
                string grados[] = {"1ro de primaria", "2do de primaria", "3ro de primaria", "4to de primaria", "5to de primaria"};
                cargarvector(vec1, 5, grados);
                mostrarvector(vec1, 5, grados);
                int resultado = sumarvector(vec1, 5);
                cout<< "El total de alumnos incritos es de: " << resultado << endl;
                break;
            }
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

int main(){
    menuOpciones();
    return 0;
}
