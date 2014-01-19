#include <iostream>
using namespace std;

void qSort(int num[], int left, int right)
{
     int pivot, l_hold, r_hold;
     
     l_hold = left;
     r_hold = right;
     pivot = num[left];
     while(left < right)
     {
         while((num[right] >= pivot) && (left < right))
             right--;
         
         if(left != right)
         {
              num[left] = num[right];
              left++;
         }
         
         while((num[left] <= pivot) && (left < right))
              left++;
         
         if(left != right)
         {
               num[right] = num[left];
               right--;
         }
     }
     
     num[left] = pivot;
     pivot = left;
     left = l_hold;
     right = l_hold;
     
     if (left < pivot)
        qSort(num, left, pivot-1);
     
     if (right > pivot)
        qSort(num, pivot+1, right);
}

void quickSort(int num[], int size)
{
     qSort(num, 0, size-1);
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
    
    quickSort(array, N);
    
    cout << "Sorted: " << endl;
    for(int i = 0; i < N; i++)
            cout << array[i] << endl;
    
    system("pause");
    return 0;
}
