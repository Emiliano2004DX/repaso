#ifndef PUNTO_H
#define PUNTO_H

class Punto {
private:
    double x;
    double y;

public:
    Punto();
    Punto(double x, double y);
    ~Punto();

    void mostrar() const;
    void mover(double dx, double dy);
};

#endif