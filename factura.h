
#ifndef FACTURA_H
#define FACTURA_H

#include <vector>
#include "cliente.h"

class Factura : public Cliente
{
private:
    string nombreCine;      // Nombre del cine
    string ruc;             // RUC (Registro Único del Contribuyente) del cine
    int espaciado1 = 80;
    int espaciado2 = 80;

public:
    Factura();  // Constructor por defecto
    Factura(string cedula, string nombre, string direccion, string telefono);  // Constructor que recibe la cédula, nombre, dirección y teléfono del cliente

    string imprimirDatos();  // Método para imprimir los datos de la factura
};

#endif // FACTURA_H
