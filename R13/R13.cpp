#include <iostream>

class Arreglo {
private:
    int* datos;
    int n;

public:
    // Constructor
    Arreglo(int tam) {
        n = tam;
        datos = new int[n];

        for (int i = 0; i < n; i++) {
            datos[i] = 0;
        }

        std::cout << "Constructor: " << this << std::endl;
    }

    // Constructor de copia
    Arreglo(const Arreglo& otro) {
        n = otro.n;
        datos = new int[n];

        for (int i = 0; i < n; i++) {
            datos[i] = otro.datos[i];
        }

        std::cout << "Constructor de copia: " << this << std::endl;
    }

    // Operator =
    Arreglo& operator=(const Arreglo& otro) {
        if (this != &otro) {
            delete[] datos;

            n = otro.n;
            datos = new int[n];

            for (int i = 0; i < n; i++) {
                datos[i] = otro.datos[i];
            }
        }

        std::cout << "Operator =: " << this << std::endl;

        return *this;
    }

    // Destructor
    ~Arreglo() {
        std::cout << "Destructor: " << this << std::endl;
        delete[] datos;
    }

    // set
    void set(int pos, int valor) {
        datos[pos] = valor;
    }

    // get
    int get(int pos) const {
        return datos[pos];
    }

    // tam
    int tam() const {
        return n;
    }
};

int main() {

    Arreglo a(3);

    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);

    std::cout << "Tamano de a: " << a.tam() << std::endl;
    std::cout << "a[0]: " << a.get(0) << std::endl;
    std::cout << "a[1]: " << a.get(1) << std::endl;
    std::cout << "a[2]: " << a.get(2) << std::endl;

    // Constructor de copia
    Arreglo b = a;

    b.set(0, 99);

    std::cout << "\nDespues de b.set(0, 99):" << std::endl;
    std::cout << "a[0]: " << a.get(0) << std::endl;
    std::cout << "b[0]: " << b.get(0) << std::endl;

    // Operator =
    Arreglo c(3);
    c = a;

    c.set(0, 77);

    std::cout << "\nDespues de c = a y c.set(0, 77):" << std::endl;
    std::cout << "a[0]: " << a.get(0) << std::endl;
    std::cout << "c[0]: " << c.get(0) << std::endl;

    return 0;
}