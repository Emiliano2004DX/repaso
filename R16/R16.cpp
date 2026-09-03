#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// Clase abstracta
class Figura {
public:
    virtual double area() const = 0;
    virtual string nombre() const = 0;

    virtual ~Figura() = default;
};

// Clase Circulo
class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {}

    double area() const override {
        return M_PI * radio * radio;
    }

    string nombre() const override {
        return "Circulo";
    }
};

// Clase Rectangulo
class Rectangulo : public Figura {
private:
    double base;
    double altura;

public:
    Rectangulo(double b, double h) : base(b), altura(h) {}

    double area() const override {
        return base * altura;
    }

    string nombre() const override {
        return "Rectangulo";
    }
};

int main() {

    // Vector de punteros a la clase abstracta
    vector<Figura*> figuras;

    // Agregamos diferentes tipos de figuras
    figuras.push_back(new Circulo(5));
    figuras.push_back(new Rectangulo(4, 6));
    figuras.push_back(new Circulo(3));
    figuras.push_back(new Rectangulo(10, 2));

    double total = 0;

    // Recorrer el vector
    for (Figura* figura : figuras) {
        cout << figura->nombre()
             << " - Area: "
             << figura->area()
             << endl;

        total += figura->area();
    }

    cout << "Area total: " << total << endl;

    // Liberar memoria
    for (Figura* figura : figuras) {
        delete figura;
    }

    return 0;
}