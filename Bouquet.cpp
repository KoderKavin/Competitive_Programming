#include <iostream>
#include <vector>
using namespace std;

int max(vector<int>& nums){
    int max = nums[0];
    for(int val:nums){
        if(val>max){
            max = val;
        }
    }
    return max;
}

bool isValid(vector<int>& bloomDay,int m,int k,int mid){
    int t = 0;
    int b =0;
    for(int i =0;i<bloomDay.size();i++){
        if(bloomDay[i]>mid){
            t =0;
            continue;
        }
        t++;
        if(t==k){
            b++;
            t=0;
        }
    }
    //cout<<b<<" "<<mid<<"\n";
    if(b>=m){
        return true;
    }else{
        return false;
    }
}

int minDays(vector<int>& bloomDay,int m,int k){
    int st = 0;
    int end = max(bloomDay);
    int ans = -1;
    if(bloomDay.size()/k <m){
        return -1;
    }
    while(st<=end){
        int mid = st+(end-st)/2;
        if(isValid(bloomDay,m,k,mid)==true){
            ans = mid;
            end = mid-1;
        }else{
            st = mid+1;
        }
    }
    return ans;
}

void testCase(vector<int> bloomDay,int m,int k){
    int result = minDays(bloomDay,m,k);
    cout<<result<<"\n";
}

int main(){
    testCase({1,10,3,10,2},3,1);
    testCase({1,10,3,10,2},3,2);
    testCase({7,7,7,7,12,7,7},2,3);

    return 0;
}