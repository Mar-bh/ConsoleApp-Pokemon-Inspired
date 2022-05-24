/* Descripcion = declaracion de los metodos de la clase Entrenador
Autor: Mariana Esquivel Hernández - 01641224
*/
//Implementacion de la clase
#include <iostream>
#include "Entrenador.h"
#include <string>

//constructores
Entrenador::Entrenador() {
	nombre = "Invitado";
	experiencia = 0;
	medallas = 0;
	rango = "NOOB";
}

Entrenador::Entrenador(std::string _nomb, int _expe, int _meda, std::string _rang) {
	nombre = _nomb;
	experiencia = _expe;
	medallas = _meda;
	rango = _rang;
}

//Metodos de acceso o getters
std::string Entrenador::getNombre() const {
	return nombre;
}

int Entrenador::getExperiencia() const {
	return experiencia;
}

int Entrenador::getMedallas() const {
	return medallas;
}

std::string Entrenador::getRango() const {
	return rango;
}

//Metodos modificadores o setters
void Entrenador::setNombre(std::string _nom) {
	nombre = _nom;
}
void Entrenador::setExperiencia(int _exp) {
	experiencia = _exp;
}
void Entrenador::setMedallas(int _med) {
	medallas = _med;
}
void Entrenador::setRango(std::string _ran) {
	rango = _ran;
}

//Metodos adicionales
void Entrenador::imprime() {
	std::cout << "\n\t//Entrenador// \n>>>Nombre: \t\t" << nombre << "\n>>>Experiencia: \t" << experiencia << "\n>>>Medallas: \t\t" << medallas << "\n>>>Rango: \t\t" << rango<<"\n";
}