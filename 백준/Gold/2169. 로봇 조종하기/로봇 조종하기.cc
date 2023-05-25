#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int DP[3][1000][1000];
int map[1000][1000];
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }
    DP[0][0][0]=map[0][0];
    DP[1][0][0]=map[0][0];
    DP[2][0][0]=map[0][0];
    for(int j=1;j<M;j++){
        for(int i=0;i<3;i++){
            DP[i][0][j]=DP[i][0][j-1]+map[0][j];
        }
    }
    for(int i=1;i<N;i++){
        DP[0][i][0]=DP[2][i-1][0]+map[i][0];
        for(int j=1;j<M;j++){
            DP[0][i][j]=max(DP[2][i-1][j],DP[0][i][j-1]);
            DP[0][i][j]+=map[i][j];
        }
        DP[1][i][M-1]=DP[2][i-1][M-1]+map[i][M-1];
        for(int j=M-2;j>=0;j--){
            DP[1][i][j]=max(DP[2][i-1][j],DP[1][i][j+1]);
            DP[1][i][j]+=map[i][j];
        }
        for(int j=0;j<M;j++){
            DP[2][i][j]=max(DP[0][i][j],DP[1][i][j]);
        }
    }
    cout<<DP[2][N-1][M-1];
}