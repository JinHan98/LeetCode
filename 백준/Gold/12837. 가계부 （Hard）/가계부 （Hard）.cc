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
    cin>>N>>M;
    segtree=vector<long long >(4*N);
    num=vector<long long>(N+1);
    int a,b,c;
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        if(a==1){
            update(b,c,1,1,N);
        }
        else{
            long long temp=get(1,1,N,b,c);
            cout<<temp<<'\n';
        }
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
        return before+after;
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
            num[start]+=diff;
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