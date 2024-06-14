/*
 *
 * Proyecto Integrador clase Cita
 * Kamila Jeannette Martinez Ibarra
 * A01711833
 * 14/06/2024
 * version : 1
 * Esta clase define objeto de tipo Cita que contiene todos los atributos 
 * y operaciones necesarias para agregar los medicos necesarios y generar 
 * una factura. Las clases que utiliza son las de Medico(Polimorfismo), como 
 * agregación, y Factura, como composición. 
 */

#ifndef CITA_H
#define CITA_H

#include <bits/stdc++.h>
#include "medico.h" // Biblioteca con objetos a utilizar
#include "factura.h"

using namespace std;

class Cita {
	// Declaramos las variables privadas
	private:
		Medico* medicos[1000];
		int i_med;
		string fecha;
		string hora;
		Factura f; 
	
	// Declaramos los constructores y metodos a utilizar
	public:
		// Constructores
		
		//Constructor por default
		// Creamos nuestro objeto Factura dentro de los constructores
		Cita() : i_med(0), fecha(""), hora(""), f(Factura()) {} 
		
		//Constructor con parametros
		Cita(string date, string hour) : i_med(0), fecha(date), hora(hour), f(Factura(date, 0)) {}

		// Getters
		string get_fecha() { return fecha; }
		string get_hora() { return hora; }

		// Setters
		void set_fecha(string date) { fecha = date; }
		void set_hora(string hour) { hora = hour; }

		// Metodos
		void muestra_medicos();
		void muestra_medicos(const string& tipo);
		void agrega_medico(Medico* medico);
		void calc_pago(float precio_base);
		void imprimir_factura();
		string toString();
};

/**
 * muestra_medicos imprime los medicos en medicos[]
 *
 * Utiliza el arreglo medicos[] y i_med, para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos con su método toString().
 *
 * @param
 * @return
 */
void Cita::muestra_medicos() {
    for (int i = 0; i < i_med; i++) {
        cout << medicos[i]->toString();
    }
}

/**
 * muestra_medicos imprime los médicos en el arreglo medicos[] que coincidan 
 * con el tipo especificado.
 *
 * Recorre el arreglo medicos[] utilizando la variable i_med, e imprime 
 * aquellos médicos cuyo tipo coincida con el tipo proporcionado,
 * utilizando su método toString().
 *
 * @param tipo El tipo de médico que se desea mostrar.
 * @return
 */
void Cita::muestra_medicos(const string& tipo) {
    for (int i = 0; i < i_med; i++) {
        if (medicos[i]->get_tipo() == tipo) {
            cout << medicos[i]->toString();
        }
    }
}

/**
 * agrega_medico agrega un objeto hijo de la clase Medico
 *
 * Agrega el objeto proveido, sin importar si es Cardiologo o Pediatra
 * y lo agrega al arreglo medicos[]
 *
 * @param medico Puntero al objeto Medico que se agregará al arreglo.
 * @return 
 */
void Cita::agrega_medico(Medico* medico) {
    medicos[i_med] = medico;
    i_med++;
}

/**
 * calc_pago calcula el pago total acumulando el monto a cobrar de cada médico.
 *
 * Aplica la funcion de agregarMonto() a la factura f, calculando el monto
 * a cobrar de cada medico a partir de un precio base dado por el usuario
 *
 * @param precio_base El precio base utilizado para calcular el monto a cobrar de cada médico.
 * @return 
 */
void Cita::calc_pago(float precio_base) {
    for (int i = 0; i < i_med; i++) {
        f.agregarMonto(medicos[i]->monto_a_cobrar(precio_base));
    }
}

/**
 * imprimir_factura imprime la factura generada por la cita.
 *
 * Manda a llamar el metodo hacerFactura() del objeto factura f que imprime
 * la factura generada.
 *
 * @param 
 * @return 
 */

void Cita::imprimir_factura() {
    f.hacerFactura();
}

/**
 * toString convierte a atributos a string.
 *
 * Concatena todos los valores de los atributos en un solo string
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Cita::toString() {
    stringstream aux;
    aux << "La cita es el dia " << get_fecha() << " a las " << get_hora() << "\n";
    return aux.str();
}

#endif // CITA_H
