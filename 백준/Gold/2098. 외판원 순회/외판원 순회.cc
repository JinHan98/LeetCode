#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
int N;
int dist[16][16];
int ans_bit;
vector<vector<int> >DP;
int DFS(int start, int number);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>dist[i][j];
        }
    }
    DP=vector<vector<int> >(N,vector<int>(1<<N,-1));
    ans_bit=(1<<N)-1;
    int ans=DFS(0,1);
    cout<<ans;
}
int DFS(int start, int number){
    if(number==ans_bit){
        if(dist[start][0]==0)
            return 2000000000;
        else
            return dist[start][0];
    }
    if(DP[start][number]!=-1)
        return DP[start][number];
    DP[start][number]=2000000000;
    for(int i=0;i<N;i++){
        if(dist[start][i]==0)
            continue;
        if(number&(1<<i))
            continue;
        DP[start][number]=min(DP[start][number],dist[start][i]+DFS(i,number|1<<i));
    }
    return DP[start][number];
}