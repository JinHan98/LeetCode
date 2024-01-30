#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N,M;
int limit;
queue<pair<int,int> >k;
int dist[1000001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int temp;
    int ans=0;
    for(int i=0;i<=N;i++){
        dist[i]=1000000000;
    }
    for(int i=0;i<M;i++){
        cin>>temp;
        k.push({temp,0});
        dist[temp]=0;
    }
    limit=log2(N)+1;
    while(!k.empty()){
        pair<int,int> temp=k.front();
        k.pop();
        for(int i=0;i<limit;i++){
            int val=(temp.first^(1<<i));
            if(val>N)
                continue;
            if(dist[val]>dist[temp.first]+1){
                dist[val]=dist[temp.first]+1;
                if(dist[val]>ans)
                    ans=dist[val];
                k.push({val,temp.second+1});
            }
        }
    }
    cout<<ans;
    return 0;
}