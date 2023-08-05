#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
// 1 apple 2 snake
using namespace std;
int board[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
pair<int,char> k[100];
int N,K,L;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int time=0;
    int dir=0;
    int ix=0;
    queue<pair<int,int> >snake; 
    cin>>N>>K;
    int x,y;
    for(int i=0;i<K;i++){
        cin>>x>>y;
        board[x][y]=1;
    }
    cin>>L;
    for(int i=0;i<L;i++){
        cin>>k[i].first>>k[i].second;
    }
    board[1][1]=2;
    snake.push(make_pair(1,1));
    while(1){
        if(ix<L&&time==k[ix].first){
            if(k[ix].second=='D')
                dir++;
            else
                dir--;
            if(dir==4)
                dir=0;
            if(dir==-1)
                dir=3;
            ix++;
        }
        time++;
        snake.push(make_pair(snake.back().first+dy[dir],snake.back().second+dx[dir]));
        if(snake.back().first<1||snake.back().first>N||snake.back().second<1||snake.back().second>N){
            break;
        }
        if(board[snake.back().first][snake.back().second]!=1){
            if(board[snake.back().first][snake.back().second]==2)
                break;
            board[snake.front().first][snake.front().second]=0;
            snake.pop();
        }
        if(board[snake.back().first][snake.back().second]!=2)
            board[snake.back().first][snake.back().second]=2;
        else
            break;
    }
    cout<<time;
}

/*
1 1 10000
1 1 0
1 0 10001

*/