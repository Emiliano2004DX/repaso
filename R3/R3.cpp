#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

int leerEnRango(string msg, int lo, int hi)
{
    int n;
    string linea;

    while (true)
    {
        cout << msg;
        getline(cin, linea);

        stringstream ss(linea);

        // Lee el número
        if (ss >> n)
        {
            string extra;

            // Comprueba que no haya basura después
            if (!(ss >> extra))
            {
                if (n >= lo && n <= hi)
                {
                    return n;
                }
            }
        }

        cout << "Escribe un entero entre "
             << lo << " y " << hi << ".\n";
    }
}

int main()
{
    int numero;

    numero = leerEnRango(
        "Escribe un entero entre 1 y 100: ",
        1,
        100
    );

    cout << "Numero valido: " << numero << endl;

    return 0;
}