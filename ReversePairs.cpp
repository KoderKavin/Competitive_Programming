#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&nums,int st,int end,int mid){
    vector<int> temp;
    int i = st;
    int j = mid+1;
    while(i<=mid && j<=end){
        if(nums[i]<nums[j]){
            temp.push_back(nums[i]);
            i++;
        }else{
            temp.push_back(nums[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(nums[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(nums[j]);
        j++;
    }
    for(int idx = 0;idx<temp.size();idx++){
        nums[idx+st] = temp[idx];
    }
}
int counter(vector<int>&nums,int st,int end,int mid){
    int i = st;
    int j = mid+1;
    int count = 0;
    while(i<=mid && j<=end){
        if(long(nums[i])>2*long(nums[j])){
            count += mid+1-i;
            j++;
        }else{
            i++;
        }
    }
    return count;
}
int mergeSort(vector<int>&nums,int st,int end){
    if(st>=end){
        return 0;
    }
    int mid = st + (end-st)/2;
    int lcount = mergeSort(nums,st,mid);
    int rcount = mergeSort(nums,mid+1,end);
    int mcount = counter(nums,st,end,mid);
    merge(nums,st,end,mid);
    return lcount+rcount+mcount;
}

int reversePairs(vector<int>& nums){
    int count = mergeSort(nums,0,nums.size()-1);
    return count;
}

void testCase(vector<int> nums){
    int count = reversePairs(nums);
    cout<<count<<"\n";
}

int main(){
    testCase({1,3,2,3,1});
    testCase({2,4,3,5,1});
    testCase({2147483647,2147483647,2147483647,2147483647,2147483647,2147483647});
    return 0;
}