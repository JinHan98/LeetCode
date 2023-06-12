#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N;
vector<pair<int,int> > tree[10001];
int p;
int ans=0;
bool isvisit[10001];
void DFS(int i,int sum);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int a,b,c;
    for(int i=0;i<N-1;i++){
        cin>>a>>b>>c;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }
    DFS(1,0);
    for(int i=0;i<=N;i++)
        isvisit[i]=false;
    DFS(p,0);
    cout<<ans;
}
void DFS(int i,int sum){
    if(isvisit[i])
        return ;
    isvisit[i]=true;
    if(sum>ans){
        ans=sum;
        p=i;
    }
    for(int j=0;j<tree[i].size();j++){
        if(!isvisit[tree[i][j].first]){
            DFS(tree[i][j].first,sum+tree[i][j].second);
        }
    }
}