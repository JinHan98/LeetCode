#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int N,M;
int a=0;
int ans[3];
int chicken[30][30];
void DFS(int i,int depth);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>chicken[i][j];
        }
    }
    for(int i=0;i<M;i++){
        DFS(i,0);
    }
    cout<<a;
}
void DFS(int i,int depth){
    ans[depth]=i;
    if(depth==2){
        int temp=0;
        for(int i=0;i<N;i++){
            int tmp=max(chicken[i][ans[0]],chicken[i][ans[1]]);
            tmp=max(tmp,chicken[i][ans[2]]);
            temp+=tmp;
        }
        if(temp>a)
            a=temp;
        return ;
    }
    else{
        for(int k=i+1;k<M;k++){
            DFS(k,depth+1);
        }
    }
}