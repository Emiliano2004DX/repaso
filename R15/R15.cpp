#include <iostream>
#include <string>

using namespace std;

class Persona {
protected:
    string nombre;

public:
    Persona(string n) : nombre(n) {
        cout << "Constructor Persona" << endl;
    }

    ~Persona() {
        cout << "Destructor Persona" << endl;
    }
};

class Empleado : public Persona {
protected:
    double salario;

public:
    Empleado(string n, double s) : Persona(n), salario(s) {
        cout << "Constructor Empleado" << endl;
    }

    ~Empleado() {
        cout << "Destructor Empleado" << endl;
    }
};

class Gerente : public Empleado {
private:
    int empleadosACargo;

public:
    Gerente(string n, double s, int e)
        : Empleado(n, s), empleadosACargo(e) {
        cout << "Constructor Gerente" << endl;
    }

    ~Gerente() {
        cout << "Destructor Gerente" << endl;
    }
};

int main() {
    {
        Gerente g("Ana", 1000, 5);
    }

    return 0;
}