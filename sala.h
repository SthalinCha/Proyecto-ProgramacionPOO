#ifndef SALA_H
#define SALA_H

#include <string>
using namespace std;

class Sala
{
private:
    char arr[5][5];   // Matriz para representar los asientos de la sala (5 filas x 5 columnas)
    int fnum;         // Número total de filas en la sala
    int fcol;         // Número total de columnas en la sala
    char fila;        // Fila seleccionada por el usuario
    int col;          // Columna seleccionada por el usuario

    bool crearSala(); // Función privada para crear la sala con asientos disponibles

public:
    Sala();          // Constructor de la clase

    bool asignarSala(char, int);  // Método para asignar una sala según la fila y columna seleccionadas
    void sala();                  // Método para mostrar la sala y los asientos disponibles
    int numAsientos();            // Método para obtener el número total de asientos en la sala
};

#endif // SALA_H
