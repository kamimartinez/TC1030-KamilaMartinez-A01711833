#ifndef CARDIOLOGO_H
#define CARDIOLOGO_H

#include <bits/stdc++.h>
#include "medico.h"

using namespace std;

class cardiologo:public medico{
	private: 
	string universidad;
	string experiencia;
	
	public:
	//CONSTRUCTORES
	cardiologo(): medico(), universidad(""), experiencia("") {};
	cardiologo(long long id_, string name, int age, string u, string e): medico(id_, name, age), universidad(u), experiencia(e) {};
	
	// GETTERS
	string get_uni() {
		return universidad;
	}
	string get_exp(){
		return experiencia;
	}
	
	//SETTERS
	void set_uni(string uni){
		universidad=uni;
	}
	void set_exp(string exp){
		experiencia=exp;
	}
	
	//METODOS
	void realizarECG() {
		cout << "Examen ECG realizado" << endl;
	}
};



#endif
