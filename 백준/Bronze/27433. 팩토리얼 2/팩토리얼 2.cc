#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    long long ans=1;
    cin>>N;
    for(int i=2;i<=N;i++){
        ans*=i;
    }
    cout<<ans;
}