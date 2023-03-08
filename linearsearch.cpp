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
	int i=0;
	while (i<=n-1)
	{
		if (arr[i]==x)
		{
			return i;
		}
		i++;
	}

	return -1;
}

int searchRec(int arr[], int n, int x)
{
	if (n==0)
	{
		return -1;
	}

	if (arr[0]==x)
	{
		return 0;
	}

	
	if (searchRec(arr+1, n-1, x) == -1)
	{
		return searchRec(arr+1, n-1, x);
	}
	else
	{
		return searchRec(arr+1, n-1, x) + 1;
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
	cout<<search(arr, n, x)<<" "<<searchRec(arr, n, x)<<endl;


	return 0;
}
