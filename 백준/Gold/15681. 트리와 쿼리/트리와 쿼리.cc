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
int N,R,Q;
bool isvisit[100001];
vector<int> DP;
vector<int> Graph[100001];
int DFS(int start,int depth);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>R>>Q;
    DP=vector<int>(N+1);
    int start,end;
    for(int i=0;i<N-1;i++){
        cin>>start>>end;
        Graph[start].push_back(end);
        Graph[end].push_back(start);
    }
    DFS(R,0);
    int ans;
    for(int i=0;i<Q;i++){
        cin>>ans;
        cout<<DP[ans]<<'\n';
    }
    return 0;
}
int DFS(int start,int depth){
    isvisit[start]=true;
    bool leaf=true;
    for(int i=0;i<Graph[start].size();i++){
        if(!isvisit[Graph[start][i]]){
            leaf=false;
            DP[start]+=DFS(Graph[start][i],depth+1);
        }
    }
    DP[start]++;
    return DP[start];
}