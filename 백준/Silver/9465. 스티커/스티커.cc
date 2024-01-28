#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
using namespace std;

int N,T;
int num[2][100000];
int DP[2][100000];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        for(int j=0;j<N;j++){
            cin>>num[0][j];
        }
        for(int j=0;j<N;j++){
            cin>>num[1][j];
        }
        DP[0][0]=num[0][0];
        DP[1][0]=num[1][0];
        DP[0][1]=DP[1][0]+num[0][1];
        DP[1][1]=DP[0][0]+num[1][1];
        for(int j=2;j<N;j++){
            DP[0][j]=max(max(DP[0][j-2],DP[1][j-1]),DP[1][j-2]);
            DP[0][j]+=num[0][j];
            DP[1][j]=max(max(DP[1][j-2],DP[0][j-1]),DP[0][j-2]);
            DP[1][j]+=num[1][j];
        }
        cout<<max(DP[0][N-1],DP[1][N-1])<<'\n';
    }
    
}