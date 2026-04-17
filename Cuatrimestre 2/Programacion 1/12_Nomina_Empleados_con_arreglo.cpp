/*
 Programador: Keyner Peralta 
 Matrícula: xxxxxxxxx
 -Realizar un programa en C++ capaz de leer los datos de un empleado y
  en base al sueldo calcular impuesto de 25%, cuando el sueldo sea mayor de 34,400.
  Debe permitir ingresar más de un empleado
*/
#include <iostream>
#include <iomanip>

using namespace std;

//variable que indica el tamaño del arreglo de la nomina
int cantidadEmpleados;

//Nomina de empleado
struct Empleado
{
    //Cedula: funciona como ID para modificar y eliminar empleados
    string cedula;
    bool existe = false;
    string nombre;
    string apellido;
    float impuesto;
    float sueldo;
    float neto;
};

//Este menu muestra los datos del programador y las opciones que puede realizar el programa
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
    cout << "\t|||\t           Fecha: Marzo, 2026                                                           |||" << endl;
    cout << "\t===                                                                                             ===" << endl;
    cout << "\t===================================================================================================" << endl;
    cout << "\t===*********************************[    Nomina de empleados    ]*******************************===" << endl;
    cout << "\t===================================================================================================" << endl;
    cout << "\t===                                      Seleccione una opcion                                  ==="<< endl;
    cout << "\t===---------------------------------------------------------------------------------------------==="<< endl;
    cout << "\t===\t                    1. Agregar empleados a la nomina                                    === "<< endl;
    cout << "\t===\t                    2. Ver la nomina de empleados                                       === "<< endl;
    cout << "\t===\t                    3. Cambiar datos de un empleado de la nomina                        === "<< endl;
    cout << "\t===\t                    4. Eliminar un empleado de la nomina                                === "<< endl;
    cout << "\t===\t                    5. Salir del programa                                               === "<< endl;
    cout << "\t==================================================================================================="<< endl;
}

//Esta funcion pregunta al usuario el tamaño del arreglo de la nomina
void preguntarCantidadEmpleados()
{
    cout << "\t===================================================================================================" << endl;
    cout << "\t|||                              Universidad Tecnologica de Santiago                            |||" << endl;
    cout << "\t===================================================================================================" << endl;
    cout << "\t===***********************************[  Datos del Programador  ]*******************************===" << endl;
    cout << "\t===                                                                                             ===" << endl;
    cout << "\t|||\t           Carrera: Ingenieria en Sistemas Computacionales                              |||" << endl;
    cout << "\t|||\t           Nombre: Keyner Miguel Peralta Perez                                          |||" << endl;
    cout << "\t|||\t           Matricula: 1-25-8863                                                         |||" << endl;
    cout << "\t|||\t           Fecha: Marzo, 2026                                                           |||" << endl;
    cout << "\t===                                                                                             ===" << endl;
    cout << "\t===================================================================================================" << endl;
    cout << "\t===*********************************[    Nomina de empleados    ]*******************************===" << endl;
    cout << "\t===================================================================================================" << endl;
    cout << "\t|||    " << endl;
    cout << "\t|||    Introduzca la cantidad maxima de empleados que se pueden agregar a su nomina: ";
    //validamos la entrada del usuario
    if(!(cin >> cantidadEmpleados))
    {
        cin.clear();
        //establecemos 5 como valor por defecto
        cantidadEmpleados = 5;
        cout<< "\t    Entrada erronea, se le asignara 5 empleados maximos" << endl;
    }
    cin.ignore(10000,'\n');
    cout << endl;
}


void calcularSueldo(Empleado* empleado)
{
    if(empleado->sueldo >= 34400.00)
    {
        empleado->impuesto = (empleado->sueldo - 34400.00) * 0.25;

        empleado->neto = empleado->sueldo - empleado->impuesto;
    }
    else
    {
        empleado->impuesto = 0.0;
        empleado->neto = empleado->sueldo;
    }
}

//Funcion complementaria de: agregarEmpleado
string verificaCedula(Empleado* empleado)
{
    string cedulaTemporal;
    bool cedulaValida;
    do
    {
        cedulaValida = true;

        cout << "\t|||\t\t   Ingrese la cedula o ID de su empleado: ";
        getline(cin, cedulaTemporal);

        for(int j = 0; j < cantidadEmpleados; j++)
        {
            if(empleado[j].existe && empleado[j].cedula == cedulaTemporal)
            {
                cout << "\t|||\t\t   ERROR: Ya existe un empleado con esa cedula\n";
                cedulaValida = false;
                break;
            }
        }

    } while(!cedulaValida);

    return cedulaTemporal;
}

//Esta funcion busca en el arreglo de la nomina si hay un espacio libre
int buscarEspacioLibre(Empleado* empleado)
{
    for(int i = 0; i < cantidadEmpleados; i++)
    {
        if(!empleado[i].existe)
        {
            return i;
        }
    }
    return -1;
}

//Función que agrega empleados a la nomina
void agregarEmpleado(Empleado* empleado)
{
    char respuesta;

    while(true)
    {
        int i = buscarEspacioLibre(empleado);

        if(i == -1)
        {
            cout << "\t***********************************************************************************************" <<endl;
            cout << "\t****                   Capacidad maxima alcanzada elimine empleados                        ****" << endl;
            cout << "\t***********************************************************************************************" <<endl;
            return;
        }

        cout << "\t|||\t\t   Ingresa el nombre de su empleado: ";
        getline(cin, empleado[i].nombre);

        cout << "\t|||\t\t   Ingresa los apellidos de su empleado: ";
        getline(cin, empleado[i].apellido);

        cout << "\t|||\t\t   Ingresa el sueldo de su empleado: ";
        while(!(cin >> empleado[i].sueldo))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\t|||\t\t   -Ingresa un sueldo valido a su empleado: ";
        }
        cin.ignore(10000, '\n');

        empleado[i].cedula = verificaCedula(empleado);

        calcularSueldo(&empleado[i]);

        empleado[i].existe = true;

        cout << "\n";
        cout << "\t***************************************************************************************************" << endl;
        cout << "\t***                                   Empleado agregado exitosamente !                          ***" << endl;
        cout << "\t***************************************************************************************************" << endl;

        cout << "\t Desea continuar agregando empleados (s/n): ";
        cin >> respuesta;
        cin.ignore(10000, '\n');

        if(respuesta == 'n' || respuesta == 'N') break;

        cout << endl;
    }
}

bool mostrarEmpleado(Empleado* empleado)
{
    bool hayEmpleados = false;

    //iteramos sobre el arreglo para estar seguros de que no existan empleados agregados
    for(int i = 0; i < cantidadEmpleados; i++)
    {
        if(empleado[i].existe)
        {
            hayEmpleados = true;
            break;
        }
    }

    //En caso de que empleado no exista, ejecuta este mensaje
    if(!hayEmpleados)
    {
        cout << "\n";
        cout << "\t***************************************************************************************************" << endl;
        cout << "\t***                               No existen empleados en la nomina                             ***" << endl;
        cout << "\t***************************************************************************************************" << endl;
        return false;
    }

    cout<< "\n";

    //cambiamos la alineacion a la izquierda por culpa de setw()
    cout << left;
    cout << "\t##############################################################################################################################"<<endl;
    cout << "\t###                                Se aplica impuesto de 25% a sueldos superiores de 34,400                                ###"<<endl;
    cout << "\t##############################################################################################################################"<<endl;
    cout << "\t--------------------------------------------------------------------------------------------------------------------------------"<< endl;
    cout << "\t|   Cedula / ID    |      Nombre      |      Apellidos     |       Sueldo       |     Impuesto        |    Sueldo  neto        |" << endl;
    cout << "\t--------------------------------------------------------------------------------------------------------------------------------"<< endl;

    double sueldoTotal = 0;
    double impuestoTotal = 0;
    double netoTotal = 0;

    for(int i = 0; i < cantidadEmpleados; i++)
    {
        if(empleado[i].existe == false) continue;
        cout << left;
        cout << "\t| " << setw(17) << empleado[i].cedula; cout << "| ";
        cout << setw(17) << empleado[i].nombre; cout << "| ";
        cout << setw(19) << empleado[i].apellido; cout << "| ";
        cout << "RD$ "<< setw(14) << right << empleado[i].sueldo; cout << " | ";
        cout << "RD$ "<< setw(16) << empleado[i].impuesto; cout << "| ";
        cout << "RD$ "<< setw(19) << empleado[i].neto; cout << "|";
        cout << "\n";
        cout << "\t--------------------------------------------------------------------------------------------------------------------------------"<<endl;
        sueldoTotal += empleado[i].sueldo;
        impuestoTotal += empleado[i].impuesto;
        netoTotal += empleado[i].neto;
    }

    cout << "\t================================================================================================================================"<< endl;
    cout << "\t| " << setw(57) << left << "TOTALES"; cout << "| ";
    cout << "RD$ "<< setw(14) << right << sueldoTotal; cout << " | ";
    cout << "RD$ "<< setw(16) << impuestoTotal; cout << "| ";
    cout << "RD$ "<< setw(19) << netoTotal; cout << "|";
    cout << "\n";
    cout << "\t================================================================================================================================"<< endl;

    return true;
}

string verificaCedulaUnica(Empleado* empleado)
{
    string cedulaTemporal;
    bool cedulaValida;
    do
    {
        cedulaValida = true;

        cout << "\t|||\t\t   Ingrese una nueva cedula o ID de su empleado: ";
        getline(cin, cedulaTemporal);

        for(int j = 0; j < cantidadEmpleados; j++)
        {
            if(empleado[j].existe && empleado[j].cedula == cedulaTemporal)
            {
                cout << "\t|||\t\t   ERROR: Ya existe un empleado con esa cedula\n";
                cedulaValida = false;
                break;
            }
        }

    } while(!cedulaValida);

    return cedulaTemporal;
}

void cambiarDatosEmpleado(Empleado* empleado)
{
    if(!mostrarEmpleado(empleado))
        return;

    cout << "\t|||\t\t Introduzca la cedula del empleado a modificar: ";

    string cedula;

    getline(cin, cedula);

    bool encontrado = false;

    for(int i = 0; i < cantidadEmpleados; i++)
    {
        if(empleado[i].existe && empleado[i].cedula == cedula)
        {
            encontrado = true;
            cout << "\n\t|||================================================================================|||" << endl;
            cout << "\t|||                                 Datos actuales del empleado                    |||" << endl;
            cout << "\t|||================================================================================|||" << endl;
            cout << "\t|||\t\tNombre: " << empleado[i].nombre << endl;
            cout << "\t|||\t\tApellido: " << empleado[i].apellido << endl;
            cout << "\t|||\t\tCedula: " << empleado[i].cedula << endl;
            cout << "\t|||\t\tSueldo: " << empleado[i].sueldo << endl;
            cout << endl;
            cout << "\t|||================================================================================|||" << endl;
            cout << "\t|||                Ingrese los nuevos datos de su empleado                         |||" << endl;
            cout << "\t|||================================================================================|||" << endl;
            cout << "\t|||\t\tNuevo nombre: ";
            getline(cin, empleado[i].nombre);

            cout << "\t|||\t\tNuevo apellido: ";
            getline(cin, empleado[i].apellido);

            //Ingresamos una nueva cedula
            empleado[i].cedula = verificaCedulaUnica(empleado);

            cout << "\t|||\t\tNuevo sueldo: ";
            cin >> empleado[i].sueldo;
            cin.ignore(10000, '\n');

            // Recalcular sueldo
            calcularSueldo(&empleado[i]);

            cout << "\n\t***************************************************************************************************" << endl;
            cout << "\t***                              Empleado actualizado exitosamente!                             ***" << endl;
            cout << "\t***************************************************************************************************" << endl;

            break;
        }
    }

    if(!encontrado)
    {
        cout << "\n\t***************************************************************************************************" << endl;
        cout << "\t***                    Empleado no encontrado, verifique la cedula ingresada                    ***" << endl;
        cout << "\t***************************************************************************************************" << endl;
    }
}

void eliminarEmpleado(Empleado* empleado)
{

    bool hayEmpleado = mostrarEmpleado(empleado);

    if(!hayEmpleado) return;

    cout << "\t|||\t\t" << endl;
    cout << "\t|||\t\t Introduzca la cedula de su empleado para eliminar: ";

    string cedula;

    getline(cin, cedula);

    bool empleadoEncontrado = false;

    for(int i = 0; i < cantidadEmpleados; i++)
    {
        if(empleado[i].existe && empleado[i].cedula == cedula)
        {
            empleadoEncontrado = true;

            //ponemos las variables en su estado base
            empleado[i].cedula = "";
            empleado[i].nombre = "";
            empleado[i].apellido = "";
            empleado[i].sueldo = 0;
            empleado[i].neto = 0;
            empleado[i].impuesto = 0;
            empleado[i].existe = false;
            break;

        }
    }

    if(!empleadoEncontrado)
    {
        cout << "\n";
        cout << "\t***************************************************************************************************" << endl;
        cout << "\t***                    Empleado no encontrado, por favor introduzca un cedula valida            ***" << endl;
        cout << "\t***************************************************************************************************" << endl;
    }
    else
    {
        cout << "\n";
        cout << "\t***************************************************************************************************" << endl;
        cout << "\t***                                   Empleado eliminado exitosamente!                          ***" << endl;
        cout << "\t***************************************************************************************************" << endl;
    }

}


int main()
{
    //variable de control del bucle principal
    preguntarCantidadEmpleados();

    //Hacemos un arreglo dinamico
    Empleado* empleados = new Empleado[cantidadEmpleados];

    bool control = true;

    while(control)
    {
        menu();

        cout << "\tIntroduce tu respuesta: ";
        int respuesta;

        //Si el el cin falla por entrada invalida, lo reseteamos
        if(!(cin >> respuesta))
        {
            cin.clear();
            //Limpiamos el buffer
            cin.ignore(10000, '\n');
            continue;
        }

        //Limpiamos el buffer
        cin.ignore(10000, '\n');

        switch(respuesta)
        {

            case 1:
                cout << "\t===================================================================================================" << endl;
                cout << "\t|||                   Seleccionaste 1: Agregar empleados a la nomina                            |||" << endl;
                cout << "\t===================================================================================================" << endl;
                agregarEmpleado(empleados);
                break;

            case 2:
                cout << "\t===================================================================================================" << endl;
                cout << "\t|||               Seleccionaste 2: Ver la nomina de empleado                                    |||" << endl;
                cout << "\t===================================================================================================" << endl;
                mostrarEmpleado(empleados);
                break;

            case 3:
                cout << "\t===================================================================================================" << endl;
                cout << "\t|||               Seleccionaste 3: Cambiar datos de un empleado de la nomina                    |||" << endl;
                cout << "\t===================================================================================================" << endl;
                cambiarDatosEmpleado(empleados);
                break;

            case 4:
                cout << "\t===================================================================================================" << endl;
                cout << "\t|||                Seleccionaste 4: Eliminar un empleado la nomina                              |||" << endl;
                cout << "\t===================================================================================================" << endl;
                eliminarEmpleado(empleados);
                break;

            case 5:
                control = false;
                cout << "\t===================================================================================================" << endl;
                cout << "\t|||                         Seleccionaste 5: Salir del programa                                 |||" << endl;
                cout << "\t===================================================================================================" << endl;
                cout << "\t|||                               ====# Vuelve pronto #====                                     |||" << endl;
                cout << "\t===================================================================================================" << endl;
                break;

            default:
                cout << "\t===================================================================================================" << endl;
                cout << "\t|||                   Opcion invalida. Por favor, selecciona una valida                         |||" << endl;
                cout << "\t===================================================================================================" << endl;
                break;
        }
        cout << "\n";
    }
    delete[] empleados;
    return 0;
}
