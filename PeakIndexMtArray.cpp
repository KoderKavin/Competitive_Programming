#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector <int>& arr){
    int st = 0;
    int end = arr.size() -1;
    while(st<=end){
        int mid = st + (end-st)/2;
        if(arr[mid]<arr[mid+1]){
            st = mid;
        }
        else if(arr[mid]<arr[mid-1]){
            end = mid;
        }
        else{
            return mid;
        }
    }
    return -1;
}

void testCase(int testNo, vector<int> arr, int eOut){
    cout<<"Test case: "<<testNo<<"\n";
    int fOut = peakIndexInMountainArray(arr);
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
    testCase(1,{0,1,0},1);
    testCase(2,{0,2,1,0},1);
    testCase(3,{0,10,5,2},1);
    return 0;
}