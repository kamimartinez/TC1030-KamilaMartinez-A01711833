#include <bits/stdc++.h>
#include "medico.h"
#include "factura.h"
#include "cita.h"
#include "paciente.h"

using namespace std;

int main() {
    cout << "kehrbckire" << endl;
    Paciente kamila(123457, "Kamila Martinez", 18, "79035898");
    cout << kamila.getNombre() << endl;

    Cita c("Lunes 26 de Mayo", "2 pm");

    Medico* m = new Cardiologo(1, "Dr. Smith", 40, "Universidad XYZ", "10 años de experiencia");
    Medico* m2 = new Pediatra(2, "Dr. Williams", 55, 3);

    c.agrega_medico(m);

    float precio_base;
    cout << "Ingresa el precio base para el costo de los medicos para Cita 1: " << endl;
    cin >> precio_base;

    c.calc_pago(precio_base);

    c.imprimir_factura();

    kamila.agendar_cita(c);

    Cita c2("Martes 31 de Febrero", "5 pm");

    c2.agrega_medico(m2);

    cout << "Ingresa el precio base para el costo de los medicos para Cita 2: " << endl;
    cin >> precio_base;

    c2.calc_pago(precio_base);

    c2.imprimir_factura();

    kamila.agendar_cita(c2);

    kamila.muestra_citas();

    return 0;
}
