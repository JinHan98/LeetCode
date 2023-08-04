#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int R,C;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char map[1000][1000];
bool isvisit[1000][1000];
int t[1000][1000];
void fireBFS(int x,int y);
void BFS(int x, int y);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            t[i][j]=10000;
        }
    }
    int start_x,start_y;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>map[i][j];
            if(map[i][j]=='J'){
                start_x=i;
                start_y=j;
            }
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]=='F'){
                fireBFS(i,j);
            }
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<R;j++)
            isvisit[i][j]=false;
    }
    BFS(start_x,start_y);
}
void fireBFS(int x, int y){
    t[x][y]=0;
    queue<vector<int> >k;
    k.push({x,y,0});
    while(!k.empty()){
        vector<int> temp=k.front();
        k.pop();
        for(int i=0;i<4;i++){
            int t_x=temp[0]+dx[i];
            int t_y=temp[1]+dy[i];
            if(t_x<0||t_y<0||t_x>R-1||t_y>C-1)
                continue;
            if(!isvisit[t_x][t_y]&&map[t_x][t_y]!='#'){
                if(t[t_x][t_y]>temp[2]+1){
                    t[t_x][t_y]=temp[2]+1;
                    k.push({t_x,t_y,temp[2]+1});
                }
            }
        }
    }
}
void BFS(int x, int y){
    isvisit[x][y]=true;
    queue<vector<int> > k;
    k.push({x,y,0});
    if(x==0||y==0||x==R-1||y==C-1){
        cout<<1;
        return ;
    }
    while(!k.empty()){
        vector<int> temp=k.front();
        k.pop();
        for(int i=0;i<4;i++){
            int t_x=temp[0]+dx[i];
            int t_y=temp[1]+dy[i];
            if(t_x<0||t_y<0||t_x>R-1||t_y>C-1)
                continue;
            if(!isvisit[t_x][t_y]&&map[t_x][t_y]!='#'){
                if(t[t_x][t_y]<=temp[2]+1)
                    continue;
                isvisit[t_x][t_y]=true;
                k.push({t_x,t_y,temp[2]+1});
                if(t_x==0||t_y==0||t_x==R-1||t_y==C-1){
                    cout<<temp[2]+2;
                    return ;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
}