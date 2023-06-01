#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int DP[500][500];
int map[500][500];
bool isvisit[500][500];
int DFS(int i,int j);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            DP[i][j]=DFS(i,j);
        }
    }
    int mx=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mx<DP[i][j])
                mx=DP[i][j];
        }
    }
    cout<<mx;
    return 0;
}
int DFS(int i,int j){
    if(DP[i][j]!=0)
        return DP[i][j];
    DP[i][j]=1;
    for(int k=0;k<4;k++){
        if(i+dx[k]<0||j+dy[k]<0||j+dy[k]>N-1||i+dx[k]>N-1)
            continue;
        if(map[i+dx[k]][j+dy[k]]>map[i][j]){
            DP[i][j]=max(DFS(i+dx[k],j+dy[k])+1,DP[i][j]);
        }
    }
    return DP[i][j];
}