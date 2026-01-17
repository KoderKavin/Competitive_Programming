#include <iostream>
#include <vector>
using namespace std;

int max(int s,int k,int m){
    if(m>=s && m>=k){
        return m;
    }else if(k>=s && k>=m){
        return k;
    }else{
        return s;
    }
}

int hourGlass(int s,int k,int m){
    int r = m%k;
    int q = (m-m%k)/k;
    int ans = -1;
    if(max(s,k,m)==m){
        if(k>=s){
            if(r>=s){
                ans = 0;
            }else{
                ans = s-r;
            }
        }else{
            if(q%2 ==0){
                ans = s-r;
            }else{
                ans = k-r;
            }
        }
    }else if(max(s,k,m)== k){
        if(s>m){
            ans = s-m;
        }else{
            ans =0;
        }
    }else{
        if(k>m){
            ans = s-m;
        }else{
            if(q%2 ==0){
                ans = s-r;
            }else{
                ans = k-r;
            }
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    vector <int> output;
    for(int i =0;i<t;i++){
        int s,k,m;
        cin>>s>>k>>m;
        int result = hourGlass(s,k,m);
        output.push_back(result);
    }
    for(int i =0;i<t;i++){
        cout<<output[i]<<"\n";
    }

    return 0;
}
// int main(){
//     int test1,test2,test3,test4;
//     test1 = hourGlass(12,2,3);
//     test2 = hourGlass(16,7,7);
//     test3 =hourGlass(1,1,10);
//     test4 = hourGlass(2,60,15);
//     cout<<test1<<"\n";
//     cout<<test2<<"\n";
//     cout<<test3<<"\n";
//     cout<<test4<<"\n";
//     return 0;
// }