#include <bits/stdc++.h>
#include "medico.h"
#include "cardiologo.h"
#include "pediatra.h"
#include "factura.h"
#include "tratamiento.h"
#include "cita.h"
#include "paciente.h"

using namespace std;

int main() {
	Paciente kamila(123457, "Kamila Martinez", 18, "79035898");
	cout << kamila.getNombre() << endl;
	
    // Crear un objeto de Cardiologo
    cardiologo* card = new cardiologo(1, "Dr. Smith", 40, "Universidad XYZ", "10 años de experiencia");

    // Crear un objeto de Pediatra
    pediatra* ped = new pediatra(2, "Dr. Johnson", 35, 50);

    // Crear un objeto de Cita
    Cita cita(1, "2024-05-23", "10:00");
    cita.setCardiologo(card);
    cita.setPediatra(ped);

    // Crear un objeto de Factura
    factura f("2024-05-23", 100.0);
    cita.setFactura(f);

    // Agregar un tratamiento a la cita
    tratamiento t("Medicina A", 30);
    cita.addTratamiento(t);

    // Agregar monto a la factura
    cita.agregarMonto(50.0);

    // Imprimir información de la cita y factura
    cout << "Información de la cita:" << endl;
    cout << "Doctor Type: " << cita.get_tp() << endl;
    cout << "Fecha: " << cita.get_fecha() << endl;
    cout << "Hora: " << cita.get_hora() << endl;
    cout << "Factura:" << endl;
    cita.hacerFactura();

    
    return 0;
}
