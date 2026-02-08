#include <iostream>
#include <vector>
using namespace std;

int fence(int n,int w){
    int ans = (n/w)*(w-1) + n%w;
    return ans;
}

int main(){
    int t;
    cin>>t;
    vector<int> output;
    for(int i =0;i<t;i++){
        int n,w;
        cin>>n;
        cin>>w;
        int ans = fence(n,w);
        output.push_back(ans);
    }
    for(int val:output){
        cout<<val<<"\n";
    }
    return 0;
}