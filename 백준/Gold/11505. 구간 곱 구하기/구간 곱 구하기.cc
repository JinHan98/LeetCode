#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
long long N,M,K;
vector<long long> segtree;
vector<long long> num;
long long init(long long idx,long long start,long long end);
long long mul(long long idx,long long start,long long end, long long left, long long right);
long long update(long long update_idx,long long diff,long long idx,long long start,long long end);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M>>K;
    segtree=vector<long long>(4*N);
    num=vector<long long>(N+1);
    for(long long i=1;i<=N;i++){
        cin>>num[i];
    }
    init(1,1,N);
    long long a,b,c;
    for(long long i=0;i<M+K;i++){
        cin>>a>>b>>c;
        if(a==1){
            if(num[b]!=0){
                update(b,c,1,1,N);
                num[b]=c;
            }
            else{
                num[b]=c;
                init(1,1,N);
            }
        }
        else{
            cout<<mul(1,1,N,b,c)<<'\n';
        }
    }
    return 0;
    
}
long long init(long long idx,long long start,long long end){
    if(start==end)
        segtree[idx]=num[start];
    else{
        segtree[idx]=(init(idx*2,start,(start+end)/2)*init(idx*2+1,(start+end)/2+1,end))%1000000007;
    }
    return segtree[idx];
}
long long mul(long long idx,long long start,long long end, long long left, long long right){
    if(start>=left&&end<=right){
        return segtree[idx];
    }
    else if(end<left||start>right)
        return 1;
    else{
        return (mul(idx*2,start,(start+end)/2,left,right)*mul(idx*2+1,(start+end)/2+1,end,left,right))%1000000007;
    }
}
long long update(long long update_idx,long long diff,long long idx,long long start,long long end){
    if(start>update_idx||end<update_idx)
        return segtree[idx];
    else if(start==end){
        if(start==update_idx){
            return segtree[idx]=diff;
        }
        else
            return segtree[idx];
    }
    return segtree[idx]=(update(update_idx,diff,idx*2,start,(start+end)/2)*update(update_idx,diff,idx*2+1,(start+end)/2+1,end))%1000000007;
}