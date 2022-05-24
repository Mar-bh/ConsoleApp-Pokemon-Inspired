/* Descripcion: declaracion de los metodos de la clase pokebola
Autor: Mariana Esquivel Hernández - 
*/
#ifndef ENTRENADOR_H
#define ENTRENADOR_H
#include <string>
#include "Medalla.h"

class Entrenador {
    public:
        Entrenador();
        Entrenador(std::string, int, int, std::string);
        std::string getNombre() const;
        int getExperiencia() const;
        int getMedallas() const;
        std::string getRango() const;
        void setNombre(std::string);
        void setExperiencia(int);
        void setMedallas(int);
        void setRango(std::string);
        void imprime();

    private:
        std::string nombre;
        int experiencia;
        int medallas;
        std::string rango;
};
#endif