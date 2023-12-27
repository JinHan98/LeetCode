#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N,M;
int num[100000];
int acc[100001];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    int a,b,k;
    for(int i=0;i<M;i++){
        cin>>a>>b>>k;
        acc[a-1]+=k;
        acc[b]-=k;
    }
    for(int i=1;i<N;i++){
        acc[i]=acc[i-1]+acc[i];
    }
    for(int i=0;i<N;i++){
        cout<<acc[i]+num[i]<<' ';
    }
    
}