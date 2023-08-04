#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int ans=0;
int R,C,K;
char camp[5][5];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool isvisit[5][5];
void DFS(int x, int y, int depth);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>R>>C>>K;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>camp[i][j];
        }
    }
    DFS(0,C-1,1);
    cout<<ans;
}
void DFS(int x, int y, int depth){
    isvisit[x][y]=true;
    if(depth==K){
        if(x==R-1&&y==0)
            ans++;
        return ;
    }
    for(int i=0;i<4;i++){
        int new_x=x+dx[i];
        int new_y=y+dy[i];
        if(new_x<0||new_x>R-1||new_y<0||new_y>C-1)
            continue;
        if(!isvisit[new_x][new_y]&&camp[new_x][new_y]!='T'){
            DFS(new_x,new_y,depth+1);
            isvisit[new_x][new_y]=false;
        }
    }
}