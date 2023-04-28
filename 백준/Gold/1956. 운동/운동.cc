#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int weight[401][401];
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j)
                weight[i][j]=0;
            else
                weight[i][j]=1000000000;
        }
    }
    int start,end,cost;
    for(int i=0;i<M;i++){
        cin>>start>>end>>cost;
        weight[start][end]=cost;
    }
    for(int k=1;k<=N;k++){
        for(int j=1;j<=N;j++){
            for(int i=1;i<=N;i++){
                if(weight[i][j]>weight[i][k]+weight[k][j])
                    weight[i][j]=weight[i][k]+weight[k][j];
            }
        }
    }
    int ans=2000000000;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j)
                continue;
            if(weight[i][j]+weight[j][i]<ans){
                ans=weight[i][j]+weight[j][i];
            }
        }
    }
    if(ans>1000000000){
        cout<<-1;
        return 0;
    }
    cout<<ans;
    return 0;
}