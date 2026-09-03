#include <iostream>
#include <numeric>
using namespace std;

class Fraccion {
private:
    int num_;
    int den_;

    void reducir() {
        // El denominador debe ser positivo
        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }

        int mcd = gcd(abs(num_), abs(den_));
        num_ /= mcd;
        den_ /= mcd;
    }

public:
    // Constructor
    Fraccion(int n = 0, int d = 1) : num_(n), den_(d) {
        reducir();
    }

    // Operador +
    Fraccion operator+(const Fraccion& otra) const {
        return Fraccion(
            num_ * otra.den_ + otra.num_ * den_,
            den_ * otra.den_
        );
    }

    // Operador *
    Fraccion operator*(const Fraccion& otra) const {
        return Fraccion(
            num_ * otra.num_,
            den_ * otra.den_
        );
    }

    // Operador ==
    bool operator==(const Fraccion& otra) const {
        return num_ == otra.num_ && den_ == otra.den_;
    }

    // Operador <
    bool operator<(const Fraccion& otra) const {
        return num_ * otra.den_ < otra.num_ * den_;
    }

    // Operador << como función amiga
    friend ostream& operator<<(ostream& salida, const Fraccion& f);
};

// Función libre amiga
ostream& operator<<(ostream& salida, const Fraccion& f) {
    salida << f.num_ << "/" << f.den_;
    return salida;
}

int main() {
    Fraccion f1(1, 2);
    Fraccion f2(1, 3);

    cout << "1/2 + 1/3 = " << f1 + f2 << endl;

    Fraccion f3(6, -8);

    cout << "6/-8 = " << f3 << endl;

    return 0;
}