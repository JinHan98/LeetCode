#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

int ans=0;
int arr[20];
bool isvisit[20];
int N;
pair<int,int>hp_happy[20];
void DFS(int idx,int depth,int hp,int happy);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int hp=100;
    int happy=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>hp_happy[i].first;//체력 기쁨
    }
    for(int i=0;i<N;i++){
        cin>>hp_happy[i].second;
    }
    for(int i=0;i<N;i++){
        DFS(i,0,100,0);
    }
    cout<<ans;
}
void DFS(int idx,int depth, int hp,int happy){
    isvisit[idx]=true;
    arr[depth]=idx;
    hp-=hp_happy[idx].first;
    if(hp<=0)
        return ;
    happy+=hp_happy[idx].second;
    if(happy>ans)
        ans=happy;
    for(int i=idx+1;i<N;i++){
        if(!isvisit[i]){
            DFS(i,depth+1,hp,happy);
            isvisit[i]=false;
        }
    }
}
