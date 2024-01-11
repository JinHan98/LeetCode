#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N,M;
vector<long long> segtree;
vector<long long> num;
long long init(long long idx,long long start,long long end);
void get(long long idx,long long start,long long end, long long left, long long right,long long var);
long long update(long long update_idx,long long idx,long long start,long long end);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    segtree=vector<long long>(4*N+1);
    num=vector<long long>(N+1);
    for(int i=1;i<=N;i++){
        cin>>num[i];
    }
    cin>>M;
    init(1,1,N);
    int a,b,c,d;
    for(int i=1;i<=M;i++){
        cin>>a;
        if(a==1){
            cin>>b>>c>>d;
            get(1,1,N,b,c,d);
        }
        else{
            cin>>b;
            cout<<update(b,1,1,N)<<'\n';
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
    }
    return segtree[idx];
}
void get(long long idx,long long start,long long end, long long left, long long right,long long var){
    if(start>=left&&end<=right){
        segtree[idx]+=var;
        return ;
    }
    else if(end<left||start>right)
        return ;
    get(idx*2,start,(start+end)/2,left,right,var);
    get(idx*2+1,(start+end)/2+1,end,left,right,var);
}
long long update(long long update_idx,long long idx,long long start,long long end){
    if(start==end){
        if(start==update_idx){
            return segtree[idx];
        }
        else
            return 0;
    }
    else if(start>update_idx||end<update_idx)
        return 0;
    long long before=update(update_idx,idx*2,start,(start+end)/2);
    long long after=update(update_idx,idx*2+1,(start+end)/2+1,end);
    return before+after+segtree[idx];
}