#include "bar.h"

bool Bar::getComprado() const
{
    return comprado;
}

string Bar::getNombre() const
{
    return nombre;
}

float Bar::getPrecio() const
{
    return precio;
}

int Bar::getCantidad() const
{
    return cantidad;
}

float Bar::totalProducto()
{
    return cantidad * precio;
}

void Bar::setCantidad(int value)
{
    cantidad = value;
}

void Bar::setComprado(bool value)
{
    comprado = value;
}

Bar::Bar()
{
    this->id = totalProductos;
    this->nombre = " ";
    this->precio = 0.0;
    this->comprado = false;
    this->cantidad = 0;
}

Bar::Bar(string nombre, float precio)
{
    this->id = totalProductos;
    this->nombre = nombre;
    this->precio = precio;
    totalProductos++;
    this->comprado = false;
    this->cantidad = 0;
}

string Bar::getDatos()
{
    ostringstream out;
    out << "[" << this->id << "] " << this->nombre << "  $"
        << fixed << setprecision(2) << this->precio;
    return out.str();
}

float Bar::comprar()
{
    this->comprado = true;
    this->cantidad++;
    return precio;
}
