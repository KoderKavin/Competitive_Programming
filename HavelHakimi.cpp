#include <iostream>
#include <vector>
using namespace std;
//failed

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void Sort(vector <int> &nums,int k){
    int n = nums.size();
    for(int i =k;i<n-1;i++){
        for(int j = k;j<n-i-1;j++){
            if(nums[j]<nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
    }
}

bool Hakimi(vector <int> nums){
    int n = nums.size();
    int i =0;
    for(int i =0;i<n;i++){
        Sort(nums,i);   
        int k = nums[i];
        if(k>n-i-1){
            return false;
        }
        for(int j =i+1;j<i+k+1;j++){
            nums[j] = nums[j]- 1;
            if(nums[j]<0){
                return false;
            }
        }
    }
    return true;
}

void Test(vector <int> nums){
    bool result = Hakimi(nums);
    if(result == true){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    cout<<"\n";
}

int main(){
    Test({5,4,4,3,2,1,1});
    Test({2, 2, 2, 2, 2});
    Test({3, 3, 3, 1});
    Test({4, 1, 1, 1, 1});
    Test({3, 2, 2, 2, 1});

    return 0;
}
