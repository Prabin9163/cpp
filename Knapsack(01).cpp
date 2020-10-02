#include<bits/stdc++.h>
#define M 1001
using namespace std;

int t[M][M];   //for the size of the array look at constraints

int max(int a, int b)
{
	return (a>b?a:b);
}

int Knapsack(vector<int> &wt, vector<int> &val, int n, int w)
{
	//Initialization filling 0 in 1st row and 1st column
	for(int i=0; i<M; i++)       
	{                            
		for(int j=0; j<M; j++)   
		{                         
			if(i==0||j==0)       
				t[i][j] = 0;
		}
	}                            
	//Choice diagram
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<w+1; j++)
		{
			if(wt[i-1]<=j)
				t[i][j] = max(t[i-1][j],(val[i-1] + t[i-1][j-wt[i-1]]));
			else
				t[i][j] = t[i-1][j];
		}
	}
	return t[n][w];
}

int main()
{
	int n,w;
	cin>>n>>w;
	vector<int> wt(n);
	vector<int> val(n);
	for(int i=0; i<n; i++)
		cin>>wt[i];
	for(int i=0; i<n; i++)
		cin>>val[i];
	cout<<Knapsack(wt,val,n,w);
	return 0;
}
