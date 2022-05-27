/* Descripcion: declaracion de los metodos de la clase pokebola
*/
#include <iostream>
#include "Pokemon.h"
#include <string>

Pokemon::Pokemon() {
	nombre = "Fennekin";
	tipo = "Fuego";
	nivel = 0;;
}

Pokemon::Pokemon(std::string _nomb, std::string _tipo, int _nive) {
	nombre = _nomb;
	tipo = _tipo;
	nivel = _nive;
}

//Metodos de acceso o getters
std::string Pokemon::getNombre() const { 
	return nombre;
}

std::string Pokemon::getTipo() const {
	return tipo;
}

int Pokemon::getNivel() const {
	return nivel;
}

std::string Pokemon::getHabilidades(int opcion) const {
	return habilidades[opcion];
}

//Metodos modificadores o setters
void Pokemon::setNombre(std::string _nom) {
	nombre = _nom;
}
void Pokemon::setTipo(std::string _tip) {
	tipo = _tip;
}
void Pokemon::setNivel(int _niv) {
	nivel = _niv;
}

//Metodos adicionales
void Pokemon::imprime() {
	std::cout << "----Pokemones----" << std::endl;
	std::cout << "Nombre: \t" << nombre <<  std::endl;
	std::cout << "Tipo: \t\t" << tipo << std::endl;
	std::cout << "Nivel: \t\t" << nivel << std::endl; 
}

void Pokemon::imprimirHabilidad(int opcion) {
	std::cout << "La habilidad que el Pokemon " << nombre << " utilizara es: " << habilidades[opcion] << std::endl; 
}