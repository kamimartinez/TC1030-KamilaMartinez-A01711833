#ifndef CITA_H
#define CITA_H

#include <bits/stdc++.h>
#include "medico.h"
#include "factura.h"
#include "tratamiento.h"

using namespace std;

class Cita {
	private:
    medico * med[10000];
    int i_med;
    string fecha;
    string hora;
    factura f; 
    vector<tratamiento> tratamientos; 
	public:
	// Constructors
	Cita() :  fecha(""), hora(""), i_med(0) {};
	Cita(const string& date, const string& hour) : fecha(date), hora(hour), i_med(0) {};

	// Getters
	
	string get_fecha() const {
		return fecha;
	}
	string get_hora() const {
		return hora;
	}

	// Setters 
	
	void set_fecha(const string& date) {
		fecha = date;		
	}
	void set_hora(const string& hour) {
		hora = hour;
	}
	
	// Metodos
    void crea_doctores(int n) {
		int idD=100000;
		string name;
		for(int i=0;i<n;i++) {
			int x;
			cout << "¿Que tipo de doctor quieres agregar? Cardiologo(0) Pediatra(1)" << endl;
			cin >> x;
			i_med++;
			if(x==0) {
				cout << "Introduce el nombre" << endl;
				cin >> name;
				med[i_med] = new cardiologo(idD, name, 45, "Tecnologico de Monterrey", "basico");
				idD++;
			} else {
				cout << "Introduce el nombre" << endl;
				cin >> name;
				med[i_med] = new pediatra(idD, name, 45, 0);
				idD++;
			}
		}
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

