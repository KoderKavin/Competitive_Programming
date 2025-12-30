#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int reverse(int x) {
        vector <int> output_vector;
        int final_num = 0;
        if(x<0){
            x= abs(x);
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
            final_num = 0-final_num;
        }
        else{
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
        }
        
        return final_num;
        
}


int main(){
    int x;
    cin>>x;
    int result = reverse(x);
    cout<<result;
}