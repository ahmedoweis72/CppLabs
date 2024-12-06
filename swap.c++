#include <iostream>
using namespace std;
void swap(int *num1, int *num2)
{
    int temp = 0;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void swap(int &num1, int &num2)
{
    int temp = 0;
    temp = num1;
    num1 = num2;
    num2 = temp;
}
int main()
{
    int num1 = 5, num2 = 10;
    // swap(&num1, &num2);
    // swap(num1, num2);
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    cout << num1 << "Num1" << endl;
    cout << num2 << "Num2" << endl;
}