

#ifndef CINE_H
#define CINE_H

#include "pelicula.h"
#include "boletos.h"
#include "sala.h"
#include "bar.h"
#include "factura.h"
#include <string>
#include <stdlib.h>

class Cine
{
private:
    const int CONTRASENIA = 12345;             // Contraseña para acceder al modo administrador
    int opc;                                  // Opción seleccionada por el usuario
    int boletos;                              // Cantidad de boletos a comprar
    static const int numeroPeliculas = 5;     // Número máximo de películas en cartelera
    const float PRECIO_BOLETO = 3.15;         // Precio por boleto
    static const int totalProductos = 10;     // Número total de productos en el bar
    Pelicula *cartelera[numeroPeliculas];     // Arreglo de punteros a objetos Pelicula para almacenar la cartelera
    Sala *sala[numeroPeliculas];              // Arreglo de punteros a objetos Sala para representar las salas del cine
    Bar *bar[totalProductos];                 // Arreglo de punteros a objetos Bar para almacenar los productos del bar
    Factura *fact;                            // Puntero a objeto Factura para representar la factura de compra

public:
    Cine();                                   // Constructor por defecto
    string mostrarCartelera();                // Método para mostrar la cartelera de películas
    string mostrarSala();                     // Método para mostrar la disponibilidad de asientos en una sala
    string comprarBoletos();                  // Método para comprar boletos
    string comprarComida();                   // Método para comprar comida en el bar
    bool filaColumna(char, int);              // Método para verificar si una fila y columna están disponibles
    string factura();                         // Método para generar y mostrar la factura de compra
    string imprimirDescripcion();             // Método para imprimir una descripción general del cine
    string Admin();                           // Método para acceder al modo administrador
    void modificarPelicula();                 // Método para modificar la información de una película en cartelera
};

#endif // CINE_H
