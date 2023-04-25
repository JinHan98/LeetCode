#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
// 1 apple 2 snake
using namespace std;
int cheeze[101][101];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int N,M;
int total=0;
void BFS();
int main(){//0 밀폐된 공간 1 치즈 2 없어질 치즈 3 공기
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int ans=0;
    int ans2=0;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>cheeze[i][j];
            if(cheeze[i][j]==1)
                total++;
        }
    }
    while(total>0){
        BFS();
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if(cheeze[i][j]==1){
                    int temp_x;
                    int temp_y;
                    bool melt=false;
                    for(int k=0;k<4;k++){
                        temp_x=i+dx[k];
                        temp_y=j+dy[k];
                        if(cheeze[temp_x][temp_y]==3){
                            melt=true;
                            break;
                        }
                    }
                    if(melt)
                        cheeze[i][j]=2;
                }
            }
        }
        ans2=0;
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if(cheeze[i][j]==2){
                    cheeze[i][j]=0;
                    total--;
                    ans2++;
                }
            }
        }
        ;
        ans++;
    }
    cout<<ans<<'\n'<<ans2;
}
void BFS(){
    bool isvisit[100][100]={false,};
    isvisit[0][0]=true;
    cheeze[0][0]=3;
    queue<pair<int,int> > k;
    pair<int,int> temp;
    k.push({0,0});
    while(!k.empty()){
        temp=k.front();
        k.pop();
        for(int i=0;i<4;i++){
            pair<int,int> tmp;
            tmp.first=temp.first+dx[i];
            tmp.second=temp.second+dy[i];
            if(tmp.first<0||tmp.first>N-1||tmp.second<0||tmp.second>M-1)
                continue;
            if(!isvisit[tmp.first][tmp.second]){
                if(cheeze[tmp.first][tmp.second]==3||cheeze[tmp.first][tmp.second]==0){
                    isvisit[tmp.first][tmp.second]=true;
                    cheeze[tmp.first][tmp.second]=3;
                    k.push(tmp);
                }
            }
        }
    }
}

/*
1 1 10000
1 1 0
1 0 10001

*/