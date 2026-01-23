#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subArrayCount(vector<int>& nums ,int k){
    vector<int> ps;
    unordered_map<int,int> psums;
    int count = 0;
    int sum = 0;
    for(int j = 0;j<nums.size();j++){
        sum+= nums[j];
        ps.push_back(sum);
        if(ps[j]==k){
            count++;
        }
        if(psums.find(ps[j]-k)!=psums.end()){
            count += psums.at(ps[j]-k);
        }
        if(psums.find(ps[j])!= psums.end()){
            psums[ps[j]]++;
        }else{
            psums[ps[j]] = 1;
        }
    }
    return count;
}   

void testCase(int testNo, vector<int> arr,int k, int eOut){
    cout<<"Test case: "<<testNo<<"\n";
    int fOut = subArrayCount(arr,k);
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
    testCase(1,{1,1,1},2,2);
    testCase(2,{1,2,3},3,2);
    return 0;
}