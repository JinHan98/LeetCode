#include<iostream>
#include<algorithm>
#include <queue>
#include <cmath>
using namespace std;
priority_queue<int,vector<int>,greater<int> > room[1000];
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >k;
    int ans=2000000000;
    cin>>N>>M;
    int num;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>num;
            room[i].push(num);
        }
    }
    int mx=0;
    for(int i=0;i<N;i++){
        k.push({room[i].top(),i});
        if(room[i].top()>mx)
            mx=room[i].top();
        room[i].pop();
    }
    ans=mx-k.top().first;
    while(1){
        if(room[k.top().second].empty())
            break;
        k.push({room[k.top().second].top(),k.top().second});
        if(room[k.top().second].top()>mx)
            mx=room[k.top().second].top();
        room[k.top().second].pop();
        k.pop();
        if(ans>mx-k.top().first){
            ans=mx-k.top().first;
        }
    }
    cout<<ans;
}
