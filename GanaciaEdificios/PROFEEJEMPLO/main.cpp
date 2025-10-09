#include <iostream>
using namespace std;

struct Empleado {
    string nombre;
    string apellido;
    string cargo;
    float salario;
    float bono;
    float descuento;
    int horas_trabajadas;
    int horas_extra;
    float pago_extra;
    float salario_total;
};

const int HORAS_SEMANALES = 42; // constante para control de horas

void calcularSalario(Empleado &empleado) {
    // Inicializamos variables importantes
    empleado.bono = 0;
    empleado.descuento = 0;
    empleado.pago_extra = 0;
    empleado.salario_total = 0;
    empleado.horas_extra = 0;

    float tarifa_hora = empleado.salario / HORAS_SEMANALES;

    if (empleado.horas_trabajadas > HORAS_SEMANALES) {
        empleado.horas_extra = empleado.horas_trabajadas - HORAS_SEMANALES;
        empleado.pago_extra = empleado.horas_extra * (tarifa_hora * 2);
    } else {
        int horas_faltantes = HORAS_SEMANALES - empleado.horas_trabajadas;
        empleado.descuento += horas_faltantes * tarifa_hora; // descuento por horas faltantes
    }

    empleado.bono = empleado.salario * 0.15;      // bono del 15%
    empleado.descuento += empleado.salario * 0.08; // descuento del 8%
    empleado.salario_total = empleado.salario + empleado.bono - empleado.descuento + empleado.pago_extra;
}

int main() {
    int N;
    cout << "Ingrese el número de empleados: ";
    cin >> N;
    cout << endl;

    Empleado empleados[N];

    for (int i = 0; i < N; i++) {
        int opcion;
        bool cargo_valido = false;

        cout << "=== Registro del empleado " << i + 1 << " ===" << endl;
        cout << "Nombre: ";
        cin >> empleados[i].nombre;
        cout << "Apellido: ";
        cin >> empleados[i].apellido;

        while (!cargo_valido) {
            cout << "\nSeleccione el cargo del empleado " << i + 1 << ":" << endl;
            cout << "1. Ventas (5900 bs)" << endl;
            cout << "2. Contabilidad (6780 bs)" << endl;
            cout << "3. Financiera (7320 bs)" << endl;
            cout << "4. Mantenimiento (6200 bs)" << endl;
            cout << "5. Gerente (8300 bs)" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    empleados[i].cargo = "Ventas";
                    empleados[i].salario = 5900;
                    cargo_valido = true;
                    break;
                case 2:
                    empleados[i].cargo = "Contabilidad";
                    empleados[i].salario = 6780;
                    cargo_valido = true;
                    break;
                case 3:
                    empleados[i].cargo = "Financiera";
                    empleados[i].salario = 7320;
                    cargo_valido = true;
                    break;
                case 4:
                    empleados[i].cargo = "Mantenimiento";
                    empleados[i].salario = 6200;
                    cargo_valido = true;
                    break;
                case 5:
                    empleados[i].cargo = "Gerente";
                    empleados[i].salario = 8300;
                    cargo_valido = true;
                    break;
                default:
                    cout << "❌ Opción inválida. Intente nuevamente.\n";
                    break;
            }
        }

        // Validar horas trabajadas
        do {
            cout << "Ingrese las horas totales trabajadas por el empleado " << i + 1 << ": ";
            cin >> empleados[i].horas_trabajadas;
            if (empleados[i].horas_trabajadas < 0)
                cout << "Error: las horas no pueden ser negativas.\n";
        } while (empleados[i].horas_trabajadas < 0);

        calcularSalario(empleados[i]);
        cout << endl;
    }

    // Mostrar la información
    float totalPlanilla = 0;

    cout << "\n========= RESUMEN DE EMPLEADOS =========\n";
    for (int i = 0; i < N; i++) {
        cout << "\n-------------------------------------------" << endl;
        cout << "Empleado #" << i + 1 << ": " << empleados[i].nombre << " " << empleados[i].apellido << endl;
        cout << "Cargo: " << empleados[i].cargo << endl;
        cout << "Salario base: " << empleados[i].salario << " bs" << endl;
        cout << "Bono (15%): " << empleados[i].bono << " bs" << endl;
        cout << "Descuento total: " << empleados[i].descuento << " bs" << endl;
        cout << "Horas trabajadas: " << empleados[i].horas_trabajadas << endl;
        cout << "Horas extra: " << empleados[i].horas_extra << " (" << empleados[i].pago_extra << " bs)" << endl;
        cout << "➡️  Salario TOTAL: " << empleados[i].salario_total << " bs" << endl;

        totalPlanilla += empleados[i].salario_total;
    }

    cout << "\n========================================" << endl;
    cout << "TOTAL A PAGAR A TODO EL PERSONAL: " << totalPlanilla << " bs" << endl;
    cout << "========================================" << endl;

    return 0;
}
