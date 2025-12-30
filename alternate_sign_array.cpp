#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int> nums) {
    vector <int> positive;
    vector <int> negative;
    vector <int> output;
    int l = nums.size();
    for(int i =0;i<l;i++){
        if(nums[i]<0){
            negative.push_back(nums[i]);
        }
        else{
            positive.push_back(nums[i]);
        }
    }
    for(int j =0;j<l;j++){
        if(j%2 == 0){
            output.push_back(positive[(j)/2]);
        }
        else{
            output.push_back(negative[(j-1)/2]);
        }
    }
    return output;
}

void run_testCase(vector <int> nums){
    vector <int> output = rearrangeArray(nums);
    for(int i = 0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    vector <int> nums1,nums2;
    nums1 = {3,1,-2,-5,2,-4};
    nums2 = {-1,1};
    run_testCase(nums1);
    run_testCase(nums2);
    return 0;
}