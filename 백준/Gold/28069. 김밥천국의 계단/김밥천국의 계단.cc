#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N,K;
bool isvisit[1000001];
bool BFS();
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    if(BFS()){
        cout<<"minigimbob";
    }
    else
        cout<<"water";
}
bool BFS(){
    queue<pair<int,int> > k;
    k.push({N,K});
    isvisit[N]=true;
    while(!k.empty()){
        int location=k.front().first;
        int move=k.front().second;
        k.pop();
        if(location==1){
            if(move>0){
                return 1;
            }
            continue;
        }
        if(move==0)
            continue;
        if(!isvisit[location-1]){
            k.push({location-1,move-1});
            isvisit[location-1]=true;
        }
        if(location%3==0){
            if(!isvisit[location/3*2]){
                k.push({location/3*2,move-1});
                isvisit[location/3*2]=true;
            }
        }
        else if(location%3==1){
            if(!isvisit[(location-1)/3*2+1]){
                k.push({(location-1)/3*2+1,move-1});
                isvisit[(location-1)/3*2+1]=true;
            }
        }
    }
    return 0;
}