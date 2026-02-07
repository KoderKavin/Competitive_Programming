#include <iostream>
#include <vector>
using namespace std;

int max(vector<int>& nums){
    int max = 0;
    for(int i =0;i<nums.size();i++){
        if(nums[i]>nums[max]){
            max = i;
        }
    }
    return max;
}

int compare(int x,int up,int down){
    if(x>up && x>down){
        return 0;
    }else if(x<=up){
        return 1;
    }else{
        return -1;
    }
}



vector<int> findPeakGrid(vector<vector<int>>& mat){
    int n = mat.size();
    int st = 0;
    int end = mat.size()-1;
    vector<int> output = {-1,-1};
    int result;
    if(n==1){
        int maxIdx = max(mat[0]);
        output = {0,maxIdx};
        return output;
    }
    while(st<end){
        int mid = st + (end-st)/2;
        int maxIdx = max(mat[mid]);
        if(mid==0){
            result = compare(mat[0][maxIdx],-1,mat[1][maxIdx]);
        }else if(mid==mat.size()-1){
            result = compare(mat[n-1][maxIdx],mat[n-2][maxIdx],-1);
        }else{
            result = compare(mat[mid][maxIdx],mat[mid-1][maxIdx],mat[mid+1][maxIdx]);
        }
        if(result==1){
            end = mid;
        }else if(result==-1){
            st = mid+1;
        }else{
            output = {mid,maxIdx};
            return output;
        }
        
    }
    if(st==end){
        int mid = st;
        int maxIdx = max(mat[mid]);
        if(mid==0){
            result = compare(mat[0][maxIdx],-1,mat[1][maxIdx]);
        }else if(mid==mat.size()-1){
            result = compare(mat[n-1][maxIdx],mat[n-2][maxIdx],-1);
        }else{
            result = compare(mat[mid][maxIdx],mat[mid-1][maxIdx],mat[mid+1][maxIdx]);
        }

        if(result==0){
            output = {mid,maxIdx};
        }
    }
    
    return output;
}

void testCase(vector<vector<int>> mat){
    vector<int> output = findPeakGrid(mat);
    for(int val:output){
        cout<<val<<" ";
    }
    cout<<"\n";
}

int main(){
    testCase({{1,4},{3,2}});
    testCase({{10,20,15},{21,30,14},{7,16,32}});
    testCase({{70,50,40,30,20},{100,1,2,3,4}});
    testCase({{67}});
    
    return 0;
}