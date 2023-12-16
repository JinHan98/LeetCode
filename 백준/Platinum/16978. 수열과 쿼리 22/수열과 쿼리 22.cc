#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
long long N,M;
vector<long long > segtree;
vector<long long> num;
long long init(long long idx,long long start,long long end);
long long get(long long idx,long long start,long long end, long long left, long long right);
long long update(long long update_idx,long long diff,long long idx,long long start,long long end);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    segtree=vector<long long >(4*N+1);
    num=vector<long long>(N+1);
    vector<vector<long long> > change;
    priority_queue<vector<long long>,vector<vector<long long> >,greater<vector<long long> > > query;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > ans;
    long long a,b,c;
    for(long long i=1;i<=N;i++){
        cin>>num[i];
    }
    cin>>M;
    init(1,1,N);
    for(long long i=0;i<M;i++){
        cin>>a;
        if(a==1){
            cin>>b>>c;
            change.push_back({b,c});
        }
        else{
            long long order;
            cin>>order>>b>>c;
            query.push({order,b,c,i});
        }
    }
    long long current_order=0;
    while(!query.empty()){
        if(current_order==query.top()[0]){
            ans.push({query.top()[3],get(1,1,N,query.top()[1],query.top()[2])});
            query.pop();
        }
        else{
            update(change[current_order][0],change[current_order][1],1,1,N);
            current_order++;
        }
    }
    while(!ans.empty()){
        cout<<ans.top().second<<'\n';
        ans.pop();
    }
    return 0;
    
}
long long init(long long idx,long long start,long long end){
    if(start==end){
        segtree[idx]=num[start];
    }
    else{
        long long before=init(idx*2,start,(start+end)/2);
        long long after=init(idx*2+1,(start+end)/2+1,end);
        segtree[idx]=before+after;
    }
    return segtree[idx];
}
long long get(long long idx,long long start,long long end, long long left, long long right){
    if(start>=left&&end<=right){
        return segtree[idx];
    }
    else if(end<left||start>right)
        return 0;
    else{
        long long before=get(idx*2,start,(start+end)/2,left,right);
        long long after=get(idx*2+1,(start+end)/2+1,end,left,right);
        return before+after;
    }
}
long long update(long long update_idx,long long diff,long long idx,long long start,long long end){
    if(start==end){
        if(start==update_idx){
            num[start]=diff;
            segtree[idx]=num[start];
            return segtree[idx];
        }
        else
            return segtree[idx];
    }
    else if(start>update_idx||end<update_idx)
        return segtree[idx];
    long long before=update(update_idx,diff,idx*2,start,(start+end)/2);
    long long after=update(update_idx,diff,idx*2+1,(start+end)/2+1,end);
    return segtree[idx]=before+after;
}