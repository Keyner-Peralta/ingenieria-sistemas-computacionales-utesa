#include <iostream>
using namespace std;
int factorial(int num)
{
    int result = 1;

    for(int i = 2; i <= num; i++)
        result *= i;

    return result;
}
int main()
{
    int num;
    cin >> num;
    cout << "el factorial de " << num << "! : " << factorial(num);
    return 0;
}
