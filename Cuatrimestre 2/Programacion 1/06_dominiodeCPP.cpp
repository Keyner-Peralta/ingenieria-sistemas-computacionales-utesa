#include <iostream>
#include <cstring>
#include <string>
#include <clocale>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    string c1 = "HOLA";
    string c2 = "HOLAmundo";
    bool sonIguales = (c1 == c2);
    bool c1EsMayor = (c1 > c2);
    bool c2EsMenor = (c1 < c2);
    cout << "Son iguales: " << sonIguales <<endl;
    cout << "c1 es mayor: " << c1EsMayor <<endl;
    cout << "c2 es mayor: " << c2EsMenor <<endl;
    cout <<"-------------------------------------\n";
    setlocale(LC_ALL, "spanish");
    cout << "Ahora podemos usar tíldes. Esto es increíble ¿? ñ\n";
    cout <<"-------------------------------------\n";
    srand(time(NULL));
    int numeroAleatorio = rand();
    cout << numeroAleatorio << endl;
    return 0;
}
