#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void wiggleSort(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<int> temp;
    int end = nums.size()-1;
    int mid = end/2;
    int i = mid;
    int j= end;
    for(int idx = 0;idx<end+1;idx++){
        if(idx%2==0){
            temp.push_back(nums[i]);
            i--;
        }else{
            temp.push_back(nums[j]);
            j--;
        }
    }
    nums = temp;
}

void test(vector<int> nums){
    wiggleSort(nums);
    for(int val:nums){
        cout<<val<<" ";
    }
    cout<<"\n";
}

int main(){
    test({1,5,1,1,6,4});
    test({1,3,2,2,3,1});
    test({4,5,5,6});
}