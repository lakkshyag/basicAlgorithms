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
	int i=0;
	while (i<=n-2)
	{
		int j=i+1;
		int minI=i;

		while (j<=n-1)
		{
			if (arr[j]<arr[minI])
			{
				minI=j;
			}
			j++;
		}

		if (minI!=i)
		{
			int temp=arr[i];
			arr[i]=arr[minI];
			arr[minI]=temp;
		}
		i++;
	}

}

int minRec(int arr[], int n, int i)
{
	if (i==n-1)
	{
		return i;
	}

	int j = minRec(arr, n, i+1);
	
	if (arr[i]<arr[j])
	{
		return i;
	}
	else
	{
		return j;
	}

}

void sortRec(int arr[], int n)
{
	if (n==0)
	{
		return;
	}
	int i = minRec(arr, n, 0);

	int temp=arr[i];
	arr[i]=arr[0];
	arr[0]=temp;

	sortRec(arr+1, n-1);
}

int main()
{
	int n;
	cin>>n;
	int arr[100];
	
	arrayCreate(arr, n);
	sortRec(arr, n);
	arrayPrint(arr, n);

	
	return 0;
}
