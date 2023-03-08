
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
	int i = 1;
	
	while (i <= n-1)
	{
		int j = i;

		while (j >= 1 && arr[j] < arr[j-1])
		{
			int temp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = temp;

			j--;
		}

		i++;
	}
}

void sortRec(int arr[], int n, int i, int j)
{
	if (i==n)
	{
		return;
	}
	
	if (arr[j] < arr[j-1] && j >=1 )
	{
		int temp = arr[j];
		arr[j] = arr[j-1];
		arr[j-1] = temp;
		
		sortRec(arr, n, i, j-1);
	}

	else if (j==0 || arr[j] >= arr[j-1])
	{
		sortRec(arr, n, i+1, i+1);
	}
		
}

int main()
{
	int n;
	cin>>n;
	int arr[100];

	arrayCreate(arr, n);
	sortRec(arr, n, 1, 1);
	arrayPrint(arr, n);



	return 0;
}
