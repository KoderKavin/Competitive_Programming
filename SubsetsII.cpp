#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void myFunc(vector<int> &nums,vector<vector<int>> &ans,vector<int>subset,int i){
    if(i==nums.size()){
        ans.push_back(subset);
        return;
    }


    subset.push_back(nums[i]); //inclusion step
    myFunc(nums,ans,subset,i+1); //next level call

    subset.pop_back();//backtracking
    int idx = i+1;
    if(idx!=nums.size()){
        while(nums[i]==nums[idx]){
            idx++;
            if(idx==nums.size()){
                break;
            }
        }
    }
    myFunc(nums,ans,subset,idx);//exclusion after skipping repeated values


}

vector <vector<int>> subsetsWithDup(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> subset = {};
    sort(nums.begin(),nums.end());
    myFunc(nums,ans,subset,0);
    return ans;
}

void testCase(vector<int> nums){
    vector<vector<int>> ans = subsetsWithDup(nums);
    for(vector<int> val:ans){
        cout<<"[ ";
        for(int val1: val){
            cout<<val1<<" ";
        }
        cout<<"], ";
    }
    cout<<"\n";
}

int main(){
    testCase({1,2,2});
    testCase({1});
    testCase({0});
    testCase({1,1});
    return 0;
}