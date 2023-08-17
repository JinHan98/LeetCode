#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

bool Bellmanford(int a);
vector<int> dist[101];
vector<pair<int,pair<int,int> > > weight;
vector<int> rev[101];
long long val[101];
bool visit[101];
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
        rev[e].push_back(s);
    }
    for(int i=2;i<=N;i++){
        val[i]=-1000000000000;
    }
    queue<int> q;
	q.push(N);
	visit[N] = true;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < rev[cidx].size(); i++) {
			int next = rev[cidx][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
    if(Bellmanford(1)){
        if(dist[N].size()==0){
            cout<<-1;
            return 0;
        }
        for(int i=0;i<dist[N].size();i++){
            cout<<dist[N][i]<<' ';
        }
        cout<<N;
    }
    else
        cout<<-1;
    weight.clear();
}
bool Bellmanford(int a){
    for(int i=0;i<N;i++){
        for(int j=0;j<weight.size();j++){
            int from=weight[j].first;
            int to=weight[j].second.first;
            int dis=weight[j].second.second;
            if(val[from]==-1000000000000)
                continue;
            if(val[from]+dis>val[to]){
                val[to]=val[from]+dis;
                if(dist[to].empty()){
                    dist[to]=dist[from];
                    dist[to].push_back(from);
                }
                else{
                    dist[to].clear();
                    dist[to]=dist[from];
                    dist[to].push_back(from);
                }
                if(i==N-1&&visit[to])
                    return false;
            }
        }
    }
    return true;
}