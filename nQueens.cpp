#include <iostream>
using namespace std;

bool diag(int n, int r, int s, int sol[])
{
     bool res = true;
     for (int s1=0; s1<n; s1++)
     { 
         if ((sol[s1]!=-1) &&(s1-s==sol[s1]-r))
         {
            res=false;
            break;
         }
         if ((sol[s1]!=-1) && (s1-s==r-sol[s1]))
         {
            res=false;
            break;
         }
     }
     return res;
}

void print(int n, int sol[]) 
{   
    for(int i=0; i<=n*8; i++)
            cout <<"-";
    cout<< endl;
    for (int r=0; r<n;r++)
    {
         for (int s=0; s<n; s++)
         {
             if (sol[s]!=r) cout << "|\t|";
             else cout << "| o\t|"; 
         }
         cout << endl; 
    }   
    for(int i=0; i<=n*8; i++)
            cout <<"-";
    cout << "\n\n\n";
}


void Queens(int n, int r, int sol[])
{
     for (int s=0; s<n; s++) 
         if ((sol[s]==-1) && diag(n,r,s,sol))
         {
            sol[s]=r;
            if (r==n-1)
            {
               print(n,sol);
            }
            else
            {
                Queens(n,r+1,sol);
            }
            sol[s]=-1;
         }
}


int main()
{
    int n;
    
    cout << "Unesite broj kraljica: ";
    cin >> n;
    
    int sol[n];
    for (int i=0; i<n; i++)
        sol[i]=-1;
    
    Queens(n,0,sol);
    
    system("pause");
    return 0;
}
