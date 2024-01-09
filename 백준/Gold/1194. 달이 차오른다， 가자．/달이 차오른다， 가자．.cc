#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N,M;
vector<vector<int> > DP[1<<6];
char map[50][50];
pair<int,int> start_point;
pair<int,int> end_point;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void BFS();
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]=='0'){
                start_point.first=i;
                start_point.second=j;
            }
            else if(map[i][j]=='1'){
                end_point.first=i;
                end_point.second=j;
            }
        }
    }
    for(int i=0;i<(1<<6);i++){
        DP[i]=vector<vector<int> >(N,vector<int>(M,1000000000));
    }
    BFS();
    cout<<-1;
}
void BFS(){
    queue<vector<int> >k;
    DP[0][start_point.first][start_point.second]=0;
    k.push({start_point.first,start_point.second,0});
    while(!k.empty()){
        vector<int> temp=k.front();
        k.pop();
        for(int i=0;i<4;i++){
            int x=temp[0]+dx[i];
            int y=temp[1]+dy[i];
            if(x<0||y<0||x>N-1||y>M-1)
                continue;
            if(map[x][y]=='#'){
                continue;
            }
            if(map[x][y]=='.'){
                if(DP[temp[2]][temp[0]][temp[1]]+1<DP[temp[2]][x][y]){
                    DP[temp[2]][x][y]=DP[temp[2]][temp[0]][temp[1]]+1;
                    k.push({x,y,temp[2]});
                }
            }
            else if(map[x][y]>='a'&&map[x][y]<='f'){
                int num=temp[2];
                num=num|(1<<(map[x][y]-'a'));
                if(DP[temp[2]][temp[0]][temp[1]]+1<DP[num][x][y]){
                    DP[num][x][y]=DP[temp[2]][temp[0]][temp[1]]+1;
                    k.push({x,y,num});
                }
            }
            else if(map[x][y]=='1'){
                if(DP[temp[2]][temp[0]][temp[1]]+1<DP[temp[2]][x][y]){
                    cout<<DP[temp[2]][temp[0]][temp[1]]+1;
                    exit(0);
                }
            }
            else if(map[x][y]=='0'){
                if(DP[temp[2]][temp[0]][temp[1]]+1<DP[temp[2]][x][y]){
                    DP[temp[2]][x][y]=DP[temp[2]][temp[0]][temp[1]]+1;
                    k.push({x,y,temp[2]});
                }
            }
            else{
                int num=map[x][y]-'A';
                num=1<<num;
                if(temp[2]&num){
                    if(DP[temp[2]][temp[0]][temp[1]]+1<DP[temp[2]][x][y]){
                        DP[temp[2]][x][y]=DP[temp[2]][temp[0]][temp[1]]+1;
                        k.push({x,y,temp[2]});
                    }
                }

            }
        }
    }
}