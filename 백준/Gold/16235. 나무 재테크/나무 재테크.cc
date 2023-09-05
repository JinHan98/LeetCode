#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N,M,K;
int yangboon[11][11];//현재 양분
int plus_yangboon[11][11];//추가되는 양분
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
deque<int> tree[11][11];
deque<pair<int,int> > bunsik;
void spring_summer();
void fall();
void winter();
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>plus_yangboon[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            yangboon[i][j]=5;
    }
    for(int i=0;i<M;i++){
        int x,y,z;
        cin>>x>>y>>z;
        tree[x][y].push_back(z);
    }
    for(int i=0;i<K;i++){
        spring_summer();
        fall();
        winter();
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            ans+=tree[i][j].size();
        }
    }
    cout<<ans;
}
void spring_summer(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(tree[i][j].empty())
                continue;
            else{
                deque<int> new_tree;
                int dead=0;
                for(int t :tree[i][j]){
                    if(t<=yangboon[i][j]){
                        yangboon[i][j]-=t;
                        new_tree.push_back(t+1);
                        if((t+1)%5==0){
                            bunsik.push_back({i,j});
                        }
                    }
                    else{
                        dead+=(t/2);
                    }
                }
                yangboon[i][j]+=dead;
                tree[i][j]=new_tree;
            }
        }
    }
}
void fall(){
    while(!bunsik.empty()){
        pair<int,int> temp=bunsik.front();
        for(int k=0;k<8;k++){
            int x=temp.first+dx[k];
            int y=temp.second+dy[k];
            if(x<1||x>N||y<1||y>N)
                continue;
            tree[x][y].push_front(1);
        }
        bunsik.pop_front();
    }
}
void winter(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            yangboon[i][j]+=plus_yangboon[i][j];
        }
    }
}