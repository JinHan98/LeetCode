#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
long long N,K;
vector<char> segtree;
vector<long long> num;
char init(long long idx,long long start,long long end);
char get(long long idx,long long start,long long end, long long left, long long right);
char update(long long update_idx,long long diff,long long idx,long long start,long long end);
char giho(char a,char b);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    while(1){
        cin>>N>>K;
        if(cin.eof())
            break;
        segtree=vector<char>(4*N+1);
        num=vector<long long>(N+1);
        vector<vector<long long> > change;
        long long b,c;
        char a;
        for(long long i=1;i<=N;i++){
            cin>>num[i];
        }
        init(1,1,N);
        for(long long i=0;i<K;i++){
            cin>>a>>b>>c;
            if(a=='C'){
                update(b,c,1,1,N);
            }
            else{
                cout<<get(1,1,N,b,c);
            }
        }
        cout<<'\n';
    }
    return 0;
    
}
char init(long long idx,long long start,long long end){
    if(start==end){
        if(num[start]>0)
            segtree[idx]='+';
        else if(num[start]<0)
            segtree[idx]='-';
        else
            segtree[idx]='0';
    }
    else{
        char before=init(idx*2,start,(start+end)/2);
        char after=init(idx*2+1,(start+end)/2+1,end);
        segtree[idx]=giho(before,after);
    }
    return segtree[idx];
}
char get(long long idx,long long start,long long end, long long left, long long right){
    if(start>=left&&end<=right){
        return segtree[idx];
    }
    else if(end<left||start>right)
        return '+';
    else{
        char before=get(idx*2,start,(start+end)/2,left,right);
        char after=get(idx*2+1,(start+end)/2+1,end,left,right);
        return giho(before,after);
    }
}
char update(long long update_idx,long long diff,long long idx,long long start,long long end){
    if(start==end){
        if(start==update_idx){
            num[start]=diff;
            if(num[start]>0)
                segtree[idx]='+';
            else if(num[start]<0)
                segtree[idx]='-';
            else
                segtree[idx]='0';
            return segtree[idx];
        }
        else
            return segtree[idx];
    }
    else if(start>update_idx||end<update_idx)
        return segtree[idx];
    char before=update(update_idx,diff,idx*2,start,(start+end)/2);
    char after=update(update_idx,diff,idx*2+1,(start+end)/2+1,end);
    return segtree[idx]=giho(before,after);
}
char giho(char a,char b){
    if(a=='0'||b=='0')
        return '0';
    if(a==b)
        return '+';
    else
        return '-';
}