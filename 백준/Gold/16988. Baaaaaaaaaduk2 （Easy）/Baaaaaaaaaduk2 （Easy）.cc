#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
int map[20][20];
int all_count=0;
bool isvisit[20][20];
pair<int,int> black[400];
int dol[2];
int answer=0;
int black_idx=0;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int BFS(int i,int j);
void DFS(int idx);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]==0){
                black[black_idx].first=i;
                black[black_idx++].second=j;
            }
        }
    }
    for(int i=0;i<black_idx;i++){
        DFS(i);
    }
    cout<<answer;
}
void DFS(int idx){
    dol[0]=idx;
    map[black[idx].first][black[idx].second]=1;
    for(int a=idx+1;a<black_idx;a++){
        dol[1]=a;
        map[black[a].first][black[a].second]=1;
        int mx=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]==2&&!isvisit[i][j]){
                    int a=BFS(i,j);
                    mx+=a;
                }
            }
        }
        if(answer<mx)
            answer=mx;
        map[black[a].first][black[a].second]=0;
        for(int a=0;a<N;a++){
            for(int b=0;b<M;b++)
                isvisit[a][b]=false;
        }
    }
    map[black[idx].first][black[idx].second]=0;
}
int BFS(int i,int j){
    isvisit[i][j]=true;
    int ans=0;
    bool isans=true;
    pair<int,int> temp;
    queue<pair<int,int> > k;
    k.push({i,j});
    while(!k.empty()){
        temp=k.front();
        k.pop();
        ans++;
        for(int a=0;a<4;a++){
            int x=temp.first+dx[a];
            int y=temp.second+dy[a];
            if(isvisit[x][y]||x<0||x>N-1||y<0||y>M-1||map[x][y]==1)
                continue;
            if(map[x][y]==0){
                isans=false;
            }
            if(map[x][y]==2){
                k.push({x,y});
                isvisit[x][y]=true;
            }
        }
    }
    if(!isans)
        return 0;
    return ans;
}