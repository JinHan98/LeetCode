#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N,M;
int num[100001];
void join(int a,int b);
int find(int a);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    int ans=0;
    for(int i=1;i<=N;i++){
        num[i]=i;
    }
    priority_queue<vector<int> > k;
    vector<int> temp(4);
    for(int i=0;i<M;i++){
        cin>>temp[1]>>temp[2]>>temp[0]>>temp[3];
        if(temp[3]==1){
            find(temp[1]);
            find(temp[2]);
            join(temp[1],temp[2]);
            continue;
        }
        ans+=temp[0];
        k.push(temp);
    }
    while(!k.empty()){
        temp=k.top();
        k.pop();
        find(temp[1]);
        find(temp[2]);
        if(num[temp[1]]==num[temp[2]]){
            continue;
        }
        join(temp[1],temp[2]);
        ans-=temp[0];
    }
    cout<<ans;
}
void join(int a,int b){
    a=find(a);
    b=find(b);
    if(num[a]<num[b]){
        num[b]=num[a];
    }
    else{
        num[a]=num[b];
    }
}
int find(int a){
    if(a==num[a])
        return a;
    else{
         return num[a]=find(num[a]);
    }
}
