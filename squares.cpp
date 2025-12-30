#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> get_input(){
    vector <int> input_vector;
    for(int i =0;i<4;i++){
        int temp;
        cin>>temp;
        input_vector.push_back(temp);
    }
    return input_vector;
}
int check_square(vector <int> input_array){
    for(int i =0;i<4;i++){
        if(input_array[i]!=input_array[0]){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n;
    cin>>n;
    vector <int> input_vector;
    vector <string> output_vector;
    for(int i = 0;i<n;i++){
        input_vector = get_input();
        if(check_square(input_vector) ==0){
            output_vector.push_back("NO");
        }
        else if(check_square(input_vector) == 1){
            output_vector.push_back("YES");
        }
        else {
            output_vector.push_back("cooked");
        }
    }
    for(int j = 0;j<n;j++){
        cout<<output_vector[j]<<"\n";
    }
    return 0;
}