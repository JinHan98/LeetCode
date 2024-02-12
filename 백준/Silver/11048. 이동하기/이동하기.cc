#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
using namespace std;

int N,M;
int dx[3]={-1,0,-1};
int dy[3]={0,-1,-1};
int num[1000][1000];
int DP[1000][1000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>num[i][j];
        }
    }
    DP[0][0]=num[0][0];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            DP[i][j]=num[i][j];
            int mx=0;
            for(int k=0;k<3;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x<0||y<0)
                    continue;
                if(DP[x][y]>mx)
                    mx=DP[x][y];
            }
            DP[i][j]+=mx;
        }
    }
    cout<<DP[N-1][M-1];
}