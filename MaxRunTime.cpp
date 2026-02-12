#include <iostream>
#include <vector>
using namespace std;

long long max(vector<int>& nums){
    long long max = nums[0];
    for(long long val:nums){
        if (val>max){
            max = val;
        }
    }
    return max;
}

bool isValid(vector<int>& batteries,int n,long long time){
    long long total_time = 0;
    for(int i =0;i<batteries.size();i++){
        if(batteries[i]>=time){
            total_time += time;
        }else{
            total_time += batteries[i];
        }
    }
    if(total_time<n*time){
        return false;
    }else{
        return true;
    }
}

long long maxRunTime(int n,vector<int>& batteries){
    long long st =0;
    long long end = (batteries.size()-n +1)*max(batteries);
    long long ans = -1;
    while(st<=end){
        long long mid = st +(end-st)/2;
        if(isValid(batteries,n,mid)){
            ans = mid;
            st = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}

void testCase(int n,vector<int> batteries){
    int result = maxRunTime(n,batteries);
    cout<<result<<"\n";
}

int main(){
    testCase(2,{3,3,3});
    testCase(2,{1,1,1,1});

    return 0;
}