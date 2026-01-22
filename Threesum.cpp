#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr,int st,int mid,int end){
    int i = st;
    int j = mid+1;
    vector<int> temp;
    while(i<= mid && j<= end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx = 0;idx<temp.size();idx++){
        arr[idx+st] = temp[idx];
    }
}

void mergeSort(vector<int>&arr ,int st,int end){
    if(st >= end){
        return ;
    }
    int mid = st+ (end-st)/2;
    mergeSort(arr,st,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,st,mid,end);
}

void sort(vector <int>& arr){
    mergeSort(arr,0,arr.size()-1);
}

vector <vector<int>> threeSum(vector<int>& nums){
    sort(nums);
    vector<vector<int>> ans;
    for(int i = 0;i<nums.size();i++){
        if(i>0){
            if(nums[i]==nums[i-1]){
                continue;
            }
        }
        int j = i+1;
        int k = nums.size()-1;
        int target = 0-nums[i];
        while(j<k){
            if(j>i+1){
                if(nums[j]==nums[j-1]){
                    j++;
                    continue;
                }
            }
            if(nums[j]+nums[k]<target){
                j++;
            }else if(nums[j]+nums[k]>target){
                k--;
            }else{
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
            }
        }
    }
    return ans;
}
void testCase(int testNo, vector<int> arr, vector<vector<int>> eOut){
    cout<<"Test case: "<<testNo<<"\n";
    vector<vector<int>> fOut = threeSum(arr);
    cout<<"your output: ";
    for(vector<int> val:fOut){
        cout<<"[ ";
        for(int val1 :val){
            cout<<val1<<" ";
        }
        cout<<"]";
    }
    cout<<"\n";
    cout<<"expected output: ";
    for(vector<int> val:eOut){
        cout<<"[ ";
        for(int val1 :val){
            cout<<val1<<" ";
        }
        cout<<"]";
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
    testCase(1,{-1,0,1,2,-1,-4},{{-1,-1,2},{-1,0,1}});
    testCase(2,{0,1,1},{{}});
    testCase(3,{0,0,0},{{0,0,0}});
    return 0;
}