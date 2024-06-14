/*
 *
 * Proyecto Integrador clase Paciente
 * Kamila Jeannette Martinez Ibarra
 * A01711833
 * 14/06/2024
 * version : 1
 * Esta clase define objeto de tipo Paciente que contiene todas las 
 * operaciones necesarias para poder adjuntar hasta 100' citas por paciente.
 */
#ifndef PACIENTE_H
#define PACIENTE_H

#include <bits/stdc++.h>
// Biblioteca con objetos a utilizar
#include "cita.h"

class Paciente {
	// Declaramos las variables privadas
private:
    long long id;
    string nombre;
    int edad;
    long long telefono;
    Cita citas[100]; // Arreglo de tamaño fijo para las citas
    int numCitas;
    int capacidad;

	// Declaramos los constructores y metodos a utilizar
public:
    // Constructores
    
    //Constructor por default
    Paciente() : id(0), nombre(""), edad(0), telefono(0), numCitas(0), capacidad(100) {}
    
    //Constructor con parametros
    Paciente(long long id_, string name, int age, long long tel) 
        : id(id_), nombre(name), edad(age), telefono(tel), numCitas(0), capacidad(100) {}

    // Getters
    long long getId() { return id; }
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    long long getTelefono() { return telefono; }

    // Setters
    void setId(long long id_) { id = id_; }
    void setNombre(std::string name) { nombre = name; }
    void setEdad(int age) { edad = age; }
    void setTelefono(long long tel) { telefono = tel; }

	// Metodos
    void agendar_cita(const Cita& c);
    void muestra_citas();
};

/**
 * agendar_cita añade objetos de clase Cita a citas[]
 *
 * Recibe un objeto de Clase Cita y lo agrega a nuestro arreglo citas[]
 * siempre y cuando no superemos nuestra capacidad del arreglo fijo.
 *
 * @param c Objeto de clase Cita que se agregará a la lista de citas.
 * @return
 */
void Paciente::agendar_cita(const Cita& c) {
    if (numCitas < capacidad) {
        citas[numCitas++] = c;
    } else {
        std::cerr << "No se pueden agendar más citas. Límite alcanzado." << std::endl;
    }
}


/**
 * muestra_citas imprime las citas del paciente
 *
 * Utiliza el arreglo citas[] y numCitas, para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos con su método toString().
 *
 * @param
 * @return
 */
void Paciente::muestra_citas(){
    for (int i = 0; i < numCitas; ++i) {
		cout <<"CITA " << i+1 << endl;
        cout << citas[i].toString() << std::endl;
    }
}

#endif // PACIENTE_H



