
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {

    vector<string> palabras = {
        "hola", "mundo", "hola", "casa", "mundo",
        "hola", "perro", "casa", "gato", "perro"
    };

   

    vector<pair<string, int>> vectorConteo;

    for (string palabra : palabras) {
        bool encontrada = false;

        for (auto& dato : vectorConteo) {
            if (dato.first == palabra) {
                dato.second++;
                encontrada = true;
                break;
            }
        }

        if (!encontrada) {
            vectorConteo.push_back({palabra, 1});
        }
    }

    cout << "===== VECTOR =====" << endl;

    for (auto dato : vectorConteo) {
        cout << dato.first << ": " << dato.second << endl;
    }

    map<string, int> mapConteo;

    for (string palabra : palabras) {
        mapConteo[palabra]++;
    }

    cout << "\n===== MAP =====" << endl;

    for (auto dato : mapConteo) {
        cout << dato.first << ": " << dato.second << endl;
    }


    // =========================
    // SET
    // =========================

    set<string> palabrasUnicas;

    for (string palabra : palabras) {
        palabrasUnicas.insert(palabra);
    }

    cout << "\n===== SET =====" << endl;

    for (string palabra : palabrasUnicas) {

        int contador = 0;

        for (string elemento : palabras) {
            if (elemento == palabra) {
                contador++;
            }
        }

        cout << palabra << ": " << contador << endl;
    }


  

    cout << "\n===== COSTO =====" << endl;

    cout << "Vector: O(n * u)" << endl;
    cout << "Map:    O(n log u)" << endl;
    cout << "Set:    O(n * u)" << endl;

    cout << "\nDonde n = numero total de palabras" << endl;
    cout << "y u = numero de palabras diferentes" << endl;

    cout << "\n===== CONCLUSION =====" << endl;

    cout << "El map conviene mas para contar palabras porque" << endl;
    cout << "guarda cada palabra junto con su contador." << endl;

    cout << "El vector puede convenir si hay pocas palabras." << endl;

    cout << "El set conviene cuando solo queremos conocer" << endl;
    cout << "las palabras diferentes y no necesitamos contarlas." << endl;

    return 0;
}
```
