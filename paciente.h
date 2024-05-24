#ifndef PACIENTE_H
#define PACIENTE_H

#include <bits/stdc++.h>
#include "medico.h"
#include "cardiologo.h"
#include "pediatra.h"
#include "factura.h"
#include "tratamiento.h"
#include "cita.h"

using namespace std;

class Paciente {
	private:
    long long id;
    string nombre;
    int edad;
    string telefono;
    vector<Cita> citas;
    
	public:
    // Constructors
    Paciente() : id(0), nombre(""), edad(0), telefono("") {}
    Paciente(long long id_, const string& name, int age, const string& tel) 
        : id(id_), nombre(name), edad(age), telefono(tel) {}

    // Getters
    long long getId() const {
        return id;
    }
    string getNombre() const {
        return nombre;
    }
    int getEdad() const {
        return edad;
    }
    string getTelefono() const {
        return telefono;
    }
    vector<Cita>& getCitas() {
        return citas;
    }

    // Setters
    void setId(long long id_) {
        id = id_;
    }
    void setNombre(const string& name) {
        nombre = name;
    }
    void setEdad(int age) {
        edad = age;
    }
    void setTelefono(const string& tel) {
        telefono = tel;
    }

    // Methods to manage citas
    void addCita(const Cita& cita) {
        citas.push_back(cita);
    }


};

#endif // PACIENTE_H

