#include <iostream>
#include <cstdlib>
using namespace std;

void FakeCoin(int coins[], int N)
{
     int sum1, sum2;
     if((N%2) == 0)
     {
         int c1[N/2], c2[N/2];
         
         for(int i = 0; i < (N/2); i++)
         {
             c1[i] = coins[i];
             c2[i+(N/2)] = coins[i+(N/2)];
             
             sum1 += c1[i];
             sum2 += c2[i+(N/2)];
         }
         
         if(sum1 > sum2)
             FakeCoin(c2, (N/2));
         else
             FakeCoin(c1, (N/2));
     }
     
     else
     {
         int N = N-1;
         int c1[N/2], c2[N/2];
         
         for(int i = 0; i < (N/2); i++)
         {
             c1[i] = coins[i];
             c2[i+(N/2)] = coins[i+(N/2)];
             
             sum1 += c1[i];
             sum2 += c2[i+(N/2)];
         }
         
         if(sum1 > sum2)
             FakeCoin(c2, (N/2));
         if(sum1 < sum2)
             FakeCoin(c1, (N/2));
         if(sum1 == sum2)
             cout << "Coin found!" << endl;
     }
}

int main()
{
    int x, n;
    
    cout << "Number of coins: ";
    cin >> n;
    
    int coins[n];
    srand(time(NULL));
    x = rand()%n;
    
    for(int i = 0; i < n; i++)
    {
        coins[i] = 1;
    }
    
    coins[x] = 0;
    
    FakeCoin(coins, n);
    
    system("pause");
    return 0;
}
