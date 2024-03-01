#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int ans=0;
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        ans+=temp;
    }
    ans+=(8*(N-1));
    cout<<ans/24<<' '<<ans%24;
}