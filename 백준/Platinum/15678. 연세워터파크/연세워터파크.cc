#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
long long N,D;
vector<long long> segtree;
vector<long long> num;
//int init(long long idx,long long start,long long end);
long long get(long long idx,long long start,long long end, long long left, long long right);
long long update(long long update_idx,long long diff,long long idx,long long start,long long end);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>D;
    segtree=vector<long long>(4*N+1,-2000000000);
    num=vector<long long>(N+1);
    for(long long i=1;i<=N;i++){
        cin>>num[i];
    }
    update(N,num[N],1,1,N);
    long long ans=num[N];
    for(int i=N-1;i>0;i--){
        int start=i+1;
        int end=i+D;
        if(end>N)
            end=N;
        long long temp=get(1,1,N,start,end);
        long long x=max(0LL,temp);
        ans=max(x+num[i],ans);
        if(i>1)
            update(i,x+num[i],1,1,N);
    }
    cout<<ans;
    return 0;
    
}
// int init(long long idx,long long start,long long end){
//     if(start==end){
//         segtree[idx]={num[start],start};
//     }
//     else{
//         pair<int,int> before=init(idx*2,start,(start+end)/2);
//         pair<int,int> after=init(idx*2+1,(start+end)/2+1,end);
//         if(before.first>after.first)
//             segtree[idx]=before;
//         else
//             segtree[idx]=after;
//     }
//     return segtree[idx];
// }
long long get(long long idx,long long start,long long end, long long left, long long right){
    if(start>=left&&end<=right){
        return segtree[idx];
    }
    else if(end<left||start>right)
        return -2000000000;
    else{
        long long before=get(idx*2,start,(start+end)/2,left,right);
        long long after=get(idx*2+1,(start+end)/2+1,end,left,right);
        return max(before,after);
    }
}
long long update(long long update_idx,long long diff,long long idx,long long start,long long end){
    if(start==end){
        if(start==update_idx){
            segtree[idx]=diff;
            
            return segtree[idx];
        }
        else
            return segtree[idx];
    }
    else if(start>update_idx||end<update_idx)
        return segtree[idx];
    long long before=update(update_idx,diff,idx*2,start,(start+end)/2);
    long long after=update(update_idx,diff,idx*2+1,(start+end)/2+1,end);
    return segtree[idx]=max(before,after);
}