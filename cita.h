#ifndef CITA_H
#define CITA_H

#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include "medico.h"
#include "factura.h"

using namespace std;

class Cita {
private:
    Medico* medicos[1000];
    int i_med;
    string fecha;
    string hora;
    Factura f; 

public:
    // Constructors
    Cita() : i_med(0), fecha(""), hora(""), f(Factura()) {} 
    Cita(string date, string hour) : i_med(0), fecha(date), hora(hour), f(Factura(date, 0)) {}

    // Getters
    string get_fecha() const {
        return fecha;
    }
    string get_hora() const {
        return hora;
    }

    // Setters
    void set_fecha(string date) {
        fecha = date;
    }
    void set_hora(string hour) {
        hora = hour;
    }

    // Metodos
    void muestra_medicos() const;
    void muestra_medicos(const string& tipo) const;
    void agrega_medico(Medico* medico);
    void calc_pago(float precio_base);
    void imprimir_factura() const;
    string toString() const;
};

void Cita::muestra_medicos() const {
    for (int i = 0; i < i_med; i++) {
        cout << medicos[i]->toString();
    }
}

void Cita::muestra_medicos(const string& tipo) const {
    for (int i = 0; i < i_med; i++) {
        if (medicos[i]->get_tipo() == tipo) {
            cout << medicos[i]->toString();
        }
    }
}

void Cita::agrega_medico(Medico* medico) {
    medicos[i_med] = medico;
    i_med++;
}

void Cita::calc_pago(float precio_base) {
    for (int i = 0; i < i_med; i++) {
        f.agregarMonto(medicos[i]->monto_a_cobrar(precio_base));
    }
}

void Cita::imprimir_factura() const {
    f.hacerFactura();
}

string Cita::toString() const {
    stringstream aux;
    aux << "La cita es el dia " << get_fecha() << " a las " << get_hora() << "\n";
    return aux.str();
}

#endif // CITA_H
