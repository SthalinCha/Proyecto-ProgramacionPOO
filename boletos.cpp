#include "boletos.h"
Boletos::Boletos()
{
    this->boleto = 0;
    this->sala = 0;
    this->fila = ' ';
    this->columna = 0;
}

Boletos::Boletos(int sala, char fila, int columna, Pelicula pelicula)
{
    this->sala = sala;
    this->fila = toupper(fila);
    this->columna = columna;
    this->pelicula = pelicula;

}

string Boletos::mostrarPlano()
{
    string str;
    string lineaSuperior(50, '-');
    string lineaInferior(50, '-');
    string espacio1(43, ' ');
    string espacio2(39, ' ');
    string espacio3(39, ' ');
    string espacio4(5, ' ');

    str += "+" + lineaSuperior + "+\n";
    str += "|Sala: " + to_string(sala) + ""+espacio1 + "|\n";
    str += "|Hora: " + pelicula.getHora() + espacio2 + "|\n";
    str += "|Asiento: " + string(1, fila) +  to_string(columna) + espacio3 + "|\n";
    str += "|Pelicula: " + pelicula.getTitulo() + espacio4 + "|\n";
    str += "+" + lineaInferior + "+\n";

    return str;
}
int Boletos::getSala() const{
    return sala;
}
void Boletos::setSala(int value){
    sala = value;
}
char Boletos::getFila() const{
    return fila;
}
void Boletos::setFila(char value){
    fila = value;
}
int Boletos::getColumna() const{
    return columna;
}
void Boletos::setColumna(int value){
    columna = value;
}
