#ifndef PELICULA_H
#define PELICULA_H

#include <string>    //  para trabajar con cadenas de texto
#include <sstream>   //  para realizar operaciones de entrada/salida en cadenas de texto
#include <iomanip>   //  para manipulación de formatos de salida

using namespace std;

class Pelicula
{
private:
    int id;                // Identificador de la película
    string titulo;         // Titulo de la pelicula
    float duracion;        // Duración de la película en horas
    bool estreno;          // Indicador de si la película es un estreno o no
    string hora;           // Hora de proyección de la película
    bool comprado;         // Indicador de si la película ha sido comprada o no
    int cantidad;          // Cantidad de boletos disponibles para la película
    static int totalPeliculas;  // Variable estática para contar el total de películas

public:
    // Constructores
    Pelicula();  // Constructor por defecto
    Pelicula(string titulo, float duracion, bool estreno, string hora);

    // Métodos de acceso a los atributos
    int getId() const;
    string getHora() const;
    string getTitulo() const;
    string getDuracion() const;
    string getDatos();
    string toStringEstreno();

    // Métodos de modificación de los atributos
    void setComprado(bool value);
    bool getComprado() const;
    int getCantidad() const;
    void setCantidad(int value);
    void setEstreno(bool value);
    void setDuracion(float value);
    void setHora(const string &value);
    void setTitulo(const string &value);
};

#endif // PELICULA_H
