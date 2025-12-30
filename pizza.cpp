#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t,n;
    cin>>t;
    vector <int> output_vector;
    for(int i =0;i<t;i++){
        cin>>n;
        int m = n;
        int hao = 0;
        int counter = 0;
        while(m>2){
            hao = hao + m/3;
            m = m/3;
        }
        while(n>2){
            n = n-2;
            counter++;
        }
        if(counter >hao){
            hao = counter;
        }
        output_vector.push_back(hao);
    }
    for(int j =0;j<t;j++){
        cout<<output_vector[j]<<"\n";
    }
    return 0;
}