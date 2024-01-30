#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

char map[1000][1000];
queue<pair<int,int> >k[10];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int S[10];
int ans[10];
int blank=0;
int N,M,P;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M>>P;
    for(int i=0;i<P;i++){
        cin>>S[i+1];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]>='1'&&map[i][j]<=P+'0'){
                k[map[i][j]-'0'].push({i,j});
            }
            if(map[i][j]=='.')
                blank++;
        }
    }
    while(blank>0){
        for(int i=1;i<=P;i++){
            for(int j=1;j<=S[i];j++){
                queue<pair<int,int> > t_q;
                if(k[i].empty())
                    break;
                while(!k[i].empty()){
                    pair<int,int> temp=k[i].front();
                    k[i].pop();
                    for(int a=0;a<4;a++){
                        int x=temp.first+dx[a];
                        int y=temp.second+dy[a];
                        if(x<0||y<0||x>N-1||y>M-1)
                            continue;
                        if(map[x][y]=='.'){
                            t_q.push({x,y});
                            map[x][y]=i+'0';
                            blank--;
                        }
                    }
                }
                while(!t_q.empty()){
                    k[i].push(t_q.front());
                    t_q.pop();
                }
            }
        }
        bool again=false;
        for(int i=1;i<=P;i++){
            if(!k[i].empty()){
                again=true;
                break;
            }
        }
        if(!again)
            break;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]>='0'&&map[i][j]<=P+'0'){
                ans[map[i][j]-'0']++;
            }
        }
    }
    for(int i=1;i<=P;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}