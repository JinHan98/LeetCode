#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int dest,oil;
pair<int,int> gas[10000];
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>gas[i].first>>gas[i].second;
    }
    sort(gas,gas+N);
    priority_queue<int> k;
    int ans=0;
    int point=0;
    int idx=0;
    cin>>dest>>oil;
    while(oil<dest){
        while(idx<N&&gas[idx].first<=oil){
            k.push(gas[idx++].second);
        }
        if(k.empty()){
            cout<<-1;
            return 0;
        }
        else{
            oil+=k.top();
            k.pop();
            ans++;
        }
    }
    cout<<ans;
}
