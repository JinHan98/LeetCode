#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N,M;
int num[1000001];
void join(int a,int b);
int find(int a);
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int selecter,a,b;
    cin>>N>>M;
    for(int i=0;i<=N;i++)
        num[i]=i;
    for(int i=0;i<M;i++){
        cin>>selecter>>a>>b;
        if(selecter==0){
            join(a,b);
        }
        else{
            find(a);
            find(b);
            if(num[a]==num[b]){
                cout<<"yes"<<'\n';
            }
            else
                cout<<"no"<<'\n';
        }
    }
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
