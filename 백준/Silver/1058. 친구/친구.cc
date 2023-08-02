#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
char rel[51][51];
int temp;
int ans=0;
int N;
set<int> num;
void DFS(int current,int depth);
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>rel[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        num.clear();
        DFS(i,0);
        ans=max(ans,(int)num.size()-1);
    }
    cout<<ans;
}
void DFS(int current,int depth){
    num.insert(current);
    if(depth==2)
        return ;
    for(int j=1;j<=N;j++){
        if(rel[current][j]=='Y')
            DFS(j,depth+1);
    }
}
