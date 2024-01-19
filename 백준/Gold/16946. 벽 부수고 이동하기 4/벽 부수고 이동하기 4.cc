#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int DP[1000][1000];
char graph[1000][1000];
bool isvisit[1000][1000];
int weight=0;
vector<int> zero_weight;
void BFS(int i, int j);
void get(int i, int j);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>graph[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(graph[i][j]=='0'&&!isvisit[i][j]){
                BFS(i,j);
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(graph[i][j]=='1')
                get(i,j);
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(graph[i][j]=='0')
                cout<<0;
            else
                cout<<DP[i][j]%10;
        }
        cout<<'\n';
    }
}
void BFS(int i, int j){
    int count=1;
    queue<pair<int,int> >k;
    k.push({i,j});
    isvisit[i][j]=true;
    DP[i][j]=weight;
    while(!k.empty()){
        pair<int,int> temp=k.front();
        k.pop();
        for(int t=0;t<4;t++){
            int x=temp.first+dx[t];
            int y=temp.second+dy[t];
            if(x<0||y<0||x>N-1||y>M-1)
                continue;
            if(graph[x][y]=='1'||isvisit[x][y])
                continue;
            isvisit[x][y]=true;
            DP[x][y]=weight;
            k.push({x,y});
            count++;
        }
    }
    zero_weight.push_back(count);
    weight++;
}
void get(int i, int j){
    int ans=1;
    queue<pair<int,int> >k;
    set<int> already;
    k.push({i,j});
    while(!k.empty()){
        pair<int,int> temp=k.front();
        k.pop();
        for(int t=0;t<4;t++){
            int x=temp.first+dx[t];
            int y=temp.second+dy[t];
            if(x<0||y<0||x>N-1||y>M-1)
                continue;
            if(graph[x][y]=='0'){
                auto iter=already.find(DP[x][y]);
                if(iter==already.end()){
                    ans+=zero_weight[DP[x][y]];
                    already.insert(DP[x][y]);
                }
            }
        }
    }
    DP[i][j]=ans;
}