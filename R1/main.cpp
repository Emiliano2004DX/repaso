#include <iostream>

#include "suma.h"

int main()
{
    int primerNumero;
    int segundoNumero;

    std::cout << "Ingresa dos numeros: ";
    std::cin >> primerNumero >> segundoNumero;

    std::cout << "La suma es: " << sumar(primerNumero, segundoNumero) << '\n';
    return 0;
}
