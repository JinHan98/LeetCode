#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,C,M;
priority_queue<vector<int>,vector<vector<int> >,greater<vector<int> > >k;
int mx_val[2001];
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>C>>M;
    int s,e,w;
    int ans=0;
    for(int i=0;i<M;i++){
        cin>>s>>e>>w;
        k.push({e,s,w});
    }
    while(!k.empty()){
        int weight=k.top()[2];
        for(int i=k.top()[1];i<k.top()[0];i++){
            weight=min(weight,C-mx_val[i]);
        }
        if(weight>0){
            ans+=weight;
            for(int i=k.top()[1];i<k.top()[0];i++){
                mx_val[i]+=weight;
            }
        }
        k.pop();
    }
    cout<<ans;
}