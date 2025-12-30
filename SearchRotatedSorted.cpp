#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector <int>& nums,int target,int st,int end){
    while(st<=end){
        int mid = st + (end-st)/2;
        if(target<nums[mid]){
            end = mid-1;
        }
        else if(target > nums[mid]){
            st = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int search(vector <int>& nums, int target){
    int st = 0;
    int end = nums.size()-1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(nums[st]<=nums[mid]){
            if(nums[st]<=target && target <= nums[mid]){
                return(binarySearch(nums,target,st,mid));
            }
            else{
                st = mid+1;
            }
        }
        else{
            if(nums[mid]<=target && target <= nums[end]){
                return binarySearch(nums,target,mid,end);
            }
            else{
                end = mid-1;
            }
        }
    }
    return -1;
}

void testCase(vector<int> nums,int target,int result){
    int uOut = search(nums,target);
    cout<<uOut<<" : ";
    if(uOut == result){
        cout<<"passed"<<"\n";
    }
    else{
        cout<<"failed"<<"\n";
    }
}

int main(){
    testCase({4,5,6,7,0,1,2},0,4);
    testCase({4,5,6,7,0,1,2},3,-1);
    testCase({1},0,-1);
    return 0;
}