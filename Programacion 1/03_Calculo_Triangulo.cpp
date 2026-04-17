//Programador: Keyner Peralta 
//Matrícula: xxxxxxxxx
//Programa que calcula el área de un triángulo

#include <iostream>
using namespace std;

float area, base, altura;
int main()
{

    cout << "=============================================================" << endl;
    cout << "|||          Universidad Tecnologica de Santiago          |||" << endl;
    cout << "=============================================================" << endl;
    cout << "===**************[ Datos del Programador ]****************===" << endl;
    cout << "===                                                       ===" << endl;
    cout << "|||\t Carrera: Ingenieria en Sistemas Computacionales  |||" << endl;
    cout << "|||\t Nombre: Keyner Peralta                           |||" << endl;
    cout << "|||\t Matricula: xxxxxxxxx                             |||" << endl;
    cout << "|||\t Fecha: Febrero, 2026                             |||" << endl;
    cout << "===                                                       ===" << endl;
    cout << "=============================================================" << endl;
    cout << "===*******[ Calculadora del area de un triangulo ]********===" << endl;
    cout << "=============================================================" << endl;
    cout << " \t Digite la base de su triangulo: "; cin >> base;
    cout << " \t Digite la altura de su triangulo: "; cin >> altura;
    area = base * altura / 2;
    cout << "=============================================================" << endl;
    cout << "\t Resultado: " <<  area << endl;
    cout << "=============================================================" << endl;
    return 0;
}

