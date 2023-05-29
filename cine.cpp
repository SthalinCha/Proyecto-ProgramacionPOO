#include "cine.h"
#include <iostream>

Cine::Cine()
{
    //Quemado de pleiculas, salas y el bar
    cartelera[0] = new Pelicula("Guardianes de la Galaxia: Volumen 3", 154, true, "10:00");
    cartelera[1] = new Pelicula("Super Mario Bros. La pelicula      ", 92, true, "12:15");
    cartelera[2] = new Pelicula("Posesion Infernal: El despertar    ", 97, false, "15:00");
    cartelera[3] = new Pelicula("Jeepers Creepers: El renacer       ", 88, false, "19:00");
    cartelera[4] = new Pelicula("El Nino detras de la Puerta        ", 88, false, "21:45");

    for(int i = 0; i < numeroPeliculas; i++)
        sala[i] = new Sala;
    bar[0] = new Bar("Coca-Cola", 3.5);
    bar[1] = new Bar("Sprite", 3.15);
    bar[2] = new Bar("Agua Mineral", 1.99);
    bar[3] = new Bar("M&M's", 2.75);
    bar[4] = new Bar("KitKat", 2.75);
    bar[5] = new Bar("Reese's", 2.75);
    bar[6] = new Bar("Palomitas de Maiz Grandes", 3.5);
    bar[7] = new Bar("Palomitas de Maiz Medianas", 2.99);
    bar[8] = new Bar("Hot Dogs", 4.25);
    bar[9] = new Bar("Pretzels", 4.25);


}

string Cine::mostrarCartelera()
{
    //Imprimir la cartelera
    string str;
    str = "\n\t*** C A R T E L E R A ***\n";
    for(int i = 0; i < numeroPeliculas; i++)
    {
        str += cartelera[i]->getDatos();
    }
    str += "\n";
    return str;
}

string Cine::mostrarSala()
{
    int id;
    cout << "\nIngrese el id de la pelicula: ";
    while (!(cin >> id))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nERROR. Sola hay 5 salas 1,2,3,4,5: ";
    }
    while(id <= 0 || id > numeroPeliculas)
    {
        cout << "ERROR: Actualmente solo se proyectan  " << numeroPeliculas;
        cout << "\nVuelva a intentarlo: ";
        cin >> id;
    }
    cout << cartelera[id-1]->getDatos();
    cout << "*** A S I E N T O S ***\n";
    sala[id-1]->sala();
    return "\0";
}


string Cine::comprarBoletos()
{
    int id, columna;
    char fila;
    cout << "\nIngrese el id de la pelicula: ";
    while (!(cin >> id))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nError. Vuelve a ingresar: ";
    }
    while(id <= 0 || id > numeroPeliculas)
    {
        cout << "\nERROR: Solo disponemos de " << numeroPeliculas;
        cout << "\nVuelva a intentarlo: ";
        while (!(cin >> id))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nError. Vuelve a ingresar: ";
        }
    }

    cout << "\nIngrese el numero de boletos: ";

    while (!(cin >> boletos))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nError. Vuelve a ingresar: ";
    }

    while(boletos < 0)
    {
        cout << "\nERROR: El numero de boletos minimo es 1"
                "\nVuelva a intentarlo: ";
        cin >> boletos;
    }

    if(boletos == 0)
    {
        cout << "\n** No se ha realizado una compra** !" << "\n";
        return "\0";
    }

    while(boletos>sala[id-1]->numAsientos()){
        cout << "\nERROR: Numero de asientos excedido";
        cout << "\nVuelva a ingresar: ";
        while (!(cin >> boletos))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nError. Vuelve a ingresar: ";
        }
    }
    Boletos *boleto[boletos];
    cartelera[id-1]->setCantidad(boletos);
    cartelera[id-1]->setComprado(true);
    cout << "\nSeleccione los asientos" << "\n";

    sala[id-1]->sala();

    for (int i = 0 ; i < boletos; i++){
        cout << "\nBoleto # " << i + 1 << "\n";
        cout << "Ingrese el asiento:";
        while (!(cin >> fila>>columna))
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Vuelva a ingresar: ";
        }
        while(filaColumna(fila,columna)==false){
            cin.ignore(100, '\n');
            cout << "ERROR. Asiento no existente"
                    "\nVuelva a ingresar el asiento: ";
            while (!(cin >> fila>>columna))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Vuelva a ingresar: ";
            }
        }

        while (sala[id-1]->asignarSala(fila, columna)==false) {
            cout << "Ingrese el asiento: ";
            cin >> fila >> columna;
        }
        boleto[i] = new Boletos(id, fila, columna, *cartelera[id-1]);
    }

    cout << "\nRESUMEN DE SU COMPRA\n";
    for (int i = 0; i < boletos; i++)
    {
        cout << "\nBoleto #" << i + 1 << "\n";
        cout << boleto[i]->mostrarPlano();
    }
    float total = PRECIO_BOLETO * boletos;
    cout << "Total: $" << fixed << setprecision(2) << total << "\n\n";
    return "";
}

string Cine::comprarComida()
{
    int opc;
    float total = 0;
    cout << "\n\t- - B A R - -\n";
    for (int i = 0; i < totalProductos; i++)
    {
        cout << bar[i]->getDatos() << endl;
    }
    cout<<"Para finalizar su compra digite 0"<<"\n";

    do
    {

        cout << "Digite el ID del producto: ";

        while (!(cin >> opc))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error. Vuelve a ingresar el id: ";
        }
        if(opc >= 0 && opc <= totalProductos)
            total += bar[opc-1]->comprar();
        else
            cout << "ERROR: Producto inexistente"
                    "\nVuelva a intentarlo\n";
    }while (opc != 0);
    cout << "\n\t- - RESUMEN DE LA COMPRA - -\n";
    for(int i = 0; i < totalProductos; i++)
    {
        if(bar[i]->getComprado() == true)
        {
            cout << bar[i]->getNombre();
            if(bar[i]->getNombre().size() < 8)
                cout << "\t\t | $" << fixed << setprecision(2) << bar[i]->getPrecio()
                     << " *" << bar[i]->getCantidad()
                     << " | $" << fixed << setprecision(2) << bar[i]->totalProducto() << endl;
            else
                cout << "\t | $" << fixed << setprecision(2) << bar[i]->getPrecio()
                     << " *" << bar[i]->getCantidad()
                     << " | $" << fixed << setprecision(2) << bar[i]->totalProducto() << endl;
        }
    }
    cout << "\t- - - - - - - - - \n" <<
            "Su total es de:  $" << fixed << setprecision(2) << total << endl;
    return "\n";
}
bool Cine::filaColumna(char fila, int columna)
{
    bool val;
    if(fila=='A' || fila=='a'|| fila=='B'|| fila=='b'|| fila=='C'|| fila=='c'|| fila=='D'|| fila=='d'|| fila=='E'|| fila=='e'){
        val=true;
    }else{
        return false;
    }
    if(columna>0 && columna<6){
        val=true;
    }else{
        return false;
    }
    return val;
}

string Cine::factura()
{
    cout << "Forma de pago?"
            "\n1. Efectivo"
            "\n2. Tarjeta";
    cout <<"\nOpcion: ";
    cin >> opc;
    string respuesta;
    if(opc == 1)
    {
        cout << "Desea con datos o consumidor final? \n";
        cin >> respuesta;
    }
    if(respuesta[0] == 'D' || respuesta[0] == 'd' || opc == 2)
    {
        //Si desea con datos, se pedira los datos del cliente
        string nombre , apellido, cedula, num, dir;
        cout << "Cual es su nombre?\n";
        cin >> nombre >> apellido;
        // mayusculas

        nombre[0] = toupper(nombre[0]);
        apellido[0] = toupper(apellido[0]);

        nombre = nombre + " " + apellido;
        cout << "Cual es su Cedula: ";
        cin >> cedula;

        cin.ignore();
        cout << "Cual es su direccion: ";
        getline(cin, dir);
        cout << "Cual es su numero: ";
        //Se limpia el cin para poder recibir el numero
        cin.clear();
        cin >> num;
        while(num.length() != 10)
        {
            cout << "ERROR: El numero celular tiene 10 digitos"
                    "\nVuelva a ingresar el numero: ";
            cin >> num;
        }
        //Se crea una factura con datos del cliente
        Factura fact(cedula, nombre, dir, num);
        //Se imprime los datos de la factura
        cout << fact.imprimirDatos();
        //Se imprime la descripcion de lo que ha comprado
        cout << Cine::imprimirDescripcion();
    }
    else
    {
        //Se crea una factura como consumidor final
        Factura fact;
        //Se imrpime los datos de la factura
        cout << fact.imprimirDatos();
        //Se imprime la descripcion de lo que ha comprado
        cout << Cine::imprimirDescripcion();
    }
    return "\n";
}

string Cine::imprimirDescripcion()
{
    stringstream ss;
    int espaciado;
    float subTotal = 0;
    char a = -38, b = -60, c = -65, d = -77, h = -64, i = -39;

    for(int i = 0; i < numeroPeliculas; i++)
    {
        if(cartelera[i]->getComprado())
        {
            subTotal += PRECIO_BOLETO * cartelera[i]->getCantidad();
            ss << "  " << cartelera[i]->getCantidad();
            ss << "\t" << cartelera[i]->getTitulo();
            espaciado = 50 - cartelera[i]->getTitulo().length();
            for (int i = 0; i < espaciado; i++)
                ss << " ";
            ss << "$" << fixed << setprecision(2) << PRECIO_BOLETO;
            ss << "       $" << fixed << setprecision(2) << PRECIO_BOLETO * cartelera[i]->getCantidad() << "\n";
        }
    }

    for(int i = 0; i < totalProductos; i++)
    {
        if(bar[i]->getComprado())
        {
            subTotal += bar[i]->totalProducto();
            ss << "  " << bar[i]->getCantidad();
            ss << "\t" << bar[i]->getNombre();
            espaciado = 50 - bar[i]->getNombre().length();
            for (int i = 0; i < espaciado; i++)
                ss << " ";
            ss << "$" << fixed << setprecision(2) << bar[i]->getPrecio();
            ss << "       $" << fixed << setprecision(2) << bar[i]->totalProducto() << "\n";
        }
    }

    if(opc == 1)
    {
        float IVA = subTotal - (subTotal / 1.12);
        ss << a;
        for (int i = 0; i <= 78; i++)
            ss << b;
        ss << c;
        ss << "\n" << d << "Subtotal: $" << fixed << setprecision(2) << subTotal - IVA;
        espaciado = 72 - to_string(subTotal).length();
        for (int i = 0; i < espaciado; i++)
            ss << " ";
        ss << d;

        ss << "\n" << d << "IVA: $" << fixed << setprecision(2) << IVA;
        espaciado = 77 - to_string(IVA).length();
        for (int i = 0; i < espaciado; i++)
            ss << " ";
        ss << d;

        ss << "\n" << d << "Total: $" << fixed << setprecision(2) << subTotal;
        espaciado = 75 - to_string(subTotal).length();
        for (int i = 0; i < espaciado; i++)
            ss << " ";
        ss << d;
    }

    if(opc == 2)
    {
        float val, nSubtotal;
        val = subTotal * 0.03;
        nSubtotal = subTotal + val;
        float IVA = nSubtotal - (nSubtotal / 1.12);
        ss << a;
        for (int i = 0; i <= 78; i++)
            ss << b;
        ss << c;
        ss << "\n" << d << "Se incrementa un 3% por usar tarjeta";
        for (int i = 0; i < 43; i++)
            ss << " ";
        ss << d;
        ss << "\n" << d << "Subtotal: $" << fixed << setprecision(2) << nSubtotal - IVA;
        espaciado = 72 - to_string(nSubtotal).length();
        for (int i = 0; i < espaciado; i++)
            ss << " ";
        ss << d;

        ss << "\n" << d << "IVA: $" << fixed << setprecision(2) << IVA;
        espaciado = 77 - to_string(IVA).length();
        for (int i = 0; i < espaciado; i++)
            ss << " ";
        ss << d;

        ss << "\n" << d << "Total: $" << fixed << setprecision(2) << nSubtotal;
        espaciado = 75 - to_string(nSubtotal).length();
        for (int i = 0; i < espaciado; i++)
            ss << " ";
        ss << d;
    }

    ss << "\n" << h;
    for (int i = 0; i <= 78; i++)
        ss << b;
    ss << i << "\n";

    for(int i = 0; i < numeroPeliculas; i ++)
    {
        cartelera[i]->setCantidad(0);
        cartelera[i]->setComprado(false);
    }

    for (int i = 0; i < totalProductos; i++)
    {
        bar[i]->setCantidad(0);
        bar[i]->setComprado(false);
    }

    return ss.str();
}


string Cine::Admin()
{

    int opc;
    int contrasenia;
    cout << "\nIngrese la contrasenia: ";
    while (!(cin >> contrasenia))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nERROR. Ingrese  solo numeros!"
                "\nIngrese de nuevo: ";
    }
    while(contrasenia != CONTRASENIA){
        cout << "\nContrasenia invalida, intente de nuevo!" << endl;
        cin >> contrasenia;
    }
    if (contrasenia == CONTRASENIA){
        cout << " BIENVENIDO!! " << endl;
        do
        {
            cout << "\n+ + MENU DE ADMINISTRADOR + +"
                    "\n1. Modificar pelicula"
                    "\n2. Salir"
                    "\nIngrese su opcion: ";
            cin >> opc;
            switch (opc)
            {
            case 1:
                modificarPelicula();
                break;
            case 2:
                cout << "\n\t==Hasta Pronto==\n";
                break;
            default:
                cout << "\nERROR: No reconozco esa opcion\n"
                        "Vuelva a intentarlo\n\n";
                break;
            }
        }while (opc != 2);
    }
    return "\0";
}

void Cine::modificarPelicula()
{
    string nombre, hora, dato;
    char estreno;
    int id;
    float duracion;
    int opA;
    cout << "Ingrese el ID de la pelicula entre [1 y " << numeroPeliculas << "] que desea modificar: ";
    while (!(cin >> id))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nError. Vuelve a ingresar: ";
    }
    while(id <= 0 || id > numeroPeliculas)
    {
        cout << "\nERROR: La id debe ser entre 1 y " << numeroPeliculas;
        cout << "\nVuelva a intentarlo: ";
        while (!(cin >> id))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nError. Vuelve a ingresar: ";
        }
    }


    cout << "\nQue desea modificar? ";
    cout << "\n 1. Nombre "
            "\n 2. Hora"
            "\n 3. Duracion "
            "\n 4. Estreno? "
            "\n 5. Todo ";

    cin >> opA;

        switch (opA)

        {
            case 1:
                    cout << "\nIngrese el nuevo nombre de la pelicula: ";
                    cin>>nombre;
                    cartelera[id-1]->setTitulo(nombre);
                    cout << mostrarCartelera();

                break;

            case 2:
                cout << "\nIngrese la nueva hora de la pelicula: ";
                cin >> hora;
                cin.ignore();
                cartelera[id-1]->setHora(hora);
                cout << mostrarCartelera();

                break;

            case 3:
                cout << "\nIngrese la nueva duracion de la pelicula: ";
                cin >> duracion;
                cin.ignore();
                cartelera[id-1]->setDuracion(duracion);
                cout << mostrarCartelera();
                break;

            case 4:
                cout << "Ingrese 'S' si esta de estreno o ingrese 'N' si ya esta en cartelera: ";
                cin >> estreno;
                if (estreno == 'S' || estreno == 's'){
                    cartelera[id-1]->setEstreno(true);
                } else if (estreno == 'N' || estreno == 'n'){
                    cartelera[id-1]->setEstreno(false);
                }
                cout << mostrarCartelera();
                break;
            case 5:
                    cout << "\nIngrese el nuevo nombre de la pelicula: ";
                    cin>>nombre;
                    cartelera[id-1]->setTitulo(nombre);

                    cout << "\nIngrese la nueva hora de la pelicula: ";
                    cin >> hora;
                    cin.ignore();
                    cartelera[id-1]->setHora(hora);

                    cout << "\nIngrese la nueva duracion de la pelicula: ";
                    cin >> duracion;
                    cin.ignore();
                    cartelera[id-1]->setDuracion(duracion);
                    cout << mostrarCartelera();
                    cout << "Ingrese 'S' si esta de estreno o ingrese 'N' si ya esta en cartelera: ";
                    cin >> estreno;
                    if (estreno == 'S' || estreno == 's'){
                        cartelera[id-1]->setEstreno(true);
                    } else if (estreno == 'N' || estreno == 'n'){
                        cartelera[id-1]->setEstreno(false);
                    }
                    cout << mostrarCartelera();

                break;


            default:
                cout << "\nOpcion invalida. Por favor, elija una opcion valida." << endl;
                break;
        }




}
