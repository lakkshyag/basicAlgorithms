#include <iostream>
using namespace std;

void arrayCreate(int* arr, int const &n)
{
  int i=0;
  while (i<=n-1)
  {
    cin>>*(arr+i);
    i++;
  }
}

void arrayPrint(int* arr, int const &n)
{
  int i=0;
  while (i<=n-1)
  {
    cout<<*(arr+i)<<" ";
    i++;
  }
  cout<<endl;
}

int count(int* arr, int const &si, int const &ei)
{
  int count=0;
  int i=si;

  while (i<=ei)
  {
    if ( *(arr+i) < *(arr+si) )
    {
      count++;
    }
    i++;
  }
  return count;
}

void shift(int* arr, int const &si, int const &ei, int const &pvt)
{
  int i=si;
  int j=pvt+1;

  while ( i < pvt )
  {
    if ( *(arr+i) >= *(arr+pvt) )
    {
      while ( j <= ei )
      {
        if ( *(arr+j) < *(arr+pvt) )
        {
          int temp = *(arr+i);
          *(arr+i) = *(arr+j);
          *(arr+j) = temp;
        }
        j++;
      }
    }
    i++;
  }
}

void quickSort(int* arr, int si, int ei)
{
  if (si>=ei)
  {
    return;
  }

  int pvt = si + count(arr, si, ei);
  
  if ( pvt != si )
  {
    int temp = *(arr+pvt);
    *(arr+pvt) = *(arr+si);
    *(arr+si) = temp;
  }

  shift(arr, si, ei, pvt);
  quickSort(arr, si, pvt-1);
  quickSort(arr, pvt+1, ei);
}

int main()
{
  int n;
  cin>>n;

  int* arr = new int[n];
  arrayCreate(arr, n);
  quickSort(arr, 0, n-1);
  arrayPrint(arr, n);



 // cout<<count(arr, 1, n-2);
  delete []arr;
  return 0;
}
