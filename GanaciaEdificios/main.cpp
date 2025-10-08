#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct edificio {
    float enero;
    float febrero;
    float marzo;
    float abril;
    float mayo;
    float junio;
};

void Cargar(edificio Ed[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n---------- INGRESE LAS GANANCIAS POR MES - EDIFICIO " << i + 1 << " -------------\n";
        cout << "Enero: "; cin >> Ed[i].enero;
        cout << "Febrero: "; cin >> Ed[i].febrero;
        cout << "Marzo: "; cin >> Ed[i].marzo;
        cout << "Abril: "; cin >> Ed[i].abril;
        cout << "Mayo: "; cin >> Ed[i].mayo;
        cout << "Junio: "; cin >> Ed[i].junio;
    }
    cin.ignore();
}
/*

void Mostrar(edificio Ed[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n---------- GANANCIAS EDIFICIO " << i + 1 << " -------------\n";
        cout << "Enero: " << Ed[i].enero << endl;
        cout << "Febrero: " << Ed[i].febrero << endl;
        cout << "Marzo: " << Ed[i].marzo << endl;
        cout << "Abril: " << Ed[i].abril << endl;
        cout << "Mayo: " << Ed[i].mayo << endl;
        cout << "Junio: " << Ed[i].junio << endl;
        cout << "TOTAL DEL EDIFICIO " << i + 1 << ": " << totalEdificio(Ed[i]) << endl;
    }
}
*/
void guardarTexto(edificio Ed[], int n) {
    ofstream archTexto;
    string nuevoarchivo;

    cout << "\nIngrese el nombre del archivo que desea crear (con extension, ej: datos.txt): ";
    getline(cin, nuevoarchivo);

    archTexto.open(nuevoarchivo.c_str(), ios::out);
    if (archTexto.fail()) {
        cout << "Error al crear el archivo.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        archTexto << Ed[i].enero <<endl;
        archTexto<< Ed[i].febrero<<endl;
       archTexto << Ed[i].marzo <<endl;
        archTexto<< Ed[i].abril <<endl;
        archTexto << Ed[i].mayo <<endl;
        archTexto << Ed[i].junio <<endl;
    }

    archTexto.close();
    cout << "\nGanancias guardadas correctamente.\n";
}

void leer() {
    string nombre_archivo;
    ifstream archivo;

    cout << "\nIngresa el nombre del archivo que deseas leer: ";
    getline(cin, nombre_archivo);

    archivo.open(nombre_archivo.c_str(), ios::in);
    if (archivo.fail()) {
        cout << "No existe el archivo.\n";
        return;
    }

    edificio e;
    int contadorEdificios = 0;

while (!archivo.eof()) {
    archivo >> e.enero >> e.febrero >> e.marzo >> e.abril >> e.mayo >> e.junio;

    if (archivo.eof()) break;
    if (archivo.fail()) {
        cout << "\nError de lectura en el archivo.\n";
        break;
    }

    contadorEdificios++;

    float meses[6] = {e.enero, e.febrero, e.marzo, e.abril, e.mayo, e.junio};

    float totalEd = 0;
    for (int i = 0; i < 6; i++) {
        totalEd += meses[i];
    }

    cout << "\n===== EDIFICIO " << contadorEdificios << " =====\n";
    cout << "Enero:   " << e.enero << endl;
    cout << "Febrero: " << e.febrero << endl;
    cout << "Marzo:   " << e.marzo << endl;
    cout << "Abril:   " << e.abril << endl;
    cout << "Mayo:    " << e.mayo << endl;
    cout << "Junio:   " << e.junio << endl;
    cout << "TOTAL DEL EDIFICIO " << contadorEdificios << ": " << totalEd << endl;
}
}

int main() {
    edificio Ed[3];
    Cargar(Ed, 3);
    //Mostrar(Ed, 3);
    guardarTexto(Ed, 3);
    leer();

    cout << "\nProceso finalizado correctamente.\n";
    return 0;
}

