#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int d[6], r[6]={0,0,0,0,0,0}, retValue, i=0;
    d[0] = 50;
    d[1] = 20;
    d[2] = 10;
    d[3] = 5;
    d[4] = 2;
    d[5] = 1;
    
    cout << "Return value? : ";
    cin >> retValue;
    
    while(retValue!=0)
    {
       while(i < 6)
       {
          if(retValue >= d[i])
          {
             retValue = retValue - d[i];
             r[i]++;
          }
          else i++;
       }
    }
    cout << "Return: ";
    for(int i=0; i<6; i++)
    {
        if(r[i]!=0)
        {
           cout << r[i] << "x" << d[i] << " + ";
        }
    }
    
    cout << endl;
    system("pause");
    return 0;
}
