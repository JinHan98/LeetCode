#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N,M;
int mx=1000000000;
int virus_idx=0;
pair<int,int> virus[10];
int choose[10];
int map[50][50];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int t[50][50];
void DFS(int i,int depth);
void BFS(int x,int y);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int x,y;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
            if(map[i][j]==2)
                virus[virus_idx++]={i,j};
        }
    }
    for(int i=0;i<virus_idx;i++){
        DFS(i,0);
    }
    if(mx==1000000000){
        cout<<-1;
        return 0;
    }
    cout<<mx;
}
void DFS(int i,int depth){
    choose[depth]=i;
    if(depth==M-1){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j]==1)
                    t[i][j]=-1;
                else{
                    t[i][j]=1000000000;
                }
            }
        }
        for(int i=0;i<M;i++){
            t[virus[choose[i]].first][virus[choose[i]].second]=0;
            BFS(virus[choose[i]].first,virus[choose[i]].second);
        }
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(t[i][j]>ans&&map[i][j]==0)
                    ans=t[i][j];
            }
        }
        if(mx>ans)
            mx=ans;
    }
    for(int a=i+1;a<virus_idx;a++){
        DFS(a,depth+1);
    }
}
void BFS(int x, int y){
    queue<vector<int> > k;
    vector<int> temp(3);
    temp[0]=x;
    temp[1]=y;
    temp[2]=0;
    k.push(temp);
    while(!k.empty()){
        temp=k.front();
        k.pop();
        vector<int> tmp(3);
        tmp[2]=temp[2]+1;
        for(int i=0;i<4;i++){
            tmp[0]=temp[0]+dx[i];
            tmp[1]=temp[1]+dy[i];
            if(tmp[0]<0||tmp[0]>N-1||tmp[1]<0||tmp[1]>N-1){
                continue;
            }
            if(map[tmp[0]][tmp[1]]==0||map[tmp[0]][tmp[1]]==2){
                if(t[tmp[0]][tmp[1]]>tmp[2]){
                    t[tmp[0]][tmp[1]]=tmp[2];
                    k.push(tmp);
                }
            }
        }
    }
    
}