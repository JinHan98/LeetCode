#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N,M;
vector<int > segtree;
vector<int> num;
int init(int idx,int start,int end);
int get(int idx,int start,int end, int left, int right);
int update(int update_idx,int diff,int idx,int start,int end);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    segtree=vector<int >(4*N);
    num=vector<int>(N+1);
    for(int i=1;i<=N;i++){
        cin>>num[i];
    }
    init(1,1,N);
    int a,b;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        cout<<get(1,1,N,a,b)<<'\n';
    }
    return 0;
    
}
int init(int idx,int start,int end){
    if(start==end){
        segtree[idx]=num[start];
    }
    else{
        segtree[idx]=min(init(idx*2,start,(start+end)/2),init(idx*2+1,(start+end)/2+1,end));
    }
    return segtree[idx];
}
int get(int idx,int start,int end, int left, int right){
    if(start>=left&&end<=right){
        return segtree[idx];
    }
    else if(end<left||start>right)
        return 1000000001;
    else{
        return min(get(idx*2,start,(start+end)/2,left,right),get(idx*2+1,(start+end)/2+1,end,left,right));
    }
}
int update(int update_idx,int diff,int idx,int start,int end){
    if(start==end){
        if(start==update_idx){
            return segtree[idx]=diff;
        }
        else
            return segtree[idx];
    }
    else if(start>update_idx||end<update_idx)
        return segtree[idx];
    
    return segtree[idx]=min(update(update_idx,diff,idx*2,start,(start+end)/2),update(update_idx,diff,idx*2+1,(start+end)/2+1,end));
}