#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void sortColors(vector <int> &nums){
    int l,m,h,n;
    n = nums.size();
    m = 0;
    l= 0;
    h = n-1;
    while(m<=h){
        switch (nums[m])
        {
        case 0:
            swap(nums[m],nums[l]);
            m++;
            l++;
            break;
        
        case 2:
            swap(nums[m],nums[h]);
            h--;
            break;
        default:
            m++;
            break;
        }
    }
}
void testCase(vector <int> nums){
    sortColors(nums);
    for(int i =0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    vector <int> t1,t2,t3;
    t1 = {2,0,2,1,1,0};
    t2 = {2,0,1};
    t3 = {1,2,0};
    testCase(t1);
    testCase(t2);
    testCase(t3);
    return 0;
}