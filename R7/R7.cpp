#include <iostream>
#include <string>

int contarPalabras(const std::string& s) {
    int contador = 0;
    bool dentro = false;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            if (!dentro) {
                contador++;
                dentro = true;
            }
        } else {
            dentro = false;
        }
    }

    return contador;
}

std::string voltear(const std::string& s) {
    std::string resultado;

    for (int i = s.size() - 1; i >= 0; i--) {
        resultado += s[i];
    }

    return resultado;
}

int main() {
    std::string texto;

    std::cout << "Escribe una cadena: ";
    std::getline(std::cin, texto);

    std::cout << "Palabras: " << contarPalabras(texto) << std::endl;
    std::cout << "Invertida: " << voltear(texto) << std::endl;

    return 0;
}