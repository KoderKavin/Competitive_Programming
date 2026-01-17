#include <iostream>
#include <vector>

using namespace std;

void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}

void sort(vector <int>& nums,vector <int>& colors){
    for(int i =0;i<nums.size()-1;i++){
        for(int j = 0;j<nums.size()-1-i;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                swap(colors[j],colors[j+1]);
            }
        }
    }
}

int arrayColoring(vector <int>& nums,int n){
    vector <int> colors;
    for(int i = 0;i<n;i++){
        if(i%2==0){
            colors.push_back(0);
        }else{
            colors.push_back(1);
        }
    }
    sort(nums,colors);
    for(int i =0;i<n-1;i++){
        if(colors[i]==colors[i+1]){
            return 0;
        }
    }

    return 1;
    
    
}

int main(){
    int t;
    cin>>t;
    vector <string> output;
    for(int i =0;i<t;i++){
        int n;
        cin>>n;
        vector <int> nums;
        for(int j =0;j<n;j++){
            int temp;
            cin>>temp;
            nums.push_back(temp);
        }
        int result = arrayColoring(nums,n);
        if(result == 1){
            output.push_back("YES");
        }else if(result ==0){
            output.push_back("NO");
        }else{
            output.push_back("failed");
        }
    }
    for(int i =0;i<t;i++){
        cout<<output[i]<<"\n";
    }
    return 0;
}

// int main(){
//     int n = 5;
//     vector <int> nums = {3,4,1,2,5};
//     int result = arrayColoring(nums,n);
//     cout<<result;
// }