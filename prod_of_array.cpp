#include <iostream>
#include <vector>
using namespace std;
vector <int> product(vector <int> nums){
    int l= nums.size();
    ;
    
}
vector <int> getInput(int n){
    vector <int> nums;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    return nums;
}
int main(){
    int n;
    cin>>n;
    vector <int> nums;
    vector <int> outputvector;
    nums = getInput(n);
    outputvector = product(nums);
    for(int i = 0;i<n;i++){
        cout<<outputvector[i]<<"\n";
    }
    return 0;
}