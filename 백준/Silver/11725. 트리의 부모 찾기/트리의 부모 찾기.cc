#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
using namespace std;
int N;
vector<int> graph[100001];
bool isvisit[100001];
int ans[100001];
void DFS(int val);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int s,e;
    for(int i=0;i<N-1;i++){
        cin>>s>>e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    DFS(1);
    for(int i=2;i<=N;i++){
        cout<<ans[i]<<'\n';
    }
}
void DFS(int val){
    isvisit[val]=true;
    for(int i=0;i<graph[val].size();i++){
        if(!isvisit[graph[val][i]]){
            ans[graph[val][i]]=val;
            DFS(graph[val][i]);
        }
    }
}