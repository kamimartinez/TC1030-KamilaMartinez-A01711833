#ifndef FACTURA_H
#define FACTURA_H

#include <bits/stdc++.h> 

using namespace std;

class factura{
	private:
	string fecha;
	float TotalPagar;
	
	public:
	factura(): fecha("NoDate"), TotalPagar(0) {};
	factura(string date, float tp): fecha(date), TotalPagar(tp) {};
	
	//GETTERS
	string get_fecha() {
		return fecha;
	}
	float get_tp() {
		return TotalPagar;
	}
	
	//SETTERS
	void set_fecha(string date) {
		fecha=date;
	}
	void set_tp(float tp) {
		TotalPagar=tp;
	}
	
	//METODOS
	void hacerFactura() {
		cout << "Fecha de Facturación: " << get_fecha() << endl;
		cout << "Total a pagar: $" << get_tp() << endl;
	}
	
	void agregarMonto(float monto) {
		TotalPagar+=monto;
	}
};
#endif
