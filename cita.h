#ifndef CITA_H
#define CITA_H

#include <bits/stdc++.h>
#include "medico.h"
#include "cardiologo.h"
#include "pediatra.h"
#include "factura.h"
#include "tratamiento.h"

using namespace std;

class Cita {
	private:
    int tipoDoctor;
    cardiologo* c; 
    pediatra* p;   
    string fecha;
    string hora;
    factura f; 
    vector<tratamiento> tratamientos; 
	public:
	// Constructors
	Cita() : tipoDoctor(0), fecha(""), hora("") {};
	Cita(int dt, const string& date, const string& hour) : tipoDoctor(dt), fecha(date), hora(hour) {};

	// Getters
	int get_td() const {
		return tipoDoctor;
	}
	string get_fecha() const {
		return fecha;
	}
	string get_hora() const {
		return hora;
	}

	// Setters 
	void set_dt(int dt) {
		tipoDoctor = dt;
	}
	void set_fecha(const string& date) {
		fecha = date;		
	}
	void set_hora(const string& hour) {
		hora = hour;
	}
	
	// Metodos
    void setCardiologo(cardiologo* card) {
        if (c != nullptr) {
            delete c;
        }
        c = card;
    }

    void setPediatra(pediatra* ped) {
        if (p != nullptr) {
            delete p;
        }
        p = ped;
    }

    // Metodos
    void addTratamiento(const tratamiento& trat) {
        tratamientos.push_back(trat);
    }
	
	void addMontoToFactura(float monto) {
        f.agregarMonto(monto);
    }

    void printFactura()  {
        f.hacerFactura();
    }
};

#endif // CITA_H

