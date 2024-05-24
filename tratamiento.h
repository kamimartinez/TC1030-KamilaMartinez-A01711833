#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H

#include <bits/stdc++.h>

using namespace std;

class tratamiento{
	public:
	string medicamento;
	int duracion; // dias
	
	public: 
	tratamiento(): medicamento(""), duracion(0) {};
	tratamiento(string m, int d): medicamento(m), duracion(d) {};
	
	//GETTERS
	string get_med() {
		return medicamento;
	}
	int get_duracion() {
		return duracion;
	}
	
	//SETTERS
	void set_med(string med) {
		medicamento=med;
	}
	void set_duracion(int d) {
		duracion=d;
	}
	
	//METODOS
	void actTratamiento(int d) {
		duracion=d;
		cout << "La duracion del tratamiento ha sido actualizada" << endl;
	}
};
#endif
