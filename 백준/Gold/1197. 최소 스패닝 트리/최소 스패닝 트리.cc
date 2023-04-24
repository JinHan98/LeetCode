#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N,M;
int isvisit[10001];
priority_queue<vector<int>,vector<vector<int> >,greater<vector<int> > > k;
int find(int a);
void Union(int a,int b);
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        isvisit[i]=i;
    }
    vector<int> temp(3);
    for(int i=0;i<M;i++){
        cin>>temp[1]>>temp[2]>>temp[0];
        k.push(temp);
    }
    N--;
    int ans=0;
    while(N>0){
        temp=k.top();
        k.pop();
        isvisit[temp[1]]=find(temp[1]);
        isvisit[temp[2]]=find(temp[2]);
        if(isvisit[temp[1]]==isvisit[temp[2]])
            continue;
        else{
            N--;
            Union(temp[1],temp[2]);
            ans+=temp[0];
        }
    }
    cout<<ans;
}
int find(int a){
    if(isvisit[a]==a)
        return a;
    else{
        return find(isvisit[a]);
    }
}
void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)
        return ;
    else{
        if(a>b){
            isvisit[a]=b;
        }
        else
            isvisit[b]=a;
    }
}