#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isValid(vector <int>& piles,int h,int m){
    int consumed_hrs = 0;
    for(int i =0;i<piles.size();i++){
        consumed_hrs += ceil((float)piles[i]/m);
        if(consumed_hrs >h){
            return false;
        }
    }
    return true;
}

int minEatingSpeed(vector <int>& piles,int h){
    int max = piles[0];
    int n = piles.size();
    for(int i =0;i<n;i++){
        if(piles[i]>max){
            max = piles[i];
        }
    }
    int st = 1;
    int end = max;
    int mid;
    int ans = -1;
    while(st<end){
        mid = st +(end-st)/2;
        if(isValid(piles,h,mid)==true){
            ans = mid;
            end = mid;
        }else{
            st = mid+1;
        }
    }
    if(st == end){
        ans = st;
    }
    return ans;
}

void testCase(int testNo, vector<int> piles,int h,int eOut){
    cout<<"Test case: "<<testNo<<"\n";
    int fOut = minEatingSpeed(piles,h);
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
    testCase(1,{3,6,7,11},8,4);
    testCase(2,{30,11,23,4,20},5,30);
    testCase(3,{30,11,23,4,20},6,23);
    return 0;
}