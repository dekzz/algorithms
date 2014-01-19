#include <iostream>
using namespace std;

int main()
{
    int N, temp, beg, end, mid, target;
    cout << "Number of elements: ";
    cin >> N;
    int array[N];

    cout << "Enter the elements: " << endl;
    for(int i = 0; i < N; i++)
    {
            cin >> array[i];
    }
    
    for(int i = 0; i < N-1; i++)
    {
       for(int j = 0; j < N-i-1; j++)
       {
           if(array[j+1] < array[j])
           {
               temp = array[j];
               array[j] = array[j+1];
               array[j+1] = temp;
           }
       }
    }
    
    cout << "Sorted: " << endl;
    for(int i = 0; i < N; i++)
            cout << array[i] << endl;
            
    beg = 0;
    end = N;
    mid = (beg+end)/2;
    
    cout << "Search for number: ";
    cin >> target;
    
    while((beg <= end) && (array[mid] != target))
    {
        if(target < array[mid])
        {
            end = mid - 1;
            mid = (beg+end)/2;
        }
        else
        {
            beg = mid + 1;
            mid = (beg+end)/2;
        }
    }
    
    if(array[mid] == target)
        cout << "Nuber found!" << endl;
    else
        cout << "Number not found!" << endl;
    
    system("pause");
    return 0;
}
