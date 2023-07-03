#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,M,K;
    cin>>N>>M>>K;
    vector<vector<vector<int> > >line(M);
    vector<int> next_idx(M,1);
    for(int i=0;i<N;i++){
        int D,H;
        cin>>D>>H;
        line[i%M].push_back({D,H,-(i%M),i});
    }
    priority_queue<vector<int> > waiting;
    for(int i=0;i<M;i++){
        if(!line[i].empty()){
            waiting.push(line[i][0]);
        }
    }
    int ans=0;
    while(1){
        vector<int> temp=waiting.top();
        if(temp[3]==K){
            cout<<ans;
            return 0;
        }
        waiting.pop();
        if(line[-temp[2]].size()>next_idx[-temp[2]]){
            waiting.push(line[-temp[2]][next_idx[-temp[2]]++]);
        }
        ans++;
    }
}