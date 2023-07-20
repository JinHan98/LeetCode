#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N,T,W,M;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    queue<pair<int,int> > waiting;
    priority_queue<vector<int>,vector<vector<int> >,greater<vector<int> > > come;
    cin>>N>>T>>W;
    for(int i=0;i<N;i++){
        int px,tx;
        cin>>px>>tx;
        waiting.push({px,tx});
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int px,tx,cx;
        cin>>px>>tx>>cx;
        come.push({cx,px,tx});
    }
    int time=0;
    while(time<W){
        bool rest=false;
        if(waiting.front().second>T){
            for(int i=0;i<T;i++){
                if(i+time==W)
                    break;
                cout<<waiting.front().first<<'\n';
                
            }
            waiting.front().second-=T;
            time+=T;
            rest=true;
        }
        else{
            for(int i=0;i<waiting.front().second;i++){
                if(i+time==W)
                    break;
                cout<<waiting.front().first<<'\n';
                
            }
            time+=waiting.front().second;
            waiting.pop();
        }
        while(!come.empty()){
            if(come.top()[0]<=time){
                waiting.push({come.top()[1],come.top()[2]});
                come.pop();
            }
            else
                break;
        }
        if(rest){
            waiting.push(waiting.front());
            waiting.pop();
        }
    }
}