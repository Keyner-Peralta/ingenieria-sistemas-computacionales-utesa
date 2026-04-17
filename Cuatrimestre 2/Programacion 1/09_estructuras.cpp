#include <iostream>
using namespace std;

struct Persona
{
    string nombre;
    int edad;
    float altura;
    bool TienePareja;
};

int main()
{
    Persona p1, p2;
    p1.nombre = "Keyner";
    p2.nombre = "Andres";
    cout << "El nombre de p1 es " << p1.nombre << endl;
    cout << "El nombre de p2 es " << p2.nombre << endl;
    cout << "------------------------------------\n";
    p2 = p1;
    cout << "se copiaron los datos del p1 al p2\n";
    cout << "El nombre de p1 es " << p1.nombre << endl;
    cout << "El nombre de p2 es " << p2.nombre << endl;

    return 0;
}


