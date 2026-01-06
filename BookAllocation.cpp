#include <iostream>
#include <vector>
using namespace std;

int sumOfArray(vector <int>&nums){
    int sum = 0;
    for(int i =0;i<nums.size();i++){
        sum += nums[i];
    }
    return sum;
}

bool isValid(int max_capacity,vector <int>& weights,int max_days){
    int days = 1;
    int total_weight = 0;
    for(int i =0;i<weights.size();i++){
        if(weights[i]>max_capacity){
            return false;
        }
        if(total_weight+weights[i]<=max_capacity){
            total_weight+= weights[i];
        }else{
            days++;
            total_weight = weights[i];
        }
    }
    if(days>max_days){
        return false;
    }else{
        return true;
    }
}

int shipWithinDays(vector<int>& weights, int days) {
    int st = 0; 
    int end = sumOfArray(weights);
    int mid;
    int ans = -1;
    while(st<end){
        mid = st + (end-st)/2;
        if(isValid(mid,weights,days)){
            end = mid;
            ans = mid;
        }else{
            st = mid+1;
        }
    }
    if(st = end){
        ans = end;
    }
    return ans;
}

void testCase(int testNo, vector<int> arr,int days, int eOut){
    cout<<"Test case: "<<testNo<<"\n";
    int fOut = shipWithinDays(arr,days);
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
    testCase(1,{1,2,3,4,5,6,7,8,9,10},5,15);
    testCase(2,{3,2,2,4,1,4},3,6);
    testCase(3,{1,2,3,1,1},4,3);
    testCase(4,{1,2,3,4,5,6,7,8,9,10},1,55);
    return 0;
}