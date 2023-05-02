#include <iostream>
#include <queue>
using namespace std;

int p[52][52];
bool isvisit[52];
int link[52][52];
bool knowtruth[52];
int N,M;

int BFS(int a);

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int num,temp;
    int ans=0;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>temp;
        knowtruth[temp]=true;
    }
    for(int i=0;i<M;i++){
        cin>>num;
        for(int u=0;u<num;u++){
            cin>>link[i][u];
        }
        for(int j=0;j<num-1;j++){
            for(int k=1;k<num;k++){
                p[link[i][j]][link[i][k]]=1;
                p[link[i][k]][link[i][j]]=1;
            }
        }
    }
    for(int i=0;i<M;i++){
        if(BFS(link[i][0])==1)
            ans++;
        for(int i=1;i<=N;i++)
            isvisit[i]=false;
    }
    cout<<ans;
}
int BFS(int a){
    queue<int> k;
    int temp;
    k.push(a);
    while(!k.empty()){
        temp=k.front();
        isvisit[temp]=true;
        if(knowtruth[temp])
            return 0;
        k.pop();
        for(int i=1;i<=N;i++){
            if(p[temp][i]==1&&!isvisit[i]){
                k.push(i);
            }
        }
    }
    return 1;
}

