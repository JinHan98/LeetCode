#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int K;
int DP[2][46];//0 A 1 B
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    DP[0][0]=1;
    DP[1][1]=1;
    for(int i=2;i<=45;i++){
        DP[1][i]=DP[0][i-1];
        DP[0][i]+=DP[1][i-1];
        DP[1][i]+=DP[1][i-1];
    }
    cin>>K;
    cout<<DP[0][K]<<' '<<DP[1][K];
}
