#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector <int> twoSum(vector <int>& nums,int target){
    unordered_map <int,int> complements;
    for(int i = 0;i<nums.size();i++){
        int a = nums[i];
        int b = target - nums[i];
        if(complements.find(b)!= complements.end()){
            return{complements.at(b),i};
        }
        complements[nums[i]] = i;
    }
    return {-1};
}

void testCase(int testNo, vector<int> arr,int target, vector<int> eOut){
    cout<<"Test case: "<<testNo<<"\n";
    vector<int> fOut = twoSum(arr,target);
    cout<<"your output: ";
    for(int val:fOut){
        cout<<val<<" ";
    }
    cout<<"\n";
    cout<<"expected output: ";
    for(int val:eOut){
        cout<<val<<" ";
    }
    cout<<"\n";
    if(eOut == fOut){
        cout<<"passed"<<"\n";
    }
    else{
        cout<<"failed"<<"\n";
    }
    cout<<" "<<"\n";
}

int main(){
    testCase(1,{2,7,11,15},9,{0,1});
    testCase(2,{3,2,4},6,{1,2});
    testCase(3,{3,3},6,{0,1});
    return 0;
}