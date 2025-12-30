#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void Sort(vector <int> &nums){
    int n = nums.size();
    for(int i = 0;i<n-1;i++){
        for(int j =0;j<n-1-i;j++){
            if(nums[j]<nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}

long cakewalk(vector <int> calorie){
    Sort(calorie);
    long miles = 0;
    int n = calorie.size();
    for(int j =0;j<n;j++){
        miles += pow(2,j)*calorie[j];
    }
    return miles;

}
void testCase(vector <int> nums){
    long result = cakewalk(nums);
    cout<<result<<"\n";
}
int main(){
    vector <int> t1,t2,t3;
    t1 = {1,3,2};
    t2 = {7,4,9,6};
    testCase(t1);
    testCase(t2);
    return 0;
}