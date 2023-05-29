
#ifndef BAR_H
#define BAR_H

#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Bar
{
private:
    int id;             // Identificador del producto del bar
    string nombre;      // Nombre del producto
    float precio;       // Precio del producto
    bool comprado;      // Indicador de si el producto ha sido comprado o no
    int cantidad;       // Cantidad disponible del producto
public:
    Bar();                       // Constructor por defecto
    Bar(string nombre, float precio);   // Constructor que recibe nombre y precio del producto
    static int totalProductos;   // Variable estática para contar el total de productos del bar

    string getDatos();           // Método para obtener los datos del producto
    float comprar();             // Método para realizar una compra del producto
    bool getComprado() const;    // Método para obtener el estado de compra del producto
    string getNombre() const;    // Método para obtener el nombre del producto
    float getPrecio() const;     // Método para obtener el precio del producto
    int getCantidad() const;     // Método para obtener la cantidad disponible del producto
    float totalProducto();       // Método para calcular el valor total del producto
    void setCantidad(int value); // Método para asignar la cantidad disponible del producto
    void setComprado(bool value);// Método para asignar el estado de compra del producto
};

#endif // BAR_H
