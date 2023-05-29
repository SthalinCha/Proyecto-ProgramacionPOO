#include "pelicula.h"

int Pelicula::getId() const
{
    return id;
}

string Pelicula::getHora() const
{
    return hora;
}

string Pelicula::getTitulo() const
{
    return titulo;
}
string Pelicula::getDuracion() const
{
    stringstream ss;
    ss << fixed << setprecision(2) << duracion;
    return ss.str();
}

string Pelicula::getDatos()
{
    return to_string(this->id) + " - ["
            + getHora() + "]\t"
            + getTitulo() +
            " (" + getDuracion() + ")\t "
            + toStringEstreno() + "\n";
}

void Pelicula::setComprado(bool value)
{
    comprado = value;
}

bool Pelicula::getComprado() const
{
    return comprado;
}

int Pelicula::getCantidad() const
{
    return cantidad;
}

void Pelicula::setCantidad(int value)
{
    cantidad = value;
}

void Pelicula::setEstreno(bool value)
{
    estreno = value;
}

void Pelicula::setDuracion(float value)
{
    duracion = value;
}

void Pelicula::setHora(const string &value)
{
    hora = value;
}

void Pelicula::setTitulo(const string &value)
{
    titulo = value;
}

Pelicula::Pelicula()
{
    this->comprado = false;
    this->id = totalPeliculas;
    this->titulo = "\0";
    this->duracion = 0;
    this->estreno = false;
    this->hora = "\0";
    totalPeliculas++;
}

Pelicula::Pelicula(string titulo, float duracion, bool estreno, string hora)
{

    this->id = totalPeliculas;
    this->titulo = titulo;
    this->duracion = duracion;
    this->estreno = estreno;
    this->hora = hora;
    this->comprado = false;
    totalPeliculas++;
}

string Pelicula::toStringEstreno()
{
    return this->estreno? "* ESTRENO *" : "";
}
