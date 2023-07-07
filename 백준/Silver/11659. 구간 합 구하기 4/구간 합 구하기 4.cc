#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,M,start,end,ans,tmp;
    cin>>N>>M;
    vector<int> k(N);
    ans=0;
    cin>>k[0];
    for(int i=1;i<N;i++){
        cin>>tmp;
        k[i]+=(k[i-1]+tmp);
    }
    for(int i=0;i<M;i++){
        cin>>start>>end;
        ans=k[end-1]-k[start-2];
        cout<<ans<<'\n';
        ans=0;
    }
}