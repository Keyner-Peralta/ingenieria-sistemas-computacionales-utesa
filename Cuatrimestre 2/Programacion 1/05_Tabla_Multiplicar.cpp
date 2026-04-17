// Programador: Keyner Peralta 
// Matricula: xxxxxxxxxx
// -Realizar un programa que imprima la tabla de multiplicar de cualquier numero
#include <iostream>

using namespace std;

//variable del menu
int respuesta;
char Si_No;

float numero;
int multiplo;

int main()
{
    //Controla el bucle principal
    int control = 1;

    while(control)
    {
        cout << "\t=============================================================" << endl;
        cout << "\t|||          Universidad Tecnologica de Santiago          |||" << endl;
        cout << "\t=============================================================" << endl;
        cout << "\t===**************[ Datos del Programador ]****************===" << endl;
        cout << "\t===                                                       ===" << endl;
        cout << "\t|||\t Carrera: Ingenieria en Sistemas Computacionales  |||" << endl;
        cout << "\t|||\t Nombre: Keyner Peralta                           |||" << endl;
        cout << "\t|||\t Matricula: xxxxxxxxx                             |||" << endl;
        cout << "\t|||\t Fecha: Marzo, 2026                               |||" << endl;
        cout << "\t===                                                       ===" << endl;
        cout << "\t=============================================================" << endl;
        cout << "\t===************[   Tablas de multiplicar   ]**************===" << endl;
        cout << "\t=============================================================" << endl;
        cout << "\t===               Seleccione una opcion                   ==="<< endl;
        cout << "\t===-------------------------------------------------------==="<< endl;
        cout << "\t===\t 1. Ver tabla hasta su multiplo 12                === "<< endl;
        cout << "\t===\t 2. Ver tabla hasta el multiplo deseado           === "<< endl;
        cout << "\t===\t 3. Salir del programa                            === "<< endl;
        cout << "\t============================================================="<< endl;

        //Entrada de datos
        cout << "\t=== Introduce tu repuesta: ";
        cin >> respuesta;

        switch(respuesta)
        {
            case 1:
                cout << "\t-------------------------------------------------------------"<< endl;
                cout << "\t Introduce tu numero: "; cin >> numero;
                cout << "\t-------------------------------------------------------------"<< endl;

                for(int i = 1; i <= 12; i++)
                {
                    cout << "\t\t" << numero << " * " << i << " = " << (numero * i) << endl;
                }

                cout << "\tQuieres seguir ejecutando el programa (s/n)?" << endl;

                cout << "\t"; cin >> Si_No;

                // Termina con el bucle
                if(Si_No == 'n' || Si_No == 'N') control = 0;
                break;

            case 2:
                cout << "\t-------------------------------------------------------------"<< endl;
                cout << "\t Introduce tu numero: "; cin >> numero;
                cout << "\t Introduce tu multiplo: "; cin >> multiplo;
                cout << "\t-------------------------------------------------------------"<< endl;

                for(int i = 1; i <= multiplo; i++)
                {
                    cout << "\t\t" << numero << " * " << i << " = " << numero * i << endl;
                }

                cout << "\tQuieres seguir ejecutando el programa (s/n)?" << endl;
                cout << "\t"; cin >> Si_No;

                // Termina con el bucle
                if(Si_No == 'n' || Si_No == 'N') control = 0;
                break;
            case 3:
                control = 0;
                break;

            default:
                cout << "\n\n\t*************************************************************" << endl;
                cout << "\t\tOpcion invalida, selecciona una opcion por favor" << endl;
                cout << "\t*************************************************************\n" << endl;
                break;

        }

    }

    cout << "\t=============================================================" << endl;
    cout << "\t\t    Programa finalizado existosamente!!" << endl;
    cout << "\t=============================================================" << endl;

    return 0;
}
