#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string num[50];
long long alpha[10];
bool notzero[10];
int val[10];
int N;
int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    pair<long long ,int>k[10];
    for(int i=0;i<N;i++){
        cin>>num[i];
        int size=num[i].size();
        long long multi=1;
        for(int j=size-1;j>=0;j--){
            if(j==0)
                notzero[num[i][j]-'A']=true;
            alpha[num[i][j]-'A']+=multi;
            multi*=10;
        }
    }
    for(int i=0;i<10;i++){
        k[i]={alpha[i],i};
    }
    
    sort(k,k+10);
    int zero=-1;
    int su=1;
    for(int i=0;i<10;i++){
        if(!notzero[k[i].second]&&zero==-1){
            zero=k[i].second;
        }
        else
            val[k[i].second]=su++;
    }

    
    long long ans=0;
    for(int i=0;i<N;i++){
        int size=num[i].size();
        long long multi=1;
        for(int j=size-1;j>=0;j--){
            ans+=multi*val[num[i][j]-'A'];
            multi*=10;
        }
    }
    cout<<ans;
}
