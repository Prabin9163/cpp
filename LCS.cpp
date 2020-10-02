#include<iostream>
#include<cstring>

#define M  1001
using namespace std;

int t[M][M];

int LCS(string s1, string s2, int m, int n)
{
	//Initialization
	for(int i=0; i<M; i++)
	{
		t[i][0] = 0;
		t[0][i] = 0;
	}
	//Choice Diagram
	for(int i=1; i<m+1; i++)
	{
		for(int j=1; j<n+1; j++)
		{
			if(s1[i-1]==s2[j-1])
				t[i][j] = t[i-1][j-1] + 1;
			else
				t[i][j] = max(t[i-1][j],t[i][j-1]);
		}
	}
	return t[m][n];
}

int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;
	int m = s1.size();
	int n = s2.size();
	memset(t,0,sizeof(t));
	cout<<LCS(s1,s2,m,n)<<endl;
	return 0;
}
