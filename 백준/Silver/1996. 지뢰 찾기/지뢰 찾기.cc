#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
using namespace std;
int N;
int dx[8]={1,0,-1,1,-1,1,0,-1};
int dy[8]={1,1,1,0,0,-1,-1,-1};
char bomb[1000][1000];
int num[1000][1000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>bomb[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(bomb[i][j]!='.'){
                for(int k=0;k<8;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x<0||x>N-1||y<0||y>N-1)
                        continue;
                    num[x][y]+=(bomb[i][j]-'0');
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(bomb[i][j]!='.'){
                cout<<'*';
                continue;
            }
            if(num[i][j]>9){
                cout<<'M';
            }
            else{
                cout<<num[i][j];
            }
        }
        cout<<'\n';
    }
}
