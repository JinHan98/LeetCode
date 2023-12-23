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
int N,M;
vector<pair<int,int> > graph[1001];
int BFS(int s,int e);

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int s,e,v;
    for(int i=0;i<N-1;i++){
        cin>>s>>e>>v;
        graph[s].push_back({e,v});
        graph[e].push_back({s,v});
    }
    for(int i=0;i<M;i++){
        cin>>s>>e;
        cout<<BFS(s,e)<<'\n';
    }
}
int BFS(int s,int e){
    bool isvisit[1001]={0,};
    queue<pair<int,int> >k;
    vector<int> distance(1001,0);
    k.push({s,0});
    isvisit[s]=true;
    while(!k.empty()){
        pair<int,int> temp=k.front();
        k.pop();
        for(int i=0;i<graph[temp.first].size();i++){
            if(!isvisit[graph[temp.first][i].first]){
                distance[graph[temp.first][i].first]=distance[temp.first]+graph[temp.first][i].second;
                isvisit[graph[temp.first][i].first]=true;
                k.push({graph[temp.first][i].first,0});
            }
        }
    }
    return distance[e];
}