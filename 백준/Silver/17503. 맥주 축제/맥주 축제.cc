#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N,M,K;
struct cmp
{
    bool operator()(pair<long long,long long> &a,pair<long long,long long> &b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        else
            return a.second>b.second;
    }
};

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M>>K;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,cmp> yet;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > already;
    long long count=0;
    long long sum_v=0;
    int v,c;
    long long all_sum=0;
    for(int i=0;i<K;i++){
        cin>>v>>c;
        yet.push({v,c});
        all_sum+=v;
    }
    if(all_sum<M){
        cout<<-1;
        return 0;
    }
    int val;
    pair<long long,long long> temp;
    while(!yet.empty()){
        temp=yet.top();
        if(count<N){
            count++;
            sum_v+=temp.first;
            already.push(temp);
            val=temp.second;
        }
        else{
            if(sum_v>=M){
                cout<<val;
                return 0;
            }
            else{
                sum_v-=already.top().first;
                val=temp.second;
                already.pop();
                sum_v+=temp.first;
                already.push(temp);
                if(sum_v>=M){
                    cout<<val;
                    return 0;
                }
            }
        }
        yet.pop();
    }
    if(sum_v>=M){
        cout<<val;
        return 0;
    }
    cout<<-1;
    return 0;
}