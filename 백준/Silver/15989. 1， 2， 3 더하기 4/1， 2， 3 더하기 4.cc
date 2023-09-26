#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;
int T,N;
int DP[10001][4];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    DP[1][1]=1;
    DP[2][1]=1;
    DP[2][2]=1;
    DP[3][1]=2;
    DP[3][2]=0;
    DP[3][3]=1;
    for(int i=4;i<=10000;i++){
        DP[i][1]=DP[i-1][1]+DP[i-1][2]+DP[i-1][3];
        DP[i][2]=DP[i-2][2]+DP[i-2][3];
        DP[i][3]=DP[i-3][3];
    }
    for(int i=0;i<T;i++){
        cin>>N;
        cout<<DP[N][1]+DP[N][2]+DP[N][3]<<'\n';
    }
}