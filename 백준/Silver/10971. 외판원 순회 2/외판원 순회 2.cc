#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int S[10];
int num[10];
int cost[10][10];
int N;
int isvisit[10];
long long ans=10000000000;
long long temp;
void DFS(int a,int b);
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>cost[i][j];
        }
    }
    for(int i=0;i<N;i++){
        S[i]=i+1;
    }
    for(int i=0;i<N;i++){
        DFS(i,0);
        isvisit[i]=false;
    }
    cout<<ans;
}
void DFS(int a,int b){
    if(isvisit[a])
        return ;
    else{
        isvisit[a]=true;
        num[b]=S[a];
        if(b==N-1){
            temp=0;
            for(int i=0;i<N-1;i++){
                if(cost[num[i]-1][num[i+1]-1]==0)
                    return ;
                temp+=cost[num[i]-1][num[i+1]-1];
            }
            if(cost[num[N-1]-1][num[0]-1]==0)
                return ;
            temp+=cost[num[N-1]-1][num[0]-1];
            if(temp<ans)
                ans=temp;
            return ;
        }
        for(int i=0;i<N;i++){
            if(!isvisit[i]){
                DFS(i,b+1);
                isvisit[i]=false;
            }
        }
    }
}