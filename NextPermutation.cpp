#include <iostream>
#include <vector>
using namespace std;
vector <int> sort(vector <int> input){
    for(int i =0;i<input.size();i++){
        for(int j =0;j<input.size()-i-1;j++){
            if(input[j]>input[j+1]){
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp;
            }
        }
    }
    return input;
}

void nextPermutation(vector <int> &nums){
        
}
void testCase(vector <int> &nums){
    nextPermutation(nums);
    for(int i =0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    vector <int> i1,i2,i3,i4;
    i1 ={1,2,3};
    i2 = {3,2,1};
    i3 = {1,1,5};
    i4 = {1,3,2};
    testCase(i1);
    testCase(i2);
    testCase(i3);
    testCase(i4);

    return 0;
}