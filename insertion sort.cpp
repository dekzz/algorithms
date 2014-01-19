#include <iostream>
using namespace std;

void insertionSort(int field[], int size)
{
     int i, j, v;
     
     for(i = 1; i < size; i++)
     {
         v = field[i];
         j = i-1;
         while((j >= 0) && (field[j] > v))
         {
             field[j+1] = field[j];
              j -= 1;
         }
         field[j+1] = v;
     }
}

int main()
{
    int N;
    cout << "Number of elements: ";
    cin >> N;
    int array[N];

    cout << "Enter the elements: " << endl;
    for(int i = 0; i < N; i++)
    {
            cin >> array[i];
    }
    
    insertionSort(array, N);
    
    cout << "Sorted: " << endl;
    for(int i = 0; i < N; i++)
            cout << array[i] << endl;
    
    system("pause");
    return 0;
}
