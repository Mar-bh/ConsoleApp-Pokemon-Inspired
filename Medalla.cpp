<<<<<<< HEAD
/* Descripcion = declaracion de los metodos de la clase Medalla
Autor: Mariana Esquivel Hernández - 01641224
=======
/* Descripcion: declaracion de los metodos de la clase pokebola
Autor: Mariana Esquivel Hernández - 
>>>>>>> 59e867d7505525a6bace72aed94ca32bb10332fc
*/
#include <iostream>
#include "Medalla.h"
#include <string>

//constructores
Medalla::Medalla() {
    nombre = "Sin medalla";
    valor = "Sin valor";
}

Medalla::Medalla(std::string _nombre, std::string _valor) {
    nombre = _nombre;
    valor = _valor;
}

//Metodos de acceso o getters
std::string Medalla::getNombre() const {
    return nombre;
}

std::string Medalla::getValor() const {
    return valor;
}

//Metodos modificadores o setters
void Medalla::setNombre(std::string _nombre) {
    nombre = _nombre;
}

void Medalla::setValor(std::string _valor) {
    valor = _valor;
}

//Metodo extra
void Medalla::imprime() {
    std::cout << "--------------MEDALLA----------------" << std::endl;
    std::cout << "El nombre es: " << nombre << std::endl;
    std::cout << "El valor es: " << valor << std::endl;

}