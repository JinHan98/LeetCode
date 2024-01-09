#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
int coin[100];
int DP[10001];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>coin[i];
        if(coin[i]<=10000)
            DP[coin[i]]++;
        for(int k=0;k+coin[i]<=K;k++){
            DP[k+coin[i]]+=DP[k];
        }
    }
    cout<<DP[K];
}