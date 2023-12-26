#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N,M,Q;
long long acc[100001];
long long acc_out[100001];
pair<long long,long long> mis[100001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M>>Q;
    for(int i=1;i<=N;i++){
        cin>>acc[i];
        long long idx=acc[i]/M;
        idx+=i;
        long long val=acc[i]%M;
        if(val!=0)
            idx++;
        else
            val=M;
        if(idx<=N){
            mis[idx].first++;
            mis[idx].second-=val;
        }
    }
    long long many=0;
    for(int i=1;i<=N;i++){
        acc_out[i]-=mis[i].second;
        acc[i]+=mis[i].second;
        many-=mis[i].first;
        acc[i]-=(M*many);
        acc_out[i]+=(M*many);
        acc[i]+=acc[i-1];
        many++;
    }
    int point,num;
    for(int i=0;i<Q;i++){
        cin>>point>>num;
        if(point==1){
            cout<<acc[num]<<'\n';
        }
        else
            cout<<acc_out[num]<<'\n';
    }
    return 0;
}