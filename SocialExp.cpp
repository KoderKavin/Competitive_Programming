#include <iostream>
#include <vector>
using namespace std;

int socialExp(int n){
    int ans = -1;
    if(n == 2){
        ans = 2;
    }else if(n==3){
        ans = 3;
    }else{
        if(n%2==0){
            ans = 0;
        }else if(n%2==1){
            ans = 1;
        }
    }
    return ans;
    
}

int main(){
    int t;
    cin>>t;
    vector <int> output;
    for(int i =0;i<t;i++){
        int n;
        cin>>n;
        int result = socialExp(n);
        output.push_back(result);
    }
    for(int i =0;i<t;i++){
        cout<<output[i]<<"\n";
    }
}