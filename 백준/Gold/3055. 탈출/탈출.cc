#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
char map[50][50];
int fall[50][50];
bool isvisit[50][50];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void make_fall();
void go(int x,int y);
int R,C;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int x,y;
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>map[i][j];
            if(map[i][j]=='S'){
                x=i;
                y=j;
            }
            fall[i][j]=1000000000;
        }
    }
    make_fall();
    go(x,y);
    
}
void make_fall(){
    queue<vector<int> > k;
    vector<int> temp(3);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(map[i][j]=='*'){
                temp[0]=i;
                temp[1]=j;
                temp[2]=0;
                fall[i][j]=0;
                k.push(temp);
            }
        }
    }
    while(!k.empty()){
        temp=k.front();
        k.pop();
        vector<int> tmp(3);
        tmp[2]=temp[2]+1;
        for(int i=0;i<4;i++){
            tmp[0]=temp[0]+dx[i];
            tmp[1]=temp[1]+dy[i];
            if(tmp[0]<0||tmp[0]>R-1||tmp[1]<0||tmp[1]>C-1){
                continue;
            }
            if(map[tmp[0]][tmp[1]]!='X'&&map[tmp[0]][tmp[1]]!='D'){
                if(fall[tmp[0]][tmp[1]]==1000000000){
                    fall[tmp[0]][tmp[1]]=tmp[2];
                    k.push(tmp);
                }
            }
        }
    }
}
void go(int x,int y){
    vector<int> temp(3);
    queue<vector<int> > k;
    temp[0]=x;
    temp[1]=y;
    temp[2]=0;
    k.push(temp);
    while(!k.empty()){
        temp=k.front();
        k.pop();
        vector<int> tmp(3);
        tmp[2]=temp[2]+1;
        for(int i=0;i<4;i++){
            tmp[0]=temp[0]+dx[i];
            tmp[1]=temp[1]+dy[i];
            if(tmp[0]<0||tmp[0]>R-1||tmp[1]<0||tmp[1]>C-1||map[tmp[0]][tmp[1]]=='X'||isvisit[tmp[0]][tmp[1]]){
                    continue;
            }
            if(map[tmp[0]][tmp[1]]=='D'){
                cout<<tmp[2];
                exit(0);
            }
            if(fall[tmp[0]][tmp[1]]>tmp[2]){
                k.push(tmp);
                isvisit[tmp[0]][tmp[1]]=true;
            }
        }
    }
    cout<<"KAKTUS";
    return ;
}