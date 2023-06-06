#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N,M;
char board[10][10];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
pair<int,int> R_point;
pair<int,int> B_point;
pair<int,int> O_point;
int BFS();
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]=='R'){
                R_point={i,j};
                board[i][j]='.';
            }
            else if(board[i][j]=='B'){
                B_point={i,j};
                board[i][j]='.';
            }
            else if(board[i][j]=='O'){
                O_point={i,j};
            }
        }
    }
    cout<<BFS();
}
int BFS(){
    queue<vector<pair<int,int> > >k;
    vector<pair<int,int> >temp(3);
    temp[0]=R_point;
    temp[1]=B_point;
    temp[2]={0,0};
    k.push(temp);
    while(!k.empty()){
        temp=k.front();
        vector<pair<int,int> >tmp(3);
        if(temp[2].first==10)
            break;
        k.pop();
        for(int i=0;i<4;i++){//오,왼, 아래, 위
            tmp=temp;
            tmp[2].first=temp[2].first+1;
            bool ed=false;
            for(int j=1;j<10;j++){
                if(tmp[0].first+dx[i]<1||tmp[0].second+dy[i]<1||tmp[0].first+dx[i]>N-2||tmp[0].second+dy[i]>M-2||(tmp[0].first+dx[i]==tmp[1].first&&tmp[0].second+dy[i]==tmp[1].second))
                    break;
                if(board[tmp[0].first+dx[i]][tmp[0].second+dy[i]]=='.'){
                    tmp[0].first+=dx[i];
                    tmp[0].second+=dy[i];
                }
                else if(board[tmp[0].first+dx[i]][tmp[0].second+dy[i]]=='O'){
                    ed=true;
                    tmp[0]={0,0};
                    break;
                }
                else
                    break;
            }
            bool fail=false;
            for(int j=1;j<10;j++){
                if(tmp[1].first+dx[i]<1||tmp[1].second+dy[i]<1||tmp[1].first+dx[i]>N-2||tmp[1].second+dy[i]>M-2||(tmp[0].first==tmp[1].first+dx[i]&&tmp[0].second==tmp[1].second+dy[i]))
                    break;
                if(board[tmp[1].first+dx[i]][tmp[1].second+dy[i]]=='.'){
                    tmp[1].first+=dx[i];
                    tmp[1].second+=dy[i];
                }
                else if(board[tmp[1].first+dx[i]][tmp[1].second+dy[i]]=='O'){
                    fail=true;
                    break;
                }
                else
                    break;
            }
            if(fail)
                continue;
            if(ed){
                return tmp[2].first;
            }
            for(int j=1;j<10;j++){
                if(tmp[0].first+dx[i]<1||tmp[0].second+dy[i]<1||tmp[0].first+dx[i]>N-2||tmp[0].second+dy[i]>M-2||(tmp[0].first+dx[i]==tmp[1].first&&tmp[0].second+dy[i]==tmp[1].second))
                    break;
                if(board[tmp[0].first+dx[i]][tmp[0].second+dy[i]]=='.'){
                    tmp[0].first+=dx[i];
                    tmp[0].second+=dy[i];
                }
                else if(board[tmp[0].first+dx[i]][tmp[0].second+dy[i]]=='O')
                    return tmp[2].first;
                else
                    break;
            }
            if(temp[0]==tmp[0]&&temp[1]==tmp[1])
                continue;
            k.push(tmp);
        }
    }
    return -1;
}