#ifndef PACIENTE_H
#define PACIENTE_H

#include <bits/stdc++.h>
#include "medico.h"
#include "factura.h"
#include "cita.h"

using namespace std;

class Paciente {
    private:
        long long id;
        string nombre;
        int edad;
        string telefono;
        Cita citas[10000];
        int i_c;

    public:
        // Constructors
        Paciente() : id(0), nombre(""), edad(0), telefono(""), i_c(0) {}
        Paciente(long long id_, string name, int age, string tel) 
            : id(id_), nombre(name), edad(age), telefono(tel), i_c(0) {}

        // Getters
        long long getId() {
            return id;
        }
        string getNombre() {
            return nombre;
        }
        int getEdad(){
            return edad;
        }
        string getTelefono() {
            return telefono;
        }

        // Setters
        void setId(long long id_) {
            id = id_;
        }
        void setNombre(string name) {
            nombre = name;
        }
        void setEdad(int age) {
            edad = age;
        }
        void setTelefono(string tel) {
            telefono = tel;
        }

		void agendar_cita(Cita);
		void muestra_citas();
};

void Paciente::agendar_cita(Cita c) {
    citas[i_c] = c;
    i_c++;
}

void Paciente::muestra_citas() {
    for (int i = 0; i < i_c; i++) {
        cout << citas[i].toString(); 
    }
}

#endif // PACIENTE_H



