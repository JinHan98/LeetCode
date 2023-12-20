#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;
int N,M,K;
int two_sq(int a){
    int ans=0;
    a/=2;
    while(a!=0){
        a/=2;
        ans++;
    }
    return ans;
}
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans;
    cin>>N>>M>>K;
    int mx=two_sq(N);
    int pr=two_sq(K);
    ans=mx<pr+M?mx:pr+M;
    cout<<ans;
}
