/* Descripción: main de royecto integrador. Menu que permite registrarse como entrenador pokemon y realizar actividades relacionadas con esto
Autores:
Mariana Bustos Hernandez - A01641324
Mariana Esquivel Hernandez -  A01641244
Fecha: 02 12 2021
*/
#include <iostream>
#include <fstream>
using namespace std; // Si se pone antes de los include de las Clases, no tenemos que ponerlo en los .h
#include <string>
#include "Entrenador.h"
#include "Pokebola.h"
const int CANT = 15; // cantidad de pokemones disponibles

//Función para agregar a una lista los pokemones del archivo txt
void pokemonDisponible(Pokemon poke[],int &cantidad){ //Ambos miembros del equipo
    string tipo, nombre;
    int nivel;
    cantidad = 0;
    ifstream archivo;
    archivo.open("Pokemon.txt");
    while(archivo >> nombre >> tipo >> nivel ){
        poke[cantidad].setNombre(nombre);
        poke[cantidad].setTipo(tipo);
        poke[cantidad].setNivel(nivel);
        cantidad++;
    }
    archivo.close();
}

//Funcion para imprimir los pokemones disponibles
void imprimirPokemonDisponible(Pokemon poke[], int cantidad) { //Mariana Bustos
    for (int i = 0; i < cantidad; i++) {
        poke[i].imprime();
        cout << endl;
    }
    cout << "Todos estos 15 pokemones tienen las mismas habilidades " << endl;
    cout << "-------Habilidades------ " << std::endl;
    for(int i = 0; i < 4; i++){
		std::cout << "Habilidad " << i+1 << ": \t\t"<< poke[1].getHabilidades(i) << std::endl;
    }
}

//Funcion para calcular el Rango del jugador
string rango(int cant_exp, int cant_medallas) { //Mariana Esquivel
    int suma;
    suma = cant_exp + cant_medallas;
    if (suma == 0) {
        return "-";
    }
    else if (suma > 0 && suma <= 2) {
        return "I";
    }
    else if (suma > 2 && suma <= 4) {
        return "II";
    }
    else if (suma > 4 && suma <= 6) {
        return "III";
    }
    else if (suma > 6 && suma <= 8) {
        return "IV";
    }
    else {
        return "V";
    }
}

//Función para registrar al entrenador
Entrenador registrarEntrenador() { //Ambos miembros del equipo
    int opcion = 0;
    cout << "---------------------" << endl;
    cout << "------BIENVENIDO-----" << endl;
    do {
        cout << "Presiona 1) para registrarte como entrenador o  2) para entrar como invitado" << endl;
        cin >> opcion;
        if (opcion != 1 && opcion != 2) {
            cout << "Opcion ingresada invalida" << endl;
        }
    } while (opcion != 1 && opcion != 2);
    if (opcion == 1) {
        string nombre;
        int experiencia;
        int medallas;
        cout << "Ingresa tu nombre: " << endl;
        cin >> nombre;
        cout << "Ingresa tus anios de experiencia: " << endl;
        cin >> experiencia;
        cout << "Ingresa la cantidad de medallas que posees: " << endl;
        cin >> medallas;
        string Rango = rango(experiencia, medallas);
        Entrenador entrenador(nombre, experiencia, medallas, Rango);
        return entrenador;
    }
    else {
        Entrenador entrenador;
        return entrenador;
    }
}

//Funcion para seleccionar una habilidad del pokemon
void habilidades(Pokebola pokebola) { //Mariana Esquivel
    Pokemon pokemon;
    int validacionPokemon;
    int opcion;
    do {
        cout << "Quieres usar tu pokemon?\n1) Si :D\n2) No >:(" << endl;
        cin >> validacionPokemon;
        if (validacionPokemon != 1 && validacionPokemon != 2) {
            cout << "Porfavor escoge entre el numero 1 y 2" << endl;
        }
    } while (validacionPokemon != 1 && validacionPokemon != 2);
    if (validacionPokemon == 1) {
        do {
            cout << "¿Qué habilidad deseas usar? :\n1)Golpe\n2)Habilidad especial\n3)Poder acumulado\n4)Poder definitivo" << endl;
            cin >> opcion; 
            if (opcion <= 1 && opcion > 4) {
                cout << "Solo hay 4 habilidades" << endl;
            }
        } while (opcion <= 1 && opcion > 4);
        pokemon = pokebola.getPokemon();
        pokemon.imprimirHabilidad(opcion-1);
    }
    else {
        cout << "Tu pokemon no utilizara ninguna habillidad " << endl;
    }
}

//funcion para utilizar la pokebola, permite atrapar a un pokemon 
void utilizaPokebola(Pokemon pokemon[], Pokebola pokebola) { //Mariana Bustos
    int indicePoke = 0;
    string op,op2;
    cout << "Puedes ahcer uso de una Pokebola " << endl;
    pokebola.imprime();
    cout << "Deseas atrapar un pokemon? " << endl << "1) Si" << endl << "Cualquier otra tecla: No" << endl;
    cin >> op;
    if (op == "1") {
        do {
            cout << "Elige un pokemon, teclea un numero del 1 al 15" << endl;
            cin >> indicePoke;
        } while (indicePoke <= 1 && indicePoke >= 15);
        pokebola.atrapar(pokemon[indicePoke - 1]);
        cout << "Has atrapado el pokemon : " << pokebola.getPokemon().getNombre() << endl;
        do{
            cout << "Quieres ver la informacion del pokemon: \n1)Si\n2)No"  << endl;
            cin >> op2;
            if (op2 != "1" && op2!= "2"){
                cout << "Opcion invalida" << endl;
            }
        } while(op2!= "1" && op2!= "2");
        if (op2 == "1"){
            pokebola.getPokemon().imprime();
            cout << "-------Habilidades------ " << std::endl;
	        for(int i = 0; i < 4; i++){
		        std::cout << "Habilidad " << i+1 << ": \t\t" << pokebola.getPokemon().getHabilidades(i) << std::endl;
        	}
        }
       
    } else{
        cout << "Decidiste no atrapar ningun pokemon"  << endl;
    }
}

//funcion para ingresar un nueva medalla para el entrenador/usuario
void ingresarMedalla(Entrenador entrenador){ //Mariana Bustos
    string nombre, valor;
    cout << "-------------------------------" << endl;
    cout << "Ingresa el nombre de la medalla: " << endl;
    cin >> nombre;
    cout << "Ingresa el valor de la medalla: " << endl;
    cin >> valor;
    Medalla nuevaMedalla(nombre,valor);
    int cant;
    cant = entrenador.getMedallas()+1;
    cout << entrenador.getNombre() << " ahora tiene " << cant << " medallas " << endl;
}

int main() {
    Pokemon poke[CANT];
    Pokebola pokebola;
    int cantidadPokemon;
    Entrenador entrenador = registrarEntrenador(); 
    pokemonDisponible(poke, cantidadPokemon);
    char opcion;
    do {
        cout << endl; // consultas 
        cout << "Opciones disponibles " << endl;
        cout << " 1) Ver estatus del entrenador " << endl;
        cout << " 2) Ver la lista de Pokemones disponibles " << endl;
        cout << " 3) Utilizar Pokebola" << endl;
        cout << " 4) Usar las habilidades de tu Pokemon"<< endl;
        cout << " 5) Ingresa una medalla " << endl;
        cout << " 6) Salir" << endl;
        cin >> opcion;
        switch (opcion) {
            case '1':
	            entrenador.imprime();
                break;
            case '2':
                imprimirPokemonDisponible(poke, cantidadPokemon);
                break;
            case '3': 
                utilizaPokebola(poke,pokebola);
                break;
            case '4':
                habilidades(pokebola);
                break;
            case '5':
                ingresarMedalla(entrenador);
                break;
            case '6':
                cout << "Elegiste salir del programa..."<< endl;
                break;
            default:
                cout << "Opcion invalida"<<endl;
        }
        system("Pause");
    } while (opcion != '6');
    return 0;
}