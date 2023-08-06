#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
void DFS(int m,int n,int choice,int sum);
int N,M;
int ans=1000000;
int mat[6][6];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<M;i++){
        DFS(i,0,0,mat[0][i]);
    }
    cout<<ans;
}
void DFS(int m,int n,int choice,int sum){
    if(n==N-1){
        if(sum<ans)
            ans=sum;
            return ;
    }
    if(choice!=1&&m>0){
        DFS(m-1,n+1,1,sum+mat[n+1][m-1]);
    }
    if(choice!=2){
       DFS(m,n+1,2,sum+mat[n+1][m]); 
    }
    if(choice!=3&&m<M-1){
        DFS(m+1,n+1,3,sum+mat[n+1][m+1]);
    }
}