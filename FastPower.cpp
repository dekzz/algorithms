#include <iostream>
using namespace std;

int FastPower(int n, int pow)
{
    if(pow == 1)
           return n;
    else
    {
        int x = FastPower(n, pow/2);
        if(pow%2)
                 return x*x*n;
        else
            return x*x;
    }
}

int main()
{
    int n, pow;
    
    cout << "Number: ";
    cin >> n;
    cout << "Power of: ";
    cin >> pow;
    
    cout << FastPower(n, pow) << endl;
    
    system("pause");
    return 0;
}
