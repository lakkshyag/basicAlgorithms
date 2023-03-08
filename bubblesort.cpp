#include <iostream>
using namespace std;

void arrayCreate(int arr[], int n)
{
	int i=0;
	while (i<=n-1)
	{
		cin>>arr[i];
		i++;
	}
}

void arrayPrint(int arr[], int n)
{
	int i=0;
	while (i<=n-1)
	{
		cout<<arr[i]<<" ";
		i++;
	}
	cout<<endl;
}

void sort(int arr[], int n)
{
	while (n>=1)
	{
		int i=0;
		while (i<=n-2)
		{	
			if (arr[i]>arr[i+1])
			{
				int temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
			i++;
		}
		n--;
	}
}

void sortRec(int arr[], int n, int i)
{	
	if (n==1)
	{
		return;
	}

	if (i==n-1)
	{
		sortRec(arr, n-1, 0);
	}

	else if (arr[i]>arr[i+1])
	{
		int temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = temp;
		sortRec(arr, n, i+1);
	}

	else
	{
		sortRec(arr, n, i+1);
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[100];

	arrayCreate(arr, n);
	sortRec(arr, n, 0);
	arrayPrint(arr, n);


	return 0;
}
