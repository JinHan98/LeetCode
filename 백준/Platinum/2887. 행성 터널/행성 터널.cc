#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <stack>
using namespace std;
int N;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >k;
vector<pair<int,int> >xx;
vector<pair<int,int> >yy;
vector<pair<int,int> >zz;
void uni(int a,int b);
int find(int a);
int kru[100001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    int x,y,z;
    for(int i=0;i<N;i++){
        cin>>x>>y>>z;
        xx.push_back({x,i+1});
        yy.push_back({y,i+1});
        zz.push_back({z,i+1});
    }
    for(int i=1;i<=N;i++)
        kru[i]=i;
    sort(xx.begin(),xx.end());
    sort(yy.begin(),yy.end());
    sort(zz.begin(),zz.end());
    for(int i=0;i<N-1;i++){
        k.push({xx[i+1].first-xx[i].first,{xx[i+1].second,xx[i].second}});
        k.push({yy[i+1].first-yy[i].first,{yy[i+1].second,yy[i].second}});
        k.push({zz[i+1].first-zz[i].first,{zz[i+1].second,zz[i].second}});
    }
    int ans=0;
    int num=0;
    while(num!=N-1){
        pair<int,pair<int,int> >temp=k.top();
        k.pop();
        int a=temp.second.first;
        int b=temp.second.second;
        if(a>b){
            int t=a;
            a=b;
            b=t;
        }
        a=find(a);
        b=find(b);
        if(a!=b){
            uni(a,b);
            ans+=temp.first;
            num++;
        }
    }
    cout<<ans;
}
int find(int a){
    if(a==kru[a])
        return a;
    else
        return kru[a]=find(kru[a]);
}
void uni(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        kru[b]=a;
    }
}