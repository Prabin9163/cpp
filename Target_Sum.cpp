#include<iostream>
#define size 5
using namespace std;

int ctr()
{
    static int count = -1;
    count ++;
    return count;
}

void calculate(int nums[], int i, int sum, int S) {
    
        if (i == size) {
            if (sum == S)
                ctr();
        } else {
            calculate(nums, i + 1, sum + nums[i], S);
            calculate(nums, i + 1, sum - nums[i], S);
        }
    }

int findTargetSumWays(int nums[], int S) {
        calculate(nums, 0, 0, S);
        return ctr();
    }

int main()
{
    int nums[size]={1,1,1,1};
    int S = 3;
    

    cout<<"Number of ways are : "<<findTargetSumWays(nums, S);
}