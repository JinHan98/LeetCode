#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
int N;
pair<long long,long long> val[100001][18];
long long energy[100001];
void DFS(int start,int parent);
vector<pair<int,int> > graph[100001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>energy[i];
    }
    int s,e,v;
    for(int i=0;i<N-1;i++){
        cin>>s>>e>>v;
        graph[s].push_back({e,v});
        graph[e].push_back({s,v});
    }
    DFS(1,0);
    for(int i=1;i<=17;i++){
        for(int j=1;j<=N;j++){
            val[j][i].first=val[val[j][i-1].first][i-1].first;
            val[j][i].second=val[val[j][i-1].first][i-1].second+val[j][i-1].second;
        }
    }
    for(int i=1;i<=N;i++){
        int ans=i;
        for(int j=17;(j>=0)&&energy[i];j--){
            if(val[i][j].first!=0&&val[ans][j].second<=energy[i]){
                energy[i]-=val[ans][j].second;
                ans=val[ans][j].first;
            }
            if(ans==1)
                break;
        }
        if(ans==0){
            cout<<1<<'\n';
        }
        else
            cout<<ans<<'\n';
    }
}
void DFS(int start,int parent){
    for(int i=0;i<graph[start].size();i++){
        if(graph[start][i].first!=parent){
            val[graph[start][i].first][0]={start,graph[start][i].second};
            DFS(graph[start][i].first,start);
        }
    }
}
