#ifndef FACTURA_H
#define FACTURA_H

#include <bits/stdc++.h>

using namespace std;

class Factura {
    private:
        string fecha;
        float TotalPagar;

    public:
        Factura() : fecha("NoDate"), TotalPagar(0) {};
        Factura(string date, float tp) : fecha(date), TotalPagar(tp) {};

        // GETTERS
        string get_fecha() {
            return fecha;
        }
        float get_tp() {
            return TotalPagar;
        }

        // SETTERS
        void set_fecha(string date) {
            fecha = date;
        }
        void set_tp(float tp) {
            TotalPagar = tp;
        }

        // METODOS
        void hacerFactura() {
            cout << "Fecha de Facturación: " << get_fecha() << endl;
            cout << "Total a pagar: $" << get_tp() << endl;
        }

        void agregarMonto(float monto) {
            TotalPagar += monto;
        }
};
#endif // FACTURA_H
