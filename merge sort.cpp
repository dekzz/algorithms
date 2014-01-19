#include <iostream>
using namespace std;

int max(int x, int y)
{
    if(x > y)
         return x;
    else
        return y;
}

void mergeHelp(int *input, int left, int right, int *temp)
{
     if(right == left + 1)
              return;
     else
     {
         int i = 0;
         int lenght = right - left;
         int mid = lenght/2;
         int l = left, r = left + mid;
         
         mergeHelp(input, left, left + mid, temp);
         mergeHelp(input, left + mid, right, temp);
         
         for(i = 0; i < lenght; i++)
         {
                 if(l < left + mid && (r == right || max(input[l], input[r]) == input[l]))
                 {
                      temp[i] = input[l];
                      l++;
                 }
                 else
                 {
                     temp[i] = input[r];
                     r++;
                 }
         }
         for(i = left; i < right; i++)
               input[i] = temp[i - left];
     }
}

int mergeSort(int *input, int size)
{
    int *temp = new int(size*sizeof(int));
    if(temp != NULL)
    {
            mergeHelp(input, 0, size, temp); 
            delete temp;
            return 1;
    }
    else
        return 0;
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
    
    mergeSort(array, N);
    
    cout << "Sorted: " << endl;
    for(int i = 0; i < N; i++)
            cout << array[i] << endl;
    
    system("pause");
    return 0;
}
