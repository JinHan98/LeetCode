#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>

using namespace std;
long long N,M,A,B;
vector<pair<long long,long long> >graph[200001];
vector<long long> back[200001];
long long dist[200001];
void BFS(long long start);
void DFS(long long start);
set<int> ans;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M>>A>>B;
    int s,e,v;
    for(int i=0;i<M;i++){
        cin>>s>>e>>v;
        graph[s].push_back({e,v});
        graph[e].push_back({s,v});
    }
    for(int i=1;i<=N;i++){
        dist[i]=3000000000000000001;
    }
    BFS(A);
    DFS(B);
    cout<<ans.size()<<'\n';
    for(auto iter=ans.begin();iter!=ans.end();iter++){
        cout<<*iter<<' ';
    }
}
void BFS(long long start){
    priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > >k;
    dist[start]=0;
    k.push({0,start});
    while(!k.empty()){
        pair<long long,long long> temp=k.top();
        k.pop();
        if(temp.first>dist[temp.second])
            continue;
        for(int i=0;i<graph[temp.second].size();i++){
            long long new_dist=graph[temp.second][i].second+temp.first;
            int new_point=graph[temp.second][i].first;
            if(new_dist<dist[new_point]){
                dist[new_point]=new_dist;
                k.push({new_dist,new_point});
                back[new_point].clear();
                back[new_point].push_back(temp.second);
            }
            else if(new_dist==dist[new_point])
                back[new_point].push_back(temp.second);
        }
    }
}
void DFS(long long start){
    ans.insert(start);
    for(int i=0;i<back[start].size();i++){
        DFS(back[start][i]);
    }
}