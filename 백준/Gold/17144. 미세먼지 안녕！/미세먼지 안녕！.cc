#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int R,C,T;
pair<int,int> house[50][50];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
pair<int,int> f_con;
pair<int,int> l_con;
void influ();
void add();
void move();
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>R>>C>>T;
    bool st=false;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>house[i][j].first;
            if(st)
                continue;
            if(house[i][j].first==-1){
                f_con.first=i;
                f_con.second=j;
                l_con.first=i+1;
                l_con.second=j;
                st=true;
            }
        }
    }
    for(int i=0;i<T;i++){
        influ();
        add();
        move();
    }
    int ans=0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(house[i][j].first!=-1){
                ans+=house[i][j].first;
            }
        }
    }
    cout<<ans;
}
void influ(){
    for(int x=0;x<R;x++){
        for(int y=0;y<C;y++){
            int value=house[x][y].first;
            if(value==-1)
                continue;
            for(int k=0;k<4;k++){
                int new_x=x+dx[k];
                int new_y=y+dy[k];
                if(new_x<0||new_x>R-1||new_y<0||new_y>C-1)
                    continue;
                if(house[new_x][new_y].first==-1)
                    continue;
                house[new_x][new_y].second+=(value/5);
                house[x][y].first-=(value/5);
                
            }
        }
    }
}
void add(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            house[i][j].first+=house[i][j].second;
            house[i][j].second=0;
        }
    }
}
void move(){
    house[f_con.first-1][f_con.second].first=0;
    for(int i=f_con.first-1;i>0;i--){
        house[i][f_con.second].first=house[i-1][f_con.second].first;
    }
    for(int i=0;i<C-1;i++){
        house[0][i].first=house[0][i+1].first;
    }
    for(int i=0;i<f_con.first;i++){
        house[i][C-1].first=house[i+1][C-1].first;
    }
    for(int i=C-1;i>1;i--){
        house[f_con.first][i].first=house[f_con.first][i-1].first;
    }
    house[f_con.first][f_con.second+1].first=0;
    house[l_con.first+1][f_con.second].first=0;
    for(int i=l_con.first+1;i<R-1;i++){
        house[i][l_con.second].first=house[i+1][l_con.second].first;
    }
    for(int i=0;i<C-1;i++){
        house[R-1][i].first=house[R-1][i+1].first;
    }
    for(int i=R-1;i>l_con.first;i--){
        house[i][C-1].first=house[i-1][C-1].first;
    }
    for(int i=C-1;i>1;i--){
        house[l_con.first][i].first=house[l_con.first][i-1].first;
    }
    house[l_con.first][f_con.second+1].first=0;
}