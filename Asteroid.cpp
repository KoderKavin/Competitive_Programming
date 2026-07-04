#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids){
    stack<int> s;
    for(int val:asteroids){
        while(!s.empty()){
            if(val<0 && s.top()>0){
                if(abs(val)>abs(s.top())){
                    //cout<<"test2 ";
                    s.pop();
                }else if(abs(val)<abs(s.top())){
                    //cout<<"test3 ";
                    break;
                }else{
                    //cout<<"test4 ";
                    s.pop();
                    goto checkpoint;
                }
            }else{
                //cout<<"test1 ";
                s.push(val);
                break;
            }
        }
        if(s.empty()){
            s.push(val);
        }
        checkpoint: ;
    }
    vector<int> output(s.size(),0);
    int i =s.size();
    while(!s.empty()){
        i--;
        output[i] = s.top();
        s.pop();
    }
    return output;
}

void testCase(vector<int> asteroids){
    vector<int> result = asteroidCollision(asteroids);
    for(int val:result){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    testCase({5,10,-5});
    testCase({8,-8});
    testCase({10,2,-5});
    testCase({3,5,-6,2,-1,4});

    return 0;
}