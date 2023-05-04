#include<iostream>
using namespace std;
long long N,K;
int main(){
    cin>>N>>K;
    long long left=1;
    long long right=K+1;
    while(left<right){
        long long temp=0;
        int middle=(left+right)/2;
        for(long long j=1;j<=N;j++){
            long long val=min(middle/j,N);
            temp+=val;
            if(middle/j==0)
                break;
        }
        if(temp<K){
            left=middle+1;
        }
        else{
            right=middle;
        }
    }
    cout<<left;
}