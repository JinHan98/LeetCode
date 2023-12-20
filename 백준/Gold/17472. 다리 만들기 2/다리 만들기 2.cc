#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;
int N,M;
bool isvisit[10][10];
int island[10][10];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int find(int idx);
void uni(int a,int b);
vector<int> connect;
priority_queue<vector<int>,vector<vector<int> >,greater<vector<int> > >k;
void DFS(int x,int y,int island_count);
void make_graph(int x,int y,int island_number);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int ans=0;
    int island_count=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>island[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(island[i][j]!=0&&!isvisit[i][j]){
                DFS(i,j,island_count);
                island_count++;
            }
        }
    }
    connect=vector<int>(island_count);
    for(int i=1;i<island_count;i++)
        connect[i]=i;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(island[i][j]!=0){
                make_graph(i,j,island[i][j]);
            }
        }
    }
    while(!k.empty()){
        vector<int> temp=k.top();
        k.pop();
        int a=find(temp[1]);
        int b=find(temp[2]);
        if(a!=b){
            ans+=temp[0];
            uni(a,b);
        }
    }
    for(int i=1;i<island_count;i++){
        if(find(i)!=1){
            cout<<-1;
            return 0;
        }
    }
    if(ans!=0)
        cout<<ans;
    else
        cout<<-1;
}
void DFS(int x,int y,int island_count){
    island[x][y]=island_count;
    isvisit[x][y]=true;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<0||xx>N-1||yy<0||yy>M-1||island[xx][yy]==0||isvisit[xx][yy])
            continue;
        DFS(xx,yy,island_count);
    }
}
void make_graph(int x,int y,int island_number){
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        int dis=0;
        while(1){
            if(xx<0||xx>N-1||yy<0||yy>M-1)
                break;
            if(island[xx][yy]==island[x][y])
                break;
            if(island[xx][yy]!=0&&island[xx][yy]!=island[x][y]){
                if(dis!=1&&dis!=0){
                    k.push({dis,island[xx][yy],island[x][y]});
                }
                break;
            }
            xx+=dx[i];
            yy+=dy[i];
            dis++;
        }
    }
}
int find(int idx){
    if(idx==connect[idx]){
        return connect[idx]=idx;
    }
    else{
        return connect[idx]=find(connect[idx]);
    }
}
void uni(int a,int b){
    a=find(a);
    b=find(b);
    if(a>b){
        connect[a]=b;
    }
    else{
        connect[b]=a;
    }
    return ;
}