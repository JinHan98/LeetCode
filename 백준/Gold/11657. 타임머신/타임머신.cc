#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

bool Bellmanford(int a);
vector<pair<int,pair<int,int> > > weight;
long long val[1001];
int N,M;
int s,e,w;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>s>>e>>w;
        weight.push_back({s,{e,w}});
    }
    for(int i=2;i<=N;i++){
        val[i]=10000000000;
    }
    if(Bellmanford(1)){
        for(int i=2;i<=N;i++){
            if(val[i]==10000000000)
                cout<<-1<<'\n';
            else
                cout<<val[i]<<'\n';
        }
    }
    else
        cout<<-1;
}
bool Bellmanford(int a){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int from=weight[j].first;
            int to=weight[j].second.first;
            int dis=weight[j].second.second;
            if(val[from]==10000000000)
                continue;
            if(val[from]+dis<val[to]){
                val[to]=val[from]+dis;
                if(i==N-1)
                    return false;
            }
        }
    }
    return true;
}