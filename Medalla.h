/* Descripcion: declaracion de los metodos de la clase pokebola
Autor: Mariana Esquivel Hernández - 
*/
#ifndef MEDALLA_H
#define MEDALL_H
#include <string>

class Medalla {
    public:
        Medalla();
        Medalla(std::string, std::string);
        std::string getNombre() const;
        std::string getValor() const;
        void setNombre(std::string);
        void setValor(std::string);
        void imprime();

    private:
        std::string nombre;
        std::string valor;
};

#endif