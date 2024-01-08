#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;
char m[1000][1000];
vector<vector<int> > DP[11];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int N,M,K;
int BFS();
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>m[i][j];
        }
    }
    for(int i=0;i<=K;i++)
        DP[i]=vector<vector<int> >(N,vector<int>(M,1000000000));
    BFS();
    int ans=DP[0][N-1][M-1];
    for(int i=1;i<=K;i++){
        if(ans>DP[i][N-1][M-1])
            ans=DP[i][N-1][M-1];
    }
    if(ans==1000000000)
        ans=-1;
    cout<<ans;
}
int BFS(){
    queue<vector<int> >k;
    k.push({0,0,0});
    DP[0][0][0]=1;
    while(!k.empty()){
        vector<int> temp=k.front();
        k.pop();
        for(int i=0;i<4;i++){
            int x=temp[0]+dx[i];
            int y=temp[1]+dy[i];
            if(x<0||y<0||x>N-1||y>M-1)
                continue;
            if(m[x][y]=='0'){
                if(DP[temp[2]][temp[0]][temp[1]]+1<DP[temp[2]][x][y]){
                    DP[temp[2]][x][y]=DP[temp[2]][temp[0]][temp[1]]+1;
                    k.push({x,y,temp[2]});
                }
                
            }
            else{
                if(temp[2]>=K)
                    continue;
                int move=DP[temp[2]][temp[0]][temp[1]];
                if(move%2==0)
                    move++;
                if(move+1<DP[temp[2]+1][x][y]){
                    DP[temp[2]+1][x][y]=move+1;
                    k.push({x,y,temp[2]+1});
                }
            }
        }
    }
    return 0;
}