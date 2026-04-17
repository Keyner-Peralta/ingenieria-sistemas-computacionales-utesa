/*
 Programador: Keyner Peralta 
 Matrícula: xxxxxxxxxxxx
 -Realizar un programa en C++ capaz de leer los datos de un empleado y
 en base al sueldo calcular impuesto de 25%, cuando el sueldo sea mayor de 34,400
*/
#include <iostream>
#include <iomanip>
using namespace std;

struct Empleado
{
    bool existe = false;
    string nombre;
    string apellido;
    float impuesto;
    float sueldo;
    float neto;
} empleado;

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
    cout << "\t===\t                    1. Agregar un empleado a la nomina                                  === "<< endl;
    cout << "\t===\t                    2. Ver la nomina de su empleado                                     === "<< endl;
    cout << "\t===\t                    3. Eliminar un empleado la nomina                                   === "<< endl;
    cout << "\t===\t                    4. Salir del programa                                               === "<< endl;
    cout << "\t==================================================================================================="<< endl;
}

void calcularSueldo()
{
    if(empleado.sueldo >= 34400.00)
    {
        empleado.impuesto = (empleado.sueldo - 34400.00) * 0.25;

        empleado.neto = empleado.sueldo - empleado.impuesto;
    }
    else
    {
        empleado.impuesto = 0.0;
        empleado.neto = empleado.sueldo;
    }
}
void agregarEmpleado()
{

    cout << "\t|||\t\t   Ingresa el nombre de tu empleado: ";
        getline(cin, empleado.nombre);

    cout << "\t|||\t\t   Ingresa los apellidos de tu empleado: ";
        getline(cin, empleado.apellido);

    cout << "\t|||\t\t   Ingresa el sueldo de tu empleado: ";
        cin >> empleado.sueldo;
    //limpiamos el buffer
    cin.ignore(10000, '\n');

    calcularSueldo();

    empleado.existe = true;
    cout << "\n";
    cout << "\t***************************************************************************************************" << endl;
    cout << "\t***                                   Empleado agregado exitosamente !                          ***" << endl;
    cout << "\t***************************************************************************************************" << endl;
}

void mostrarEmpleado()
{
    //En caso de que empleado no exista, ejecuta este mensaje
    if(!empleado.existe)
    {
        cout << "\n";
        cout << "\t***************************************************************************************************" << endl;
        cout << "\t***                               No existen empleados en la nomina                             ***" << endl;
        cout << "\t***************************************************************************************************" << endl;
        return;
    }
    cout<< "\n";
    //cambiamos la alineacion a la izquierda por culpa de setw()
    cout << left;
    cout << "\t####################################################################################################"<<endl;
    cout << "\t###                     Se aplica impuesto de 25% a sueldos superiores de 34,400                 ###"<<endl;
    cout << "\t####################################################################################################"<<endl;
    cout << "\t----------------------------------------------------------------------------------------------------"<< endl;
    cout << "\t      Nombre      |      Apellidos     |      Sueldo      |     Impuesto      |    Sueldo  neto    |" << endl;
    cout << "\t----------------------------------------------------------------------------------------------------"<< endl;
    cout << "\t"<< setw(18) << empleado.nombre; cout << "| ";
    cout << setw(19) << empleado.apellido; cout << "| ";
    cout << "RD$ "<< setw(13) << empleado.sueldo; cout << "| ";
    cout << "RD$ "<< setw(14) << empleado.impuesto; cout << "| ";
    cout << "RD$ "<< setw(15) << empleado.neto; cout << "|";
    cout << "\n";
}

void eliminarEmpleado()
{
    if(!empleado.existe)
    {
        cout << "\n";
        cout << "\t************************************************************************************************" << endl;
        cout << "\t***                        No existen empleados en la nomina                                 ***" << endl;
        cout << "\t************************************************************************************************" << endl;
        return;
    }
    //ponemos las variables en su estado base
    empleado.nombre = "";
    empleado.apellido = "";
    empleado.sueldo = 0;
    empleado.neto = 0;
    empleado.impuesto = 0;
    empleado.existe = false;
    cout << "\n";
    cout << "\t***************************************************************************************************" << endl;
    cout << "\t***                                   Empleado eliminado exitosamente!                          ***" << endl;
    cout << "\t***************************************************************************************************" << endl;

}
int main()
{
    //variable de control del bucle principal
    bool control = true;
    while(control)
    {
        menu();

        cout << "\tIntroduce tu respuesta: ";
        int respuesta;
        //Si el el cin falla por entrada invalida
        // lo reseteamos
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
                cout << "\t|||                   Seleccionaste 1: Agregar un empleado a la nomina                          |||" << endl;
                cout << "\t===================================================================================================" << endl;
                agregarEmpleado();
                break;
            case 2:
                cout << "\t===================================================================================================" << endl;
                cout << "\t|||                   Seleccionaste 2: Ver la nomina de su empleado                             |||" << endl;
                cout << "\t===================================================================================================" << endl;
                mostrarEmpleado();
                break;
            case 3:
                cout << "\t===================================================================================================" << endl;
                cout << "\t|||                   Seleccionaste 3: Eliminar un empleado la nomina                           |||" << endl;
                cout << "\t===================================================================================================" << endl;
                eliminarEmpleado();
                break;
            case 4:
                control = false;
                cout << "\t===================================================================================================" << endl;
                cout << "\t|||                         Seleccionaste 4: Salir del programa                                 |||" << endl;
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
    return 0;
}

