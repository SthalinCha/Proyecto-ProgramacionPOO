

#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

class Cliente
{
private:
    string nombre;      // Nombre del cliente
    string ci;          // Cédula de identidad del cliente
    string direccion;   // Dirección del cliente
    string telefono;    // Número de teléfono del cliente

public:
    Cliente();  // Constructor por defecto
    Cliente(string cedula, string nombre, string direccion, string telefono);  // Constructor que recibe la cédula, nombre, dirección y teléfono del cliente

    string getNombre() const;    // Método para obtener el nombre del cliente
    string getCi() const;        // Método para obtener la cédula del cliente
    string getDireccion() const; // Método para obtener la dirección del cliente
    void setDireccion(const string &value);  // Método para asignar la dirección del cliente
    string getTelefono() const;  // Método para obtener el número de teléfono del cliente
};

#endif // CLIENTE_H
