
#ifndef BOLETOS_H
#define BOLETOS_H

#include <iomanip>
#include "pelicula.h"  // Incluye el archivo de encabezado de la clase Pelicula
using namespace std;

class Boletos : public Pelicula
{
private:
    int sala;           // Número de sala donde se proyecta la película
    char fila;          // Fila del asiento seleccionado
    int columna;        // Columna del asiento seleccionado
    int boleto;         // Número de boleto asignado
    Pelicula pelicula;  // Objeto de la clase Pelicula para almacenar la información de la película
    int separacion = 40;

public:
    Boletos();  // Constructor por defecto
    Boletos(int sala, char fila, int columna, Pelicula);  // Constructor que recibe los valores de sala, fila, columna y un objeto Pelicula

    string mostrarPlano();  // Método para mostrar el plano de asientos de la sala
    char getFila() const;   // Método para obtener la fila del asiento seleccionado
    void setFila(char value);   // Método para asignar la fila del asiento seleccionado
    int getColumna() const;   // Método para obtener la columna del asiento seleccionado
    void setColumna(int value);   // Método para asignar la columna del asiento seleccionado
    int getSala() const;   // Método para obtener el número de sala
    void setSala(int value);   // Método para asignar el número de sala
};
#endif // BOLETOS_H
