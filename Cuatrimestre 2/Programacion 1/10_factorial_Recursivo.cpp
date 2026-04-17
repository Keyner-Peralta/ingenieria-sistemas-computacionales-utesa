#include <iostream>
using namespace std;

int factorial(int num)
{
    if(num == 0)
        return 1;
    else
        return num * factorial(num - 1);
}

int main()
{
    int num;
    cin >> num;
    cout << "El factorial de " << num << "!: " << factorial(num);
    return 0;
}
