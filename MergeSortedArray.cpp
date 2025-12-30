#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums,int m, vector<int>& nums2,int n){
    int j = n-1;
    int i = m-1;
    int ptr = m+n-1;
    while(i>=0 || j>=0){
        if(i<0){
            nums[ptr] = nums2[j];
            j--;
            ptr--;
        }
        else if(j<0){
            nums[ptr] =nums[i];
            i--;
            ptr--;
        }
        else if(nums[i]>nums2[j] ){
            nums[ptr] = nums[i];
            i--;
            ptr--;
        }
        else if(nums2[j]>=nums[i]){
            nums[ptr] = nums2[j];
            j--;
            ptr--;
        }
    }
}
void testCase(vector<int> nums,int m, vector<int> nums2,int n,vector <int> result){
    merge(nums,m,nums2,n);
    cout<<"nums = [";
    for(int i =0;i<m+n;i++){
        cout<<nums[i]<<", ";
    }
    cout<<"] : ";
    if(nums == result){
        cout<<"passed"<<"\n";
    }
    else{
        cout<<"failed"<<"\n";
    }
}
int main(){
    testCase({1,2,3,0,0,0},3,{2,5,6},3,{1,2,2,3,5,6});
    testCase({1},1,{},0,{1});
    testCase({0},0,{1},1,{1});
    return 0;
}