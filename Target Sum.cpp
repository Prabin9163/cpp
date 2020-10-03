#include<bits/stdc++.h>
using namespace std;

  int dp[21][2001];
   int solve(int pos, vector <int> v, int tempSum, int s){
      if(pos == v.size()){
         return s == tempSum;
      }
      if(dp[pos][tempSum+1000]!=-1)return dp[pos][tempSum+1000];
      int ans = solve(pos+1,v,tempSum-v[pos],s) +solve(pos+1,v,tempSum+v[pos],s);
      dp[pos][tempSum+1000] = ans;
      return ans;
   }
   int findTargetSumWays(vector<int>& nums, int s) {
      int n = nums.size();
      if(s>1000)return 0;
      for(int i =0;i<21;i++){
         for(int j =0;j<2001;j++){
            dp[i][j] = -1;
         }
      }
      return solve(0,nums,0,s);
   }

int main()
{
	int s;
  cout<<"Enter the target number: ";
	cin>>s;
  int n;
  cout<<"Enter the size of array: ";
	cin>>n;
	vector<int> arr(n);
  cout<<"Enter the array values: ";
	for(int i=0; i<n; i++)
		cin>>arr[i];
	cout<<findTargetSumWays(arr,s)<<endl;
	return 0;
}
