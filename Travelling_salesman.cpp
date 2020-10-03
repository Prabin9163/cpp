#include<iostream>
 
using namespace std;
 
int a[100][100],seen[10],n,cost=0;
 

int least_cost(int v)
{
	int i,nc=9999;
	int min=9999,k_min;
 
	for(i=0;i < n;i++)
	{
		if((a[v][i]!=0)&&(seen[i]==0))
			if(a[v][i]+a[i][v] < min)
			{
				min=a[i][0]+a[v][i];
				k_min=a[v][i];
				nc=i;
			}
	}
 
	if(min!=999)
		cost+=k_min;
 
	return nc;
}
 
void min_cost(int node)
{
	int i,ncity;
 
	seen[node]=1;
 
	cout<<node+1<<"--->";
	ncity=least_cost(node);
 
	if(ncity==999)
	{
		ncity=0;
		cout<<ncity+1;
		cost+=a[node][ncity];
 
		return;
	}
 
	min_cost(ncity);
}
 
int main()
{
	int i,j;
 
	cout<<"Enter the number of vertices: ";
	cin>>n;
 
	cout<<"\nEnter the Cost Matrix\n";
 
	for(i=0;i < n;i++)
	{
		cout<<"\nEnter Elements of Row: "<<i+1<<"\n";
 
		for( j=0;j < n;j++)
			cin>>a[i][j];
 
		seen[i]=0;
	}
 
	cout<<"\n\nThe cost Matrix is:";
 
	for( i=0;i < n;i++)
	{
		cout<<"\n";
 
		for(j=0;j < n;j++)
			cout<<"\t"<<a[i][j];
	}
 
	cout<<"\n\nThe Path is:\n";
	min_cost(0); //0-based index
 
	cout<<"\n\nMinimum cost is "<< cost;
 
	return 0;