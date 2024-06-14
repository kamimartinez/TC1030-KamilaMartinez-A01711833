#ifndef MEDICO_H
#define MEDICO_H

#include <bits/stdc++.h>
#include <string>
#include <sstream>

using namespace std;

class Medico {
private:
    long long id;
    string nombre;
    int edad;
    string tipo;

public:
    // CONSTRUCTORES
    Medico() : id(0), nombre(""), edad(0), tipo("") {}
    Medico(long long id_, string name, int age, string tip) : id(id_), nombre(name), edad(age), tipo(tip) {}

    // GETTERS
    long long get_id() const {
        return id;
    }
    string get_nombre() const {
        return nombre;
    }
    int get_edad() const {
        return edad;
    }
    string get_tipo() const {
        return tipo;
    }

    // SETTERS
    void set_id(long long id_) {
        id = id_;
    }
    void set_nombre(string name) {
        nombre = name;
    }
    void set_edad(int age) {
        edad = age;
    }
    void set_tipo(string t) {
        tipo = t;
    }

    // METODOS
    virtual float monto_a_cobrar(float precio_base) const = 0;
    virtual string toString() const = 0;
};

class Cardiologo : public Medico {
private: 
    string universidad;
    string experiencia;

public:
    // CONSTRUCTORES
    Cardiologo() : Medico(), universidad(""), experiencia("") {}
    Cardiologo(long long id_, string name, int age, string u, string e) 
        : Medico(id_, name, age, "Cardiologo"), universidad(u), experiencia(e) {}

    // GETTERS
    string get_uni() const {
        return universidad;
    }
    string get_exp() const {
        return experiencia;
    }

    // SETTERS
    void set_uni(string uni) {
        universidad = uni;
    }
    void set_exp(string exp) {
        experiencia = exp;
    }

    // METODOS
    float monto_a_cobrar(float precio_base) const;
    string toString() const;
};

float Cardiologo::monto_a_cobrar(float precio_base) const {
    return precio_base * 3.5;
}

string Cardiologo::toString() const {
    stringstream aux;
    aux << "Id es " << get_id() << " su nombre es " << get_nombre() << " su edad es " << get_edad()
        << ", estudio en " << get_uni() << " y tiene un nivel de experiencia de " << get_exp() << "\n";
    return aux.str();
}

class Pediatra : public Medico {
private:
    int PacientesInfantiles;

public: 
    Pediatra() : Medico(), PacientesInfantiles(0) {}
    Pediatra(long long id_, string name, int age, int pi) : Medico(id_, name, age, "Pediatra"), PacientesInfantiles(pi) {}

    // GETTERS
    int get_pi() const {
        return PacientesInfantiles;
    }

    // SETTERS
    void set_pi(int pi) {
        PacientesInfantiles = pi;
    }

    // METODOS
    float monto_a_cobrar(float precio_base) const;
    string toString() const;
};

float Pediatra::monto_a_cobrar(float precio_base) const {
    return precio_base * 1.75;
}

string Pediatra::toString() const {
    stringstream aux;
    aux << "Id es " << get_id() << " su nombre es " << get_nombre() << " su edad es " << get_edad()
        << ". Ha tenido " << get_pi() << " Pacientes Infantiles" << "\n";
    return aux.str();
}

#endif // MEDICO_H
