#include "factura.h"
#include <time.h>
#include <string>
Factura::Factura()
{

    this->ruc = "9999999";
    this->nombreCine = "- - SUPERCINE - -";
    espaciado1 -= Cliente::getNombre().length();
    espaciado2 -= Cliente::getDireccion().length();
}

Factura::Factura(string cedula, string nombre, string direccion, string telefono) : Cliente(cedula, nombre, direccion, telefono)
{
    this->ruc = "9999999";
    this->nombreCine = "- - SUPERCINE - -";
    espaciado1 -= Cliente::getNombre().length();
    espaciado2 -= Cliente::getDireccion().length();
}

string Factura::imprimirDatos()
{
    string str;

    // Cabecera
    str = "\n-   -   -   -   -   -   - FACTURA -   -   -   -   -   -   -\n";
    str += string(78, '-') + "\n";

    // Datos del cine
    str += "\t\t\t" + nombreCine + string(37, ' ') + "\n";
    str += string("RUC ") + ruc + string(63, ' ') + "\n";
    str += string("Dir: AV GEENRAL RUMINAHUI s/n") + string(44, ' ') + "\n";
    str += string("Telf: 0999999999") + string(63, ' ') + "\n";
    str += string("OBLIGADO A LLEVAR CONTABILIDAD: Si") + string(45, ' ') + "\n";

    str += string(78, '-') + "\n";

    // Datos del cliente
    str += string("Nombre: ") + Cliente::getNombre() + string(espaciado1, ' ') + "\n";
    string ciRucLabel = (Cliente::getCi().length() == 10) ? "CI: " : "RUC: ";
    int saltos = (Cliente::getCi().length() == 10) ? 61 : 58;
    str += ciRucLabel + Cliente::getCi() + string(saltos - ciRucLabel.length(), ' ') + "\n";
    str += string("Dir: ") + Cliente::getDireccion() + string(espaciado2, ' ') + "\n";
    str += string("Telf: ") + Cliente::getTelefono() + string(63, ' ') + "\n";

    str += string(78, '-') + "\n";

    // Resumen de la compra
    str += string(" Cantidad ") + "\t\tDescripcion\t\t\t" + string(" Precio U. ") + string(" Precio T. ") + "\n";
    str += string(78, '-') + "\n";

    return str;
}
