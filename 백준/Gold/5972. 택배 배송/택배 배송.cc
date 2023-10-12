#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <deque>
#include <map>
using namespace std;
int N,M;
int solution(vector<pair<int,int> > graph[],int N);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int s,e,v;
    vector<pair<int,int> > graph[N+1];
    for(int i=0;i<M;i++){
        cin>>s>>e>>v;
        graph[s].push_back({e,v});
        graph[e].push_back({s,v});
    }
    cout<<solution(graph,N);
}
int solution(vector<pair<int,int> > graph[],int N){
    vector<int> value(N+1,1000000000);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > k;
    value[1]=0;
    k.push({0,1});
    while(!k.empty()){
        int node=k.top().second;
        int distance=k.top().first;
        k.pop();
        if(distance>value[node])
            continue;
        for(int i=0;i<graph[node].size();i++){
            int new_node=graph[node][i].first;
            int new_distance=graph[node][i].second;
            if(value[new_node]>value[node]+new_distance){
                value[new_node]=value[node]+new_distance;
                k.push({new_distance,new_node});
            }
        }
    }
    return value[N];
}