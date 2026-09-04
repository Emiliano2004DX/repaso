#include <iostream>
#include <vector>

using namespace std;

void probarSinReserve() {
    vector<int> v;

    int reasignaciones = 0;
    long long elementosCopiados = 0;
    size_t capacidadAnterior = v.capacity();

    cout << "=== SIN reserve() ===" << endl;

    for (int i = 0; i < 1000; i++) {
        v.push_back(i);

        if (v.capacity() != capacidadAnterior) {
            reasignaciones++;

            // Se copian los elementos que ya estaban en el vector
            elementosCopiados += i;

            cout << "Tamano: " << v.size()
                 << " | Capacidad: " << v.capacity() << endl;

            capacidadAnterior = v.capacity();
        }
    }

    cout << "\nReasignaciones: " << reasignaciones << endl;
    cout << "Elementos copiados en total: "
         << elementosCopiados << endl;
}


void probarConReserve() {
    vector<int> v;
    v.reserve(1000);

    int reasignaciones = 0;
    long long elementosCopiados = 0;
    size_t capacidadAnterior = v.capacity();

    cout << "\n=== CON reserve(1000) ===" << endl;

    for (int i = 0; i < 1000; i++) {
        v.push_back(i);

        if (v.capacity() != capacidadAnterior) {
            reasignaciones++;

            elementosCopiados += i;

            cout << "Tamano: " << v.size()
                 << " | Capacidad: " << v.capacity() << endl;

            capacidadAnterior = v.capacity();
        }
    }

    cout << "\nReasignaciones: " << reasignaciones << endl;
    cout << "Elementos copiados en total: "
         << elementosCopiados << endl;
}


int main() {
    probarSinReserve();
    probarConReserve();

    return 0;
}