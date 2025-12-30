#include <iostream>
#include <vector>
using namespace std;

int balance(vector <int> nums,int n){
    vector <int> counts;
    for(int i =0;i<101;i++){
        counts.push_back(0);
    }
    int l = nums.size();
    int del = 0;
    for(int i =0;i<l;i++){
        int temp = nums[i];
        counts[temp] += 1;
    }
    for(int i =0;i<101;i++){
        if(counts[i]>0 && counts[i]<i){
            del += counts[i];
        }
        else if(counts[i]>i){
            del += counts[i]-i;
        }
        
    }
    return del;
}

int main(){
    int t;
    cin>>t;
    vector <int> output;
    for(int i =0;i<t;i++){
        int n;
        cin>>n;int temp;
        vector <int> input;
        for(int i =0;i<n;i++){
            cin>>temp;
            input.push_back(temp);
        }
        int result = balance(input,n);
        output.push_back(result);
    }
    for(int i =0;i<output.size();i++){
        cout<<output[i]<<"\n";
    }
    return 0;
}