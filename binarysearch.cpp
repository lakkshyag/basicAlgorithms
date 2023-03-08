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

int search(int arr[], int n, int x)
{
	int si=0;
	int ei=n-1;

	while (si<=ei)
	{
		int mid=(si+ei)/2;

		if (arr[mid]==x)
		{
			return mid;
		}

		else if (arr[mid]<x)
		{
			si=mid+1;
		}

		else 
		{
			ei=mid-1;
		}
	}

	return -1;
}

int searchRec(int arr[], int si, int ei, int x)
{
	if (si>ei)
	{
		return -1;
	}

	int mid=(si+ei)/2;
	
	if (arr[mid]==x)
	{
		return mid;
	}

	else if (arr[mid]<x)
	{
		return searchRec(arr, mid+1, ei, x);
	}

	else
	{
		return searchRec(arr, si, mid-1, x);
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[100];
	arrayCreate(arr, n);

	int x;
	cin>>x;
	cout<<search(arr, n, x)<<" "<<searchRec(arr, 0, n-1, x)<<endl;


	return 0;
}

