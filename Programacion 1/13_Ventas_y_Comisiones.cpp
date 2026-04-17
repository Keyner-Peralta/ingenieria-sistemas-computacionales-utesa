/*
    Programador: Keyner Peralta 
    Matrícula: xxxxxxxxxxxx
    -Realizar un programa en C++ capaz de leer los datos de varios Vendedores
    y en base a lo vendido calcular la comisión para cada vendedor
    de un 15% de lo vendido.
*/
#include <iostream>
#include <iomanip>

using namespace std;

//Esta variable sirve para determina el size del arreglo vendedor
int cantidadVendedores;

struct Vendedor
{
    //ID: sirve para identificar, modificar y eliminar vendedores
    string id;
    bool existe = false;
    string nombre;
    string apellido;
    double vendido;
    double comision;
};

void menu()
{
    cout << "\t===================================================================================================" << endl;
    cout << "\t|||                              Universidad Tecnologica de Santiago                            |||" << endl;
    cout << "\t===================================================================================================" << endl;
    cout << "\t===***********************************[  Datos del Programador  ]*******************************===" << endl;
    cout << "\t===                                                                                             ===" << endl;
    cout << "\t|||\t           Carrera: Ingenieria en Sistemas Computacionales                              |||" << endl;
    cout << "\t|||\t           Nombre: Keyner Peralta                                                       |||" << endl;
    cout << "\t|||\t           Matricula: xxxxxxxxx                                                         |||" << endl;
    cout << "\t|||\t           Fecha: Abril, 2026                                                           |||" << endl;
    cout << "\t===                                                                                             ===" << endl;
    cout << "\t===================================================================================================" << endl;
    cout << "\t===*********************************[    Ventas y comisiones    ]*******************************===" << endl;
    cout << "\t===================================================================================================" << endl;
    cout << "\t===                                      Seleccione una opcion                                  ==="<< endl;
    cout << "\t===---------------------------------------------------------------------------------------------==="<< endl;
    cout << "\t===\t                    1. Agregar vendedores                                               === "<< endl;
    cout << "\t===\t                    2. Ver vendedores                                                   === "<< endl;
    cout << "\t===\t                    3. Modificar vendedores                                             === "<< endl;
    cout << "\t===\t                    4. Eliminar un vendedor                                             === "<< endl;
    cout << "\t===\t                    5. Salir del programa                                               === "<< endl;
    cout << "\t==================================================================================================="<< endl;
}

void preguntarCantidadVendedores()
{
    cout << "\t===================================================================================================" << endl;
    cout << "\t===*********************************[    Ventas y comisiones    ]*******************************===" << endl;
    cout << "\t===================================================================================================" << endl;
    cout << "\t|||    " << endl;
    cout << "\t|||    Introduzca la cantidad maxima de vendedores que permite el programa: ";

    if(!(cin >> cantidadVendedores))
    {
        cin.clear();
        cantidadVendedores = 5;
        cout << "\n";
        cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "\t|||  ***************    Entrada invalida. Se asigna 5 vendedores por defecto    *************** |||" << endl;
        cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "\n";
    }
    cin.ignore(10000,'\n');
    cout << endl;
}

// Esta funcion busca dentro del arreglo si existe un espacio libre par agregar un vendedor
int buscarEspacioLibre(Vendedor* vendedor)
{
    for(int i = 0; i < cantidadVendedores; i++)

        if(!vendedor[i].existe)
        {
            return i;
        }
    return -1;
}


//Funcion que busca un vendedor por su ID
int buscarPorID(Vendedor* vendedor, string ID)
{
    for(int i = 0; i < cantidadVendedores; i++)
    {
        //retorna la posicion para indicar que existe un vendedor con el mismo ID
        if(vendedor[i].existe && vendedor[i].id == ID)
            return i;
    }
    //retorna -1 para indicar que no se encontró un vendedor con ese ID
    return -1;
}


// Funcion que verifica que el ID sea unico al agregar un vendedor al arreglo
string verificarIDUnico(Vendedor* vendedor)
{
    string id;
    bool valida;

    do{
        valida = true;
        cout << "\t|||\t\t   ID: ";
        getline(cin, id);

        if(buscarPorID(vendedor, id) != -1)
        {
            cout << "\t|||\t\t   ID duplicado.\n";
            valida = false;
        }

    }while(!valida);

    return id;
}


//Funcion sobrecargada que verifica ID unico al modificar (evita comparar con el mismo registro)
string verificarIDUnico(Vendedor* vendedor, int posActual)
{
    string id;
    bool valida;

    do{
        valida = true;
        cout << "\t|||\t\t   ID: ";
        getline(cin, id);

        for(int i = 0; i < cantidadVendedores; i++)
        {
            if(i != posActual && vendedor[i].existe && vendedor[i].id == id)
            {
                cout << "\t|||\t\t   ID duplicado.\n";
                valida = false;
                break;
            }
        }

    }while(!valida);

    return id;
}

//Funcion que agrega vendedores al arreglo
void agregar(Vendedor* vendedor)
{
    char respuesta;

    while(true)
    {
        int i = buscarEspacioLibre(vendedor);

        //Si no hay espacio disponible
        if(i == -1)
        {
            cout << "\n";
            cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            cout << "\t|||  ***************  Capacidad maxima alcanzada. Elimine vendedores primero   *************** |||" << endl;
            cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
            cout << "\n";
            return;
        }

        cout << "\t|||\t\t   Ingresa el nombre del vendedor: ";
        getline(cin, vendedor[i].nombre);

        cout << "\t|||\t\t   Ingresa el apellido del vendedor: ";
        getline(cin, vendedor[i].apellido);

        cout << "\t|||\t\t   Ingresa el monto vendido: ";
        while(!(cin >> vendedor[i].vendido))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\t|||\t\t   -Ingresa un monto valido: ";
        }
        cin.ignore(10000, '\n');

        vendedor[i].id = verificarIDUnico(vendedor);

        vendedor[i].comision = vendedor[i].vendido * 0.15;

        vendedor[i].existe = true;

        cout << "\n";
        cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "\t|||          *****************  Vendedor agregado exitosamente *****************               |||" << endl;
        cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "\n";
        cout << "\t|||\tDesea continuar agregando vendedores (s/n): ";
        cin >> respuesta;
        cin.ignore(10000, '\n');

        if(respuesta == 'n' || respuesta == 'N') break;

        cout << endl;
    }
}

//Funcion que muestra todos los vendedores
void mostrar(Vendedor* vendedor)
{
    bool hayVendedores = false;

    //Verificamos si hay vendedores registrados
    for(int i = 0; i < cantidadVendedores; i++)
    {
        if(vendedor[i].existe)
        {
            hayVendedores = true;
            break;
        }
    }

    // Si no hay vendedores
    if(!hayVendedores)
    {
        cout << "\n";
        cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "\t|||                   No existen vendedores registrados en el sistema                          |||" << endl;
        cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "\n";
        return;
    }

    cout << "\n";

    cout << left;
    cout << "\t###############################################################################################################"<<endl;
    cout << "\t###                                   LISTADO GENERAL DE VENDEDORES                                          ###"<<endl;
    cout << "\t###############################################################################################################"<<endl;

    cout << "\t-------------------------------------------------------------------------------------------"<< endl;
    cout << "\t|       ID       |     Nombre     |     Apellido     |     Vendido     |     Comision     |" << endl;
    cout << "\t-------------------------------------------------------------------------------------------"<< endl;

    double totalVendido = 0;
    double totalComision = 0;

    cout << fixed << setprecision(2);

    for(int i = 0; i < cantidadVendedores; i++)
    {
        if(!vendedor[i].existe) continue;

        cout << left;
        cout << "\t| " << setw(15) << vendedor[i].id << "| ";
        cout << setw(15) << vendedor[i].nombre << "| ";
        cout << setw(17) << vendedor[i].apellido << "| ";
        cout << "RD$ " << setw(12) << right << vendedor[i].vendido << "| ";
        cout << "RD$ " << setw(13) << vendedor[i].comision << "|";
        cout << "\n";

        cout << "\t-------------------------------------------------------------------------------------------"<< endl;

        totalVendido += vendedor[i].vendido;
        totalComision += vendedor[i].comision;
    }

    cout << "\t==========================================================================================="<< endl;
    cout << "\t| " << setw(51) << left << "TOTALES"; cout << "| ";
    cout << "RD$ " << setw(12) << right << totalVendido << "| ";
    cout << "RD$ " << setw(13) << totalComision << "|";
    cout << "\n";
    cout << "\t==========================================================================================="<< endl;

    cout << "\n";
}

//Funcion que modifica los datos de un vendedor
void modificar(Vendedor* vendedor)
{
    mostrar(vendedor);

    cout << "\t|||\t\t Introduzca el id del vendedor a modificar: ";

    string id;
    getline(cin, id);

    int pos = buscarPorID(vendedor, id);

    //Si no se encuentra el vendedor
    if(pos == -1)
    {
        cout << "\n";
        cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << "\t|||        Vendedor no encontrado. Verifique el id ingresado                                   |||" << endl;
        cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
        return;
    }

    cout << "\n";
    cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "\t|||                           Datos actuales del vendedor                                      |||" << endl;
    cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

    cout << "\t|||\t\tNombre: " << vendedor[pos].nombre << endl;
    cout << "\t|||\t\tApellido: " << vendedor[pos].apellido << endl;
    cout << "\t|||\t\tID: " << vendedor[pos].id << endl;
    cout << "\t|||\t\tVendido: " << vendedor[pos].vendido << endl;

    cout << "\n";
    cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "\t|||                        Ingrese los nuevos datos del vendedor                                |||" << endl;
    cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;

    cout << "\t|||\t\tNuevo nombre: ";
    getline(cin, vendedor[pos].nombre);

    cout << "\t|||\t\tNuevo apellido: ";
    getline(cin, vendedor[pos].apellido);

    vendedor[pos].id = verificarIDUnico(vendedor, pos);

    cout << "\t|||\t\tNuevo monto vendido: ";
    while(!(cin >> vendedor[pos].vendido))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\t|||\t\t   -Ingresa un monto valido: ";
    }
    cin.ignore(10000, '\n');

    vendedor[pos].comision = vendedor[pos].vendido * 0.15;

    cout << "\n";
    cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "\t|||                   Vendedor actualizado exitosamente                                         |||" << endl;
    cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
}

//Funcion que elimina un vendedor
void eliminar(Vendedor* vendedor)
{
    mostrar(vendedor);

    string id;
    cout << "\t|||\t\tID del vendedor a eliminar: ";
    getline(cin, id);

    int pos = buscarPorID(vendedor, id);

    //Si no se encuentra
    if(pos == -1)
    {
        cout << "\t|||\t\tNo encontrado.\n";
        return;
    }

    //Marcamos como eliminado
    vendedor[pos].existe = false;

    cout << "\n";
    cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "\t||| ***************             Vendedor eliminado exitosamente!!!             *************** |||" << endl;
    cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "\n";
}

int main()
{
    //Inicializamos el tamaño del arreglo
    preguntarCantidadVendedores();

    //Creamos arreglo dinamico
    Vendedor* vendedor = new Vendedor[cantidadVendedores];

    bool control = true;

    //Bucle principal del programa
    while(control)
    {
        menu();
        cout << "\t|||" << endl;
        cout << "\t|||\tIntroduce tu respuesta: ";
        int respuesta;

        //Si el cin falla por entrada invalida, lo reseteamos
        if(!(cin >> respuesta))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(10000, '\n');

        switch(respuesta)
        {

            case 1:
                cout << "\t|||" << endl;
                cout << "\n";
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\t|||         ***************** Seleccionaste 1: Agregar vendedores *****************             |||" << endl;
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\n";
                agregar(vendedor);
                break;

            case 2:
                cout << "\t|||" << endl;
                cout << "\n";
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\t|||         ***************** Seleccionaste 2: Ver vendedores *********************             |||" << endl;
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\n";
                mostrar(vendedor);
                break;

            case 3:
                cout << "\t|||" << endl;
                cout << "\n";
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\t|||         ***************** Seleccionaste 3: Modificar vendedores ***************             |||" << endl;
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\n";
                modificar(vendedor);
                break;

            case 4:
                cout << "\t|||" << endl;
                cout << "\n";
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\t|||         ***************** Seleccionaste 4: Eliminar vendedor ******************             |||" << endl;
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\n";
                eliminar(vendedor);
                break;

            case 5:
                cout << "\t|||" << endl;
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\t|||         ***************** Seleccionaste 5: Salir del programa ***************               |||" << endl;
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\t///                                                                                             ///" << endl;
                cout << "\t|||                   ***************** Vuelve pronto  ***************                          |||" << endl;
                cout << "\t///                                                                                             ///" << endl;
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\n";
                control = false;
                break;

            default:
                cout << "\t|||" << endl;
                cout << "\n";
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\t|||         ***************** Opcion invalida *******************************                    |||" << endl;
                cout << "\t///////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
                cout << "\n";
                break;
        }
        cout << "\n";
    }

    delete[] vendedor;
    return 0;
}
