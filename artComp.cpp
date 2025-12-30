#include <iostream>
#include <vector>
#include <string>
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

string artComp(vector <int> input_list){
    vector <int> sorted_list = sort(input_list);
    int difference = sorted_list[2]-sorted_list[0];
    if(difference<10){
        return ("final "+ sorted_list[1]);
    }
    else{
        return ("check again");
    }
}


int main(){
    vector <int> i1,i2,i3,i4;
    i1 = {88 ,94, 95};
    i2 = {100,80,81};
    i3 = {98,99,98};
    i4 = {95,86,85};
    cout<<artComp(i1);
    cout<<artComp(i2);
    cout<<artComp(i3);
    cout<<artComp(i4);
    

}