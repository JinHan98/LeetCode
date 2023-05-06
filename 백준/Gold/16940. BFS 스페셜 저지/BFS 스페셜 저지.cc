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
    cout<<BFS(1);
}
bool BFS(int i){
    isvisit[i]=true;
    queue<int> k;
    k.push(i);
    while(!k.empty()){
        int temp=k.front();
        k.pop();
        sort(graph[temp].begin(),graph[temp].end());
        bool again=false;
        while(1){
            if(binary_search(graph[temp].begin(),graph[temp].end(),ans[idx])){
                k.push(ans[idx]);
                idx++;
            }
            else
                break;
        }
    }
    if(idx==N)
        return 1;
    else
        return 0;
}