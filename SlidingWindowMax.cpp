#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void pushQ(deque<int> &q,int idx,vector<int> &nums){
    while(true){
        if(q.empty()){
            q.push_back(idx);
            return;
        }
        if(nums[idx]>=nums[q.back()]){
            q.pop_back();
        }else{
            q.push_back(idx);
            return;
        }
    }
}

vector <int> maxSlidingWindow(vector<int> &nums, int k){
    deque<int> q;
    vector<int>output;
    for(int i =0;i<k;i++){
        if(q.empty()){
            q.push_back(i);
        }else{
            pushQ(q,i,nums);
        }
    }
    output.push_back(nums[q.front()]);
    for(int i =k;i<nums.size();i++){
        while(!q.empty() && q.front()<=i-k){
            q.pop_front();
        }
        pushQ(q,i,nums);
        output.push_back(nums[q.front()]);
    }
    return output;
}

void testCase(vector<int> nums,int k){
    vector<int>result = maxSlidingWindow(nums,k);
    for(int val:result){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    testCase({1,3,-1,-3,5,3,6,7},3);
    testCase({1},1);
    testCase({1,-1},1);

    return 0;
}