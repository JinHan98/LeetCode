#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int weight[401][401];
int N,M,X;
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
        cin>>start>>end;
        weight[start][end]=1;
    }
    for(int k=1;k<=N;k++){
        for(int j=1;j<=N;j++){
            for(int i=1;i<=N;i++){
                if(weight[i][j]>weight[i][k]+weight[k][j])
                    weight[i][j]=weight[i][k]+weight[k][j];
            }
        }
    }
    cin>>X;
    for(int i=0;i<X;i++){
        cin>>start>>end;
        if(weight[start][end]==1000000000&&weight[end][start]==1000000000){
            cout<<"0\n";
            continue;
        }
        if(weight[start][end]!=1000000000){
            cout<<"-1\n";
        }
        else if(weight[end][start]!=1000000000)
            cout<<"1\n";
        else
            cout<<"0\n";
    }
    return 0;
}