#ifndef CITA_H
#define CITA_H

#include <bits/stdc++.h>
#include "medico.h"
#include "factura.h"

using namespace std;

class Cita {
    private:
        Medico* medicos[10000];
        int i_med;
        string fecha;
        string hora;
        Factura f; 

    public:
        // Constructors
        Cita() : i_med(0), fecha(""), hora(""), f(Factura()) {}; 
        Cita( string date,  string hour) : i_med(0), fecha(date), hora(hour), f(Factura(date, 0)) {};

        // Getters
        string get_fecha() {
            return fecha;
        }
        string get_hora() {
            return hora;
        }

        // Setters
        void set_fecha( string date) {
            fecha = date;
        }
        void set_hora(string hour) {
            hora = hour;
        }

        // Metodos
        void muestra_medicos();
        void muestra_medicos(string);
        void agrega_medico(Medico* medico);
        void calc_pago(float);
        void imprimir_factura();
        string toString();
};

void Cita::muestra_medicos() {
    for (int i = 0; i < i_med; i++) {
        cout << medicos[i]->toString();
    }
}

void Cita::muestra_medicos(string tipo) {
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

void Cita::imprimir_factura() {
    f.hacerFactura();
}

string Cita::toString() {
    stringstream aux;
    aux << "La cita es el dia " << get_fecha() << " a las " << get_hora() << "\n";
    return aux.str();
}
#endif // CITA_H
