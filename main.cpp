/*
 * Proyecto Integrador clase Cita
 * Kamila Jeannette Martinez Ibarra
 * A01711833
 * 14/06/2024
 * version : 1
 * Este es un proyecto demo para la clase TC1030 Programación Orientado a
 * Objetos. Es un programa que pide los datos a un paciente, y le da la 
 * opcion de agendar N cantidad de citas, con un maximo de 100, y en cada
 * cita se asigan de 1 a M doctores y se produce una factura. 
 */

#include <bits/stdc++.h>
// Bibliotecas con objetos a utilizar
#include "medico.h"
#include "factura.h"
#include "cita.h"
#include "paciente.h"

using namespace std;

int main() {
	
	// Pedimos la informacion al usuario para registrarlo como Paciente
    long long id, telefono;
    string nombre, pn, ln;
    int edad;
	
	//Utilizar cin.ignore() nos facilita el uso de getline() y hace que el codigo corra
    cout << "Ingrese ID del paciente: ";
    cin >> id;
    cin.ignore(); // Limpia el buffer de entrada

    cout << "Ingrese nombre del paciente: ";
    getline(cin, pn);

    cout << "Ingrese apellido del paciente: ";
    getline(cin, ln);
    nombre = pn + " " + ln;

    cout << "Ingrese edad del paciente: ";
    cin >> edad;
    cin.ignore(); 

    cout << "Ingrese telefono del paciente: ";
    cin >> telefono;
    cin.ignore(); 

    Paciente p(id, nombre, edad, telefono);

	// Le preguntamos al Usuario cuantas citas desear ingresar
    int cant_citas, cant_medicos, opcion, precio_base;
    cout << "¿Cuantas citas quiere agendar para el/la paciente " << p.getNombre() << "?" << endl;
    cin >> cant_citas;
    cin.ignore(); 

    for (int i = 0; i < cant_citas; i++) {
        cant_medicos = 0;

        cout << endl;
        cout << "CITA " << i + 1 << endl;

        string fecha, hora;

        cout << "Ingrese fecha de la cita (dd/mm/aaaa): ";
        getline(cin, fecha);

        cout << "Ingrese hora de la cita (1-24): ";
        getline(cin, hora);
		
		// Creamos la Cita i
        Cita c(fecha, hora);
		
		// Preguntamos cuantos doctores ocupa para la cita y los agregamos
        cout << "¿Cuantos doctores quiere agendar para la cita?" << endl;
        cin >> cant_medicos;
        cin.ignore(); 

        for (int j = 0; j < cant_medicos; j++) {
            cout << endl;
            cout << "MEDICO " << j + 1 << endl;
            cout << "Tipo: Cardiologo(0), Pediatra(1)" << endl;
            cin >> opcion;
            cin.ignore(); 

            if (opcion == 0) {
                long long id;
                string nombre, universidad, pn, ln;
                int edad;
                float experiencia;

                cout << "Ingrese ID del medico: ";
                cin >> id;
                cin.ignore(); 

                cout << "Ingrese primer nombre del medico: ";
                getline(cin, pn);

                cout << "Ingrese apellido del medico: ";
                getline(cin, ln);

                nombre = pn + " " + ln;

                cout << "Ingrese edad del medico: ";
                cin >> edad;
                cin.ignore();

                cout << "Ingrese universidad del medico: ";
                getline(cin, universidad);

                cout << "Ingrese años de experiencia del medico: ";
                cin >> experiencia;
                cin.ignore();

                Medico* m = new Cardiologo(id, nombre, edad, universidad, experiencia);

                c.agrega_medico(m);
                cout << "Medico (Cardiólogo) agregado correctamente." << endl;
            } else if (opcion == 1) {
                long long id;
                string nombre, pn, ln;
                int edad, pacientes_infantiles;

                cout << "Ingrese ID del medico: ";
                cin >> id;
                cin.ignore(); 

                cout << "Ingrese primer nombre del medico: ";
                getline(cin, pn);

                cout << "Ingrese apellido del medico: ";
                getline(cin, ln);

                nombre = pn + " " + ln;

                cout << "Ingrese edad del medico: ";
                cin >> edad;
                cin.ignore(); 

                cout << "Ingrese cantidad de pacientes infantiles atendidos: ";
                cin >> pacientes_infantiles;
                cin.ignore(); 

                Medico* m = new Pediatra(id, nombre, edad, pacientes_infantiles);

                c.agrega_medico(m);
                cout << "Medico (Pediatra) agregado correctamente." << endl;
            } else {
				// Si no una opcion valida, volvemos a preguntar
                cout << "Opción no válida. Intente de nuevo." << endl;
                j--; // Repetir la iteración actual
                continue;
            }
        }
		
		//Para poder realizar la Factura pedimos precio_base
        cout << "Ingresa el precio base para el costo de los medicos para la cita " << i + 1 << ":"<< endl;
        cin >> precio_base;
        cin.ignore();
		
		// Imprimimos la factura
        c.calc_pago(precio_base);
        cout << endl;
        cout << "FACTURA CITA " << i+1 << endl;
        c.imprimir_factura();
		
		// Agendamos la cita para el usuario
        p.agendar_cita(c);
    }
	
	//Imprimimos las citas que tiene el usuario
    p.muestra_citas();

   
    return 0;
}

