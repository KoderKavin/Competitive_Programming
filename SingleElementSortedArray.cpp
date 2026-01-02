#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int st = 0;
    int end = nums.size()-1;
    while(st<end){
        int mid = st + (end-st)/2;
        if(nums[mid]==nums[mid+1]){
            if((end-mid)%2==1){
                end = mid-1;
            }else{
                st = mid;
            }
        }else if(nums[mid]==nums[mid-1]){
            if((mid-st)%2 == 1){
                st = mid+1;
            }else{
                end = mid;
            }   
        }else{
            return nums[mid];
        }
    }
    if(st == end){
        return nums[st];
    }
    return -1;
}

void testCase(int testNo, vector<int> arr, int eOut){
    cout<<"Test case: "<<testNo<<"\n";
    int fOut = singleNonDuplicate(arr);
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
    testCase(1,{1,1,2,3,3,4,4,8,8},2);
    testCase(2,{3,3,7,7,10,11,11},10);
    return 0;
}
