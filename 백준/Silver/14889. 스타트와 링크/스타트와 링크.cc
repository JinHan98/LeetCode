#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int best[21][21];
int start[11];
long long ans=1000000000000;
int link[11];
int ind;
long long temp;
bool isvisit[21];
bool isin(int a);
void DFS(int a,int b);
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            cin>>best[i][j];
    }
    for(int i=1;i<=N;i++)
        DFS(i,1);
    cout<<ans;
}
void DFS(int a,int b){
    if(isvisit[a])
        return ;
    else{
        isvisit[a]=true;
        start[b]=a;
        if(b==N/2){
            ind=1;
            for(int i=1;i<=N;i++){
                if(!isin(i)){
                    link[ind]=i;
                    ind++;
                }
            }
            temp=0;
            for(int i=1;i<N/2;i++){
                for(int j=i+1;j<=N/2;j++){
                    temp+=(best[start[i]][start[j]]+best[start[j]][start[i]]);
                    temp-=(best[link[i]][link[j]]+best[link[j]][link[i]]);
                }
            }
            ans=min(ans,abs(temp));
            return ;
        }
        for(int i=a+1;i<=N;i++){
            DFS(i,b+1);
            isvisit[i]=false;
        }
    }
}
bool isin(int a){
    for(int i=1;i<=N/2;i++){
        if(a==start[i])
            return true;
    }
    return false;
}
