#include <iostream>

void leerNotas(double notas[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Nota " << i + 1 << ": ";
        std::cin >> notas[i];
    }
}

double calcularPromedio(double notas[], int n) {
    double suma = 0;

    for (int i = 0; i < n; i++) {
        suma += notas[i];
    }

    return suma / n;
}

void mostrarResultado(double prom) {
    std::cout << "Promedio: " << prom << '\n';

    if (prom >= 70)
        std::cout << "Aprobado\n";
    else
        std::cout << "Reprobado\n";
}

int main() {
    double notas[3];

    leerNotas(notas, 3);

    double prom = calcularPromedio(notas, 3);

    mostrarResultado(prom);

    return 0;
}