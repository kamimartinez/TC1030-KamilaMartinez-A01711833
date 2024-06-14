/*
 *
 * Proyecto Integrador clase Factura
 * Kamila Jeannette Martinez Ibarra
 * A01711833
 * 14/06/2024
 * version : 1
 * Esta clase define objeto de tipo Factura que contiene atributos y metodos
 * que colaboran a predecir e imprimir el monto a cobrar
 */

#ifndef FACTURA_H
#define FACTURA_H

#include <bits/stdc++.h>
#include <string>

using namespace std;

class Factura {
	//Declaramos las variables privadas de instancia
	private:
		string fecha;
		float TotalPagar;
	
	//Declaro constructor por default y metodos públicos.
	public:
	
		//CONSTRUCTORES
		
		// Constructor por default
		Factura() : fecha("NoDate"), TotalPagar(0) {}
		
		// Constructor con parametros
		Factura(string date, float tp) : fecha(date), TotalPagar(tp) {}

		// GETTERS
		string get_fecha() { return fecha; }
		float get_tp() { return TotalPagar; }

		// SETTERS
		void set_fecha(string date) { fecha = date; }
		void set_tp(float tp) { TotalPagar = tp; }

		// METODOS
		void hacerFactura();
		void agregarMonto(float);
};

/**
 * hacerFactura imprime la fecha y monto a cobrar
 *
 * Imprime la fecha y monto a cobrar
 *
 * @param 
 * @return
 */
void Factura::hacerFactura() {
        cout << "Fecha de Facturación: " << get_fecha() << endl;
        cout << "Total a pagar: $" << get_tp() << endl;
}

/**
 * agregarMonto agrega monto a TotalPagar
 *
 * Agrega el monto recibido en el parametro y lo agrega a la variable
 * TotalPagar
 *
 * @param float monto
 * @return
 */
void Factura::agregarMonto(float monto) {
        TotalPagar += monto;
}

#endif // FACTURA_H

