#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char map[5][5];
void DFS(int i,int j,int many, string num);
set<string> ans;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            DFS(i,j,1,"");
        }
    }
    cout<<ans.size();
}
void DFS(int i,int j,int many, string num){
    num.push_back(map[i][j]);
    if(many==6){
        ans.insert(num);
        return ;
    }
    for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x<0||x>4||y<0||y>4)
            continue;
        DFS(x,y,many+1,num);
    }
    
}
