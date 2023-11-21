#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;
char board[100][100];
int R,C;
string order;
int dx[10]={0,1,1,1,0,0,0,-1,-1,-1};
int dy[10]={0,-1,0,1,-1,0,1,-1,0,1};
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    pair<int,int> jongsu_position;
    set<pair<int,int> >aduino;
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>board[i][j];
            if(board[i][j]=='I'){
                jongsu_position.first=i;
                jongsu_position.second=j;
            }
            else if(board[i][j]=='R'){
                aduino.insert({i,j});
            }
        }
    }
    cin>>order;
    for(int i=0;i<order.size();i++){
        board[jongsu_position.first][jongsu_position.second]='.';
        jongsu_position.first+=dx[order[i]-'0'];
        jongsu_position.second+=dy[order[i]-'0'];
        if(board[jongsu_position.first][jongsu_position.second]=='R'){
            cout<<"kraj "<<i+1;
            return 0;
        }
        board[jongsu_position.first][jongsu_position.second]='I';
        map<pair<int,int>,int > new_aduino;
        for(auto iter=aduino.begin();iter!=aduino.end();iter++){
            board[iter->first][iter->second]='.';
            int xx=iter->first-jongsu_position.first;
            int yy=iter->second-jongsu_position.second;
            if(xx<0)
                xx=1;
            else if(xx>0)
                xx=-1;
            if(yy<0)
                yy=1;
            else if(yy>0)
                yy=-1;
            if(board[iter->first+xx][iter->second+yy]=='I'){
                cout<<"kraj "<<i+1;
                return 0;
            }
            auto iter2=new_aduino.find({iter->first+xx,iter->second+yy});
            if(iter2!=new_aduino.end()){
                new_aduino[{iter->first+xx,iter->second+yy}]++;
            }
            else
                new_aduino[{iter->first+xx,iter->second+yy}]=1;
        }
        aduino={};
        for(auto iter=new_aduino.begin();iter!=new_aduino.end();iter++){
            if(iter->second==1){
                board[iter->first.first][iter->first.second]='R';
                aduino.insert(iter->first);
            }
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<board[i][j];
        }
        cout<<'\n';
    }
}