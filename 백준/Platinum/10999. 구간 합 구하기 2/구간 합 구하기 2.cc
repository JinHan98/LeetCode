#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N,M,K;
vector<pair<long long,long long> > segtree;
vector<long long> num;
void update_lazy(long long idx,long long start, long long end);
long long init(long long idx,long long start,long long end);
long long get(long long idx,long long start,long long end, long long left, long long right);
void update(long long idx,long long start,long long end, long long left, long long right,long long val);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M>>K;
    segtree=vector<pair<long long,long long> >(4*(N+1));
    num=vector<long long>(N+1);
    for(int i=1;i<=N;i++){
        cin>>num[i];
    }
    init(1,1,N);
    long long a,b,c,d;
    for(int i=1;i<=M+K;i++){
        cin>>a;
        if(a==1){
            cin>>b>>c>>d;
            update(1,1,N,b,c,d);
        }
        else{
            cin>>b>>c;
            cout<<get(1,1,N,b,c)<<'\n';
        }
    }
    
    return 0;
    
}
long long init(long long idx,long long start,long long end){
    if(start==end){
        segtree[idx].first=num[start];
    }
    else{
        long long before=init(idx*2,start,(start+end)/2);
        long long after=init(idx*2+1,(start+end)/2+1,end);
        segtree[idx].first=before+after;
    }
    return segtree[idx].first;
}
void update_lazy(long long idx,long long start, long long end){
    if(segtree[idx].second!=0){
        segtree[idx].first+=(segtree[idx].second*(end-start+1));
        if(start!=end){
            segtree[idx*2].second+=segtree[idx].second;
            segtree[idx*2+1].second+=segtree[idx].second;
        }
        segtree[idx].second=0;
    }
}
long long get(long long idx,long long start,long long end, long long left, long long right){
    update_lazy(idx,start,end);
    if(start>=left&&end<=right){
        return segtree[idx].first;
    }
    else if(end<left||start>right)
        return 0;
    long long before=get(idx*2,start,(start+end)/2,left,right);
    long long after=get(idx*2+1,(start+end)/2+1,end,left,right);
    return before+after;
}
void update(long long idx,long long start,long long end, long long left, long long right,long long val){
    update_lazy(idx,start,end);
    if(start>=left&&end<=right){
        segtree[idx].first+=(val*(end-start+1));
        if(start!=end){
            segtree[idx*2].second+=val;
            segtree[idx*2+1].second+=val;
        }
        return ;
    }
    else if(end<left||start>right)
        return ;
    update(idx*2,start,(start+end)/2,left,right,val);
    update(idx*2+1,(start+end)/2+1,end,left,right,val);
    segtree[idx].first=segtree[idx*2].first+segtree[idx*2+1].first;
}