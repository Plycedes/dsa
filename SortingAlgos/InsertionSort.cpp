#include <bits/stdc++.h>

using namespace std;

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{		
		j = i;

		while (j >= 0 && arr[j-1] > arr[j] )
		{
			swap(arr[j], arr[j-1]);
			j = j - 1;
		}		
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int N = sizeof(arr) / sizeof(arr[0]);

    cout<<endl<<"Unsorted Array:";
    printArray(arr, N);
    cout<<endl<<"Sorted Array:";
	insertionSort(arr, N);
	printArray(arr, N);
    cout<<endl;
	return 0;
}