// Programa que lee dos valores y da como resultado la Suma
#include <iostream>
int A,B,C;
int main(){
    std::cout << "Programador: Keyner Peralta" << std::endl;
    std::cout << "Matricula: xxxxxxxx" << std::endl;
    std::cout << "======== Programa sumador de valores ========" << std::endl;
    std::cout << "Digite 1er valor : ";
    std::cin >> A;
    std::cout << "Digite 2do Valor : ";
    std::cin >> B;
    C = A + B;
    std::cout << "La suma es : " << C << std::endl;
    std::cout << "=============================================" << std::endl;
    return 0;
}