#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// int firstUniqChar(string s){
//     unordered_map<char,int> m;
//     for(char c: s){
//         if(m.find(c)!= m.end()){
//             m[c]++;
//         }else{
//             m.insert({c,1});
//         }
//     }
//     for(int i =0;i<s.size();i++){
//         if(m[s[i]]==1){
//             return i;
//         }
//     }
//     return -1;
// }

int firstUniqChar(string s){
    unordered_map<char,int> m;
    queue<int> q;
    for(int i =0;i<s.size();i++){
        char c = s[i];
        if(m.find(c)!= m.end()){
            m[c]++;
        }else{
            m.insert({c,1});
            q.push(i);
        }
        while(!q.empty()){
            if(m[s[q.front()]]>1){
                q.pop();
            }else{
                break;
            }
        }
    }
    if(q.empty()){
        return -1;
    }else{
        return q.front();
    }
    
}

void testCase(string s){
    int result = firstUniqChar(s);
    cout<<result<<endl;
}

int main(){
    testCase("leetcode");
    testCase("loveleetcode");
    testCase("aabb");
    return 0;
}