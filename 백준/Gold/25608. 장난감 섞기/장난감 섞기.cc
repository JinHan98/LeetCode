#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
int num[10][10001];
int DP[10][10001];
int acc[10][10001];
int val[10][3];
bool isvisit[10];
int temp;
int ans=0;
void DFS(int index,int depth,int result);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=1;j<=M;j++){
            cin>>num[i][j];
            acc[i][j]=num[i][j]+acc[i][j-1];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<=M;j++){
            val[i][0]=max(val[i][0],acc[i][j]);//앞에서 부터 제일 큰 값
            val[i][1]=max(val[i][1],acc[i][M]-acc[i][j]);//뒤에서 부터 제일 큰 값
            if(j==1){
                DP[i][j]=num[i][j];
            }
            else{
                DP[i][j]=max(DP[i][j-1]+num[i][j],0);
                ans=max(ans,DP[i][j]);
            }
        }
        val[i][2]=max(acc[i][M],0);
    }
    if(N==1){
        ans=max(val[0][0],ans);
        ans=max(val[0][1],ans);
        ans=max(ans,val[0][2]);
        cout<<ans;
        return 0;
    }
    for(int i=0;i<N;i++){
        temp=0;
        DFS(i,1,0);
        isvisit[i]=false;
    }
    cout<<ans;
}
void DFS(int index,int depth,int result){
    isvisit[index]=true;
    if(depth==1){
        result=max(val[index][1],0);
        if(result>ans)
            ans=result;
        for(int i=0;i<N;i++){
            if(!isvisit[i]){
                DFS(i,depth+1,result);
                isvisit[i]=false;
            }
        }
    }
    else{
        if(depth==N){
            result=max(result,result+val[index][0]);
            if(result>ans)
                ans=result;
            return ;
        }
        else{
            result=result+val[index][2];
            if(result>ans)
                ans=result;
            for(int i=0;i<N;i++){
                if(!isvisit[i]){
                    DFS(i,depth+1,result);
                    isvisit[i]=false;
                }
            }
        }
    }
}
