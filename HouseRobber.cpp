#include <iostream>
#include <vector>
using namespace std;

int currentMoney(int k,vector<int> &nums,vector<int> &dp){
    if(k<0){
        return 0;
    }else if(k==0 || k==1){
        return nums[k];
    }
    if(dp[k]==-1){
        dp[k] = max(currentMoney(k-2,nums,dp),currentMoney(k-3,nums,dp)) + nums[k];
    }
    return dp[k];
}

int rob(vector<int>& nums){
    int n = nums.size();
    vector<int>dp(n,-1);
    int result = max(currentMoney(n-1,nums,dp),currentMoney(n-2,nums,dp)); 
    return result; 
}

void testCase(vector<int> nums){
    int result = rob(nums);
    cout<<result<<endl;
}

int main(){
    testCase({1,2,3,1});
    testCase({2,7,9,3,1});
    return 0;
}