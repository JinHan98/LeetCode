#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
using namespace std;
void BFS(int a);
set<pair<int,int> > weight[500];
int val[500];
vector<pair<int,int> > before[500];
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int s,e;
    while(1){
        cin>>N>>M;
        if(N==0&&M==0)
            return 0;
        cin>>s>>e;
        for(int j=0;j<N;j++)
            val[j]=1000000001;
        int st,ed,dis;
        for(int j=0;j<M;j++){
            cin>>st>>ed>>dis;
            weight[st].insert({ed,dis});
        }
        BFS(s);
        queue<pair<int,int> >k;
        k.push({e,0});
        bool isvisit[500]={false,};
        while(!k.empty()){
            pair<int,int> temp=k.front();
            k.pop();
            if(isvisit[temp.first])
                continue;
            isvisit[temp.first]=true;
            for(int i=0;i<before[temp.first].size();i++){
                k.push({before[temp.first][i]});
                weight[before[temp.first][i].first].erase({temp.first,before[temp.first][i].second});
            }
        }
        for(int j=0;j<N;j++)
            val[j]=1000000001;
        BFS(s);
        if(val[e]!=1000000001)
            cout<<val[e]<<'\n';
        else
            cout<<-1<<'\n';
        for(int i=0;i<N;i++){
            weight[i]={};
            before[i].clear();
        }
    }
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
        for(auto iter=weight[current].begin();iter!=weight[current].end();iter++){
            int next=iter->first;
            int next_distance=iter->second+distance;
            if(val[next]>next_distance){
                val[next]=next_distance;
                before[iter->first].clear();
                before[iter->first].push_back({current,iter->second});
                k.push({next_distance,next});
            }
            else if(val[next]==next_distance)
                before[iter->first].push_back({current,iter->second});
        }
    }
}