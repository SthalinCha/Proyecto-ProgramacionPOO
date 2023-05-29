#include <iostream>
#include "cine.h"
#include <vector>
int Pelicula::totalPeliculas = 1;
int Bar::totalProductos = 1;
using namespace std;
int main()
{

    int opc;
    cout << "\t\t- - SUPERCINES - -\n";
    Cine c1;
    do
    {
        cout << "+ + MENU PRINCIPAL + +"

                "\n1. Mostrar Cartelera"
                "\n2. Mostrar Sala"
                "\n3. Comprar Boletos"
                "\n4. Bar"
                "\n5. Factura"
                "\n6. Administrador"
                "\n7. Salir"
                "\nIngrese su opcion: ";
        if (!(cin >> opc))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nERROR: No reconozco esa opcion\n"
                    "Vuelva a intentarlo\n\n";
            continue;
        }
        switch (opc)
        {

        case 1:
            cout << c1.mostrarCartelera();
            break;
        case 2:
            cout << c1.mostrarSala();
            break;
        case 3:
            c1.comprarBoletos();
            break;
        case 4:
            cout << c1.comprarComida();
            break;
        case 5:
            cout << c1.factura();
            break;
        case 6:
            c1.Admin();
            break;
        case 7:
            cout << "\n--Gracias por utilizar el programa!--"
                    "\n\t==Hasta Pronto==\n";
            break;
        default:
            cout << "\nERROR: fuera de rango\n"
                    "Vuelva a intentarlo\n\n";
            break;
        }
    }while (opc != 7);
    return 0;
}
