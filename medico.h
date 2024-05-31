#ifndef MEDICO_H
#define MEDICO_H

#include <bits/stdc++.h>

using namespace std;

class medico{
	private:
	long long id;
	string nombre;
	int edad;
	
	public:
	//CONSTRUCTORES
	medico() {};
	medico(long long id_, string name, int age) : id(id_), nombre(name), edad(age) {};
	
	// GETTERS
	long long get_id() {
		return id;
	}
	string get_nombre(){
		return nombre;
	}
	int get_edad() {
		return edad;
	}
	
	//SETTERS
	void set_id(long long id_) {
		id=id_;
	}
	void set_nombre(string name) {
		nombre=name;
	}
	void set_edad(int age) {
		edad=age;
	}
	
	//METODOS
	
	virtual void RevisarExamSangre() {
		cout << "Examen de Sangre revisado por Medico" << endl;
	}
};


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
	
	void RevisarExamSangre() {
		cout << "Examen de Sangre revisado por Cardiologo" << endl;
	}
};

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
    
    void RevisarExamSangre() {
		cout << "Examen de Sangre revisado por Pediatra" << endl;
	}
};
#endif
