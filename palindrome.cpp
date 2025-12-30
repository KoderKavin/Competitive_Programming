#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int reverse(int x) {
        vector <int> output_vector;
        int final_num = 0;
        while(x/10>0){
                output_vector.push_back(x%10);
                x = x/10;
            }
            output_vector.push_back(x%10);
            int l = output_vector.size();
            for(int i =0;i<l;i++){
                if(final_num>pow(2,31)-1-output_vector[i]*pow(10,l-i-1)){
                    return 0;
                }
                final_num = final_num + output_vector[i]*pow(10,l-i-1);
        }
        
        return final_num;
        
}

bool isPalindrome(int x){
    if(x<0){
        return false;
    }
    int reversed = reverse(x);
    if(reversed == x){
        return true;
    }
    else{
        return false;
    }
}
void testCase(int x){
    bool result = isPalindrome(x);
    cout<<result<<"\n";
}

int main(){
    vector <int> testCases = {121,-121,10};
    for(int i = 0;i<testCases.size();i++){
        testCase(testCases[i]);
    }

    return 0;
}