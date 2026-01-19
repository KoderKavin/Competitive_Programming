#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int>& posn,int m,int min_dist,int n){
    int cows = 1;
    int last_cow_posn = posn[0];
    for(int i =1;i<n;i++){
        if(posn[i]-last_cow_posn >= min_dist){
            cows++;
            last_cow_posn = posn[i];
        }

        if(cows == m){
            return true;
        }
    }
    return false;
}

int maxDistance(vector <int>& posn, int m){
    int n = posn.size();
    sort(posn.begin(),posn.end());
    int st = 1;
    int end = posn[posn.size()-1]- posn[0];
    int ans = -1;
    int mid;
    while(st<=end){
        mid = st +(end-st)/2;
        if(isValid(posn,m,mid,n)==true){
            ans = mid;
            st = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;

}

void testCase(int testNo, vector<int> posn,int m,int eOut){
    cout<<"Test case: "<<testNo<<"\n";
    int fOut = maxDistance(posn,m);
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
    testCase(1,{1,2,3,4,7},3,3);
    testCase(2,{5,4,3,2,1,1000000000},2,999999999);
    testCase(3,{79,74,57,22},4,5);
    return 0;
}