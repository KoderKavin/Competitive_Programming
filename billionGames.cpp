#include <iostream>
#include <vector>
using namespace std;

int games(int n,int l, int r,vector <int> est){
    int mid = (l+r)/2;
    int min_score;
    for(int p = l;p<r+1;p++){
        int score = 0;
        for(int j = 0;j<n;j++){
            if(est[j]< mid){
                score += (p-est[j]);
            }
            else if(est[j]>mid){
                score += (est[j]-p);
            }
        }
        if(p ==l){
            min_score = score;
        }
        if(min_score>score){
            min_score = score;
        }
    }
    return min_score;
}   

int main(){
    int t;
    cin>>t;
    vector <int> output;
    for(int i =0;i<t;i++){
        int n,l,r;
        vector <int> est;
        cin>>n>>l>>r;
        for(int j =0;j<n;j++){
            int temp;
            cin>>temp;
            est.push_back(temp);
        }
        int result = games(n,l,r,est);
        output.push_back(result);
    }
    for (int i =0;i<output.size();i++){
        cout<<output[i]<<"\n";
    }

    return 0;
}