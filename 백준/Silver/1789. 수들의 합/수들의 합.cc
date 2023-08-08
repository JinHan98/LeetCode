#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
long long arr[100000];
int main(){
    for(int i=1;i<100000;i++){
        arr[i]=arr[i-1]+i;
    }
    long long N;
    cin>>N;
    for(int i=1;i<100000;i++){
        if(N<arr[i]){
            cout<<i-1;
            return 0;
        }
        else if(N==i){
            cout<<i;
            return 0;
        }
    }
    return 0;
}
