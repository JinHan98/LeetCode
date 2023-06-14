#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T,N,M;
bool isget[1001];
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    priority_queue<pair<int,int> > qu;
    for(int k=0;k<T;k++){
        cin>>N>>M;
        pair<int,int> temp;
        int a,b;
        for(int i=1;i<=M;i++){
            cin>>a>>b;
            qu.push({a,-b});
        }
        for(int i=1;i<=N;i++)
            isget[i]=false;
        int ans=0;
        while(!qu.empty()){
            a=qu.top().first;
            b=-qu.top().second;
            for(int i=b;i>=a;i--){
                if(!isget[i]){
                    isget[i]=true;
                    ans++;
                    break;
                }
            }
            qu.pop();
        }
        
        cout<<ans<<'\n';
    }
}
