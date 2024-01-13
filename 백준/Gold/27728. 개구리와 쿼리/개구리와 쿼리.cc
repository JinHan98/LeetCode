#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;
int N,Q;
int num[500][500];
int DP[500][500];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>Q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>num[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=N-2;j>=0;j--){
            num[i][j]+=num[i][j+1];
        }
    }
    for(int i=0;i<N;i++){
        DP[0][i]=num[0][i];
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<N;j++){
            DP[i][j]=min(num[i][j],DP[i-1][j]);
        }
    }
    int x,y,z;
    for(int i=0;i<Q;i++){
        cin>>x>>y>>z;
        int ans=num[x-1][y-1];
        for(int j=y-1;j<N;j++){
            ans=min(ans,num[x-1][y-1]-num[x-1][j]+DP[x-1-z][j]);
        }
        cout<<ans<<'\n';
    }
    
}