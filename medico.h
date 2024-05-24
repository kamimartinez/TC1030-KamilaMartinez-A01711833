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
};
#endif
