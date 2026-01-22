#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// void merge(vector<int>&arr,int st,int mid,int end){
//     int i = st;
//     int j= mid+1;
//     vector<int> temp;
//     while(i<=mid && j<=end){
//         if(arr[i]<=arr[j]){
//             temp.push_back(arr[i]);
//             i++;
//         }else{
//             temp.push_back(arr[j]);
//             j++;
//         }
//     }
//     while(i<=mid){
//         temp.push_back(arr[i]);
//         i++;
//     }
//     while(j<=end){
//         temp.push_back(arr[j]);
//         j++;
//     }
//     for(int idx = 0;idx<temp.size();idx++){
//         arr[idx+st] = temp[idx];
//     }
// }

// void mergeSort(vector<int>&arr ,int st ,int end){
//     if(st>=end){
//         return ;
//     }
//     int mid = st + (end-st)/2;
    
//     mergeSort(arr,st,mid);
//     mergeSort(arr,mid+1,end);
//     merge(arr,st,mid,end);
// }

vector<vector<int>> fourSum(vector<int>& nums,int target){
    //mergeSort(nums,0,nums.size()-1);
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i = 0;i<nums.size()-3;i++){
        if(i>0){
            if(nums[i]==nums[i-1]){
                continue;
            }
        }
        for(int j = i+1;j<nums.size()-2;j++){
            if(j>i+1){
                if(nums[j]==nums[j-1]){
                    continue;
                }
            }
            int k = j+1;
            int l = nums.size()-1;
            int ntar = target-nums[i]-nums[j];
            while(k<l){
                int sum = nums[k]+nums[l];
                if(k>j+1){
                    if(nums[k]==nums[k-1]){
                        k++;
                        continue;
                    }
                }
                if(sum<ntar){
                    k++;
                }else if(sum>ntar){
                    l--;
                }else{
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                }
            }
        }
    }
    return ans;
}

void testCase(int testNo, vector<int> arr,int target, vector<vector<int>> eOut){
    cout<<"Test case: "<<testNo<<"\n";
    vector<vector<int>> fOut = fourSum(arr,target);
    cout<<"your output: ";
    for(vector<int> val:fOut){
        cout<<"[ ";
        for(int val1 :val){
            cout<<val1<<" ";
        }
        cout<<"], ";
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
    testCase(1,{1,0,-1,0,-2,2},0,{{-2,-1,1,2},{-2,0,0,2},{-1,0,0,1}});
    testCase(2,{2,2,2,2,2},8,{{2,2,2,2}});
    return 0;
}