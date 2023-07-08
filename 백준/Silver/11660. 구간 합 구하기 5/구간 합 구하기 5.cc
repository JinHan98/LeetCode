#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N,M;
int num[1025][1025];
int acc[1025][1025];
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>num[i][j];
            acc[i][j]=acc[i][j-1]+num[i][j];
        }
    }
    int s_x,s_y,e_x,e_y;
    for(int i=0;i<M;i++){
        int ans=0;
        cin>>s_x>>s_y>>e_x>>e_y;
        for(int j=s_x;j<=e_x;j++){
            ans+=(acc[j][e_y]-acc[j][s_y-1]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}