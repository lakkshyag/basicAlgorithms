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

void merge(int* arr, int const &si, int const &ei)
{
	int mid = (si+ei)/2;
	int i=si;
	int j=mid+1;

	int* arrTemp = new int[ei-si+1];
	int iTemp = 0;

	while ( i<= mid && j<= ei )
	{
		if ( *(arr+i) <= *(arr+j) )
		{
			*(arrTemp+iTemp) = *(arr+i);
			i++;
			iTemp++;
		}
		else
		{
			*(arrTemp+iTemp) = *(arr+j);
			j++;
			iTemp++;
		}
	}
	
	while (i<=mid)
	{
		*(arrTemp+iTemp) = *(arr+i);
		i++;
		iTemp++;
	}
	while (j<=ei)
	{
		*(arrTemp+iTemp) = *(arr+j);
		j++;
		iTemp++;
	}
	
	iTemp=0;
	i=si;

	while (i<=ei)
	{
		*(arr+i) = *(arrTemp+iTemp);
		i++;
		iTemp++;
	}

	delete [] arrTemp;
}

void mergeSort(int* arr, int si, int ei)
{
	if (si>=ei)
	{
		return;
	}
	int mid = (si+ei)/2;

	mergeSort(arr, si, mid);
	mergeSort(arr, mid+1, ei);

	merge(arr, si, ei);
}

int main()
{
	int n;
	cin>>n;

	int* arr = new int[n];
	arrayCreate(arr, n);
	mergeSort(arr, 0, n-1);
	arrayPrint(arr, n);

	delete [] arr;

	return 0;
}
