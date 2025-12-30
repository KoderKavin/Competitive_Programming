#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string>  get_input(){
    vector <string> input_vector;
    string t,s;
    cin>>s;
    input_vector.push_back(s);
    cin>>t;
    input_vector.push_back(t);
    return input_vector;
}

string sorter(string name){
    for(int i =0;i<name.length();i++){
        for(int j= 0;j<name.length()-i-1;j++){
            if(name[j]>name[j+1]){
                char temp;
                temp = name[j];
                name[j] = name[j+1];
                name[j+1] = temp;
            }
        }
    }
    return name;
}
int check_equality(string s,string t){
    for(int i = 0;i<s.length();i++){
        if (s[i]!= t[i]){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n,q;
    cin>>n;
    vector <string> input_vector;
    vector <string> output_vector; 
    for(int i = 0;i<n;i++){
        cin>>q;
        input_vector = get_input();
        string s = sorter(input_vector[0]);
        string t = sorter(input_vector[1]);
        if(check_equality(s,t)==1){
            output_vector.push_back("YES");
        }
        else{
            output_vector.push_back("NO");
        }
    }
    for(int j= 0;j<n;j++){
        cout<<output_vector[j]<<"\n";
    }
}