#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N,M;
char camp[600][600];
bool isvisit[600][600];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans=0;
void BFS(int x,int y);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int start_x,start_y;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>camp[i][j];
            if(camp[i][j]=='I'){
                start_x=i;
                start_y=j;
            }
        }
    }
    BFS(start_x,start_y);
    if(ans==0)
        cout<<"TT";
    else
        cout<<ans;
}
void BFS(int x,int y){
    isvisit[x][y]=true;
    queue<pair<int,int> > k;
    k.push({x,y});
    while(!k.empty()){
        pair<int,int> temp=k.front();
        k.pop();
        for(int i=0;i<4;i++){
            int xx=temp.first+dx[i];
            int yy=temp.second+dy[i];
            if(xx<0||xx>N-1||yy<0||yy>M-1||isvisit[xx][yy])
                continue;
            if(camp[xx][yy]=='X')
                continue;
            else{
                if(camp[xx][yy]=='P')
                    ans++;
                k.push({xx,yy});
                isvisit[xx][yy]=true;
            }
        }
    }
}