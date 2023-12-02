#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N,M;
vector<pair<int,int> > segtree;
vector<int> num;
pair<int,int> init(int idx,int start,int end);
pair<int,int> get(int idx,int start,int end, int left, int right);
pair<int,int> update(int update_idx,int diff,int idx,int start,int end);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    segtree=vector<pair<int,int> >(4*N);
    num=vector<int>(N+1);
    for(int i=1;i<=N;i++){
        cin>>num[i];
    }
    cin>>M;
    init(1,1,N);
    int a,b,c;
    for(int i=0;i<M;i++){
        cin>>a>>b>>c;
        if(a==1){
            update(b,c,1,1,N);
            num[b]=c;
        }
        else{
            cout<<get(1,1,N,b,c).second<<'\n';
        }
    }
    return 0;
    
}
pair<int,int> init(int idx,int start,int end){
    if(start==end){
        segtree[idx].first=num[start];
        segtree[idx].second=start;
    }
    else{
        segtree[idx]=min(init(idx*2,start,(start+end)/2),init(idx*2+1,(start+end)/2+1,end));
    }
    return segtree[idx];
}
pair<int,int> get(int idx,int start,int end, int left, int right){
    if(start>=left&&end<=right){
        return segtree[idx];
    }
    else if(end<left||start>right)
        return {1000000001,0};
    else{
        return min(get(idx*2,start,(start+end)/2,left,right),get(idx*2+1,(start+end)/2+1,end,left,right));
    }
}
pair<int,int> update(int update_idx,int diff,int idx,int start,int end){
    if(start==end){
        if(start==update_idx){
            return segtree[idx]={diff,start};
        }
        else
            return segtree[idx];
    }
    else if(start>update_idx||end<update_idx)
        return segtree[idx];
    
    return segtree[idx]=min(update(update_idx,diff,idx*2,start,(start+end)/2),update(update_idx,diff,idx*2+1,(start+end)/2+1,end));
}