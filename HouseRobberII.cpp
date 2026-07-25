#include <iostream>
#include <vector>

using namespace std;

int curr(vector<int> &nums,int k,vector<int> &dp){
    if(k<0){
        return 0;
    }
    if(dp[k]!=-1){
        return dp[k];
    }
    if(k==0 || k==1){
        return nums[k];
    }
    dp[k] = max(curr(nums,k-2,dp),curr(nums,k-3,dp)) + nums[k];
    return dp[k];
}

int rob(vector<int> &nums){
    int n = nums.size();
    if(n==1){
        return nums[0];
    }
    vector<int> dp(n,-1);
    int n1 = curr(nums,n-2,dp);
    int n2 = curr(nums,n-3,dp);
    vector<int> temp(n,-1);
    dp = temp;
    dp[0] = 0;
    int n0 = curr(nums,n-1,dp);
    vector<int> temp1 = {n0,n1,n2};
    int max = n0;
    for(int val:temp1){
        if(val>max){
            max = val;
        }
    }
    return max;
}

void testCase(vector<int> nums){
    int result = rob(nums);
    cout<<result<<endl;
}

int main(){
    testCase({2,3,2});
    testCase({1,2,3,1});
    testCase({1,2,3});
    return 0;
}