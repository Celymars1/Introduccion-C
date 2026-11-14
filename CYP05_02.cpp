#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long cuentas[2000];
    float calificaciones[2000];
    int total = 0; // Cuenta cuántos alumnos únicos llevamos

    // 1. Leer los datos y guardar la calificación más alta por alumno
    for (int i = 0; i < n; i++) {
        long long c;
        float cal;
        cin >> c >> cal;

        int pos = -1;
        // Buscamos si el alumno ya está registrado
        for (int j = 0; j < total; j++) {
            if (cuentas[j] == c) {
                pos = j;
                break;
            }
        }

        if (pos != -1) {
            // Si ya existe, actualizamos solo si la nueva es mayor
            if (cal > calificaciones[pos]) {
                calificaciones[pos] = cal;
            }
        }
        else {
            // Si es un alumno nuevo, lo agregamos al final
            cuentas[total] = c;
            calificaciones[total] = cal;
            total++;
        }
    }

    // 2. Ordenar de menor a mayor (Método de burbuja simple)
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (cuentas[j] > cuentas[j + 1]) {
                // Intercambiar cuenta
                long long auxC = cuentas[j];
                cuentas[j] = cuentas[j + 1];
                cuentas[j + 1] = auxC;

                // Intercambiar calificación para que no se separen
                float auxCal = calificaciones[j];
                calificaciones[j] = calificaciones[j + 1];
                calificaciones[j + 1] = auxCal;
            }
        }
    }

    // 3. Imprimir resultados en el formato pedido
    cout << total << "\n";
    for (int i = 0; i < total; i++) {
        cout << cuentas[i] << " " << calificaciones[i];
        // Imprimimos salto de línea excepto en el último elemento
        if (i < total - 1) {
            cout << "\n";
        }
        // Modificacion de prueba para la practica de HitHub
    }

    return 0;
}