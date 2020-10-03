/**
 https://www.youtube.com/watch?v=XiuSW_mEn7g
 This link will help you get an idea of radix sort very quickly.
 
 Counting sort initially, sorts the entire array based on the units place.
 Then, using this units sorted array, we compare the tens place and resort.
 Then, this procedure is continued till we have gone through all weights of numbers.
 Hope this helps!
 
 INPUT: 53 89 150 36 63 633 233
 
 Sort 1: 150 53 633 233 36 89
 Sort 2: 633 233 36 150 53 89
 Sort 3: 36 53 89 150 233 633
 
 Works well when range of input is limited.
 * */



#include <bits/stdc++.h> 
using namespace std;

int getMax(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

void countSort(int a[], int n, int exp)
{
	int output[n], i, count[10] = {0};

	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i-1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		a[i] = output[i];
}

void radixsort(int a[], int n)
{
	int exp, m;
	m = getMax(a, n);

	for (exp = 1; m/exp > 0; exp *= 10)
		countSort(a, n, exp);
}

int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;

	int a[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>a[i];
	}

	radixsort(a, n);

	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
		cout<<a[i]<<" ";
	return 0;
}

