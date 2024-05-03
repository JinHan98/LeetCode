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
    int ans=0;
    cin>>N;
    for(int i=1;i<=N;i++){
        ans+=i;
    }
    cout<<ans<<'\n';
    cout<<ans*ans<<'\n';
    cout<<ans*ans<<'\n';
}