#include <iostream>
using namespace std;

int Luhn(char *BrKart, int n)
{
   int temp=0;
   int sum=0;
   bool alt = true;
   for(int i=n-1; i>=0; i--)
   {
     temp=BrKart[i]-'0';
     if(alt)
     {
       temp*=2;
       if(temp>9)
       {
         temp-=9;
       }
     }
     sum+=temp;
     alt=!alt;
   }
   sum%=10;
   if(sum!=0)
      sum=10-sum;
   
   return sum;
}

int LuhnValid(char *BrKart, int n)
{
   int temp=0;
   int sum=0;
   bool alt = false;
   for(int i=n-1; i>=0; i--)
   {
     temp=BrKart[i]-'0';
     if(alt)
     {
       temp*=2;
       if(temp>9)
       {
         temp-=9;
       }
     }
     sum+=temp;
     alt=!alt;
   }
   
   return (sum%10==0);
}

int main()
{
    int N, x;
    
        cout << "==================================" << endl;
        cout << "1. Racunanje kontrolnog broja" << endl;
        cout << "2. Provjera valjanosti kartice" << endl;
        cout << "0. Izlaz" << endl;
        cout << "==================================" << endl;
        cin >> x;
        cout << endl;
    
        if(x == 1)
        {
           cout << "Broj znamenaka: ";
           cin >> N;
           int M=N+1;
    
           char BrKart[M];
    
           cout << "Broj kartice: ";
           cin.ignore();
           cin.getline(BrKart, M);
           
           int contBr = Luhn(BrKart, N);
    
           cout << "Kontrolni broj kartice: " << contBr << endl;
           cout << "Potpuni broj kartice:" << BrKart  << contBr << endl << endl;
         }
    
        if(x == 2)
        {
           cout << "Broj znamenaka: ";
           cin >> N;
           int M=N+1;
    
           char BrKart[M];
    
           cout << "Broj kartice: ";
           cin.ignore();
           cin.getline(BrKart, M);
           
           if(LuhnValid(BrKart, N) == 1)
              cout << "Kartica " << BrKart << " je vazeca!" << endl << endl;
           else 
              cout << "Kartica " << BrKart <<  " je nevazeca!" << endl << endl;
         }
         
    system("pause");
    return 0;
}
