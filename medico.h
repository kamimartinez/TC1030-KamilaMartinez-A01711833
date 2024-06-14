/*
 *
 * Proyecto Integrador clase Medico
 * Kamila Jeannette Martinez Ibarra
 * A01711833
 * 14/06/2024
 * version : 1
 * Esta clase define objeto de tipo Medico que contiene las clases heredadas
 * Cardiologo y Pediatra
 */

#ifndef MEDICO_H
#define MEDICO_H

#include <bits/stdc++.h>

using namespace std;

//Declaracion de clase Medico que es abstracta
class Medico {
	
	//Declaramos variables de instancia
	private:
		long long id;
		string nombre;
		int edad;
		string tipo;
	
	//Declaramps los métodos que va a tener el objeto
	public:
	
		// CONSTRUCTORES
		
		//Constructor por default
		Medico() : id(0), nombre(""), edad(0), tipo("") {}
		
		//Constructor con parametros
		Medico(long long id_, string name, int age, string tip) : id(id_), nombre(name), edad(age), tipo(tip) {}

		// GETTERS
		long long get_id() { return id; }
		string get_nombre() { return nombre; }
		int get_edad() { return edad; }
		string get_tipo() {return tipo; }

		// SETTERS
		void set_id(long long id_) { id = id_; }
		void set_nombre(string name) { nombre = name;}
		void set_edad(int age) { edad = age; }
		void set_tipo(string t) { tipo = t; }

		// METODOS
		virtual float monto_a_cobrar(float precio_base) = 0; //metodo abstracto que será sobreescrito
		virtual string toString() = 0;
};

//Declaro objeto Cardiologo que hereda de Medico
class Cardiologo : public Medico {
	
	//Variables de instancia del objeto
	private: 
		string universidad;
		float experiencia;

	//Metodos del objeto
	public:
	
		// CONSTRUCTORES
		
		//Constructor por default
		Cardiologo() : Medico(), universidad(""), experiencia(0) {}
		
		//Constructor con parametros
		Cardiologo(long long id_, string name, int age, string u, float e) 
			: Medico(id_, name, age, "Cardiologo"), universidad(u), experiencia(e) {}

		// GETTERS
		string get_uni() { return universidad; }
		float get_exp() { return experiencia; }

		// SETTERS
		void set_uni(string uni) { universidad = uni; }
		void set_exp(float exp) { experiencia = exp; }

		// METODOS
		float monto_a_cobrar(float precio_base);
		string toString();
};

/**
 * monto_a_cobrar devuelve el valor a cobrar por un medico Cardiologo
 *
 * Multiplica el precio_base por una constante, 3.5
 *
 * @param float precio_base
 * @return float monto a cobrar
 */
float Cardiologo::monto_a_cobrar(float precio_base) {
    return precio_base * 3.5;
}

/**
 * toString convierte a atributos a string.
 *
 * Concatena todos los valores de los atributos en un solo string
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Cardiologo::toString() {
    stringstream aux;
    aux << "Id es " << get_id() << " su nombre es " << get_nombre() << " su edad es " << get_edad()
        << ", estudio en " << get_uni() << " y tiene " << get_exp() << " años de experiencia"<< "\n";
    return aux.str();
}

//Declaro el objeto Pediatra que hereda de Medico
class Pediatra : public Medico {
	//Variables de instancia privadas del objeto
	private:
		int PacientesInfantiles;
	
	//Metodos públicos del objeto
	public: 
		
		// CONSTRUCTORES
		
		// Constructor por default
		Pediatra() : Medico(), PacientesInfantiles(0) {}
		
		// Constructor con parametros
		Pediatra(long long id_, string name, int age, int pi) : Medico(id_, name, age, "Pediatra"), PacientesInfantiles(pi) {}

		// GETTERS
		int get_pi() { return PacientesInfantiles; }

		// SETTERS
		void set_pi(int pi) { PacientesInfantiles = pi; }

		// METODOS
		float monto_a_cobrar(float precio_base);
		string toString();
};

/**
 * monto_a_cobrar devuelve el valor a cobrar por un medico Pediatra
 *
 * Multiplica el precio_base por una constante, 1.75
 *
 * @param float precio_base
 * @return float monto a cobrar
 */
float Pediatra::monto_a_cobrar(float precio_base) {
    return precio_base * 1.75;
}

/**
 * to_string convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Pediatra::toString() {
    stringstream aux;
    aux << "Id es " << get_id() << " su nombre es " << get_nombre() << " su edad es " << get_edad()
        << ". Ha tenido " << get_pi() << " Pacientes Infantiles" << "\n";
    return aux.str();
}

#endif // MEDICO_H
