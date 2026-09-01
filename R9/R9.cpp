#include <iostream>
#include <string>
#include <stdexcept>

class Reserva {
private:
    std::string sala;
    int personas;
    int horaInicio;
    int horaFin;

public:
    // Constructor
    Reserva(const std::string& nuevaSala, int nuevasPersonas,
            int nuevoInicio, int nuevoFin) {
        
        if (nuevaSala.empty()) {
            throw std::invalid_argument("La sala no puede estar vacia");
        }

        if (nuevasPersonas < 1 || nuevasPersonas > 20) {
            throw std::invalid_argument(
                "Las personas deben estar entre 1 y 20"
            );
        }

        if (nuevoInicio < 0 || nuevoFin > 23 ||
            nuevoInicio >= nuevoFin) {
            throw std::invalid_argument(
                "Horario invalido"
            );
        }

        sala = nuevaSala;
        personas = nuevasPersonas;
        horaInicio = nuevoInicio;
        horaFin = nuevoFin;
    }

    // Getters
    std::string getSala() const {
        return sala;
    }

    int getPersonas() const {
        return personas;
    }

    int getHoraInicio() const {
        return horaInicio;
    }

    int getHoraFin() const {
        return horaFin;
    }

    // Setter para sala
    void setSala(const std::string& nuevaSala) {
        if (nuevaSala.empty()) {
            throw std::invalid_argument(
                "La sala no puede estar vacia"
            );
        }

        sala = nuevaSala;
    }

    // Setter para personas
    void setPersonas(int nuevasPersonas) {
        if (nuevasPersonas < 1 || nuevasPersonas > 20) {
            throw std::invalid_argument(
                "Las personas deben estar entre 1 y 20"
            );
        }

        personas = nuevasPersonas;
    }

    // Se modifican inicio y fin juntos
    void setHorario(int nuevoInicio, int nuevoFin) {
        if (nuevoInicio < 0 || nuevoFin > 23 ||
            nuevoInicio >= nuevoFin) {
            throw std::invalid_argument(
                "Horario invalido"
            );
        }

        horaInicio = nuevoInicio;
        horaFin = nuevoFin;
    }

    void mostrar() const {
        std::cout << "Sala: " << sala << std::endl;
        std::cout << "Personas: " << personas << std::endl;
        std::cout << "Horario: "
                  << horaInicio << ":00 - "
                  << horaFin << ":00" << std::endl;
    }
};

int main() {
    try {
        Reserva r("Sala A", 10, 8, 12);

        r.mostrar();

        // Modificacion valida
        r.setHorario(10, 15);

        std::cout << "\nNuevo horario:\n";
        r.mostrar();

        // Esto provocaria una excepcion:
        // r.setPersonas(25);

    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}