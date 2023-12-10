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
    segtree=vector<long long >(4*N);
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
        segtree[idx]=min(init(idx*2,start,(start+end)/2),init(idx*2+1,(start+end)/2+1,end));
    }
    return segtree[idx];
}
long long get(long long idx,long long start,long long end, long long left, long long right){
    if(start>=left&&end<=right){
        return segtree[idx];
    }
    else if(end<left||start>right)
        return 1000000001;
    else{
        return min(get(idx*2,start,(start+end)/2,left,right),get(idx*2+1,(start+end)/2+1,end,left,right));
    }
}
long long update(long long update_idx,long long diff,long long idx,long long start,long long end){
    if(start==end){
        if(start==update_idx){
            num[start]=diff;
            return segtree[idx]=num[start];
        }
        else
            return segtree[idx];
    }
    else if(start>update_idx||end<update_idx)
        return segtree[idx];
    return segtree[idx]=min(update(update_idx,diff,idx*2,start,(start+end)/2),update(update_idx,diff,idx*2+1,(start+end)/2+1,end));
}