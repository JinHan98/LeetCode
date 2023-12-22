#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
int m,Q;
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>m;
    vector<vector<int> >DP(31,vector<int>(m+1,0));
    for(int i=1;i<=m;i++){
        cin>>DP[0][i];
    }
    
    for(int i=1;i<=30;i++){
        for(int j=1;j<=m;j++){
            DP[i][j]=DP[i-1][DP[i-1][j]];
        }
    }
    cin>>Q;
    int n,x;
    for(int i=0;i<Q;i++){
        cin>>n>>x;
        for(int j=0;n!=0;j++){
            if(n%2==1){
                x=DP[j][x];
            }
            n=n>>1;
        }
        cout<<x<<'\n';
    }
}