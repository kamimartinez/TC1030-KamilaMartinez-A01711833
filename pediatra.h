#ifndef PEDIATRA_H
#define PEDIATRA_H

#include <bits/stdc++.h>
#include "medico.h"

using namespace std;

class pediatra: public medico {
	public:
	int PacientesInfantiles;
	
	private: 
	pediatra():  medico(), PacientesInfantiles(0) {};
	pediatra(long long id_, string name, int age, int pi): medico(id_, name, age), PacientesInfantiles(pi) {};
	
	// GETTERS
	int get_pi() {
		return PacientesInfantiles;
	}
	
	//SETTERS
	void set_pi(int pi) {
		PacientesInfantiles=pi;
	}
	
	// METODOS
	void realizarExamenInfantil() {
		cout << "Examen Infantil realizado" << endl;
	}
	
	void realizarECG(){
        cout << "El pediatra realiza un ECG adaptado para niños." << std::endl;
    }
};
#endif
