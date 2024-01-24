#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;
long long DP[1<<10][101][10];
int N;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=9;i++){
        DP[1<<i][1][i]=1;
    }
    for(int i=2;i<=N;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<1024;k++){
                if(j==0){
                    DP[k|(1<<j)][i][0]+=DP[k][i-1][1];
                    DP[k|(1<<j)][i][0]%=1000000000;
                }
                else if(j==9){
                    DP[k|(1<<j)][i][9]+=DP[k][i-1][8];
                    DP[k|(1<<j)][i][9]%=1000000000;
                }
                else{
                    DP[k|(1<<j)][i][j]+=DP[k][i-1][j-1];
                    DP[k|(1<<j)][i][j]%=1000000000;
                    DP[k|(1<<j)][i][j]+=DP[k][i-1][j+1];
                    DP[k|(1<<j)][i][j]%=1000000000;
                }
            }
        }
    }
    long long ans=0;
    for(int i=0;i<10;i++){
        ans+=DP[1023][N][i];
        ans%=1000000000;
    }
    cout<<ans<<'\n';
    
}