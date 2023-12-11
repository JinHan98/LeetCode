#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
long long N,M;
vector<pair<long long,long long> > segtree;
vector<long long> num;
pair<long long,long long> init(long long idx,long long start,long long end);
pair<long long,long long> get(long long idx,long long start,long long end, long long left, long long right);
pair<long long,long long> update(long long update_idx,long long diff,long long idx,long long start,long long end);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    segtree=vector<pair<long long,long long> >(4*N);
    num=vector<long long>(N+1);
    for(int i=1;i<=N;i++){
        cin>>num[i];
    }
    init(1,1,N);
    int a,b,c;
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        if(a==1){
            update(b,c,1,1,N);
        }
        else{
            pair<long long,long long> temp=get(1,1,N,b,c);
            cout<<temp.first+temp.second<<'\n';
        }
    }
    return 0;
    
}
pair<long long,long long> init(long long idx,long long start,long long end){
    if(start==end){
        segtree[idx].first=num[start];
    }
    else{
        pair<long long,long long> before=init(idx*2,start,(start+end)/2);
        pair<long long,long long> after=init(idx*2+1,(start+end)/2+1,end);
        if(before.first>after.first){
            segtree[idx].first=before.first;
            segtree[idx].second=max(after.first,before.second);
        }
        else if(before.first<after.first){
            segtree[idx].first=after.first;
            segtree[idx].second=max(after.second,before.first);
        }
        else
            segtree[idx]={after.first,before.first};
    }
    return segtree[idx];
}
pair<long long,long long> get(long long idx,long long start,long long end, long long left, long long right){
    if(start>=left&&end<=right){
        return segtree[idx];
    }
    else if(end<left||start>right)
        return {0,0};
    else{
        pair<long long,long long> before=get(idx*2,start,(start+end)/2,left,right);
        pair<long long,long long> after=get(idx*2+1,(start+end)/2+1,end,left,right);
        if(before.first>after.first){
            return {before.first,max(after.first,before.second)};
        }
        else if(before.first<after.first){
            return {after.first,max(after.second,before.first)};
        }
        else
            return {after.first,before.first};
    }
}
pair<long long,long long> update(long long update_idx,long long diff,long long idx,long long start,long long end){
    if(start==end){
        if(start==update_idx){
            num[start]=diff;
            segtree[idx].first=num[start];
            return segtree[idx];
        }
        else
            return segtree[idx];
    }
    else if(start>update_idx||end<update_idx)
        return segtree[idx];
    pair<long long,long long> before=update(update_idx,diff,idx*2,start,(start+end)/2);
    pair<long long,long long> after=update(update_idx,diff,idx*2+1,(start+end)/2+1,end);
    if(before.first>after.first){
        return segtree[idx]={before.first,max(after.first,before.second)};
    }
    else if(before.first<after.first){
        return segtree[idx]={after.first,max(after.second,before.first)};
    }
    else
        return segtree[idx]={after.first,before.first};
}