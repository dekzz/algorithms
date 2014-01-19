#include <iostream>
using namespace std;

int fibonacci (int n)
{
    if (n<=1)
       return n;
    
    else
        return (fibonacci(n-1)+fibonacci(n-2));
}

int main()
{
    int num;
    
    do
    {
        cout << "Enter a number (1-25): ";
        cin >> num;
    } while(num > 25);
    
    cout << num << "th number of Fibonacci series is " << fibonacci(num) << endl;
    
    system("pause");
    return 0;
}
