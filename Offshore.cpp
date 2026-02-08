#include <iostream>
#include <vector>
using namespace std;

int bank(int n,int x,int y,vector<int>& accounts){
    int total_transfer = 0;
    for(int i = 0;i<n;i++){
        total_transfer += y*(accounts[i]/x);
    }
    vector<int> possible;
    for(int i = 0;i<n;i++){
        possible.push_back(accounts[i]+ total_transfer- y*(accounts[i]/x));
    }
    int max = 0;
    for(int val:possible){
        if(val>max){
            max = val;
        }
    }
    return max;

}

void testCase(int n,int x,int y,vector<int> accounts){
    int result = bank(n,x,y,accounts);
    cout<<result<<"\n";
}

int main(){
    int t;
    cin>>t;
    vector<int>output;
    for(int i =0;i<t;i++){
        int n,x,y;
        vector<int>input;
        cin>>n>>x>>y;
        for(int j= 0;j<n;j++){
            int temp;
            cin>>temp;
            input.push_back(temp);
        }
        output.push_back(bank(n,x,y,input));
    }
    for(int val:output){
        cout<<val<<"\n";
    }
    return 0;
}