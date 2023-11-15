#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>
void join(int a,int b);
int find(int a);
int line[100001];
using namespace std;
int N,M;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        line[i]=i;
    }
    priority_queue<pair<int,pair<int,int> > >k;
    int start,end,val;
    for(int i=0;i<M;i++){
        cin>>start>>end>>val;
        k.push({val,{start,end}});
    }
    cin>>start>>end;
    int current=k.top().first;
    while(!k.empty()){
        while(!k.empty()){
            if(current==k.top().first){
                join(k.top().second.first,k.top().second.second);
                k.pop();
            }
            else{
                break;
            }
        }
        if(find(start)==find(end)){
            cout<<current;
            return 0;
        }
        current=k.top().first;
    }
}
void join(int a,int b){
    a=find(a);
    b=find(b);
    if(line[a]!=line[b]){
        if(line[a]>line[b]){
            line[a]=line[b];
        }
        else
            line[b]=line[a];
    }
}
int find(int a){
    if(line[a]==a)
        return a;
    else{
        return line[a]=find(line[a]);
    }
}