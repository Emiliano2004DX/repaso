#ifndef ARREGLO_HPP
#define ARREGLO_HPP

#include <iostream>
#include <string>

template <typename T>
class Arreglo {
private:
    T* datos_;
    int tam_;

public:
    Arreglo(int tam) {
        tam_ = tam;
        datos_ = new T[tam_];
    }

    // Constructor de copia: copia profunda
    Arreglo(const Arreglo& otro) {
        tam_ = otro.tam_;
        datos_ = new T[tam_];

        for (int i = 0; i < tam_; i++) {
            datos_[i] = otro.datos_[i];
        }
    }

    ~Arreglo() {
        delete[] datos_;
    }

    T& operator[](int indice) {
        return datos_[indice];
    }

    int tam() const {
        return tam_;
    }
};

// Prueba
int main() {

    Arreglo<double> numeros(3);

    numeros[0] = 10.5;
    numeros[1] = 20.5;
    numeros[2] = 30.5;

    Arreglo<double> copiaNumeros(numeros);
    copiaNumeros[0] = 99.9;

    std::cout << "Double original: ";
    for (int i = 0; i < numeros.tam(); i++) {
        std::cout << numeros[i] << " ";
    }

    std::cout << "\nDouble copia: ";
    for (int i = 0; i < copiaNumeros.tam(); i++) {
        std::cout << copiaNumeros[i] << " ";
    }

    Arreglo<std::string> nombres(3);

    nombres[0] = "Ana";
    nombres[1] = "Juan";
    nombres[2] = "Pedro";

    Arreglo<std::string> copiaNombres(nombres);
    copiaNombres[0] = "Carlos";

    std::cout << "\n\nString original: ";
    for (int i = 0; i < nombres.tam(); i++) {
        std::cout << nombres[i] << " ";
    }

    std::cout << "\nString copia: ";
    for (int i = 0; i < copiaNombres.tam(); i++) {
        std::cout << copiaNombres[i] << " ";
    }

    return 0;
}

#endif