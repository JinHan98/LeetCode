#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,M;
int map[1000][1000];
int ans[1000][1000];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
void BFS(int x,int y);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int start_x,start_y;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]==2){
                start_x=i;
                start_y=j;
            }
        }
    }
    BFS(start_x,start_y);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==1&&ans[i][j]==0)
                cout<<-1;
            else if(map[i][j]==2)
                cout<<0;
            else
                cout<<ans[i][j];
            cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
void BFS(int x,int y){
    queue<pair<int,int> > k;
    k.push({x,y});
    while(!k.empty()){
        pair<int,int> temp=k.front();
        k.pop();
        for(int i=0;i<4;i++){
            int new_x=temp.first+dx[i];
            int new_y=temp.second+dy[i];
            if(new_x<0||new_x>N-1||new_y<0||new_y>M-1)
                continue;
            if(map[new_x][new_y]==0)
                continue;
            if(ans[new_x][new_y]==0){
                ans[new_x][new_y]=ans[temp.first][temp.second]+1;
                k.push({new_x,new_y});
            }
        }
    }
}