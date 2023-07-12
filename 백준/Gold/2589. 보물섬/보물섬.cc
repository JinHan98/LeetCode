#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N,M;
int ans=0;
char land[50][50];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void BFS(int i, int j);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>land[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(land[i][j]=='L')
                BFS(i,j);
        }
    }   
    cout<<ans;
}
void BFS(int i, int j){
    bool isvisit[50][50]={false,};
    isvisit[i][j]=true;
    vector<int> temp={i,j,0};
    queue<vector<int> > k;
    k.push(temp);
    while(!k.empty()){
        temp=k.front();
        k.pop();
        for(int i=0;i<4;i++){
            int x=temp[0]+dx[i];
            int y=temp[1]+dy[i];
            if(x<0||x>N-1||y<0||y>M-1)
                continue;
            if(land[x][y]=='L'&&!isvisit[x][y]){
                isvisit[x][y]=true;
                k.push({x,y,temp[2]+1});
                if(temp[2]+1>ans)
                    ans=temp[2]+1;
            }
        }
    }
}