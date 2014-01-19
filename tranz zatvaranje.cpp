#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Unesite dimenziju matrice(n): ";
    cin >> n;
    int matrica[n][n];
    int pomocnaMat[n][n];
    cout << "Unesite pocetnu matricu: " << endl;
    cout << "------------------------" << endl;
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                    cout << "[" << i << "][" << j << "]= ";
                    cin >> pomocnaMat[i][j];
            }
    }
    for(int k=0;k<n;k++)
    {
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                            matrica[i][j] = pomocnaMat[i][j] || (pomocnaMat[i][k] && pomocnaMat[k][j]);
                    }
            }
            //pomocnaMat = matrica
            for(int i=0;i<n;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                            pomocnaMat[i][j] = matrica[i][j];
                    }
            }
    }
    //Ispis rezultatne matrice
    cout << endl;
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                    cout << matrica[i][j] << " ";
            }
            cout << endl;
    }
    system("pause");
    return 0;
}
