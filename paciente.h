#ifndef PACIENTE_H
#define PACIENTE_H

#include <bits/stdc++.h>
#include "cita.h"

class Paciente {
private:
    long long id;
    string nombre;
    int edad;
    string telefono;
    Cita* citas;
    int numCitas;
    int capacidad;

public:
    // Constructors
    Paciente() : id(0), nombre(""), edad(0), telefono(""), citas(nullptr), numCitas(0), capacidad(0) {}
    Paciente(long long id_, std::string name, int age, std::string tel) 
        : id(id_), nombre(name), edad(age), telefono(tel), citas(nullptr), numCitas(0), capacidad(0) {}

    
    // Getters
    long long getId() const { return id; }
    std::string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    std::string getTelefono() const { return telefono; }

    // Setters
    void setId(long long id_) { id = id_; }
    void setNombre(std::string name) { nombre = name; }
    void setEdad(int age) { edad = age; }
    void setTelefono(std::string tel) { telefono = tel; }

    void agendar_cita(const Cita& c);
    void muestra_citas() const;
};

void Paciente::agendar_cita(const Cita& c) {
    if (numCitas == capacidad) {
        // Si el arreglo está lleno, duplica su capacidad
        capacidad = (capacidad == 0) ? 1 : capacidad * 2;
        Cita* nuevoArreglo = new Cita[capacidad];
        for (int i = 0; i < numCitas; ++i) {
            nuevoArreglo[i] = citas[i];
        }
        delete[] citas;
        citas = nuevoArreglo;
    }
    citas[numCitas++] = c;
}

void Paciente::muestra_citas() const {
    for (int i = 0; i < numCitas; ++i) {
        std::cout << citas[i].toString() << std::endl;
    }
}

#endif // PACIENTE_H




