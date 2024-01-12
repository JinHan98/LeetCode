#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
long long N,K;
long long num[200000];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long ans=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    cin>>K;
    for(int i=0;i<N;i++){
        long long this_num=num[i];
        while(this_num<=K){
            ans+=(K/this_num);
            this_num*=num[i];
        }
    }
    cout<<ans;
}