#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N;
vector<int> graph[100001];
int ans[100001];
int idx=1;
bool isvisit[100001];
bool BFS(int i);
void DFS(int i);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int s,e;
    cin>>N;
    for(int i=0;i<N-1;i++){
        cin>>s>>e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    for(int i=0;i<N;i++){
        cin>>ans[i];
    }
    if(ans[0]!=1){
        cout<<0;
        return 0;
    }
    isvisit[1]=true;
    DFS(1);
    if(idx==N)
        cout<<1;
    else
        cout<<0;
}
void DFS(int i){
    sort(graph[i].begin(),graph[i].end());
    while(1){
        if(binary_search(graph[i].begin(),graph[i].end(),ans[idx])){
            idx++;
            DFS(ans[idx-1]);
        }
            else
                break;
    }
}