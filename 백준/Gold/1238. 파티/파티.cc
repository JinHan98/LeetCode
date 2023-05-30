#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
void BFS(int a);
vector<pair<int,int> > weight[1001];
int graph[1001][1001];
int val[1001];
int ans[1001];
int N,M,X;
int s,e,w;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M>>X;
    for(int i=1;i<=N;i++){
        val[i]=1500000000;
    }
    for(int i=0;i<M;i++){
        cin>>s>>e>>w;
        weight[s].push_back({w,e});
    }
    int max=0;
    for(int i=1;i<=N;i++){
        BFS(i);
        ans[i]=val[X];
        for(int i=1;i<=N;i++){
            val[i]=1500000000;
        }
    }
    BFS(X);
    for(int i=1;i<=N;i++){
        ans[i]+=val[i];
        if(ans[i]>max)
            max=ans[i];
    }
    cout<<max;
}
void BFS(int a){
    val[a]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >k;
    k.push({0,a});
    while(!k.empty()){
        int current=k.top().second;
        int distance=k.top().first;
        k.pop();
        if(val[current]<distance)
            continue;
        for(int i=0;i<weight[current].size();i++){
            int next=weight[current][i].second;
            int next_distance=weight[current][i].first+distance;
            if(val[next]>next_distance){
                val[next]=next_distance;
                k.push({next_distance,next});
            }
        }
    }
}