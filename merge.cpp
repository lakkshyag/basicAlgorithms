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

void merge(int arr1[], int arr2[], int n1, int n2, int arr[])
{
	int i=0, i1=0, i2=0;
	while (i1<=n1-1 && i2<=n2-1)
	{
		if (arr1[i1] <= arr2[i2])
		{
			arr[i]=arr1[i1];
			i1++;
		}
		else
		{
			arr[i]=arr2[i2];
			i2++;
		}
		i++;
	}

	while (i1<=n1-1)
	{
		arr[i]=arr1[i1];
		i++;
		i1++;
	}
	while (i2<=n2-1)
	{
		arr[i]=arr2[i2];
		i++;
		i2++;
	}
}

void mergeRec(int arr1[], int arr2[], int n1, int n2, int arr[])
{
	if (n1==0 && n2==0)
	{
		return;
	}

	if (n1>=1 && n2>=1)
	{
		if (arr1[0] <= arr2[0])
		{
			arr[0]=arr1[0];
			mergeRec(arr1+1, arr2, n1-1, n2, arr+1);
		}
		else
		{
			arr[0]=arr2[0];
			mergeRec(arr1, arr2+1, n1, n2-1, arr+1);
		}
	}
	else
	{
		if (n1>=1)
		{
			arr[0]=arr1[0];
			mergeRec(arr1+1, arr2, n1-1, n2, arr+1);
		}
		if (n2>=1)
		{
			arr[0]=arr2[0];
			mergeRec(arr1, arr2+1, n1, n2-1, arr+1);
		}
	}
}

int main()
{
	int n1;
	cin>>n1;
	int arr1[100];

	arrayCreate(arr1, n1);

	int n2;
	cin>>n2;
	int arr2[100];

	arrayCreate(arr2, n2);

	int arr[200];
	mergeRec(arr1, arr2, n1, n2, arr);
	arrayPrint(arr, n1+n2);


	return 0;
}
