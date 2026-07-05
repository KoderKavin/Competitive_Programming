#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> loop(vector<int> s){
    vector<int> keys;
    vector<int> freq;
    for(int i =0;i<s.size();i++){
        int curr = s[i];
        keys.push_back(curr);
        int count = 1;
        i++;
        while(i<s.size() && s[i]==curr){
            count++;
            i++;
        }
        i--;
        freq.push_back(count);
    }
    vector<int> newvec;
    for(int i =0;i<keys.size();i++){
        newvec.push_back(freq[i]);
        newvec.push_back(keys[i]);
    }
    return newvec;
}

string countAndSay(int n){
    vector<int>s = {1};
    for(int i = 1;i<n;i++){
        s = loop(s);
    }
    string finalstr = "";
    finalstr.reserve(s.size()*4);
    for(int num:s){
        finalstr += to_string(num);
    }
    return finalstr;
}

void testCase(int n){
    string result = countAndSay(n);
    cout<<result<<endl;
}

int main(){
    testCase(1);
    testCase(4);

    return 0;
}