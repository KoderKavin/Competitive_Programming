#include <iostream>
#include <vector>
using namespace std;

bool searchVec(vector<vector<int>>& matrix,int target,int row){
    int st = 0;
    int end = matrix[0].size()-1;
    bool ans = false;
    while(st<end){
        int mid = st + (end-st)/2;
        if(matrix[row][mid]<target){
            st = mid+1;
        }else if(matrix[row][mid]>target){
            end = mid-1;
        }else{
            ans = true;
            break;
        }
    }
    if(st==end && matrix[row][st]==target){
        ans = true;
    }
    return ans;
}

bool searchMatrix(vector<vector<int>>& matrix ,int target){
    int m = matrix.size();
    int n = matrix[0].size();
    int up = 0;
    int down = m-1;
    while(up<=down){
        int row = up + (down-up)/2;
        if(matrix[row][0]>target){
            down = row-1;
        }else if(matrix[row][n-1]<target){
            up = row+1;
        }else{
            return searchVec(matrix,target,row);
        }
    }
    return false;
}

int main(){
    vector<vector<int>> m1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    bool ans = searchMatrix(m1,3);
    cout<<ans;
    return 0;
}

