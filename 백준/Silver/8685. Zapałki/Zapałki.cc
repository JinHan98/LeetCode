#include <iostream>
#include <algorithm>
using namespace std;
int N;
pair<int,int> candle_map[1000000];
int candle[1000000];
int DP[1000000];
int DFS(int idx);
int main() {
    cin>>N;
    int idx=0;
    for(int i=0;i<N;i++){
        cin>>candle_map[idx].first;
        if(idx>0&&candle_map[idx].first==candle_map[idx-1].first){
            DP[idx-1]++;
            continue;
        }
        candle[idx]=candle_map[idx].first;
        candle_map[idx].second=idx;
        idx++;
    }
    N=idx;
    sort(candle_map,candle_map+N);
    for(int i=0;i<N;i++){
        DP[candle_map[i].second]=DFS(candle_map[i].second);
    }
    int ans=0;
    for(int i=0;i<N;i++){
        if(DP[i]>ans)
            ans=DP[i];
    }
    cout<<ans;
    return 0;
}
int DFS(int idx){
    int ans=DP[idx]+1;
    if(idx<N-1&&candle[idx+1]<candle[idx]){
        ans+=DP[idx+1];
    }  
    if(idx>0&&candle[idx-1]<candle[idx]){
        ans+=DP[idx-1];
    }
    return DP[idx]=ans;
}