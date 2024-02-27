#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;
int T;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    int N;
    for(int i=0;i<T;i++){
        vector<int> ans(4);
        cin>>N;
        ans[0]=N/25;
        N-=(ans[0]*25);
        ans[1]=N/10;
        N-=(ans[1]*10);
        ans[2]=N/5;
        N-=(ans[2]*5);
        ans[3]=N;
        for(int j=0;j<4;j++){
            cout<<ans[j]<<' ';
        }
        cout<<'\n';
    }
    
}