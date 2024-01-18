#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int R,C;
char map[1500][1500];
bool isvisit[1500][1500];
void BBFS();
void WBFS();
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<pair<int,int> >bq;
queue<pair<int,int> >btq;
queue<pair<int,int> >wq;
queue<pair<int,int> >wtq;
pair<int,int> start={-1,-1};
int tm=0;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>map[i][j];
            if(map[i][j]=='L'){
                if(start.first==-1){
                    start.first=i;
                    start.second=j;
                }
                wq.push({i,j});
            }
            else if(map[i][j]=='.')
                wq.push({i,j});
        }
    }
    bq.push({start.first,start.second});
    isvisit[start.first][start.second]=true;
    while(1){
        BBFS();
        WBFS();
        tm++;
        bq=btq;
        while(!btq.empty())
            btq.pop();
        wq=wtq;
        while(!wtq.empty())
            wtq.pop();
    }
    return 0;
}
void BBFS(){
   while(!bq.empty()){
       pair<int,int> temp=bq.front();
       bq.pop();
       for(int i=0;i<4;i++){
            int x=temp.first+dx[i];
            int y=temp.second+dy[i];
            if(x<0||y<0||x>R-1||y>C-1)
                continue;
            if(isvisit[x][y])
                continue;
            if(map[x][y]=='.'){
                bq.push({x,y});
                isvisit[x][y]=true;
            }
            else if(map[x][y]=='X'&&!isvisit[x][y]){
                btq.push({x,y});
                isvisit[x][y]=true;
            }
            else{
                cout<<tm;
                exit(0);
            }
       }
   }
   return ;
}
void WBFS(){
    while(!wq.empty()){
        pair<int,int> temp=wq.front();
        wq.pop();
        for(int i=0;i<4;i++){
            int x=temp.first+dx[i];
            int y=temp.second+dy[i];
            if(x<0||y<0||x>R-1||y>C-1)
                continue;
            if(map[x][y]=='X'){
                map[x][y]='.';
                wtq.push({x,y});
            }
        }
    }
}