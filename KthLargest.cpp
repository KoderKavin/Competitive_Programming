#include <iostream>
#include <vector>
using namespace std;

void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr,int st,int end,int pivot){
    int idx = st-1;
    for(int j= st;j<end;j++){
        if(arr[j]>=pivot){
            idx++;
            swap(arr[idx],arr[j]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}

void quickSort(vector<int>& arr,int st,int end){
    if(st>= end){
        return ;
    }
    int pivot = arr[end];
    int pvtIdx = partition(arr,st,end,pivot);
    quickSort(arr,st,pvtIdx-1);
    quickSort(arr,pvtIdx+1,end);
}

int findKthLargest(vector<int>&nums ,int k){
    quickSort(nums,0,nums.size()-1);
    return nums[k-1];
}

void testCase(vector<int> nums,int k){
    int ans = findKthLargest(nums,k);
    cout<<ans<<"\n";
}

int main(){
    testCase({3,2,1,5,6,4},2);
    testCase({3,2,3,1,2,4,5,5,6},4);
    return 0;
}