#include <iostream>
#include <vector>
using namespace std;

void myFunc(vector<int> &nums,vector<vector<int>> &ans,vector<int>subset,int i){
    if(i==nums.size()){
        ans.push_back(subset);
        return;
    }

    subset.push_back(nums[i]); //inclusion step
    myFunc(nums,ans,subset,i+1); //next level call

    subset.pop_back();//backtracking
    myFunc(nums,ans,subset,i+1);// exclusion step and next call

}

vector <vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> subset = {};
    myFunc(nums,ans,subset,0);
    return ans;
}

void testCase(vector<int> nums){
    vector<vector<int>> ans = subsets(nums);
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
    testCase({1,2,3});
    testCase({1,2,3,4});
    return 0;
}