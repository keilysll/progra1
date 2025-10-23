#include <iostream>
using namespace std;

void serie4(int n, int limit, int cont = 1, int mult = 2, int inc = 2) {
    if (cont > limit) return;

    cout << n << " ";

    if (cont < limit) {
        n *= mult;        // multiplica por el multiplicador actual
        mult += inc;      // actualiza multiplicador
        inc += 2;         // el incremento aumenta de 2 en 2
        serie4(n, limit, cont + 1, mult, inc);
    }
}

int main() {
    int n, limit;
    cout << "=== SERIE 4 ===" << endl;
    cout << "Ingrese el numero de inicio: ";
    cin >> n;
    cout << "Ingrese la cantidad de numeros a mostrar: ";
    cin >> limit;

    cout << "Serie 4: ";
    serie4(n, limit);
    cout << endl;
    return 0;
}
