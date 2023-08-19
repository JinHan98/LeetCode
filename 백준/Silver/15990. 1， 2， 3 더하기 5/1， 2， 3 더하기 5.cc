#include <iostream>
#include <vector>

using namespace std;

long long DP[100001][5];
int T;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    int n;
    DP[1][1]=1;
    DP[1][4]=1;
    DP[2][2]=1;
    DP[2][4]=1;
    DP[3][1]=1;
    DP[3][2]=1;
    DP[3][3]=1;
    DP[3][4]=3;
    for(int i=4;i<=100000;i++){
        DP[i][1]=DP[i-1][2]+DP[i-1][3];
        DP[i][1]%=1000000009;
        DP[i][2]=DP[i-2][1]+DP[i-2][3];
        DP[i][2]%=1000000009;
        DP[i][3]=DP[i-3][1]+DP[i-3][2];
        DP[i][3]%=1000000009;
        DP[i][4]=DP[i][1]+DP[i][2]+DP[i][3];
        DP[i][4]%=1000000009;
    }
    for(int i=0;i<T;i++){
        cin>>n;
        cout<<DP[n][4]<<'\n';
    }
}