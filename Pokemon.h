/* Descripcion = declaracion de la clase pokemon
Autor: Mariana Bustos Hernández - a01641324
*/
#ifndef POKEMON_H
#define POKEMON_H
#include <string>

class Pokemon {
    public:
        Pokemon();
        Pokemon(std::string, std::string, int);
        std::string getNombre() const;
        std::string getTipo() const;
        int getNivel() const;
        std::string getHabilidades(int) const; //habilidad
        void setNombre(std::string);
        void setTipo(std::string);
        void setNivel(int);
        void imprime();
        void subirNivel();
        void imprimirHabilidad(int);

    private:
        std::string nombre;
        std::string tipo;
        int nivel;
        std::string habilidades[4] = {"Golpe","Habilidad especial","Poder acumulado","Poder definitivo" }; //todos tienen 4       //const int MAX=4;

};
#endif //Pokemon_H

//class Habilidad
//nombre
//etc

//.h arreglos de objetos habilidades
