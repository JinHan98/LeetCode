#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N,K;
pair<int,int> num[100001];
long long acc[100001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        cin>>num[i].second>>num[i].first;
    }
    sort(num,num+N+1);
    for(int i=1;i<=N;i++)
        acc[i]=acc[i-1]+num[i].second;
    int start_idx=0;
    int end_idx=-1;
    long long ans=0;
    for(int i=1;i<=N;i++){
        if(num[start_idx].first+(2*K)<num[i].first){
            end_idx=i-1;
            break;
        }
    }
    if(end_idx==-1){
        end_idx=N;
        cout<<acc[N];
        return 0;
    }
    else{
        if(acc[end_idx]-acc[start_idx-1]>ans)
            ans=acc[end_idx]-acc[start_idx-1];
    }
    while(end_idx<=N){
        start_idx++;
        bool ed=true;
        for(int i=end_idx;i<=N;i++){
            if(num[start_idx].first+(2*K)<num[i].first){
                end_idx=i-1;
                ed=false;
                break;
            }
        }
        if(ed){
            end_idx=N;
            if(acc[end_idx]-acc[start_idx-1]>ans)
                ans=acc[end_idx]-acc[start_idx-1];    
            break;
        }
        else{
            if(acc[end_idx]-acc[start_idx-1]>ans)
                ans=acc[end_idx]-acc[start_idx-1];
        }
    }
    cout<<ans;
}