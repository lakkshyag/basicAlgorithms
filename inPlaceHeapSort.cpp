#include <iostream>
using namespace std;

void arrayCreate(int* arr, int const &n)
{
    int i = 0;
    while ( i <= n-1 )
    {
        cin>>*(arr+i);
        i++;
    }
}

void arrayPrint(int* arr, int const &n)
{
    int i = 0;
    while ( i <= n-1 )
    {
        cout<<*(arr+i)<<" ";
        i++;
    }
}

void heapInsert(int* arr, int ei)
{
    int childIndex = ei;

    while ( childIndex )
    {
        int parentIndex = (childIndex - 1)/2;
        if ( arr[childIndex] < arr[parentIndex] )
        {
            int temp = arr[childIndex];
            arr[childIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
        }
        else
        {
            break;
        }
        childIndex = parentIndex;
    }
}

void heapRemove(int* arr, int ei)
{
    int temp = arr[0];
    arr[0] = arr[ei];
    arr[ei] = temp;
    ei--;
    
    int i = 0;            
    while ( i <= ei )
    {
        int minIndex = i;
        int leftChildI = 2*i + 1;
        int rightChildI = 2*(i + 1);

        if ( (leftChildI <= ei) && (arr[leftChildI] < arr[minIndex]) )
        {
            minIndex = leftChildI;
        }
        if ( (rightChildI <= ei) && (arr[rightChildI] < arr[minIndex]) )
        {
            minIndex = rightChildI;
        }   
        if ( minIndex == i )
        {
            break;
        }
        
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
            
        i = minIndex;
    }
}

void heapSort(int* arr, int const &n)
{
    int i = 0;
    while ( i <= n-1 )
    {
        heapInsert(arr, i);
        i++;
    }

    i = n-1;
    while ( i >= 1 )
    {
        heapRemove(arr, i);
        i--;
    }

}

int main()
{
    int n;
    cin>>n;
    int* arr = new int[n];
    arrayCreate(arr , n);
    heapSort(arr, n);
    arrayPrint(arr, n);



    delete[] arr;
    return 0;
}