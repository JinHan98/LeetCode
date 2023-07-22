#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void BFS(int start,int end);
int bat[50][50];
bool isvisit[50][50];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int N,M,K;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int ans=0;
        cin>>N>>M>>K;
        for(int j=0;j<K;j++){
            int x,y;
            cin>>x>>y;
            bat[x][y]=1;
        }
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                if(!isvisit[x][y]&&bat[x][y]==1){
                    BFS(x,y);
                    ans++;
                }
            }
        }
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                bat[x][y]=0;
                isvisit[x][y]=false;
            }
        }
        cout<<ans<<'\n';
    }
}
void BFS(int start,int end){
    queue<pair<int,int> > k;
    isvisit[start][end]=true;
    k.push({start,end});
    while(!k.empty()){
        pair<int,int> temp=k.front();
        k.pop();
        for(int a=0;a<4;a++){
            int x_=temp.first+dx[a];
            int y_=temp.second+dy[a];
            if(x_<0||x_>N-1||y_<0||y_>M-1)
                continue;
            if(!isvisit[x_][y_]&&bat[x_][y_]==1){
                isvisit[x_][y_]=true;
                k.push({x_,y_});
            }
        }
    }
}
