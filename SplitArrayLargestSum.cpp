#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int>&nums){
    int sum = 0;
    for(int i =0;i<nums.size();i++){
        sum += nums[i];
    }
    return sum;
}

bool isValid(vector<int>& nums,int mid,int k){
    int sub_total = 0;
    int sub_arrays = 1;
    for(int i =0;i<nums.size();i++){
        if(nums[i]>mid){
            return false;
        }
        if(nums[i]+sub_total<=mid){
            sub_total += nums[i];
        }else{
            sub_arrays++;
            sub_total = nums[i];
        }
    }
    if(sub_arrays>k){
        return false;
    }else{
        return true;
    }
}

int splitArray(vector <int>& nums, int k){
    int st = 0;
    int end = sum(nums);
    int ans = -1;
    while(st<end){
        int mid = st + (end-st)/2;
        if(isValid(nums,mid,k)){
            end = mid;
            ans = mid;
        }else{
            st = mid+1;
        }
    }
    if(st == end){
        ans = st;
    }
    return ans;
}

void testCase(int testNo, vector<int> arr,int k, int eOut){
    cout<<"Test case: "<<testNo<<"\n";
    int fOut = splitArray(arr,k);
    cout<<"your output: "<<fOut<<"\n";
    cout<<"expected output: "<<eOut<<"\n";
    if(eOut == fOut){
        cout<<"passed"<<"\n";
    }
    else{
        cout<<"failed"<<"\n";
    }
    cout<<" "<<"\n";
}

int main(){
    testCase(1,{7,2,5,10,8},2,18);
    testCase(2,{1,2,3,4,5},2,9);
    return 0;
}