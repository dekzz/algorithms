#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cout << "NAPOMENA: n > k > 0" << endl;
    cout << "-------------------" << endl;
    cout << "Unesite n: ";
    cin >> n;
    cout << "Unesite k: ";
    cin >> k;
    int polje[n][n];
    for(int i=0;i<=n;i++)
    {
            for(int j=0;j<=i;j++)
            {
                    if(j==0 || j==i) polje[i][j] = 1;
                    else polje[i][j] = polje[i-1][j-1] + polje[i-1][j];
            }
    }
    cout << "Binomni koeficijent za uneseni n i k: ";
    cout << polje[n][k] << endl;
    system("pause");
    return 0;
}
