#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;
long long gcd(int a,int b);
long long N,K;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    if(K==1){
        cout<<0;
        return 0;
    }
    if(N-K<K)
        K=N-K;
    long long g=gcd(N,K);
    N/=g;
    K/=g;
    cout<<N*(K-1);
    
}
long long gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}