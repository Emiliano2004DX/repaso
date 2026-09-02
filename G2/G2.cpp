#ifndef ARREGLO_H
#define ARREGLO_H

class Arreglo {
private:
    int* datos;
    int tam;

public:
    // Constructor
    Arreglo(int n) {
        tam = n;
        datos = new int[tam];
    }

    // Destructor
    ~Arreglo() {
        delete[] datos;
    }

    // Constructor de copia
    Arreglo(const Arreglo& otro) {
        tam = otro.tam;
        datos = new int[tam];

        for (int i = 0; i < tam; i++) {
            datos[i] = otro.datos[i];
        }
    }

    // Operador de asignación
    Arreglo& operator=(const Arreglo& otro) {
        if (this != &otro) {
            delete[] datos;

            tam = otro.tam;
            datos = new int[tam];

            for (int i = 0; i < tam; i++) {
                datos[i] = otro.datos[i];
            }
        }

        return *this;
    }
};

#endif