#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N,K,S,X,Y;
int t=1;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int map[200][200];
int day[200][200];
bool isvisit[200][200];
void BFS(int i,int j);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    cin>>S>>X>>Y;
    int sigan=0;
    while(sigan<S){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(map[i][j]!=0&&day[i][j]<t&&!isvisit[i][j]){
                    BFS(i,j);
                }
            }
        }
        t++;
        sigan++;
    }
    cout<<map[X-1][Y-1];
}
void BFS(int i,int j){
    isvisit[i][j]=true;
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x<0||y<0||x>N-1||y>N-1)
            continue;
        if(map[x][y]==0||(day[x][y]==t&&map[x][y]>map[i][j])){
            map[x][y]=map[i][j];
            day[x][y]=t;
        }
    }
}