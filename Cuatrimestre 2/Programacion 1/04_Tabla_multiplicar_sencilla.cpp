#include <iostream>
using namespace std;

int main()
{
    int control = 1;
    float numero = 0;

    while(control)
    {
        cout << "Tablas de multiplicar del numero que deseas\n";
        cout << "Introduce tu numero(puede ser positivo, negativo o fraccionario): ";
        cin >> numero;

        for(int i = 1; i <= 12; i++)
        {
            cout << "\t" << numero << " * " << i << " = " << (numero * i)<<endl;
        }
        cout << "Quieres probar otro numero? (s/n)\n";
        char opcion;
        cin >> opcion;
        if(opcion == 'n')
            control = 0;
    }
}
