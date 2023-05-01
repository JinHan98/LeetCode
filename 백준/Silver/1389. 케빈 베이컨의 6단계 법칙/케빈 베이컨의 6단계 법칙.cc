#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int N,M;
int weight[101][101];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int s,e;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j)
                weight[i][j]=0;
            else
                weight[i][j]=1000000000;
        }
    }
    for(int i=0;i<M;i++){
        cin>>s>>e;
        weight[s][e]=1;
        weight[e][s]=1;
    }
    for(int k=1;k<=N;k++){
        for(int j=1;j<=N;j++){
            for(int i=1;i<=N;i++){
                if(weight[i][j]>weight[i][k]+weight[k][j]){
                    weight[i][j]=weight[i][k]+weight[k][j];
                }
            }
        }
    }
    int ans=0;
    int mx=1000000000;
    for(int i=1;i<=N;i++){
        int temp=0;
        for(int j=1;j<=N;j++){
            if(weight[i][j]==1000000000)
                continue;
            else
                temp+=weight[i][j];
        }
        if(temp<mx){
            mx=temp;
            ans=i;
        }
    }
    cout<<ans;
}