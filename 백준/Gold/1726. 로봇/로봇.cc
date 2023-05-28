#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[5]={0,0,0,1,-1};  //1 동 2 서 3 남 4 북
int dy[5]={0,1,-1,0,0};
int map[101][101];
int dest[3];
bool isvisit[101][101][5];
int N,M;
void BFS(int s_x,int s_y,int s_d);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>map[i][j];
        }
    }
    int s_x,s_y,s_d;
    cin>>s_x>>s_y>>s_d;
    cin>>dest[0]>>dest[1]>>dest[2];
    if(s_x==dest[0]&&s_y==dest[1]&&s_d==dest[2]){
        cout<<0;
        return 0;
    }
    BFS(s_x,s_y,s_d);
}
void BFS(int s_x,int s_y,int s_d){
    isvisit[s_x][s_y][s_d]=true;
    queue<vector<int> >k;
    vector<int> temp(4);
    temp[0]=s_x;
    temp[1]=s_y;
    temp[2]=s_d;
    temp[3]=0;
    k.push(temp);
    while(!k.empty()){
        temp=k.front();
        k.pop();
        vector<int> tmp(4);
        tmp[2]=temp[2];
        tmp[3]=temp[3]+1;
        for(int i=0;i<3;i++){
            int x=temp[0]+(dx[temp[2]]*(i+1));
            int y=temp[1]+(dy[temp[2]]*(i+1));
            if(x<1||y<1||x>N||y>M)
                break;
            if(map[x][y]==1)
                break;
            if(!isvisit[x][y][temp[2]]){
                tmp[0]=x;
                tmp[1]=y;
                if(tmp[0]==dest[0]&&tmp[1]==dest[1]&&tmp[2]==dest[2]){
                    cout<<tmp[3];
                    return ;
                }
                k.push(tmp);
            }
        }
        tmp[0]=temp[0];
        tmp[1]=temp[1];
        if(tmp[2]>2){
            if(!isvisit[tmp[0]][tmp[1]][2]){
                isvisit[tmp[0]][tmp[1]][2]=true;
                tmp[2]=2;
                if(tmp[0]==dest[0]&&tmp[1]==dest[1]&&2==dest[2]){
                    cout<<tmp[3];
                    return ;
                }
                k.push(tmp);
            }
            if(!isvisit[tmp[0]][tmp[1]][1]){
                isvisit[tmp[0]][tmp[1]][1]=true;
                tmp[2]=1;
                if(tmp[0]==dest[0]&&tmp[1]==dest[1]&&1==dest[2]){
                    cout<<tmp[3];
                    return ;
                }
                k.push(tmp);
            }
        }
        else{
            if(!isvisit[tmp[0]][tmp[1]][3]){
                isvisit[tmp[0]][tmp[1]][3]=true;
                tmp[2]=3;
                if(tmp[0]==dest[0]&&tmp[1]==dest[1]&&3==dest[2]){
                    cout<<tmp[3];
                    return ;
                }
                k.push(tmp);
            }
            if(!isvisit[tmp[0]][tmp[1]][4]){
                isvisit[tmp[0]][tmp[1]][4]=true;
                tmp[2]=4;
                if(tmp[0]==dest[0]&&tmp[1]==dest[1]&&4==dest[2]){
                    cout<<tmp[3];
                    return ;
                }
                k.push(tmp);
            }
        }
    }
}