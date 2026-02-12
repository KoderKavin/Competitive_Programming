#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
using namespace std;

long long min(long long x,long long y){
    if(x<y){
        return x;
    }else {
        return y;
    }
}


long long counter(long long a,long long b,long long mid){
    if(a%b!=0 && b%a!=0){
        return mid/a + mid/b - mid/(lcm(a,b));
    }else{
        return mid/min(a,b);
    }
}

int nthMagicalNumber(int lim,int x,int y){
    long long n = lim;
    long long mod = 1e9 +7;
    long long a = x;
    long long b = y;
    long long count = 0;
    long long st = min(a,b);
    long long end = min(a*n,b*n);
    while(st<=end){
        long long mid = st + (end-st)/2;
        if(counter(a,b,mid)<n){
            st = mid+1;
        }else if(counter(a,b,mid)>n){
            end = mid-1;
        }else{
            while(mid%a!=0 && mid%b!=0){
                mid--;
            }
            return mid%mod;
        }
    }
    
    return -1;
}

void testCase(int n,int a,int b){
    int result = nthMagicalNumber(n,a,b);
    cout<<result<<"\n";
}  

int main(){

    testCase(1,2,3);
    testCase(4,2,3);
    testCase(5,2,4);
    testCase(1000000000,40000,40000);
    testCase(10,10,8);
    return 0;
}