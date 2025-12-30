#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

string expansion(int n,int x,int y,string s){
    x = abs(x);
    y = abs(y);
    int fours,eights;
    fours = 0;
    eights = 0;
    for(int i =0;i<n;i++){
        if(s[i]== '4'){
            fours ++;
        }
        else if(s[i]== '8'){
            eights ++;
        }
    }  
    if((x+y)<= (2*eights + fours) && x<= (eights + fours) && y<=(eights + fours)){
        return "YES";
    }
    else{
        return "NO";
    }
}


int main(){
    int t,n,x,y;
    string s;
    cin>>t;
    vector <string> output;
    for(int i=0;i<t;i++){
        cin>>n>>x>>y;
        cin>>s;
        string result = expansion(n,x,y,s);
        output.push_back(result);
    }
    for(int i =0;i<output.size();i++){
        cout<<output[i]<<"\n";
    }
    return 0;
}