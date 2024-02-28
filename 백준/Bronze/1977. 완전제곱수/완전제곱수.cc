#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int temp=1;
    while(temp*temp<N){
        temp++;
    }
    int m=temp*temp;
    int ans=0;
    while(temp*temp<=M){
        ans+=(temp*temp);
        temp++;
    }
    if(ans==0){
        cout<<-1;
        return 0;
    }
    cout<<ans<<'\n'<<m;
}