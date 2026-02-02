#include <iostream>
#include <vector>
using namespace std;

vector <int> func(vector<int>& nums , int target){
    int st = 0;
    int end = nums.size()-1;
    int a = -1;
    int b = -1;
    while(st<=end){
        if(st<0 ||end>nums.size()-1){
            return {a,b};
        }
        if(a!=-1 && b!= -1){
            return {a,b};
        }
        int mid = st + (end-st)/2;
        if(nums[mid]<target){
            st = mid+1;
        }else if(nums[mid]>target){
            end = mid-1;
        }else{
            int i = mid;
            int j= mid;
            while(i<nums.size()&& nums[i]==target){
                i++;
            }
            i--;
            b = i;
            while(j>=0 && nums[j]==target){
                j--;
            }
            j++;
            a = j;
        }
        
    }
    return {a,b};
}
vector<int> searchRange(vector<int>&nums,int target){
    vector<int> temp = func(nums,target);
    int a = temp[0];
    int b= temp[1];
    if(a==-1 & b!=-1){
        a = b;
    }else if(a!=-1 && b==-1){
        b = a;
    }
    return {a,b};
}

void testCase(vector<int> nums,int target){
    vector<int> ans = searchRange(nums,target);
    for(int val:ans){
        cout<<val<<" ";
    }
    cout<<"\n";
}
int main(){
    testCase({5,7,7,8,8,10},8);
    testCase({5,7,7,8,8,10},6);
    testCase({},0);
    testCase({1},1);
    testCase({2,2},2);
    testCase({3,3,3},3);
    testCase({1,2,3,3,3,3,4,5,9},3);
    return 0;
}