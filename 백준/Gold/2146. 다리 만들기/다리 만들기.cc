#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N;
int num=1;
int ans=1000000000;
int map[100][100];
bool isvisit[100][100];
bool check[100][100];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void BFS(int i,int j);
void find_ans(int i,int j);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!isvisit[i][j]&&map[i][j]!=0){
                BFS(i,j);
                num++;
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(check[i][j]){
                find_ans(i,j);
            }
        }
    }
    cout<<ans;
}
void BFS(int i,int j){
    queue<pair<int,int> > k;
    pair<int,int> temp;
    pair<int,int> tmp;
    map[i][j]=num;
    for(int k=0;k<4;k++){
        if(i+dx[k]<0||i+dx[k]>N-1||j+dy[k]<0||j+dy[k]>N-1)
            continue;
        if(map[i+dx[k]][j+dy[k]]==0){
            check[i][j]=true;
            break;
        }
    }
    k.push({i,j});
    while(!k.empty()){
        temp=k.front();
        k.pop();
        for(int i=0;i<4;i++){
            tmp.first=temp.first+dx[i];
            tmp.second=temp.second+dy[i];
            if(tmp.first<0||tmp.first>N-1||tmp.second<0||tmp.second>N-1||isvisit[tmp.first][tmp.second]||map[tmp.first][tmp.second]==0){
                continue;
            }
            isvisit[tmp.first][tmp.second]=true;
            map[tmp.first][tmp.second]=num;
            k.push(tmp);
            for(int j=0;j<4;j++){
                if(tmp.first+dx[j]<0||tmp.first+dx[j]>N-1||tmp.second+dy[j]<0||tmp.second+dy[j]>N-1)
                    continue;
                if(map[tmp.first+dx[j]][tmp.second+dy[j]]==0){
                    check[tmp.first][tmp.second]=true;
                    break;
                }
            }
        }
    }
}
void find_ans(int i,int j){
    bool visit[100][100]={false,};
    int fobiden=map[i][j];
    queue<vector<int> > k;
    vector<int> temp(3);
    vector<int> tmp(3);
    temp[0]=i;
    temp[1]=j;
    temp[2]=0;
    k.push(temp);
    while(!k.empty()){
        temp=k.front();
        k.pop();
        tmp[2]=temp[2]+1;
        for(int i=0;i<4;i++){
            tmp[0]=temp[0]+dx[i];
            tmp[1]=temp[1]+dy[i];
            if(tmp[0]<0||tmp[0]>N-1||tmp[1]<0||tmp[1]>N-1||map[tmp[0]][tmp[1]]==fobiden||visit[tmp[0]][tmp[1]]){
                continue;
            }
            visit[tmp[0]][tmp[1]]=true;
            k.push(tmp);
            if(map[tmp[0]][tmp[1]]!=0){
                if(ans>tmp[2]-1){
                    ans=tmp[2]-1;
                }
                return ;
            }
        }
    }
}