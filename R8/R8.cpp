#include <iostream>

using namespace std;

// Por valor
void intercambiar1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// Por puntero
void intercambiar2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Por referencia
void intercambiar3(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    // Por valor
    x = 1;
    y = 2;

    intercambiar1(x, y);

    cout << "Despues de intercambiar1:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;


    // Por puntero
    x = 1;
    y = 2;

    intercambiar2(&x, &y);

    cout << "\nDespues de intercambiar2:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;


    // Por referencia
    x = 1;
    y = 2;

    intercambiar3(x, y);

    cout << "\nDespues de intercambiar3:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}