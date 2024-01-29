#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

char map[1000][1000];
bool isvisit[1000][1000];
int DP[1000][1000];
int T;
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
pair<int,int> start;
int BFS();
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>M>>N;
        queue<pair<int,int> >k;
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                DP[x][y]=1000000000;
                isvisit[x][y]=false;
            }
        }
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                cin>>map[x][y];
                if(map[x][y]=='*'){
                    k.push({x,y});
                    DP[x][y]=0;
                }
                else if(map[x][y]=='@'){
                    start.first=x;
                    start.second=y;
                }
            }
        }
        while(!k.empty()){
            pair<int,int> temp=k.front();
            k.pop();
            for(int a=0;a<4;a++){
                int x=temp.first+dx[a];
                int y=temp.second+dy[a];
                if(x<0||y<0||x>N-1||y>M-1)
                    continue;
                if(map[x][y]=='.'||map[x][y]=='@'){
                    if(DP[temp.first][temp.second]+1<DP[x][y]){
                        DP[x][y]=DP[temp.first][temp.second]+1;
                        k.push({x,y});
                    }
                }
            }
        }
        int ans=BFS();
        if(ans!=-1){
            cout<<ans<<'\n';
        }
        else{
            cout<<"IMPOSSIBLE"<<'\n';
        }
    }
    
}
int BFS(){
    queue<vector<int> >k;
    k.push({start.first,start.second,0});
    isvisit[start.first][start.second]=true;
    if(start.first==0||start.second==0||start.first==N-1||start.second==M-1){
        return 1;
    }
    while(!k.empty()){
        vector<int> temp=k.front();
        k.pop();
        for(int i=0;i<4;i++){
            int x=temp[0]+dx[i];
            int y=temp[1]+dy[i];
            if(x<0||y<0||x>N-1||y>M-1||isvisit[x][y])
                continue;
            if(map[x][y]=='.'){
                if(DP[x][y]>temp[2]+1){
                    isvisit[x][y]=true;
                    k.push({x,y,temp[2]+1});
                    if(x==0||y==0||x==N-1||y==M-1){
                        return temp[2]+2;
                    }
                }
            }
        }
    }
    return -1;
}